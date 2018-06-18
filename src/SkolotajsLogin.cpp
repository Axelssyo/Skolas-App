#include "SkolotajsLogin.h"
#include "Skolotajs.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>
using namespace std;
SkolotajsLogin::SkolotajsLogin()
{
    system("CLS");
    cout <<"+-------------+"<<endl;
    cout <<"|  Skolotaja  |"<<endl;
    cout <<"|   login     |"<<endl;
    cout <<"+-------------+"<<endl;
    slogin();
}
void SkolotajsLogin::slogin(){
        string Vards;
        string izvads;
        string inputVards;
        string inputPassword;
        cout << "Ievadiet savu vardu un uzvardu atstarpes vieta izmantojot _"<<endl;
        cin >> Vards;

        cout <<"Ievadiet Paroli"<<endl;
        cin >> inputPassword;

        int offset;
        string line;
        ifstream usersFile;
        inputVards = Vards + "pw.txt";
        izvads = Vards + ".txt";
        Vards = Vards + "_l.txt";
        usersFile.open (inputVards.c_str());

        if(usersFile.is_open())
        {
            while(!usersFile.eof())
            {
                getline(usersFile,line);
                if ((offset = line.find(inputPassword, 0)) != string::npos) {

                    time_t now = time(0);
                    string dt = ctime(&now);
                    ofstream teksts;
                    teksts.open(Vards,ios::app);
                    teksts <<"Ielogojas "<<dt<<endl;
                    teksts.close();

                    ifstream read;
                    string line;
                    read.open(izvads.c_str());
                    while (getline(read, line)){
                    cout <<line<<endl;
                    }
                    cout <<"Piespiediet enter lai izlogotos!"<<endl;
                    system("pause");
                    Skolotajs();

                }

                else
                {
                    cout <<"Parole Nepareiza"<<endl;
                    system("pause");
                    SkolotajsLogin();


                }
            }

			usersFile.close();
        }else{
            cout << "Nepareizs vards vai uzvards" << endl;
            system("pause");
            SkolotajsLogin();
        }
}




