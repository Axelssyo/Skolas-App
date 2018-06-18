#include "Admin.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

Admin::Admin(){
    system("CLS");
    cout<<"+-----------------+"<<endl;
    cout<<"|    Admin menu   |"<<endl;
    cout<<"+-----------------+"<<endl;
    Izvele();

}
void Admin::Izvele(){
    int izv = 0;
    cout<<"|1.Skolotaja      |"<<endl;
    cout<<"|  profila izveide|"<<endl;
    cout<<"|-----------------+"<<endl;
    cout<<"|2.Skolotaja      |"<<endl;
    cout<<"|  stundu saraksta|"<<endl;
    cout<<"|  pievienosana   |"<<endl;
    cout<<"+-----------------+"<<endl;
    cout<<"|3.Skolotaja      |"<<endl;
    cout<<"| stundu sarakstsa|"<<endl;
    cout<<"| izvade          |"<<endl;
    cout<<"+-----------------+"<<endl;
    cout<<"|4.Skolotaja      |"<<endl;
    cout<<"| ielogosanas     |"<<endl;
    cout<<"| saraksta izvade |"<<endl;
    cout<<"+-----------------+"<<endl;
    cout<<"|5.Skolotaja      |"<<endl;
    cout<<"| paroles         |"<<endl;
    cout<<"| maina           |"<<endl;
    cout<<"+-----------------+"<<endl;
    cout<<"|6.Aizvert        |"<<endl;
    cout<<"|  programmu      |"<<endl;
    cout<<"+-----------------+"<<endl;
    cout<<endl;
    cout <<"Izvelieties, ko velaties darit:"<<endl;
    cin >> izv;

    switch(izv){
    case 1 :
        ProfIzv();
    case 2:
        StSar();
    case 3:
        sarizvade();
    case 4:
        logsar();
    case 5:
        pwmaina();
    case 6:
        exit(0);
    }
    }

void Admin::ProfIzv(){
            string vards;
            string pw;
            string filename;
            string saraksts;
            ofstream write;
            cout <<"Ievadiet skolotaja vardu formata (Vards_Uzvards )atstarpju vieta lietojot so simbolu _ (apakssvitru)"
            <<endl;
            cin >>vards;
            cout <<"Ievadiet skolotaja paroli"<<endl;
            cin >> pw;
            filename = vards + ".txt";
            write.open(filename.c_str());
            write.close();
            write.open("saraksts.txt",ios::app);
            write <<filename.c_str()<<endl;
            write.close();
            filename = vards + "_l.txt";
            write.open(filename.c_str());
            write.close();
            filename = vards + "pw.txt";
            write.open(filename.c_str());
            write <<pw<<endl;
            write.close();
            Admin();
}
void Admin::StSar(){
            ifstream read;
            string line;
            string file;
            cout<<"+--------+"<<endl;
            cout<<"|Saraksts|"<<endl;
            cout<<"+--------+"<<endl;
            read.open("saraksts.txt.");
            while (getline(read, line)){
                cout <<line<<endl;
                cout <<endl;
            }
            read.close();
            saraksts();
}
void Admin::saraksts(){
    ofstream write;
    string file;
    int a = 1;
    int c = 1;
    int b;
    cout <<"Ievadiet vardu precizi ka tas rakstits saraksta, bez .txt"<<endl;
    cin >>file;
    file = file + ".txt";
    write.open(file);
    write << "" << endl;
    write.close();
    cout <<"Ievadiet cik stundas ir skolotajam"<<endl;
    cin >>a;
    a=a+1;
    do{
        if(c==a){
        b=0;
        }else{
        string stunda;
        cout <<"Ievadiet "<<c<<". stundu (atstarpes vieta lietojiet _ )"<<endl;
        cin >> stunda;
        ofstream myfile(file.c_str(),ios::app);
        if (myfile.is_open()){
            myfile <<c<<". "<<stunda<<endl;
            myfile.close();
        }else{
        cout <<"Unable to open file";
        }
        c++;
        }
    }while(b);
    cout <<"Viss kartiba"<<endl;
    system("pause");
    Admin();
}
void Admin::sarizvade(){
    string varda;
    ifstream read;
    string line;
    cout <<"Ievadiet skolotaja vardu un uzvardu atstarpes vieta izmantojot _ "<<endl;
    cin >> varda;
    varda = varda + ".txt";
    read.open(varda.c_str());
    while (getline(read, line)){
    cout <<line<<endl;
    }
    system("pause");
    Admin();

}
void Admin::logsar(){
    string vardas;
    ifstream read;
    string line;
    cout <<"Ievadiet skolotaja vardu un uzvardu atstarpes vieta izmantojot _ "<<endl;
    cin >> vardas;
    vardas = vardas + "_l.txt";
    read.open(vardas.c_str());
    while (getline(read, line)){
    cout <<line<<endl;
    }
    system("pause");
    Admin();


}

void Admin::pwmaina(){
    ofstream fail;
    string vards;
    string pw;
    ifstream read;
    string line;
    read.open("saraksts.txt.");
    while (getline(read, line)){
        cout <<line<<endl;
        cout <<endl;
    }
    read.close();


    cout <<"Ievadiet skolotaja vardu un uzvardu atstarpes vieta izmantojot _ "<<endl;
    cin >> vards;
    cout <<"Ievadiet paroli!"<<endl;
    cin >>pw;
    vards = vards + "pw.txt";
    fail.open(vards);
    fail << pw << endl;
    fail.close();
    system("pause");
    cout <<"Paldies!"<<endl;
    Admin();
}

