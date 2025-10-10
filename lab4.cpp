#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare_func(const float& a, const float& b){
    return a > b;
}

int index_count(int length){
    // get the ceiling - 1
    int index = ceil(length * 0.1) - 1;


    return index;
}

int read_file(string& file_path){
    ifstream file(file_path);
    
    string line;
    while (getline(file, line)){
        return stoi(line);
    }
    file.close();
    return 0;
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

int use_vector(vector<float>& data){
    sort(data.begin(), data.end(), compare_func);
    int array_size = data.size();
    int valid_index = index_count(array_size);



    return data[valid_index];
}

int use_array(int data){
    return 0;
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
    int data = read_file(path);
    
    string method = argv[1];
    cout << method << endl;
    cout << index_count(9) << endl;
    if (method == "vector"){
        auto data = read_vector(path);
        use_vector(data);

        return 0;
    }
    if (method == "array"){
        use_array(data);
        return 0;
    }
    if (method == "list"){
        use_linked_list(data);
        return 0;
    }
    
    return 0;
}