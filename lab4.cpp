#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <array>
#include <list>

using namespace std;

// Hyperparameter
// allocate 10m for largest dataset
constexpr int MAX_SIZE_10M = 10000000;

// compares the values and sorts in ascending order
bool compare_func(const float& a, const float& b){
    return a < b;
}

// function that gets the index_count
int index_count(int length){
    if (length == 0){
        cerr <<"Error: No data available (empty input file)." << endl;
        exit(1);
    }
    // get the ceiling - 1
    int index = ceil(length * 0.1) - 1;
    return index;
}

// reads file and stores in vector
vector<float> read_vector(string& file_path){
    ifstream file(file_path);
    if(!file.is_open()){
        cerr << "Error: while opening file '" << file_path << "'" << endl;
        exit(1);
    }
    vector<float> data;
    string line;

    while (getline(file, line)){
        data.push_back(stof(line));
    }

    file.close();
    return data;
}

// calculates top decentile of vector returns float
float calc_top_decentile_vector(vector<float>& data){
    // sorts using compare_func
    sort(data.begin(), data.end(), compare_func);
    int array_size = data.size();
    int valid_index = index_count(array_size);

    return data[valid_index];
}

// reads array data from file
int read_array(string& file_path, array<float, MAX_SIZE_10M>& data){
    ifstream file(file_path);
    if(!file.is_open()){
        cerr << "Error: while opening file '" << file_path << "'" << endl;
        exit(1);
    }
    int count = 0;
    string line;
    while (getline(file, line)){
        data[count] = stof(line);
        count += 1;
    }

    file.close();
    return count;
}

// Calculates top decentile for array using MAX_SIZE_10M
float calc_top_decentile_array(array<float, MAX_SIZE_10M>& data, int count){
    // Sorts
    sort(data.begin(), data.begin() + count, compare_func);
    int valid_index = index_count(count);

    return data[valid_index];
}

// Reads list data and creates a list object to store data
list<float> read_list(string& file_path){
    ifstream file(file_path);
    if(!file.is_open()){
        cerr << "Error: while opening file '" << file_path << "'" << endl;
        exit(1);
    }
    list<float> data;
    string line;

    while (getline(file, line)){
        data.push_back(stof(line));
    }

    file.close();
    return data;
}
// Calculates top decentile for list using a list 
float calc_top_decentile_list(list<float>& data){
    // sort
    data.sort(compare_func);
    int list_length = data.size();
    int valid_index = index_count(list_length);
    
    auto it = data.begin();
    for (auto i=0; i < valid_index && it != data.end(); i++){
        // traverse
        ++it;
    }
    return *it;
}

// main function
int main(int argc, char* argv[]){
    if (argc < 3){
        cerr << "wrong output fromat should be: " << "Usage, " << "filename" << endl;
        return 1;
    }
    string path = argv[2];
   
    string method = argv[1];
    if (method == "vector"){
        auto data = read_vector(path);
        cout << calc_top_decentile_vector(data) << endl;
        return 0;
    }
    if (method == "array"){
        static array<float, 10000000> data;
        int count = read_array(path, data);
        cout << calc_top_decentile_array(data, count) << endl;
        return 0;
    }
    if (method == "list"){
        auto data = read_list(path);
        cout << calc_top_decentile_list(data) << endl;
        return 0;
    }
    cerr << "Nonecallable argument used, use: vector, array or list" << endl;
    return 1;
}