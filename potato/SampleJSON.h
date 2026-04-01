using json = nlohmann::json;

struct DataJSON {
    std::string description;
    std::string method;
    std::unordered_map<std::string, double> weights;
};

DataJSON Build(std::string description, std::string method, std::vector<std::string> selectedTraits, std::vector<double> weights) {
    DataJSON result;
    result.description = description;
    result.method = method;
    for (int i=0; i < selectedTraits.size(); i++) {
        result.weights.insert_or_assign(selectedTraits[i], weights[i]);
    }
    return result;
}

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DataJSON, description, method, weights)

json CreateJSON(std::string name, std::string description, std::string method, std::unordered_map<std::string, double> weights)
{
    std::unordered_map<std::string, DataJSON> Sample;
    std::vector<std::string> selectedTraits;
    std::vector<double> weight;

    for (auto const& pair : weights) {
        selectedTraits.push_back(pair.first);
        weight.push_back(pair.second);
    }

    

    Sample[name] = Build(description, method, selectedTraits, weight);

	json j = Sample;
    
    return j;
}

void SaveJSON(std::string FileName){

    json data;
    std::ifstream input_file(FileName);

    if (input_file.is_open()) {

        input_file >> data;
        input_file.close();
    }

    std::unordered_map<std::string, double> weights;

    weights.insert_or_assign("i",1);
    weights.insert_or_assign("23", 3);
    weights.insert_or_assign("32123", 34);

    json newData = CreateJSON("name13", "1", "2", weights);


    data.update(newData);


    std::ofstream output_file(FileName);
    if (output_file.is_open()) {
        output_file << data.dump(4);
        output_file.close();
    }
    else {
        return;
    }
}

json ReadJSON(std::string FileName, std::string name){

    json data;

    std::ifstream input_file(FileName);

    if (input_file.is_open()) {

        input_file >> data;
        input_file.close();
    }

    json values = data[name];

    return values;
}

void DeleteJSON(std::string FileName, std::string name) {

    json data;
    std::ifstream input_file(FileName);

    if (input_file.is_open()) {

        input_file >> data;
        input_file.close();
    }

    data.erase(name);

    std::ofstream output_file(FileName);
    if (output_file.is_open()) {
        output_file << data.dump(4);
        output_file.close();
    }
    else {
        return;
    }

}