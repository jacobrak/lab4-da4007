#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int read_file(string& file_path){
    ifstream file(file_path);
    
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();
    return 0;
}

int vector(){
    return 0;
}

int array(){
    return 0;
}

int linked_list(){
    return 0;
}

int index_count(int length){
    int index = (length * 0.1) - 1;
    return index;
}

int main(int argc, char* argv[]){
    if (argc < 2){
        cerr << "wrong output fromat should be: " << "Usage, " << "filename" << endl;
        return 1;
    }
    string path = argv[2];
    read_file(path);
    cout << index_count(20) << endl;
    return 0;
}