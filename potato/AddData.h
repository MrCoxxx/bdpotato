void AddPotatoSample()
{
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO potato (sample, origin, VIGRR_catalogue_number, productivity, field_resistance_to_late_blight, weight_of_commercial_tuber) VALUES (?, ?, ?, ?, ?, ?)";

    Sample = GetEditText(editSample);
    Origin = GetEditText(editOrigin);
    VIGRR = GetEditText(editVIGRR);
    Productivity = GetEditText(editProductivity);
    Field = GetEditText(editField);
    Weight = GetEditText(editWeightN);

    utf8_Sample = utf16_to_utf8(Sample);
    utf8_Origin = utf16_to_utf8(Origin);
    utf8_VIGRR = utf16_to_utf8(VIGRR);
    utf8_Productivity = utf16_to_utf8(Productivity);
    utf8_Field = utf16_to_utf8(Field);
    utf8_Weight = utf16_to_utf8(Weight);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_Sample.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_Origin.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_VIGRR.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Productivity.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_Field.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 6, utf8_Weight.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}

void AddMorphologicalSample()
{
    IDPotatoM = GetEditText(editIDPotatoM);
    Form = GetEditText(editForm);
    Peel = GetEditText(editPeel);
    Pulp = GetEditText(editPulp);
    Eye = GetEditText(editEye);
    Stolon = GetEditText(editStolon);

    utf8_IDPotatoM = utf16_to_utf8(IDPotatoM);
    utf8_Form = utf16_to_utf8(Form);
    utf8_Peel = utf16_to_utf8(Peel);
    utf8_Pulp = utf16_to_utf8(Pulp);
    utf8_Eye = utf16_to_utf8(Eye);
    utf8_Stolon = utf16_to_utf8(Stolon);


    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO morphological_features_of_the_tuber (id_potato, form, peel_coloring, pulp_coloring, eye_depth, stolon_trace_depth) VALUES (?, ?, ?, ?, ?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_IDPotatoM.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_Form.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_Peel.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Pulp.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_Eye.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 6, utf8_Stolon.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 7, utf8_ID.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}

void AddCulinarySample()
{
    IDPotatoC = GetEditText(editIDPotatoC);
    Taste = GetEditText(editTaste);
    Consistency = GetEditText(editConsistency);
    Darkening = GetEditText(editDarkening);

    utf8_IDPotatoC = utf16_to_utf8(IDPotatoC);
    utf8_Taste = utf16_to_utf8(Taste);
    utf8_Consistency = utf16_to_utf8(Consistency);
    utf8_Darkening = utf16_to_utf8(Darkening);


    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO culinary_qualities (id_potato, taste, pulp_consistency, darkening_after_cooking) VALUES (?, ?, ?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_IDPotatoC.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_Taste.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_Consistency.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Darkening.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_ID.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}
