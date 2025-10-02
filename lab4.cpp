#include <iostream>

using namespace std;

int index_count(int length){
    int index = (length * 0.1) - 1;
    return index;
}

int main(int argc, char* argv[]){

    cout << index_count(20) << endl;
    return 0;
}