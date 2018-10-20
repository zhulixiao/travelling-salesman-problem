#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (int argc, char* argv[]){
    int size = 0;
    cout << "The size is: ";
    cin >> size;
    ofstream output_file;
    output_file.open(argv[1]);
    output_file << size;
    output_file << "\n";

    srand((unsigned)time(0));
    int random = 0;
    for(int i = 0; i < size; i++){
        output_file << rand()%100;
        output_file << " ";
        output_file << rand()%100;
        output_file << "\n";
    }

}