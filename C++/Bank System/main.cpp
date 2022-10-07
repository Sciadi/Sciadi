#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
const char* PATH_TO_DB = "db.txt";
const char* TMP_PATH = "tmp.txt";
const char COMMA = ';';

const char* MENU = "\n\t\
1- New account \n\t\
2- Deposit amount \n\t\
3- Withdraw amount \n\t\
4- Balance enquiry \n\t\
5- All account holder list\n\t\
6- Close account \n\t\
7- Modify account \n\t\
8- Exit \n\n"; 


int new_account(string name, float acc){
    ofstream file(PATH_TO_DB, ios_base::app | ios_base::out);
    if (file){
        file<<name<<';'<<acc<<endl;
        file.close();
        return 1;
    }
    return -1;
}

/**
 * @brief Deposita soldi sul conto di utente
 *  sovrascrive il file db.txt con il file tmp.txt che ha i 
 *  valori aggiornati.
 * 
 * @param user Utente
 * @param acc 
 * @return int 1 = success state
 */
int deposit_amount(string user, float acc){
    string line,name,money;
    int pos,len;

    ifstream db_file(PATH_TO_DB);
    ofstream tmp_file(TMP_PATH);

    while(std::getline(db_file, line)){
        name = line.substr(0, line.find(COMMA));

        if(name == user){
            pos = line.find(COMMA) + 1;
            money = line.substr(pos, line.length());
            acc += stof(money);

            len = money.length();

            line.replace(pos,len, to_string(acc) );
        }
        tmp_file<<line<<'\n';
    }

    db_file.close();
    tmp_file.close();
    
    remove(PATH_TO_DB);
    rename(TMP_PATH, PATH_TO_DB);
}


int main(){
    int input;
    int a=1;
//--int (*features) ();
    cout<<MENU;

    string s = "Mario";
    while (a)
    {
        cin>>input;
        switch (input)
        {
        case 1 :
            a = new_account(s, 0);
            cout<<s<<" aggiunto\n";
            break;
            
        case 2 : 
            deposit_amount(s,100.0);
            cout<<"Versamento sul conto di "<<s<<endl;
            break;

        case 8 :
            return 0;
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}