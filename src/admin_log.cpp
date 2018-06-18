#include "admin_log.h"
#include <iostream>
#include <stdlib.h>
#include "Admin.h"
using namespace std;
void admin_log(){
    system("CLS");
    int p = 0;
    do{
    int a =0;
    cout <<"Ievadiet Admin paroli"<<endl;
    cin >> a;
    if (a == 123){
        Admin();
    }else{
        p++;
    }


    }while(p);
}
