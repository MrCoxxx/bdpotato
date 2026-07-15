#pragma once


// ─────────────────────────────────────────────────────────────────────────────
//  Структура одной записи о сорте (числовые поля для сравнения)
// ─────────────────────────────────────────────────────────────────────────────
struct PotatoRecord {
    std::wstring name;              // наименование образца

    // Агрономические (числовые)
    double commercial_tubers   = 0; // товарных клубней в клоне, шт.
    double non_marketable      = 0; // нетоварных клубней в клоне, шт.
    double weight_commercial   = 0; // масса товарного клубня, г
    double weight_non_comm     = 0; // масса нетоварного клубня, г
    double tubers_in_clone     = 0; // клубней в клоне, шт.
    double marketability       = 0; // товарность, %
    double productivity        = 0; // урожайность, кг/м²

    // Кулинарные (числовые 1-9)
    double boilability         = 0;
    double consistency         = 0;
    double friability          = 0;
    double wateriness          = 0;
    double smell               = 0;
    double taste               = 0;
    double darkening_raw       = 0;
    double darkening_boiled    = 0;
};

// ─────────────────────────────────────────────────────────────────────────────
//  Флаги признаков для сравнения (соответствуют чекбоксам окна)
// ─────────────────────────────────────────────────────────────────────────────
struct DupFields {
    bool commercial_tubers  = false;
    bool non_marketable     = false;
    bool weight_commercial  = false;
    bool weight_non_comm    = false;
    bool tubers_in_clone    = false;
    bool marketability      = false;
    bool productivity       = false;
    bool boilability        = false;
    bool consistency        = false;
    bool friability         = false;
    bool wateriness         = false;
    bool smell              = false;
    bool taste              = false;
    bool darkening_raw      = false;
    bool darkening_boiled   = false;

    // Возвращает true если ни один признак не выбран (сравниваем по всем)
    bool noneSelected() const {
        return !commercial_tubers && !non_marketable  && !weight_commercial &&
               !weight_non_comm   && !tubers_in_clone && !marketability     &&
               !productivity      && !boilability     && !consistency        &&
               !friability        && !wateriness      && !smell              &&
               !taste             && !darkening_raw   && !darkening_boiled;
    }
};

// ─────────────────────────────────────────────────────────────────────────────
//  Результат сравнения
// ─────────────────────────────────────────────────────────────────────────────
struct DupResult {
    std::wstring name;      // наименование сорта
    double distance = 0.0;  // евклидова дистанция (меньше = ближе)
    double similarity = 0.0;// сходство в % (100 = полный дубликат)
};

// ─────────────────────────────────────────────────────────────────────────────
//  Чтение всех записей из БД
// ─────────────────────────────────────────────────────────────────────────────
static std::vector<PotatoRecord> LoadAllPotatoRecords(sqlite3* db) {
    std::vector<PotatoRecord> records;
    if (!db) return records;

    const char* sql =
        "SELECT p.sample, "
        "p.commercial_tubers_in_clone, p.non_marketable_tubers_in_clone, "
        "p.weight_of_commercial_tuber, p.weight_of_non_commercial_tuber, "
        "p.tubers_in_clone, p.marketability, p.productivity, "
        "cq.tuber_boilability, cq.pulp_consistency, cq.friability, "
        "cq.wateriness_of_tubers, cq.the_smell_of_boiled_potatoes, "
        "cq.the_taste_of_boiled_potatoes, "
        "cq.darkening_of_the_flesh_of_raw_potatoes, "
        "cq.darkening_of_the_flesh_of_boiled_potatoes "
        "FROM potato p "
        "JOIN culinary_qualities cq ON p.id = cq.id_potato";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return records;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        PotatoRecord r;

        auto getStr = [&](int col) -> std::wstring {
            const unsigned char* t = sqlite3_column_text(stmt, col);
            if (!t) return L"";
            return utf8_to_utf16(reinterpret_cast<const char*>(t));
        };
        auto getDouble = [&](int col) -> double {
            return sqlite3_column_double(stmt, col);
        };

        r.name               = getStr(0);
        r.commercial_tubers  = getDouble(1);
        r.non_marketable     = getDouble(2);
        r.weight_commercial  = getDouble(3);
        r.weight_non_comm    = getDouble(4);
        r.tubers_in_clone    = getDouble(5);
        r.marketability      = getDouble(6);
        r.productivity       = getDouble(7);
        r.boilability        = getDouble(8);
        r.consistency        = getDouble(9);
        r.friability         = getDouble(10);
        r.wateriness         = getDouble(11);
        r.smell              = getDouble(12);
        r.taste              = getDouble(13);
        r.darkening_raw      = getDouble(14);
        r.darkening_boiled   = getDouble(15);

        records.push_back(r);
    }
    sqlite3_finalize(stmt);
    return records;
}

// ─────────────────────────────────────────────────────────────────────────────
//  Нормализация одного значения в [0;1] по диапазону всей коллекции
// ─────────────────────────────────────────────────────────────────────────────
static double Normalize(double val, double minVal, double maxVal) {
    if (maxVal - minVal < 1e-9) return 0.0;
    return (val - minVal) / (maxVal - minVal);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Основная функция: сравнить targetName со всеми остальными
// ─────────────────────────────────────────────────────────────────────────────
static std::vector<DupResult> FindSimilar(
    sqlite3*           db,
    const std::wstring& targetName,
    const DupFields&   fields)
{
    std::vector<DupResult> results;
    auto records = LoadAllPotatoRecords(db);
    if (records.empty()) return results;

    // Находим эталонный сорт
    PotatoRecord* target = nullptr;
    for (auto& r : records)
        if (r.name == targetName) { target = &r; break; }
    if (!target) return results;

    bool useAll = fields.noneSelected();

    // Макрос: включить поле если выбрано (или useAll)
#define USE(f) (useAll || fields.f)

    // Определяем min/max для нормализации по каждому полю
    struct MinMax { double mn = 1e18, mx = -1e18; };
    MinMax mm_ct, mm_nm, mm_wc, mm_wn, mm_tc,
           mm_mk, mm_pr, mm_bo, mm_co, mm_fr,
           mm_wa, mm_sm, mm_ta, mm_dr, mm_db;

    auto UPD = [](auto& mm, const auto& val) {
        mm.mn = min(mm.mn, val);
        mm.mx = max(mm.mx, val);
        };

    for (auto& r : records) {
        if (USE(commercial_tubers)) UPD(mm_ct, r.commercial_tubers);
        if (USE(non_marketable))    UPD(mm_nm, r.non_marketable);
        if (USE(weight_commercial)) UPD(mm_wc, r.weight_commercial);
        if (USE(weight_non_comm))   UPD(mm_wn, r.weight_non_comm);
        if (USE(tubers_in_clone))   UPD(mm_tc, r.tubers_in_clone);
        if (USE(marketability))     UPD(mm_mk, r.marketability);
        if (USE(productivity))      UPD(mm_pr, r.productivity);
        if (USE(boilability))       UPD(mm_bo, r.boilability);
        if (USE(consistency))       UPD(mm_co, r.consistency);
        if (USE(friability))        UPD(mm_fr, r.friability);
        if (USE(wateriness))        UPD(mm_wa, r.wateriness);
        if (USE(smell))             UPD(mm_sm, r.smell);
        if (USE(taste))             UPD(mm_ta, r.taste);
        if (USE(darkening_raw))     UPD(mm_dr, r.darkening_raw);
        if (USE(darkening_boiled))  UPD(mm_db, r.darkening_boiled);
    }

    // Нормализованный вектор эталона
    auto norm = [&](double v, MinMax& mm) {
        return Normalize(v, mm.mn, mm.mx);
    };

    int dims = 0; // число активных измерений
    if (USE(commercial_tubers)) dims++;
    if (USE(non_marketable))    dims++;
    if (USE(weight_commercial)) dims++;
    if (USE(weight_non_comm))   dims++;
    if (USE(tubers_in_clone))   dims++;
    if (USE(marketability))     dims++;
    if (USE(productivity))      dims++;
    if (USE(boilability))       dims++;
    if (USE(consistency))       dims++;
    if (USE(friability))        dims++;
    if (USE(wateriness))        dims++;
    if (USE(smell))             dims++;
    if (USE(taste))             dims++;
    if (USE(darkening_raw))     dims++;
    if (USE(darkening_boiled))  dims++;
    if (dims == 0) dims = 1;

    // Максимально возможная дистанция (все в sqrt(dims))
    double maxDist = std::sqrt(static_cast<double>(dims));

    for (auto& r : records) {
        if (r.name == targetName) continue; // пропускаем сам эталон

        double sumSq = 0.0;
        auto addDiff = [&](double a, double b, MinMax& mm) {
            double na = norm(a, mm), nb = norm(b, mm);
            double d = na - nb;
            sumSq += d * d;
        };

        if (USE(commercial_tubers)) addDiff(target->commercial_tubers, r.commercial_tubers, mm_ct);
        if (USE(non_marketable))    addDiff(target->non_marketable,    r.non_marketable,    mm_nm);
        if (USE(weight_commercial)) addDiff(target->weight_commercial, r.weight_commercial, mm_wc);
        if (USE(weight_non_comm))   addDiff(target->weight_non_comm,   r.weight_non_comm,   mm_wn);
        if (USE(tubers_in_clone))   addDiff(target->tubers_in_clone,   r.tubers_in_clone,   mm_tc);
        if (USE(marketability))     addDiff(target->marketability,     r.marketability,     mm_mk);
        if (USE(productivity))      addDiff(target->productivity,      r.productivity,      mm_pr);
        if (USE(boilability))       addDiff(target->boilability,       r.boilability,       mm_bo);
        if (USE(consistency))       addDiff(target->consistency,       r.consistency,       mm_co);
        if (USE(friability))        addDiff(target->friability,        r.friability,        mm_fr);
        if (USE(wateriness))        addDiff(target->wateriness,        r.wateriness,        mm_wa);
        if (USE(smell))             addDiff(target->smell,             r.smell,             mm_sm);
        if (USE(taste))             addDiff(target->taste,             r.taste,             mm_ta);
        if (USE(darkening_raw))     addDiff(target->darkening_raw,     r.darkening_raw,     mm_dr);
        if (USE(darkening_boiled))  addDiff(target->darkening_boiled,  r.darkening_boiled,  mm_db);

        DupResult res;
        res.name       = r.name;
        res.distance   = std::sqrt(sumSq);
        res.similarity = (1.0 - res.distance / maxDist) * 100.0;
        if (res.similarity < 0.0) res.similarity = 0.0;
        results.push_back(res);
    }
#undef USE

    // Сортируем: чем меньше дистанция — тем ближе к эталону
    std::sort(results.begin(), results.end(),
        [](const DupResult& a, const DupResult& b) {
            return a.distance < b.distance;
        });

    return results;
}
