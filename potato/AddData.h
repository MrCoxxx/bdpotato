void AddData() {
    sqlite3_stmt* stmt;

    std::vector<std::wstring> utf16_Data;
    std::vector<std::string> utf8_Data;
    int col = 0;

    for (int i = 0; i < DataInterface["Add"]["edit"].size(); i++) {
        utf16_Data.push_back(GetEditText(DataInterface["Add"]["edit"][i]));
    }

    for (int i = 0; i < utf16_Data.size(); i++) {
        utf8_Data.push_back(utf16_to_utf8(utf16_Data[i]));
    }

    // Выполнение SQL-запроса для добавления данных о картоте
    const char* sqlPotato = "INSERT INTO potato (sample, VIGRR_catalogue_number, origin, commercial_tubers_in_clone, "
        "non_marketable_tubers_in_clone, weight_of_commercial_tuber, weight_of_non_commercial_tuber, tubers_in_clone, marketability, productivity) "
        "VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";

    if (sqlite3_prepare_v2(db, sqlPotato, -1, &stmt, NULL) == SQLITE_OK) {

        for (int i = 1; i < 11; i++) {
            sqlite3_bind_text(stmt, i, utf8_Data[col].c_str(), -1, SQLITE_TRANSIENT);
            col++;
        }

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Ошибка добавления данных о картоте" << std::endl;
        }

        sqlite3_finalize(stmt);
    }
    
    
    const char* sqlIdPotato = "SELECT MAX(id) FROM potato;";
   
    std::vector<std::string> id_potato;
   
    if (sqlite3_prepare_v2(db, sqlIdPotato, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
   
            id_potato.push_back(std::to_string(sqlite3_column_int(stmt, 0)));
   
        }
        sqlite3_finalize(stmt);
    }
   
    // Выполнение SQL-запроса для добавления данных о морфологических особенностях клубня
    const char* sqlMorphological = "INSERT INTO morphological_features_of_the_tuber(id_potato, form, peel_coloring, pulp_coloring, eye_depth, stolon_trace_depth, tuber_skin_surface) "
        "VALUES(? , ? , ? , ? , ? , ? , ? )";
   
    if (sqlite3_prepare_v2(db, sqlMorphological, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, id_potato[0].c_str(), -1, SQLITE_TRANSIENT);

        for (int i = 2; i < 8; i++) {
            sqlite3_bind_text(stmt, i, utf8_Data[col].c_str(), -1, SQLITE_TRANSIENT);
            col++;
        }
   
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Ошибка добавления данных о морфологических особенностях клубня" << std::endl;
        }
   
        sqlite3_finalize(stmt);
    }
   
    // Выполнение SQL-запроса для добавления данных о кулинарных качествах
    const char* sqlCulinary = "INSERT INTO culinary_qualities(id_potato, tuber_boilability, pulp_consistency, friability, "
        "wateriness_of_tubers, the_smell_of_boiled_potatoes, the_taste_of_boiled_potatoes, "
        "darkening_of_the_flesh_of_raw_potatoes, darkening_of_the_flesh_of_boiled_potatoes) "
        "VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? )";
   
    if (sqlite3_prepare_v2(db, sqlCulinary, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, id_potato[0].c_str(), -1, SQLITE_TRANSIENT);

        for (int i = 2; i < 10; i++) {
            sqlite3_bind_text(stmt, i, utf8_Data[col].c_str(), -1, SQLITE_TRANSIENT);
            col++;
        }
   
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Ошибка добавления данных о кулинарных качествах" << std::endl;
        }
   
        sqlite3_finalize(stmt);
    }
   //Раскоментить когда будут данные
   // Выполнение SQL-запроса для добавления данных standart
   //const char* sqlStandart = "INSERT INTO standart(id_potato, field_resistance_to_late_blight, "
   //"the_ability_to_form_berries_from_self_pollination, flowering_duration, ripeness_group, yield_percentage) "
   //"VALUES(? , ? , ? , ? , ? , ? )";
   //
   //
   //if (sqlite3_prepare_v2(db, sqlStandart, -1, &stmt, NULL) == SQLITE_OK) {
   //    sqlite3_bind_text(stmt, 1, id_potato[0].c_str(), -1, SQLITE_TRANSIENT);

   //    for (int i = 2; i < 7; i++) {
   //        sqlite3_bind_text(stmt, i, utf8_Data[col].c_str(), -1, SQLITE_TRANSIENT);
   //        col++;
   //    }
   //
   //    if (sqlite3_step(stmt) != SQLITE_DONE) {
   //        std::cerr << "Ошибка добавления данных о морфологических особенностях клубня" << std::endl;
   //    }
   //
   //    sqlite3_finalize(stmt);
   //}
}