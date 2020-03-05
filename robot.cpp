#include "robot.h"
#include <iostream>

using namespace std;

Map::Map(int inaltime,int latime)
{
    lat=latime;
    inal=inaltime;
    harta=new int*[inal];
    for(int i=0; i<inal; i++)
        harta[i]=new int[lat];
    for(int i=0; i<inal; i++)
        for(int j=0; j<lat; j++)
            harta[i][j]=0;
    harta[0][0]=1;
}

void Map::Afisare()
{
    for(int i=0; i<inal; i++)
    {
        for(int j=0; j<lat; j++)
            cout<<harta[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void Map::PutValue(int a,int b,int x)
{
    harta[a][b]=x;
}

void Map::GetValue(int *h,int *l,int** mat)
{
    (*h)=inal;
    (*l)=lat;
}
/*
Map::~Map()
{
    for (int i = 0; i < inal; ++i)
        delete [] harta[i];
    delete [] harta;
}
*/
Capcana::Capcana(int inaltime,int latime)
{
    inal=inaltime;
    lat=latime;
}

Capcana::~Capcana() {}

Capcana1::Capcana1(int inaltime,int latime):Capcana(inaltime,latime) {}

Capcana2::Capcana2(int inaltime,int latime):Capcana(inaltime,latime) {}

Capcana3::Capcana3(int inaltime,int latime):Capcana(inaltime,latime) {}

Item::Item(int inaltime,int latime)
{
    inal=inaltime;
    lat=latime;
}

Item::~Item() {}

Item1::Item1(int inaltime,int latime):Item(inaltime,latime) {}

Item2::Item2(int inaltime,int latime):Item(inaltime,latime) {}

Item3::Item3(int inaltime,int latime):Item(inaltime,latime) {}

Robot::Robot()
{
    i=0;
    j=0;
}

Robot::~Robot() {}

void Robot::Afisare()
{
    cout<<i<<" "<<j<<endl;
}

void Robot::GetValue(int *a,int *b)
{
    (*a)=i;
    (*b)=j;
}

void Robot::IncarcarePozitie(int a,int b)
{
    i=a;
    j=b;
}
