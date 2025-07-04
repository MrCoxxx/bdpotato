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
        "p.tubers_in_clone, p.marketability, p.productivity "

        //Раскоментить когда будут данные
        //"mf.form, mf.peel_coloring, mf.pulp_coloring, "
        //"mf.eye_depth, mf.stolon_trace_depth, mf.tuber_skin_surface, "
        //"cq.tuber_boilability, cq.pulp_consistency, "
        //"cq.friability, cq.wateriness_of_tubers, cq.the_smell_of_boiled_potatoes, "
        //"cq.the_taste_of_boiled_potatoes, cq.darkening_of_the_flesh_of_raw_potatoes, cq.darkening_of_the_flesh_of_boiled_potatoes, "
        //"s.field_resistance_to_late_blight, s.the_ability_to_form_berries_from_self_pollination, "
        //"s.flowering_duration, s.ripeness_group, s.yield_percentage "
        
        "FROM potato p ";

        //Раскоментить когда будут данные
        //"JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato "
        //"JOIN culinary_qualities cq ON p.id = cq.id_potato "
        //"JOIN standart s ON p.id = s.id_potato";

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

    auto wordCheckedParam = [&](bool checked, HWND editControl, const std::string& condition) {
        if (checked) {

            GetWindowTextA(editControl, Buffer3, TextBufferSize);
            std::vector<std::string> words = split(Buffer3, ',');
            int i = 0;

            size_t wordCount = countWords(Buffer3, ',');
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
    //Potato
    wordCheckedParam(statsCheckBoxSample == BST_CHECKED, EditZonePS[0], "p.sample = ?");
    wordCheckedParam(statsCheckBoxVIGRR == BST_CHECKED, EditZonePS[1], "p.VIGRR_catalogue_number = ?");
    wordCheckedParam(statsCheckBoxOrigin == BST_CHECKED, EditZonePS[2], "p.origin = ?");

    wordCheckedParam(statsCheckBoxCommercial == BST_CHECKED, EditZonePL[0], "p.commercial_tubers_in_clone >= ?");
    wordCheckedParam(statsCheckBoxCommercial == BST_CHECKED, EditZonePR[0], "p.commercial_tubers_in_clone <= ?");

    wordCheckedParam(statsCheckBoxNon_marketable == BST_CHECKED, EditZonePL[1], "p.non_marketable_tubers_in_clone >= ?");
    wordCheckedParam(statsCheckBoxNon_marketable == BST_CHECKED, EditZonePR[1], "p.non_marketable_tubers_in_clone <= ?");

    wordCheckedParam(statsCheckBoxCommercial_tuber == BST_CHECKED, EditZonePL[2], "p.weight_of_commercial_tuber >= ?");
    wordCheckedParam(statsCheckBoxCommercial_tuber == BST_CHECKED, EditZonePR[2], "p.weight_of_commercial_tuber <= ?");

    wordCheckedParam(statsCheckBoxNon_commercial_tuber == BST_CHECKED, EditZonePL[3], "p.weight_of_non_commercial_tuber >= ?");
    wordCheckedParam(statsCheckBoxNon_commercial_tuber == BST_CHECKED, EditZonePR[3], "p.weight_of_non_commercial_tuber <= ?");

    wordCheckedParam(statsCheckBoxTubers == BST_CHECKED, EditZonePL[4], "p.tubers_in_clone >= ?");
    wordCheckedParam(statsCheckBoxTubers == BST_CHECKED, EditZonePR[4], "p.tubers_in_clone <= ?");

    wordCheckedParam(statsCheckBoxMarketability == BST_CHECKED, EditZonePL[5], "p.marketability >= ?");
    wordCheckedParam(statsCheckBoxMarketability == BST_CHECKED, EditZonePR[5], "p.marketability <= ?");

    wordCheckedParam(statsCheckBoxProductivity == BST_CHECKED, EditZonePL[6], "p.productivity >= ?");
    wordCheckedParam(statsCheckBoxProductivity == BST_CHECKED, EditZonePR[6], "p.productivity <= ?");

    //Раскоментить когда будут данные
    ////Morh
    //wordCheckedParam(statsCheckBoxForm == BST_CHECKED, EditZoneM[0], "mf.form = ?");
    //wordCheckedParam(statsCheckBoxPeel == BST_CHECKED, EditZoneM[1], "mf.peel_coloring = ?");
    //wordCheckedParam(statsCheckBoxPulp == BST_CHECKED, EditZoneM[2], "mf.pulp_coloring = ?");
    //wordCheckedParam(statsCheckBoxEye == BST_CHECKED, EditZoneM[3], "mf.eye_depth = ?");
    //wordCheckedParam(statsCheckBoxStolon == BST_CHECKED, EditZoneM[4], "mf.stolon_trace_depth = ?");
    //wordCheckedParam(statsCheckBoxSkin == BST_CHECKED, EditZoneM[5], "mf.tuber_skin_surface = ?");
    //
    //
    ////Cul
    //wordCheckedParam(statsCheckBoxBoilability == BST_CHECKED, EditZoneCL[0], "cq.tuber_boilability >= ?");
    //wordCheckedParam(statsCheckBoxBoilability == BST_CHECKED, EditZoneCR[0], "cq.tuber_boilability <= ?");
    //
    //wordCheckedParam(statsCheckBoxConsistency == BST_CHECKED, EditZoneCL[1], "cq.pulp_consistency >= ?");
    //wordCheckedParam(statsCheckBoxConsistency == BST_CHECKED, EditZoneCR[1], "cq.pulp_consistency <= ?");
    //
    //wordCheckedParam(statsCheckBoxFriability == BST_CHECKED, EditZoneCL[2], "cq.friability >= ?");
    //wordCheckedParam(statsCheckBoxFriability == BST_CHECKED, EditZoneCR[2], "cq.friability <= ?");
    //
    //wordCheckedParam(statsCheckBoxWateriness == BST_CHECKED, EditZoneCL[3], "cq.wateriness_of_tubers >= ?");
    //wordCheckedParam(statsCheckBoxWateriness == BST_CHECKED, EditZoneCR[3], "cq.wateriness_of_tubers <= ?");
    //
    //wordCheckedParam(statsCheckBoxSmell == BST_CHECKED, EditZoneCL[4], "cq.the_smell_of_boiled_potatoes >= ?");
    //wordCheckedParam(statsCheckBoxSmell == BST_CHECKED, EditZoneCR[4], "cq.the_smell_of_boiled_potatoes <= ?");
    //
    //wordCheckedParam(statsCheckBoxTaste == BST_CHECKED, EditZoneCL[5], "cq.the_taste_of_boiled_potatoes >= ?");
    //wordCheckedParam(statsCheckBoxTaste == BST_CHECKED, EditZoneCR[5], "cq.the_taste_of_boiled_potatoes <= ?");
    //
    //wordCheckedParam(statsCheckBoxDarkening_raw == BST_CHECKED, EditZoneCL[6], "cq.darkening_of_the_flesh_of_raw_potatoes >= ?");
    //wordCheckedParam(statsCheckBoxDarkening_raw == BST_CHECKED, EditZoneCR[6], "cq.darkening_of_the_flesh_of_raw_potatoes <= ?");
    //
    //wordCheckedParam(statsCheckBoxDarkening_boiled == BST_CHECKED, EditZoneCL[7], "cq.darkening_of_the_flesh_of_boiled_potatoes >= ?");
    //wordCheckedParam(statsCheckBoxDarkening_boiled == BST_CHECKED, EditZoneCR[7], "cq.darkening_of_the_flesh_of_boiled_potatoes <= ?");
    //
    //
    ////Standart
    //wordCheckedParam(statsCheckBoxField == BST_CHECKED, EditZoneSL[0], "s.field_resistance_to_late_blight >= ?");
    //wordCheckedParam(statsCheckBoxField == BST_CHECKED, EditZoneSR[0], "s.field_resistance_to_late_blight <= ?");
    //
    //wordCheckedParam(statsCheckBoxAbility == BST_CHECKED, EditZoneSL[1], "s.the_ability_to_form_berries_from_self_pollination >= ?");
    //wordCheckedParam(statsCheckBoxAbility == BST_CHECKED, EditZoneSR[1], "s.the_ability_to_form_berries_from_self_pollination <= ?");
    //
    //wordCheckedParam(statsCheckBoxFlowering == BST_CHECKED, EditZoneSL[2], "s.flowering_duration >= ?");
    //wordCheckedParam(statsCheckBoxFlowering == BST_CHECKED, EditZoneSR[2], "s.flowering_duration <= ?");
    //
    //wordCheckedParam(statsCheckBoxRipeness == BST_CHECKED, EditZoneSL[3], "s.ripeness_group >= ?");
    //wordCheckedParam(statsCheckBoxRipeness == BST_CHECKED, EditZoneSR[3], "s.ripeness_group <= ?");
    //
    //wordCheckedParam(statsCheckBoxYield == BST_CHECKED, EditZoneSL[4], "s.yield_percentage >= ?");
    //wordCheckedParam(statsCheckBoxYield == BST_CHECKED, EditZoneSR[4], "s.yield_percentage <= ?");



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