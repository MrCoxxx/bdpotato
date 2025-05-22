const char* SqlRequest() {
    if (statsCheckBoxSample == BST_CHECKED and statsCheckBoxOrigin == BST_CHECKED and statsCheckBoxOrigin == BST_CHECKED and statsCheckBoxOrigin == BST_CHECKED and
        statsCheckBoxVIGRR == BST_CHECKED and statsCheckBoxProductivity == BST_CHECKED and statsCheckBoxField == BST_CHECKED and statsCheckBoxForm == BST_CHECKED and
        statsCheckBoxPeel == BST_CHECKED and statsCheckBoxPulp == BST_CHECKED and statsCheckBoxEye == BST_CHECKED and statsCheckBoxStolon == BST_CHECKED and
        statsCheckBoxTaste == BST_CHECKED and statsCheckBoxConsistency == BST_CHECKED and statsCheckBoxDarkening == BST_CHECKED and statsCheckBoxWeight == BST_CHECKED) {

        sample = GetEditText(editSample);
        origin = GetEditText(editOrigin);
        VIGRR = GetEditText(editVIGRR);
        productivity = GetEditText(editProductivity);
        field = GetEditText(editField);
        form = GetEditText(editForm);
        peel = GetEditText(editPeel);
        pulp = GetEditText(editPulp);
        eye = GetEditText(editEye);
        stolon = GetEditText(editStolon);
        taste = GetEditText(editTaste);
        consistency = GetEditText(editConsistency);
        darkening = GetEditText(editDarkening);
        weight = GetEditText(editWeight);

        utf8_sample = utf16_to_utf8(sample);
        utf8_origin = utf16_to_utf8(origin);
        utf8_VIGRR = utf16_to_utf8(VIGRR);
        utf8_productivity = utf16_to_utf8(productivity);
        utf8_field = utf16_to_utf8(field);
        utf8_form = utf16_to_utf8(form);
        utf8_peel = utf16_to_utf8(peel);
        utf8_pulp = utf16_to_utf8(pulp);
        utf8_eye = utf16_to_utf8(eye);
        utf8_stolon = utf16_to_utf8(stolon);
        utf8_taste = utf16_to_utf8(taste);
        utf8_consistency = utf16_to_utf8(consistency);
        utf8_darkening = utf16_to_utf8(darkening);
        utf8_weight = utf16_to_utf8(weight);

        sqlAll = "SELECT p.sample, p.origin, p.VIGRR_catalogue_number, p.productivity, p.field_resistance_to_late_blight, "
            "mf.form, mf.peel_coloring, mf.pulp_coloring, mf.eye_depth, mf.stolon_trace_depth, "
            "cq.taste, cq.pulp_consistency, cq.darkening_after_cooking, p.weight_of_commercial_tuber "
            "FROM potato p JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato JOIN culinary_qualities cq ON p.id = cq.id_potato "
            "WHERE p.sample = ? AND p.origin = ? AND p.VIGRR_catalogue_number = ? AND p.productivity = ? AND p.field_resistance_to_late_blight = ? AND mf.form = ? "
            "AND mf.peel_coloring = ? AND mf.pulp_coloring = ? AND mf.eye_depth = ? AND mf.stolon_trace_depth = ? AND cq.taste = ? AND cq.pulp_consistency = ? "
            "AND cq.darkening_after_cooking = ? AND p.weight_of_commercial_tuber = ? ";
        return sqlAll;
    }
}