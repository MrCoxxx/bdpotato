std::vector<std::vector<std::wstring>> GetSample()
{
    std::vector<std::vector<std::wstring>> results;

    const char* sql = "SELECT p.sample, p.VIGRR_catalogue_number, p.origin, p.commercial_tubers_in_clone, "
        "p.non_marketable_tubers_in_clone, p.weight_of_commercial_tuber, p.weight_of_non_commercial_tuber, "
        "p.tubers_in_clone, p.marketability, p.productivity, "
        "mf.form, mf.peel_coloring, mf.pulp_coloring, "
        "mf.eye_depth, mf.stolon_trace_depth, mf.tuber_skin_surface, "
        "cq.tuber_boilability, cq.pulp_consistency, "
        "cq.friability, cq.wateriness_of_tubers, cq.the_smell_of_boiled_potatoes, "
        "cq.the_taste_of_boiled_potatoes, cq.darkening_of_the_flesh_of_raw_potatoes, cq.darkening_of_the_flesh_of_boiled_potatoes "
        "FROM potato p "
        "JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato "
        "JOIN culinary_qualities cq ON p.id = cq.id_potato";

    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        // Обработка ошибки подготовки запроса
        const char* err = sqlite3_errmsg(db);
        MessageBoxA(nullptr, err, "Database Error", MB_ICONERROR);
        return results;
    }

    // Выполняем запрос и получаем результаты
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::wstring> row;
        for (int col = 0; col < sqlite3_column_count(stmt); ++col) {
            const unsigned char* text = sqlite3_column_text(stmt, col);
            if (text) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(text)));
            }
            else {
                row.push_back(L"");
            }
        }
        results.push_back(row);
    }

    sqlite3_finalize(stmt);
    return results;
}