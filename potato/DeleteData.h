// ������� ��� ������ � �������� ������ �� �������� �������
void DeleteData(const std::string& sampleName, HWND hWnd) {
    sqlite3_stmt* stmt;

    // ��������� id ������� �� �������� �������
    std::string sqlFindByName = "SELECT id FROM potato WHERE sample = ?;";
    if (sqlite3_prepare_v2(db, sqlFindByName.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, sampleName.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            sqlite3_finalize(stmt);

            // ������� id ������� �� ������� potato
            std::string sqlDeletePotato = "DELETE FROM potato WHERE id = ?";
            if (sqlite3_prepare_v2(db, sqlDeletePotato.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "������ �������� ������ � �������: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "������ ���������� ������� ��� �������� ������ � �������" << std::endl;
            }

            // ������� id ������� �� ������� morphological_features_of_the_tuber
            std::string sqlDeleteMorphological = "DELETE FROM morphological_features_of_the_tuber WHERE id_potato = ?";
            if (sqlite3_prepare_v2(db, sqlDeleteMorphological.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "������ �������� ������ � ��������������� ������������ ������: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "������ ���������� ������� ��� �������� ������ � ��������������� ������������ ������" << std::endl;
            }
            // ������� id ������� �� ������� culinary_qualities
            std::string sqlDeleteCulinary = "DELETE FROM culinary_qualities WHERE id_potato = ?";
            if (sqlite3_prepare_v2(db, sqlDeleteCulinary.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "������ �������� ������ � ���������� ���������: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "������ ���������� ������� ��� �������� ������ � ���������� ���������" << std::endl;
            }
            // ������� id ������� �� ������� standart
            std::string sqlDeleteStandart = "DELETE FROM standart WHERE id_potato = ?";
            if (sqlite3_prepare_v2(db, sqlDeleteStandart.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "������ �������� ������ � standart: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "������ ���������� ������� ��� �������� ������ � standart" << std::endl;
            }
        }    
        
    }
    else {
        std::cerr << "�� ������ id ������� � ������� potato" << std::endl;
        MessageBox(hWnd, L"������", L"������", MB_OK);
    }

    
}