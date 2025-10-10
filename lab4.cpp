#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;
// Hyperparameter
constexpr int MAX_SIZE_10M = 10000000;

bool compare_func(const float& a, const float& b){
    return a < b;
}

int index_count(int length){
    // get the ceiling - 1
    int index = ceil(length * 0.1) - 1;


    return index;
}

vector<float> read_vector(string& file_path){
    ifstream file(file_path);
    vector<float> data;
    string line;
    while (getline(file, line)){
        data.push_back(stof(line));
    }

    file.close();
    return data;
}

float use_vector(vector<float>& data){
    sort(data.begin(), data.end(), compare_func);
    int array_size = data.size();
    int valid_index = index_count(array_size);

    return data[valid_index];
}
// allocate 10m for largest dataset
int read_array(string& file_path, array<float, MAX_SIZE_10M>& data){
    ifstream file(file_path);
    
    int count = 0;
    string line;
    while (getline(file, line)){
        data[count] = stof(line);
        count += 1;
    }

    file.close();
    return count;
}

float use_array(array<float, MAX_SIZE_10M>& data, int count){
    sort(data.begin(), data.begin() + count, compare_func);
    int valid_index = index_count(count);

    return data[valid_index];
}

int use_linked_list(int data){
    return 0;
}



int main(int argc, char* argv[]){
    if (argc < 3){
        cerr << "wrong output fromat should be: " << "Usage, " << "filename" << endl;
        return 1;
    }
    string path = argv[2];
   
    
    string method = argv[1];
    if (method == "vector"){
        auto data = read_vector(path);
        cout << use_vector(data) << endl;
        return 0;
    }
    if (method == "array"){
        static array<float, 10000000> data;
        int count = read_array(path, data);
        cout << use_array(data, count) << endl;
        return 0;
    }
    if (method == "list"){
        return 0;
    }
    
    return 0;
}