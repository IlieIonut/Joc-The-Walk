#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "robot.h"

using namespace std;

int main()
{
    int ok=0,ok1=0,k1=0,k2=0,k3=0;
    int a,b,x=15,y=15;
    cout<<"Vrei ca harta sa fie mai mare decat 15 pe 15?"<<endl<<"Daca da apasa 1"<<endl<<"Daca nu apasa 0"<<endl;
    cin>>a;
    if(a==1)
    {
        cout<<"Numarul de linii dorit:";
        cin>>x;
        cout<<endl<<"Numarul de coloane dorit:";
        cin>>y;
    }
    Map m1(x,y);
    Map m2(x,y);
    Map m3(x,y);
    srand(time(NULL));
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,3);
    m2.PutValue(a,b,3);
    m3.PutValue(a,b,3);
    Capcana1 c1(a,b);
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,3);
    m2.PutValue(a,b,3);
    m3.PutValue(a,b,3);
    Capcana2 c2(a,b);
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,3);
    m2.PutValue(a,b,3);
    m3.PutValue(a,b,3);
    Capcana3 c3(a,b);
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,2);
    m2.PutValue(a,b,2);
    m3.PutValue(a,b,2);
    Item1 i1(a,b);
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,2);
    m2.PutValue(a,b,2);
    m3.PutValue(a,b,2);
    Item2 i2(a,b);
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,2);
    m2.PutValue(a,b,2);
    m3.PutValue(a,b,2);
    Item3 i3(a,b);
    Robot1 r1;
    Robot2 r2;
    Robot3 r3;
    a=rand()%x+1;
    b=rand()%y;
    m1.PutValue(a,b,4);
    m2.PutValue(a,b,4);
    m3.PutValue(a,b,4);

    cout<<"Jocul cu primu robot"<<endl;

    m1.Afisare();
    while(ok1!=4 && ok!=-1 && ok!=1)
    {
        r1.Move(m1,&ok1);
        r1.GetValue(&a,&b);
        i1.VerifItem(a,b,1,&ok);
        i2.VerifItem(a,b,1,&ok);
        i3.VerifItem(a,b,1,&ok);
        c1.VerifCapcana(&a,&b,&ok,&k1);
        c2.VerifCapcana(&a,&b,&ok,&k2);
        c3.VerifCapcana(&a,&b,&ok,&k3);
        m1.PutValue(a,b,1);
        r1.IncarcarePozitie(a,b);
        m1.Afisare();
        cout<<endl<<"Daca vrei sa joci in continuare apasa 1."<<endl;
        cout<<endl<<"Daca vrei sa te opresti apasa 0."<<endl<<endl;
        cin>>x;
        cout<<endl<<endl;
        if(x==0)
            break;
    }
    if(ok1==4)
        cout<<endl<<"Felicitari!"<<endl<<"Ai ajuns la locatia finala"<<endl;
    cout<<"Jocul cu al doilea robot"<<endl;
    m2.Afisare();
    k1=0,k2=0,k3=0,ok=0,ok1=0;
    while(ok1!=4 && ok!=-1 && ok!=1)
    {
        r2.Move(m2,&ok1);
        r2.GetValue(&a,&b);
        i1.VerifItem(a,b,2,&ok);
        i2.VerifItem(a,b,2,&ok);
        i3.VerifItem(a,b,2,&ok);
        c1.VerifCapcana(&a,&b,&ok,&k1);
        c2.VerifCapcana(&a,&b,&ok,&k2);
        c3.VerifCapcana(&a,&b,&ok,&k3);
        m2.PutValue(a,b,1);
        r2.IncarcarePozitie(a,b);
        m2.Afisare();
        cout<<endl<<"Daca vrei sa joci in continuare apasa 1."<<endl;
        cout<<endl<<"Daca vrei sa te opresti apasa 0."<<endl<<endl;
        cin>>x;
        cout<<endl<<endl;
        if(x==0)
            break;
    }
    if(ok1==4)
        cout<<endl<<"Felicitari!"<<endl<<"Ai ajuns la locatia finala"<<endl;
    cout<<"Jocul cu al treilea robot"<<endl;
    m3.Afisare();
    k1=0,k2=0,k3=0,ok=0,ok1=0;
    y=0;
    while(ok1!=4 && ok!=-1 && ok!=1)
    {
        if(y==1)
            for(int i=0; i<2; i++)
            {
                r3.Move(m3,&ok1);
                r3.GetValue(&a,&b);
                i1.VerifItem(a,b,3,&ok);
                i2.VerifItem(a,b,3,&ok);
                i3.VerifItem(a,b,3,&ok);
                c1.VerifCapcana(&a,&b,&ok,&k1);
                c2.VerifCapcana(&a,&b,&ok,&k2);
                c3.VerifCapcana(&a,&b,&ok,&k3);
                m3.PutValue(a,b,1);
                r3.IncarcarePozitie(a,b);
            }
        else
        {
            r3.Move(m3,&ok1);
            r3.GetValue(&a,&b);
            i1.VerifItem(a,b,3,&ok);
            i2.VerifItem(a,b,3,&ok);
            i3.VerifItem(a,b,3,&ok);
            if(ok==3)
                y=1;
            c1.VerifCapcana(&a,&b,&ok,&k1);
            c2.VerifCapcana(&a,&b,&ok,&k2);
            c3.VerifCapcana(&a,&b,&ok,&k3);
            m3.PutValue(a,b,1);
            r3.IncarcarePozitie(a,b);
        }
        m3.Afisare();
        cout<<endl<<"Daca vrei sa joci in continuare apasa 1."<<endl;
        cout<<endl<<"Daca vrei sa te opresti apasa 0."<<endl<<endl;
        cin>>x;
        cout<<endl<<endl;
        if(x==0)
            break;
    }
    if(ok1==4)
        cout<<endl<<"Felicitari!"<<endl<<"Ai ajuns la locatia finala"<<endl;
    return 0;
}
