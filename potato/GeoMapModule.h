

// ------------------------------------------------------------
// UTF-8 / UTF-16
// ------------------------------------------------------------
//inline std::string WToU8(const std::wstring& s) {
//    if (s.empty()) return {};
//    int sz = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0, nullptr, nullptr);
//    std::string r(sz, 0);
//    WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), r.data(), sz, nullptr, nullptr);
//    return r;
//}
//
//inline std::wstring U8ToW(const std::string& s) {
//    if (s.empty()) return {};
//    int sz = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0);
//    std::wstring r(sz, 0);
//    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), r.data(), sz);
//    return r;
//}

inline std::wstring TrimW(std::wstring s) {
    auto notSpace = [](wchar_t ch) { return !iswspace(ch); };

    while (!s.empty() && !notSpace(s.front())) s.erase(s.begin());
    while (!s.empty() && !notSpace(s.back())) s.pop_back();
    return s;
}

inline std::wstring ToLowerW(std::wstring s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](wchar_t c) { return (wchar_t)towlower(c); });
    return s;
}

inline std::wstring NormalizeW(std::wstring s) {
    return ToLowerW(TrimW(std::move(s)));
}

// ------------------------------------------------------------
// IDs для кнопок
// ------------------------------------------------------------

// ------------------------------------------------------------
// Данные
// ------------------------------------------------------------

// ------------------------------------------------------------
// Основной модуль
// ------------------------------------------------------------
class GeoMapModule {
public:
    bool LoadFromJson(const std::string& filename) {
        std::ifstream in(filename, std::ios::binary);
        if (!in.is_open()) return false;

        std::string content((std::istreambuf_iterator<char>(in)),
            std::istreambuf_iterator<char>());

        // BOM
        if (content.size() >= 3 &&
            (unsigned char)content[0] == 0xEF &&
            (unsigned char)content[1] == 0xBB &&
            (unsigned char)content[2] == 0xBF) {
            content.erase(0, 3);
        }

        json root;
        try {
            root = json::parse(content);
        }
        catch (...) {
            return false;
        }

        m_varietyMeta.clear();
        m_regions.clear();

        if (root.contains("varieties") && root["varieties"].is_object()) {
            for (auto& [varName, obj] : root["varieties"].items()) {
                VarietyMeta meta;
                if (obj.contains("origin") && obj["origin"].is_string())
                    meta.origin = U8ToW(obj["origin"].get<std::string>());

                if (obj.contains("description") && obj["description"].is_string())
                    meta.description = U8ToW(obj["description"].get<std::string>());

                if (obj.contains("notes") && obj["notes"].is_string())
                    meta.notes = U8ToW(obj["notes"].get<std::string>());

                m_varietyMeta[U8ToW(varName)] = std::move(meta);
            }
        }

        if (root.contains("regions") && root["regions"].is_array()) {
            for (const auto& item : root["regions"]) {
                RegionInfo r;

                if (item.contains("name") && item["name"].is_string())
                    r.name = U8ToW(item["name"].get<std::string>());

                if (item.contains("country") && item["country"].is_string())
                    r.country = U8ToW(item["country"].get<std::string>());

                if (item.contains("lat") && item["lat"].is_number())
                    r.lat = item["lat"].get<double>();

                if (item.contains("lon") && item["lon"].is_number())
                    r.lon = item["lon"].get<double>();

                if (item.contains("climateText") && item["climateText"].is_string())
                    r.climateText = U8ToW(item["climateText"].get<std::string>());

                if (item.contains("climate") && item["climate"].is_object()) {
                    const auto& c = item["climate"];
                    if (c.contains("minTemp") && c["minTemp"].is_number())
                        r.climate.minTemp = c["minTemp"].get<double>();
                    if (c.contains("maxTemp") && c["maxTemp"].is_number())
                        r.climate.maxTemp = c["maxTemp"].get<double>();
                    if (c.contains("precipitation") && c["precipitation"].is_number())
                        r.climate.precipitation = c["precipitation"].get<double>();
                    if (c.contains("requiredResistance") && c["requiredResistance"].is_number())
                        r.climate.requiredResistance = ClampDouble(c["requiredResistance"].get<double>(), 0.0, 100.0);
                }

                if (item.contains("alreadyGrown") && item["alreadyGrown"].is_array()) {
                    for (const auto& v : item["alreadyGrown"]) {
                        if (v.is_string())
                            r.alreadyGrown.push_back(U8ToW(v.get<std::string>()));
                    }
                }

                m_regions.push_back(std::move(r));
            }
        }

        return true;
    }

    void SetDbVarieties(std::vector<DbVarietyRow> rows) {
        m_dbVarieties = std::move(rows);
    }

    std::vector<RegionView> BuildRegionViews() const {
        std::vector<RegionView> views;

        for (const auto& region : m_regions) {
            RegionView view;
            view.region = region;

            for (const auto& v : m_dbVarieties) {
                double res = NormalizeResistance(v.climateResistance);
                if (res >= region.climate.requiredResistance) {
                    view.suitableVarieties.push_back(v.name);
                }
            }

            std::sort(view.suitableVarieties.begin(), view.suitableVarieties.end(),
                [](const std::wstring& a, const std::wstring& b) {
                    return NormalizeW(a) < NormalizeW(b);
                });

            // Регион показываем, если есть хотя бы один подходящий сорт
            // или если есть история выращивания
            if (!view.suitableVarieties.empty() || !region.alreadyGrown.empty()) {
                views.push_back(std::move(view));
            }
        }

        return views;
    }

    json BuildPayloadForMap() const {
        json payload;
        payload["center"] = {
            {"lat", 25.0},
            {"lon", 15.0},
            {"zoom", 2}
        };

        payload["regions"] = json::array();

        const auto views = BuildRegionViews();

        for (const auto& v : views) {
            json item;
            item["name"] = WToU8(v.region.name);
            item["country"] = WToU8(v.region.country);
            item["lat"] = v.region.lat;
            item["lon"] = v.region.lon;
            item["climateText"] = WToU8(v.region.climateText);

            item["climate"] = {
                {"minTemp", v.region.climate.minTemp},
                {"maxTemp", v.region.climate.maxTemp},
                {"precipitation", v.region.climate.precipitation},
                {"requiredResistance", v.region.climate.requiredResistance}
            };

            item["suitableVarieties"] = json::array();
            for (const auto& s : v.suitableVarieties)
                item["suitableVarieties"].push_back(WToU8(s));

            item["alreadyGrown"] = json::array();
            for (const auto& s : v.region.alreadyGrown)
                item["alreadyGrown"].push_back(WToU8(s));

            item["countSuitable"] = (int)v.suitableVarieties.size();
            item["countAlreadyGrown"] = (int)v.region.alreadyGrown.size();

            payload["regions"].push_back(item);
        }

        return payload;
    }

    std::wstring BuildLeafletHtml() const {
        return LR"HTML(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Geo Map</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.9.4/dist/leaflet.css" />
    <style>
        html, body { margin:0; padding:0; width:100%; height:100%; }
        #map { width:100%; height:100%; }

        .legend {
            background: white;
            padding: 8px 10px;
            border-radius: 6px;
            box-shadow: 0 0 10px rgba(0,0,0,0.2);
            font-family: Segoe UI, Arial, sans-serif;
            font-size: 12px;
            line-height: 1.4;
        }

        .badge {
            display:inline-block;
            padding:2px 6px;
            border-radius:10px;
            margin-right:4px;
            color:#fff;
            font-size:11px;
        }

        .green { background:#2ca25f; }
        .orange { background:#e67e22; }

        ul { margin: 6px 0 0 18px; padding: 0; }
        .region-title { font-weight: 700; font-size: 14px; margin-bottom: 4px; }
        .small { color: #666; font-size: 12px; }
    </style>
</head>
<body>
<div id="map"></div>

<script src="https://unpkg.com/leaflet@1.9.4/dist/leaflet.js"></script>
<script>
    const map = L.map('map').setView([25, 15], 2);

    L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        maxZoom: 18,
        attribution: '&copy; OpenStreetMap contributors'
    }).addTo(map);

    let layers = [];

    function clearLayers() {
        for (const l of layers) map.removeLayer(l);
        layers = [];
    }

    function escapeHtml(text) {
        return String(text || '')
            .replaceAll('&', '&amp;')
            .replaceAll('<', '&lt;')
            .replaceAll('>', '&gt;')
            .replaceAll('"', '&quot;')
            .replaceAll("'", '&#039;');
    }

    function listHtml(arr) {
        if (!arr || arr.length === 0) return '<span class="small">нет данных</span>';
        return '<ul>' + arr.map(x => `<li>${escapeHtml(x)}</li>`).join('') + '</ul>';
    }

    function popupHtml(r) {
        const suitable = r.suitableVarieties || [];
        const grown = r.alreadyGrown || [];

        return `
            <div class="region-title">${escapeHtml(r.name)}</div>
            <div><b>Страна:</b> ${escapeHtml(r.country || '')}</div>
            <div><b>Климат:</b> ${escapeHtml(r.climateText || '')}</div>
            <div><b>Мин. температура:</b> ${r.climate?.minTemp ?? '-'}</div>
            <div><b>Макс. температура:</b> ${r.climate?.maxTemp ?? '-'}</div>
            <div><b>Осадки:</b> ${r.climate?.precipitation ?? '-'}</div>
            <div><b>Порог устойчивости:</b> ${r.climate?.requiredResistance ?? '-'}</div>

            <hr/>

            <div>
                <span class="badge green">Подходят: ${suitable.length}</span>
                <span class="badge orange">Ранее выращивались: ${grown.length}</span>
            </div>

            <div style="margin-top:8px;"><b>Подходящие сорта:</b>${listHtml(suitable)}</div>
            <div style="margin-top:8px;"><b>Сорта, уже выращенные в регионе:</b>${listHtml(grown)}</div>
        `;
    }

    function markerColor(r) {
        if ((r.suitableVarieties || []).length > 0) return '#2ca25f';
        if ((r.alreadyGrown || []).length > 0) return '#e67e22';
        return '#3182bd';
    }

    window.chrome.webview.addEventListener('message', event => {
        const data = event.data;
        if (!data) return;

        if (data.ready) {
            return;
        }

        clearLayers();

        if (data.center) {
            map.setView([data.center.lat, data.center.lon], data.center.zoom || 2);
        }

        const bounds = [];

        if (data.regions) {
            for (const r of data.regions) {
                if (r.lat === undefined || r.lon === undefined) continue;

                const color = markerColor(r);

                const marker = L.circleMarker([r.lat, r.lon], {
                    radius: 8,
                    color: color,
                    fillColor: color,
                    fillOpacity: 0.85,
                    weight: 2
                }).addTo(map);

                marker.bindPopup(popupHtml(r), { maxWidth: 360 });
                layers.push(marker);
                bounds.push([r.lat, r.lon]);
            }
        }

        if (bounds.length > 0) {
            map.fitBounds(bounds, { padding: [30, 30] });
        }
    });

    window.chrome.webview.postMessage("ready");
</script>
</body>
</html>
)HTML";
    }

private:
    std::vector<DbVarietyRow> m_dbVarieties;
    std::vector<RegionInfo> m_regions;
    std::unordered_map<std::wstring, VarietyMeta> m_varietyMeta;

private:
    static double ClampDouble(double v, double a, double b) {
        if (v < a) return a;
        if (v > b) return b;
        return v;
    }

    static double NormalizeResistance(double value) {
        // Поддержка разных форматов:
        // 0..1  -> процент
        // 1..5  -> перевод в 0..100
        // 0..100 -> как есть
        if (value <= 1.0) return ClampDouble(value * 100.0, 0.0, 100.0);
        if (value <= 5.0) return ClampDouble((value - 1.0) * 25.0, 0.0, 100.0);
        return ClampDouble(value, 0.0, 100.0);
    }
};

// ------------------------------------------------------------
// WebView2-окно карты
// ------------------------------------------------------------
class GeoMapWindow {
public:
    bool Create(HWND parent) {
        m_parent = parent;

        if (m_created) return true;

        CreateCoreWebView2EnvironmentWithOptions(
            nullptr, nullptr, nullptr,
            Microsoft::WRL::Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
                [this](HRESULT result, ICoreWebView2Environment* env) -> HRESULT {
                    if (FAILED(result) || !env) return E_FAIL;

                    env->CreateCoreWebView2Controller(
                        m_parent,
                        Microsoft::WRL::Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                            [this](HRESULT result2, ICoreWebView2Controller* controller) -> HRESULT {
                                if (FAILED(result2) || !controller) return E_FAIL;

                                m_controller = controller;
                                m_controller->get_CoreWebView2(&m_webView);

                                RECT rc{};
                                GetClientRect(m_parent, &rc);
                                m_controller->put_Bounds(rc);

                                EventRegistrationToken token{};
                                m_webView->add_WebMessageReceived(
                                    Microsoft::WRL::Callback<ICoreWebView2WebMessageReceivedEventHandler>(
                                        [this](ICoreWebView2*, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT {
                                            LPWSTR msg = nullptr;
                                            if (SUCCEEDED(args->TryGetWebMessageAsString(&msg)) && msg) {
                                                std::wstring text = msg;
                                                CoTaskMemFree(msg);

                                                if (text == L"ready") {
                                                    SendPayloadToWeb();
                                                }
                                            }
                                            return S_OK;
                                        }).Get(),
                                            &token);

                                m_webView->NavigateToString(m_html.c_str());
                                m_created = true;
                                return S_OK;
                            }).Get());

                    return S_OK;
                }).Get());

        return true;
    }

    void SetData(const std::vector<RegionView>& views) {
        m_views = views;
        SendPayloadToWeb();
    }

    void SetDataFromModule(const GeoMapModule& src) {
        m_modulePayload = src.BuildPayloadForMap();
        SendPayloadToWeb();
    }

    void ShowModuleData(const GeoMapModule& src) {
        m_modulePayload = src.BuildPayloadForMap();
        if (m_webView) SendPayloadToWeb();
    }

    void AttachModule(const GeoMapModule* src) {
        m_module = src;
    }

    void SetHtml(std::wstring html) {
        m_html = std::move(html);
        if (m_webView) {
            m_webView->NavigateToString(m_html.c_str());
        }
    }

    void Resize() {
        if (!m_controller) return;

        RECT rc{};
        GetClientRect(m_parent, &rc);
        m_controller->put_Bounds(rc);
    }

    void Destroy() {
        if (m_controller) {
            m_controller->Close();
            m_controller.Reset();
        }
        m_webView.Reset();
        m_created = false;
    }

private:
    void SendPayloadToWeb() {
        if (!m_webView) return;

        json payload = m_module ? m_module->BuildPayloadForMap() : m_modulePayload;

        std::wstring jsonW = U8ToW(payload.dump());
        m_webView->PostWebMessageAsJson(jsonW.c_str());
    }

private:
    HWND m_parent = nullptr;
    bool m_created = false;

    Microsoft::WRL::ComPtr<ICoreWebView2Controller> m_controller;
    Microsoft::WRL::ComPtr<ICoreWebView2> m_webView;

    std::wstring m_html;
    const GeoMapModule* m_module = nullptr;
    json m_modulePayload;
    std::vector<RegionView> m_views;
};

// ------------------------------------------------------------
// Глобальные объекты модуля
// ------------------------------------------------------------

inline GeoMapModule g_geoMapModule;
inline GeoMapWindow g_geoMapWindow;

// ------------------------------------------------------------
// Удобные функции
// ------------------------------------------------------------
inline std::vector<DbVarietyRow> ConvertDbRowsFromPairs(
    const std::vector<std::pair<std::wstring, double>>& rows)
{
    std::vector<DbVarietyRow> out;
    out.reserve(rows.size());
    for (const auto& [name, res] : rows) {
        out.push_back({ name, res });
    }
    return out;
}

void LoadFromJson(const std::string& filename) {

    g_geoMapModule.LoadFromJson(filename);

}

std::vector<std::pair<std::wstring, double>> dbRows = {
    {L"Беллароза", 70.0},
    {L"Жуковский ранний", 85.0},
    {L"Гала", 55.0}
};

inline void OpenGeoMapForWindow(HWND hWnd) {
    
    g_geoMapWindow.Create(hWnd);
    g_geoMapWindow.AttachModule(&g_geoMapModule);
    g_geoMapWindow.SetHtml(g_geoMapModule.BuildLeafletHtml());
    g_geoMapWindow.ShowModuleData(g_geoMapModule);
    g_geoMapModule.SetDbVarieties(ConvertDbRowsFromPairs(dbRows));
}

inline void RefreshGeoMap() {
    g_geoMapWindow.ShowModuleData(g_geoMapModule);
}