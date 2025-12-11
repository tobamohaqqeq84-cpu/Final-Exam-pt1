#include <iostream>
#include <fstream>
#include <string>
#include <map>
 using namespace std;


//Milestone 3.
void printAirportsInRange(const map<string, int>& traffic, int low, int high){
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for (auto it = traffic.begin(); it != traffic.end();++it){
        if(it ->second >= low && it -> second <=high){
            cout << it ->first << " " << it->second << endl; 
        }
    }
    cout << endl;
}

int main(){

    
    map<string, int> traffic;

    ifstream infile("210-final-1-FA25.txt");
    if (!infile){
        cout << "Error opening file." << endl;
        return 1;
    }
    
    string origin , destination;
    
    while(infile >> origin >> destination){
        traffic[origin] ++;
        traffic[destination] ++;
    }
    
    cout << "All airports and their traffic counts:" << endl;
    for (auto it = traffic.begin(); it != traffic.end();++it){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;

    int maxCounts = 0;

    for (auto it = traffic.begin(); it != traffic.end(); ++it){
        if (it -> second > maxCounts){
             maxCounts = it -> second;
        }
    }

    cout << "Busiest airports with traffic count " << maxCounts << ":" <<endl;

    for (auto it = traffic.begin(); it != traffic.end(); ++it){
        if (it -> second == maxCounts){
            cout << it -> first << " " << it -> second << endl;
        }
    }
    cout << endl;
    printAirportsInRange(traffic, 5, 8);
    printAirportsInRange(traffic, 9, 12);

    return 0;
}
