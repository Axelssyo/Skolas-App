#include "SkolotajsLogin.h"
#include "Skolotajs.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

Skolotajs::Skolotajs()
{
    system("CLS");
    cout<<"+---------+"<<endl;
    cout<<"|Skolotajs|"<<endl;
    cout<<"+---------+"<<endl;
    logoff();
}
void Skolotajs::logoff()
{
        string Vards;
        string inputVards;
        string inputPassword;
        cout <<"Ievadiet savu vardu uzvardu un paroli lai izlogotos."<<endl;
        cout <<"Tas vajadzigs lai parliecinatos ka jus izlogojieties"<<endl;
        cout << "Ievadiet savu vardu un uzvardu atstarpes vieta izmantojot _"<<endl;
        cin >> Vards;

        cout <<"Ievadiet Paroli"<<endl;
        cin >> inputPassword;

        int offset;
        string line;
        ifstream usersFile;
        inputVards = Vards + "pw.txt";
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
                    teksts <<"Izlogojas "<<dt<<endl;
                    teksts.close();



                    cout <<"Piespiediet enter lai aizvertu programmu!"<<endl;
                    system("pause");
                    exit(0);


                }else{
                    cout <<"Parole Nepareiza"<<endl;
                    cout <<"Piespiediet enter lai meiìinatu velreiz"<<endl;
                    system("pause");
                    Skolotajs();


                }
            }

			usersFile.close();
        }else{
            cout << "Nepareizs vards vai uzvards" << endl;
            cout <<"Piespiediet enter lai meiìinatu velreiz"<<endl;
            system("pause");
            Skolotajs();
        }



}
