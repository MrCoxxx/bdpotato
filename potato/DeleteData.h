// Функция для поиска и удаления данных по названию образца
void DeleteData(const std::string& sampleName, HWND hWnd) {
    sqlite3_stmt* stmt;

    // Получение id образца по названию образца
    std::string sqlFindByName = "SELECT id FROM potato WHERE sample = ?;";
    if (sqlite3_prepare_v2(db, sqlFindByName.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, sampleName.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            sqlite3_finalize(stmt);

            // Удаляем id образца из таблицы potato
            std::string sqlDeletePotato = "DELETE FROM potato WHERE id = ?";
            if (sqlite3_prepare_v2(db, sqlDeletePotato.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "Ошибка удаления данных о картоте: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "Ошибка подготовки запроса для удаления данных о картоте" << std::endl;
            }

            // Удаляем id образца из таблицы morphological_features_of_the_tuber
            std::string sqlDeleteMorphological = "DELETE FROM morphological_features_of_the_tuber WHERE id_potato = ?";
            if (sqlite3_prepare_v2(db, sqlDeleteMorphological.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "Ошибка удаления данных о морфологических особенностях клубня: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "Ошибка подготовки запроса для удаления данных о морфологических особенностях клубня" << std::endl;
            }
            // Удаляем id образца из таблицы culinary_qualities
            std::string sqlDeleteCulinary = "DELETE FROM culinary_qualities WHERE id_potato = ?";
            if (sqlite3_prepare_v2(db, sqlDeleteCulinary.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "Ошибка удаления данных о кулинарных качествах: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "Ошибка подготовки запроса для удаления данных о кулинарных качествах" << std::endl;
            }
            // Удаляем id образца из таблицы standart
            std::string sqlDeleteStandart = "DELETE FROM standart WHERE id_potato = ?";
            if (sqlite3_prepare_v2(db, sqlDeleteStandart.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, id);
                if (sqlite3_step(stmt) != SQLITE_DONE) {
                    std::cerr << "Ошибка удаления данных о standart: " << sqlite3_errmsg(db) << std::endl;
                }
                sqlite3_finalize(stmt);
            }
            else {
                std::cerr << "Ошибка подготовки запроса для удаления данных о standart" << std::endl;
            }
        }    
        
    }
    else {
        std::cerr << "Не найден id образца в таблице potato" << std::endl;
        MessageBox(hWnd, L"Ошибка", L"Ошибка", MB_OK);
    }

    
}