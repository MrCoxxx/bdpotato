void AddData() {
    sqlite3_stmt* stmt;

    // Получение данных из полей для добавления в базы данных
    std::wstring sample = GetEditText(editSample);
    std::wstring VIGRR = GetEditText(editVIGRR);
    std::wstring origin = GetEditText(editOrigin);
    std::wstring commercial_tubers = GetEditText(editCommercial_tubers);
    std::wstring non_marketable = GetEditText(editNon_marketable);
    std::wstring commercial = GetEditText(editCommercial);
    std::wstring non_commercial = GetEditText(editNon_commercial);
    std::wstring tubers = GetEditText(editTubers);
    std::wstring marketability = GetEditText(editMarketability);
    std::wstring productivity = GetEditText(editProductivity);


    //Раскоментить когда будут данные
    //std::wstring form = GetEditText(editForm);
    //std::wstring peel = GetEditText(editPeel);
    //std::wstring pulp = GetEditText(editPulp);
    //std::wstring eye = GetEditText(editEye);
    //std::wstring stolon = GetEditText(editStolon);
    //std::wstring skin = GetEditText(editSkin);
    //
    //
    //
    //std::wstring boilability = GetEditText(editBoilability);
    //std::wstring consistency = GetEditText(editConsistency);
    //std::wstring friability = GetEditText(editFriability);
    //std::wstring wateriness = GetEditText(editWateriness);
    //std::wstring smell = GetEditText(editSmell);
    //std::wstring taste = GetEditText(editTaste);
    //std::wstring darkening_raw = GetEditText(editDarkening_raw);
    //std::wstring darkening_boiled = GetEditText(editDarkening_boiled);
    //
    //
    //
    //std::wstring field = GetEditText(editField);
    //std::wstring ability = GetEditText(editAbility);
    //std::wstring flowering = GetEditText(editFlowering);
    //std::wstring ripeness = GetEditText(editRipeness);
    //std::wstring yield = GetEditText(editYield);

    // Конвертация строк для SQL-запроса
    std::string utf8_Sample = utf16_to_utf8(sample);
    std::string utf8_VIGRR = utf16_to_utf8(VIGRR);
    std::string utf8_Origin = utf16_to_utf8(origin);
    std::string utf8_Commercial_tubers = utf16_to_utf8(commercial_tubers);
    std::string utf8_Non_marketable = utf16_to_utf8(non_marketable);
    std::string utf8_Commercial = utf16_to_utf8(commercial);
    std::string utf8_Non_commercial = utf16_to_utf8(non_commercial);
    std::string utf8_Tubers = utf16_to_utf8(tubers);
    std::string utf8_Productivity = utf16_to_utf8(productivity);
    std::string utf8_Marketability = utf16_to_utf8(marketability);


//Раскоментить когда будут данные
//std::string utf8_Form = utf16_to_utf8(form);
//std::string utf8_PeelColoring = utf16_to_utf8(peel);
//std::string utf8_PulpColoring = utf16_to_utf8(pulp);
//std::string utf8_Eye = utf16_to_utf8(eye);
//std::string utf8_Stolon = utf16_to_utf8(stolon);
//std::string utf8_Skin = utf16_to_utf8(skin);
//
//
//
//std::string utf8_Boilability = utf16_to_utf8(boilability);
//std::string utf8_Consistency = utf16_to_utf8(consistency);
//std::string utf8_Friability = utf16_to_utf8(friability);
//std::string utf8_Wateriness = utf16_to_utf8(wateriness);
//std::string utf8_Smell = utf16_to_utf8(smell);
//std::string utf8_Taste = utf16_to_utf8(taste);
//std::string utf8_Darkening_raw = utf16_to_utf8(darkening_raw);
//std::string utf8_Darkening_boiled = utf16_to_utf8(darkening_boiled);
//
//
//
//std::string utf8_Field = utf16_to_utf8(field);
//std::string utf8_Ability = utf16_to_utf8(ability);
//std::string utf8_Flowering = utf16_to_utf8(flowering);
//std::string utf8_Ripeness = utf16_to_utf8(ripeness);
//std::string utf8_Yield = utf16_to_utf8(yield);

    // Выполнение SQL-запроса для добавления данных о картоте
    const char* sqlPotato = "INSERT INTO potato (sample, VIGRR_catalogue_number, origin, commercial_tubers_in_clone, "
        "non_marketable_tubers_in_clone, weight_of_commercial_tuber, weight_of_non_commercial_tuber, tubers_in_clone, marketability, productivity) "
        "VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";

    if (sqlite3_prepare_v2(db, sqlPotato, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_Sample.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_VIGRR.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_Origin.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Commercial_tubers.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_Non_marketable.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 6, utf8_Commercial.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 7, utf8_Non_commercial.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 8, utf8_Tubers.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 9, utf8_Marketability.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 10, utf8_Productivity.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Ошибка добавления данных о картоте" << std::endl;
        }

        sqlite3_finalize(stmt);
    }
    
    //Раскоментить когда будут данные
   //const char* sqlIdPotato = "SELECT MAX(id) FROM potato;";
   //
   //std::vector<std::string> id_potato;
   //
   //if (sqlite3_prepare_v2(db, sqlIdPotato, -1, &stmt, NULL) == SQLITE_OK) {
   //    while (sqlite3_step(stmt) == SQLITE_ROW) {
   //
   //        id_potato.push_back(std::to_string(sqlite3_column_int(stmt, 0)));
   //
   //    }
   //    sqlite3_finalize(stmt);
   //}
   //
   //// Выполнение SQL-запроса для добавления данных о морфологических особенностях клубня
   //const char* sqlMorphological = "INSERT INTO morphological_features_of_the_tuber(id_potato, form, peel_coloring, pulp_coloring, eye_depth, stolon_trace_depth, tuber_skin_surface) "
   //    "VALUES(? , ? , ? , ? , ? , ? , ? )";
   //
   //if (sqlite3_prepare_v2(db, sqlMorphological, -1, &stmt, NULL) == SQLITE_OK) {
   //    sqlite3_bind_text(stmt, 1, id_potato[0].c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 2, utf8_Form.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 3, utf8_PeelColoring.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 4, utf8_PulpColoring.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 5, utf8_Eye.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 6, utf8_Stolon.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 7, utf8_Skin.c_str(), -1, SQLITE_TRANSIENT);
   //
   //    if (sqlite3_step(stmt) != SQLITE_DONE) {
   //        std::cerr << "Ошибка добавления данных о морфологических особенностях клубня" << std::endl;
   //    }
   //
   //    sqlite3_finalize(stmt);
   //}
   //
   //// Выполнение SQL-запроса для добавления данных о кулинарных качествах
   //const char* sqlCulinary = "INSERT INTO culinary_qualities(id_potato, tuber_boilability, pulp_consistency, friability, "
   //    "wateriness_of_tubers, the_smell_of_boiled_potatoes, the_taste_of_boiled_potatoes, "
   //    "darkening_of_the_flesh_of_raw_potatoes, darkening_of_the_flesh_of_boiled_potatoes) "
   //    "VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? )";
   //
   //if (sqlite3_prepare_v2(db, sqlCulinary, -1, &stmt, NULL) == SQLITE_OK) {
   //    sqlite3_bind_text(stmt, 1, id_potato[0].c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 2, utf8_Boilability.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 3, utf8_Consistency.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 4, utf8_Friability.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 5, utf8_Wateriness.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 6, utf8_Smell.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 7, utf8_Taste.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 8, utf8_Darkening_raw.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 9, utf8_Darkening_boiled.c_str(), -1, SQLITE_TRANSIENT);
   //
   //    if (sqlite3_step(stmt) != SQLITE_DONE) {
   //        std::cerr << "Ошибка добавления данных о кулинарных качествах" << std::endl;
   //    }
   //
   //    sqlite3_finalize(stmt);
   //}
   //
   //// Выполнение SQL-запроса для добавления данных standart
   //const char* sqlStandart = "INSERT INTO standart(id_potato, field_resistance_to_late_blight, "
   //"the_ability_to_form_berries_from_self_pollination, flowering_duration, ripeness_group, yield_percentage) "
   //"VALUES(? , ? , ? , ? , ? , ? )";
   //
   //
   //if (sqlite3_prepare_v2(db, sqlStandart, -1, &stmt, NULL) == SQLITE_OK) {
   //    sqlite3_bind_text(stmt, 1, id_potato[0].c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 2, utf8_Field.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 3, utf8_Ability.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 4, utf8_Flowering.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 5, utf8_Ripeness.c_str(), -1, SQLITE_TRANSIENT);
   //    sqlite3_bind_text(stmt, 6, utf8_Yield.c_str(), -1, SQLITE_TRANSIENT);
   //
   //    if (sqlite3_step(stmt) != SQLITE_DONE) {
   //        std::cerr << "Ошибка добавления данных о морфологических особенностях клубня" << std::endl;
   //    }
   //
   //    sqlite3_finalize(stmt);
   //}
}