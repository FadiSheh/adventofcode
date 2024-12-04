#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> getInputLines(int year, int day) {

    ostringstream filePath;
    string line;
    vector<std::string> lines;
    
    filePath << year << "/Day" << day << "/input.txt";

    ifstream myFile (filePath.str());

    while( getline (myFile, line) ){

        lines.push_back(line);
        
    }

    return lines;

}    

