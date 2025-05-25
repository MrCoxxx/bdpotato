#include <string>
#include <vector>
#include <algorithm>

// ������� ��� ������� ������ �� ������������ XML-��������
std::string sanitizeForExcel(const std::string& input) {
    std::string output;
    for (char c : input) {
        // ��������� ������ �������� ������� ASCII (32-126) + ���������, ������� ������
        if ((c >= 32 && c <= 126) || c == '\t' || c == '\n' || c == '\r') {
            output += c;
        }
        // �������� ��������� � ������ ������� �� "?"
        else {
            output += '?';
        }
    }
    return output;
}

bool ExportToExcel(sqlite3* db, const std::string& filename) {
    // 1. ������� Excel-����
    lxw_workbook* workbook = workbook_new(filename.c_str());
    if (!workbook) {
        return false;
    }

    // 2. ��������� ����
    lxw_worksheet* worksheet = workbook_add_worksheet(workbook, "Data");
    if (!worksheet) {
        workbook_close(workbook);
        return false;
    }

    // 3. SQL-������
    const char* sql =
        "SELECT p.sample, p.origin, p.VIGRR_catalogue_number, p.productivity, "
        "p.field_resistance_to_late_blight, mf.form, mf.peel_coloring, mf.pulp_coloring, "
        "mf.eye_depth, mf.stolon_trace_depth, cq.taste, cq.pulp_consistency, "
        "cq.darkening_after_cooking, p.weight_of_commercial_tuber "
        "FROM potato p "
        "JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato "
        "JOIN culinary_qualities cq ON p.id = cq.id_potato";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        workbook_close(workbook);
        return false;
    }

    // 4. ��������� ��������
    const std::vector<std::string> headers = {
        "�������", "�������������", "�����", "�����������",
        "������� ������������ � �����������", "�����", "������� ������",
        "������� ������", "������� �������", "������� ���������� �����",
        "����", "������������ ������", "���������� ����� �����",
        "����� ��������� ������"
    };

    for (size_t i = 0; i < headers.size(); ++i) {
        worksheet_write_string(worksheet, 0, i, headers[i].c_str(), NULL);
    }

    // 5. ������ ������
    int row = 1;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int col = 0; col < sqlite3_column_count(stmt); ++col) {
            switch (sqlite3_column_type(stmt, col)) {
            case SQLITE_NULL:
                worksheet_write_string(worksheet, row, col, "NULL", NULL);
                break;
            case SQLITE_TEXT: {
                const char* text = (const char*)sqlite3_column_text(stmt, col);
                std::string sanitized = sanitizeForExcel(text ? text : "");
                worksheet_write_string(worksheet, row, col, sanitized.c_str(), NULL);
                break;
            }
            case SQLITE_INTEGER:
                worksheet_write_number(worksheet, row, col, sqlite3_column_int(stmt, col), NULL);
                break;
            case SQLITE_FLOAT:
                worksheet_write_number(worksheet, row, col, sqlite3_column_double(stmt, col), NULL);
                break;
            default:
                worksheet_write_string(worksheet, row, col, "?", NULL);
            }
        }
        ++row;
    }

    // 6. ������������ ��������
    sqlite3_finalize(stmt);
    lxw_error error = workbook_close(workbook);
    return (error == LXW_NO_ERROR);
}