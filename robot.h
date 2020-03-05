#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include <iostream>

using namespace std;

class Map
{
    int inal;
    int lat;
    int** harta;
public:
    friend class Robot1;
    friend class Robot2;
    friend class Robot3;
    Map(int inaltime=15,int latime=15);
//    ~Map();
    void Afisare();
    void PutValue(int a,int b,int x);
    void GetValue(int *h,int *l,int **mat);
};

class Item
{
protected:
    int inal;
    int lat;
public:
    Item(int inaltime,int latime);
    ~Item();
    virtual void VerifItem(int a,int b,int k,int *ok)=0;
};

class Item1:public Item
{
public:
    Item1(int inaltime,int latime);
    void VerifItem(int a,int b,int k,int *ok)
    {
        int tip=1;
        if(inal==a && lat==b)
        {
            if(tip!=k)
            {
                cout<<"Tipul robotului nu este potrivit cu Itemul."<<endl;
                return;
            }
            cout<<"Felicitari!"<<endl<<"Itemul te-a dus la locatia finala."<<endl;
            (*ok)=1;
        }
    }
};

class Item2:public Item
{
public:
    Item2(int inaltime,int latime);
    void VerifItem(int a,int b,int k,int *ok)
    {
        int tip=2;
        if(inal==a && lat==b)
        {
            if(tip!=k)
            {
                cout<<"Tipul robotului nu este potrivit cu Itemul"<<endl;
                return;
            }
            cout<<"Felicitari!"<<endl<<"Daca ajungi pe o capcana nu patesti nimic."<<endl;
            (*ok)=2;
        }
    }
};

class Item3:public Item
{
public:
    Item3(int inaltime,int latime);
    void VerifItem(int a,int b,int k,int *ok)
    {
        int tip=3;
        if(inal==a && lat==b)
        {
            if(tip!=k)
            {
                cout<<"Tipul robotului nu este potrivit cu Itemul."<<endl;
                return;
            }
            cout<<"Felicitari!"<<endl<<"Intr-o singura runda vei face doua miscari."<<endl;
            (*ok)=3;
        }
    }
};

class Capcana
{
protected:
    int inal;
    int lat;
public:
    Capcana(int inaltime,int latime);
    ~Capcana();
    virtual void VerifCapcana(int *a,int *b,int *ok,int *k)=0;
};

class Capcana1:public Capcana
{
public:
    Capcana1(int inaltime,int latime);
    void VerifCapcana(int *a,int *b,int *ok,int *k)
    {
        if(inal==(*a) && lat==(*b))
        {
            if((*ok)==2)
            {
                cout<<"Felicitari, ai scapat de capcana cu ajutorul itemului castigat."<<endl;
                (*ok)=0;
            }
            else
            {
                cout<<"Ai pierdut jocul."<<endl;
                (*ok)=-1;
            }

        }
    }
};

class Capcana2:public Capcana
{
public:
    Capcana2(int inaltime,int latime);
    void VerifCapcana(int *a,int *b,int *ok,int *k)
    {
        if((*k)!=1)
            if(inal==(*a) && lat==(*b))
            {
                if((*ok)==2)
                {
                    cout<<"Felicitari, ai scapat de capcana cu ajutorul itemului castigat."<<endl;
                    (*ok)=0;
                }
                else
                {
                    (*a)=0;
                    (*b)=0;
                    cout<<"Incepi jocul din nou"<<endl;
                    (*k)=1;
                }
            }
    }
};

class Capcana3:public Capcana
{
public:
    Capcana3(int inaltime,int latime);
    void VerifCapcana(int *a,int *b,int *ok,int *k)
    {
        if((*k)!=1)
            if(inal==(*a) && lat==(*b))
            {
                if((*ok)==2)
                {
                    cout<<"Felicitari, ai scapat de capcana cu ajutorul itemului castigat."<<endl;
                    (*ok)=0;
                }
                else
                {
                    if((*a)>=5)
                    {
                        (*a)=(*a)-5;
                        cout<<"Ai fost mutat 5 pozitii in spate pe linie"<<endl;
                        (*k)=1;
                    }
                    else if((*b)>=5)
                    {
                        (*b)=(*b)-5;
                        cout<<"Ai fost mutat 5 pozitii in spate pe coloana"<<endl;
                        (*k)=1;
                    }
                    else
                    {
                        if((*a)!=0)
                        {
                            cout<<"Ai fost mutat "<<(*a)<<" pozitii in spate pe linie"<<endl;
                            (*a)=0;
                            (*k)=1;
                        }
                        else
                        {
                            cout<<"Ai fost mutat "<<(*b)<<" pozitii in spate pe coloana"<<endl;
                            (*b)=0;
                            (*k)=1;
                        }
                    }


                }
            }
    }
};

class Robot
{
protected:
    int i;
    int j;
public:
    Robot();
    ~Robot();
    virtual void Move(Map m,int *ok)=0;
    void Afisare();
    void GetValue(int *a,int *b);
    void IncarcarePozitie(int a,int b);
};

class Robot1:public Robot
{
public:
    void Move(Map m,int *ok)//Robotul 1 merge pe linii
    {
        m.harta[i][j]=0;
        if((*ok)==0 && j!=m.lat-1)
            j++;
        else if(j==m.lat-1 && (*ok)==0)
        {
            i++;
            (*ok)=1;
        }
        else if((*ok)==1)
        {
            if(j==0)
            {
                i++;
                (*ok)=0;
            }
            else
                j--;
        }
        if(m.harta[i][j]==4)
            (*ok)=4;
    }
};

class Robot2:public Robot//Robotul 2 merge pe coloane
{
public:
    void Move(Map m,int *ok)
    {
        m.harta[i][j]=0;
        if((*ok)==0 && i!=m.inal-1)
            i++;
        else if(i==m.inal-1 && (*ok)==0)
        {
            j++;
            (*ok)=1;
        }
        else if((*ok)==1)
        {
            if(i==0)
            {
                j++;
                (*ok)=0;
            }
            else
                i--;
        }
        if(m.harta[i][j]==4)
            (*ok)=4;
    }
};

class Robot3:public Robot//Robotul 3 merge in forma de spirala
{
public:
    void Move(Map m,int *ok)
    {
        m.harta[i][j]=0;
        if(i+j<m.inal-1 && (*ok)==0)
        {
            i++;
            if(i+j==m.inal-1)
                (*ok)=1;
        }
        else if(i+j>m.lat-1 && (*ok)==2)
        {
            i--;
            if(j+i==m.lat-1)
                (*ok)=3;
        }
        else if(m.inal-i<m.lat-j && (*ok)==1)
        {
            j++;
            if(m.inal-i==m.lat-j)
                (*ok)=2;
        }
        else if(j-i>1 && (*ok)==3)
        {
            j--;
            if(j-i==1)
                (*ok)=0;
        }
        if(m.harta[i][j]==4)
            (*ok)=4;
    }
};

#endif // ROBOT_H_INCLUDED
