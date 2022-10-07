#include <fstream>
#include "features.h"
const char* PATH_TO_DB = "db.txt";
const char COMMA = ';';
int new_account(string name, float acc){
    ofstream file(PATH_TO_DB, ios_base::app | ios_base::out);
    if (file){
        file<<name<<';'<<acc<<endl;
        file.close();
        return 1;
    }
    return -1;
}

int deposit_amount(string s, int acc){
    return 1;
}

/**
 * @brief 
 * int deposit_amount(string s, int acc){
    string line;
    string name;
    ifstream file(PATH_TO_DB);
    while(std::getline(file, line)){
        name = line.substr(0, line.find(COMMA));
    }
    return 1;
}
 * 
 */