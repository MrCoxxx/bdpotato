std::wstring GetEditText(HWND hEdit) {
    wchar_t buffer[256];
    GetWindowTextW(hEdit, buffer, 256);
    return std::wstring(buffer);
}

struct QueryData{
    std::string sql;
    std::vector<std::string> params;
};

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
                }
                else {
                    result.sql += " AND ";
                }
                result.sql += condition;
                result.params.push_back(utf8);
            }
        }
        };

    // Добавляем условия для каждого параметра
    getCheckedParam(statsCheckBoxSample == BST_CHECKED, editSample, "p.sample = ?");
    getCheckedParam(statsCheckBoxOrigin == BST_CHECKED, editOrigin, "p.origin = ?");
    getCheckedParam(statsCheckBoxVIGRR == BST_CHECKED, editVIGRR, "p.VIGRR_catalogue_number = ?");
    getCheckedParam(statsCheckBoxProductivity == BST_CHECKED, editProductivity, "p.productivity = ?");
    getCheckedParam(statsCheckBoxField == BST_CHECKED, editField, "p.field_resistance_to_late_blight = ?");
    getCheckedParam(statsCheckBoxForm == BST_CHECKED, editForm, "mf.form = ?");
    getCheckedParam(statsCheckBoxPeel == BST_CHECKED, editPeel, "mf.peel_coloring = ?");
    getCheckedParam(statsCheckBoxPulp == BST_CHECKED, editPulp, "mf.pulp_coloring = ?");
    getCheckedParam(statsCheckBoxEye == BST_CHECKED, editEye, "mf.eye_depth = ?");
    getCheckedParam(statsCheckBoxStolon == BST_CHECKED, editStolon, "mf.stolon_trace_depth = ?");
    getCheckedParam(statsCheckBoxTaste == BST_CHECKED, editTaste, "cq.taste = ?");
    getCheckedParam(statsCheckBoxConsistency == BST_CHECKED, editConsistency, "cq.pulp_consistency = ?");
    getCheckedParam(statsCheckBoxDarkening == BST_CHECKED, editDarkening, "cq.darkening_after_cooking = ?");
    getCheckedParam(statsCheckBoxWeight == BST_CHECKED, editWeight, "p.weight_of_commercial_tuber = ?");

    return result;
}