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
    result.sql = "SELECT p.sample, p.VIGRR_catalogue_number, p.origin, p.commercial_tubers_in_clone, "
        "p.non_marketable_tubers_in_clone, p.weight_of_commercial_tuber, p.weight_of_non_commercial_tuber, "
        "p.tubers_in_clone, p.marketability, p.productivity, "
        "mf.form, mf.peel_coloring, mf.pulp_coloring, "
        "mf.eye_depth, mf.stolon_trace_depth, mf.tuber_skin_surface, "
        "cq.tuber_boilability, cq.pulp_consistency, "
        "cq.friability, cq.wateriness_of_tubers, cq.the_smell_of_boiled_potatoes, "
        "cq.the_taste_of_boiled_potatoes, cq.darkening_of_the_flesh_of_raw_potatoes, cq.darkening_of_the_flesh_of_boiled_potatoes, "
        "s.field_resistance_to_late_blight, s.the_ability_to_form_berries_from_self_pollination, "
        "s.flowering_duration, s.ripeness_group, s.yield_percentage "
        "FROM potato p "
        "JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato "
        "JOIN culinary_qualities cq ON p.id = cq.id_potato "
        "JOIN standart s ON p.id = s.id_potato";

    // Получаем данные из полей ввода
    auto getCheckedParam = [&](bool checked, HWND editControl, const std::string& condition) {
        if (checked) {
            auto text = GetEditText(editControl);
            auto utf8 = utf16_to_utf8(text);
            if (!utf8.empty()) {
                if (result.sql.find("WHERE") == std::string::npos) {
                    result.sql += " WHERE ";
                    result.sql += condition.substr(5);                              
                }
                else {
                    result.sql += condition;
                }
                result.params.push_back(utf8);
            }
        }
    };

    auto testCheckedParam = [&](bool checked, HWND editControl, const std::string& condition) {
        if (checked) {

            GetWindowTextA(editControl, Buffer3, TextBufferSize);
            std::vector<std::string> words = split(Buffer3, ' ');
            int i = 0;

            size_t wordCount = countWords(Buffer3, ' ');
            for (const auto& word : words) {
                SetWindowTextA(testPeel1, word.c_str());

                if (i == 0) {
                    getCheckedParam(checked, testPeel1, " AND (" + condition);
                    i++;
                }
                else {
                    getCheckedParam(checked, testPeel1, " OR " + condition);
                    i++;
                }
                if (i == wordCount) {
                    result.sql += ")";
                }
            }

        }
    };

    // Добавляем условия для каждого параметра
    testCheckedParam(statsCheckBoxSample == BST_CHECKED, editSample, "p.sample = ?");
    getCheckedParam(statsCheckBoxOrigin == BST_CHECKED, editOrigin, " AND p.origin = ?");
    getCheckedParam(statsCheckBoxVIGRR == BST_CHECKED, editVIGRR, " AND p.VIGRR_catalogue_number = ?");
    getCheckedParam(statsCheckBoxProductivity == BST_CHECKED, editProductivity, " AND p.productivity = ?");
    getCheckedParam(statsCheckBoxField == BST_CHECKED, editField, " AND p.field_resistance_to_late_blight = ?");
    testCheckedParam(statsCheckBoxForm == BST_CHECKED, editForm, "mf.form = ?");
    testCheckedParam(statsCheckBoxPulp == BST_CHECKED, editPulp, "mf.pulp_coloring = ?");
    testCheckedParam(statsCheckBoxEye == BST_CHECKED, editEye, "mf.eye_depth = ?");
    testCheckedParam(statsCheckBoxStolon == BST_CHECKED, editStolon, "mf.stolon_trace_depth = ?");
    testCheckedParam(statsCheckBoxTaste == BST_CHECKED, editTaste, "cq.taste = ?");
    testCheckedParam(statsCheckBoxConsistency == BST_CHECKED, editConsistency, "cq.pulp_consistency = ?");
    testCheckedParam(statsCheckBoxDarkening == BST_CHECKED, editDarkening, "cq.darkening_after_cooking = ?");
    getCheckedParam(statsCheckBoxWeight == BST_CHECKED, editWeightN, " AND p.weight_of_commercial_tuber >= ?");
    getCheckedParam(statsCheckBoxWeight == BST_CHECKED, editWeightK, " AND p.weight_of_commercial_tuber <= ?");
    testCheckedParam(statsCheckBoxPeel == BST_CHECKED, editPeel, "mf.peel_coloring = ?");

    return result;
}


std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

size_t countWords(const std::string& s, char delimiter) {
    std::istringstream iss(s);
    size_t count = 0;
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        if (!token.empty()) {  // Игнорируем пустые элементы (если ",,")
            count++;
        }
    }
    return count;
}