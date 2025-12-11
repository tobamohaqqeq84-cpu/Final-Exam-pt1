#include <iostream>
#include <fstream>
#include <string>
#include <map>
 using namespace std;

int main(){
    map<string, int> traffic;

    ifstream infile("210-final-1=FA25.txt");
    if (!infile){
        cout << "Error opening file." << endl;
        return 1;
    }
    string origin , destination;
    while(infile >> origin >> destination){
        traffic[origin] ++;
        traffic[destination] ++;
    }
    return 0;
}
