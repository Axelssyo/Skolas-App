#include <iostream>
#include <Admin.h>
#include "admin_log.h"
#include "Skolotajs.h"
#include <SkolotajsLogin.h>
using namespace std;

int main()
{
    int x;
    cout <<"*-------------------------+"<<endl;
    cout <<"|   1.Skolotajs           |"<<endl;
    cout <<"|-------------------------*"<<endl;
    cout <<"|   2.Administrators      |"<<endl;
    cout <<"*-------------------------*"<<endl;
    cout << endl;
    cout <<"Izveleties kas jus esat : "<<endl;
    cin >> x;

    switch (x){
        case 1 :
            SkolotajsLogin();
            break;
        case 2 :
            admin_log();

    }





    return 0;
}
