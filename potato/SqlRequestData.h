std::wstring GetEditText(HWND hEdit) {
    wchar_t buffer[256];
    GetWindowTextW(hEdit, buffer, 256);
    return std::wstring(buffer);
}

struct QueryData{
    std::string sql;
    std::vector<std::string> params;
};

bool checkOr = false;

bool CheckOr() {
    if (statsCheckBoxPeel1 == BST_CHECKED and statsCheckBoxPeel2 == BST_CHECKED) {
        checkOr = true;
        return checkOr;
    }
    else {
        return checkOr;
    }
}

QueryData BuildQuery()
{
    QueryData result;
    result.sql = "SELECT p.sample, p.origin, p.VIGRR_catalogue_number, p.productivity, "
        "p.field_resistance_to_late_blight, mf.form, mf.peel_coloring, mf.pulp_coloring, "
        "mf.eye_depth, mf.stolon_trace_depth, cq.taste, cq.pulp_consistency, "
        "cq.darkening_after_cooking, p.weight_of_commercial_tuber "
        "FROM potato p "
        "JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato "
        "JOIN culinary_qualities cq ON p.id = cq.id_potato";

    // Получаем данные из полей ввода
    auto getCheckedParam = [&](bool checked, HWND editControl, const std::string& condition) {
        if (checked) {
            auto text = GetEditText(editControl);
            auto utf8 = utf16_to_utf8(text);
            if (!utf8.empty()) {
                if (result.sql.find("WHERE") == std::string::npos) {
                    result.sql += " WHERE ";
                    if (editControl == editPeel2 || editControl == editPeel3) {
                        result.sql += condition.substr(4);
                    }
                    else {
                        result.sql += condition.substr(5);
                    }
                    
                }
                else {
                    result.sql += condition;
                }
                /*else if (CheckOr) {
                    result.sql += " OR ";
                    checkOr = false;
                }
                else {
                    result.sql += " AND ";
                }*/
                
                result.params.push_back(utf8);
            }
        }
    };

    // Добавляем условия для каждого параметра
    getCheckedParam(statsCheckBoxSample == BST_CHECKED, editSample, " AND p.sample = ?");
    getCheckedParam(statsCheckBoxOrigin == BST_CHECKED, editOrigin, " AND p.origin = ?");
    getCheckedParam(statsCheckBoxVIGRR == BST_CHECKED, editVIGRR, " AND p.VIGRR_catalogue_number = ?");
    getCheckedParam(statsCheckBoxProductivity == BST_CHECKED, editProductivity, " AND p.productivity = ?");
    getCheckedParam(statsCheckBoxField == BST_CHECKED, editField, " AND p.field_resistance_to_late_blight = ?");
    getCheckedParam(statsCheckBoxForm == BST_CHECKED, editForm, " AND mf.form = ?");
    getCheckedParam(statsCheckBoxPeel1 == BST_CHECKED, editPeel2, " OR mf.peel_coloring = ?");
    getCheckedParam(statsCheckBoxPeel2 == BST_CHECKED, editPeel3, " OR mf.peel_coloring = ?");
    getCheckedParam(statsCheckBoxPulp == BST_CHECKED, editPulp, " AND mf.pulp_coloring = ?");
    getCheckedParam(statsCheckBoxEye == BST_CHECKED, editEye, " AND mf.eye_depth = ?");
    getCheckedParam(statsCheckBoxStolon == BST_CHECKED, editStolon, " AND mf.stolon_trace_depth = ?");
    getCheckedParam(statsCheckBoxTaste == BST_CHECKED, editTaste, " AND cq.taste = ?");
    getCheckedParam(statsCheckBoxConsistency == BST_CHECKED, editConsistency, " AND cq.pulp_consistency = ?");
    getCheckedParam(statsCheckBoxDarkening == BST_CHECKED, editDarkening, " AND cq.darkening_after_cooking = ?");
    getCheckedParam(statsCheckBoxWeight == BST_CHECKED, editWeight, " AND p.weight_of_commercial_tuber > ?");
    getCheckedParam(statsCheckBoxWeight == BST_CHECKED, editWeight1, " AND p.weight_of_commercial_tuber < ?");

    return result;
}