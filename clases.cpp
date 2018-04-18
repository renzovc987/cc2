#include <iostream>
using namespace std;
class Vehiculo
{
    public:
    string licencia;
    int year;
public:
    Vehiculo( string License,int yer)
    {
       licencia=License;
       year=yer;
    }
    string getlicense()
    {
        return licencia;
    }
    int getyear()
    {
        return year;
    }
    virtual void mostrar()
    {
        cout<<licencia<<" "<<year<<endl;
    }
};
class Auto:public Vehiculo
{
    string Marca;
    string Modelo;
public:
    Auto(string mylicense,int myyear,string marc,string model):Vehiculo(mylicense,myyear)
    {
        licencia=mylicense;
        year=myyear;
        Marca=marc;
        Modelo=model;
    }
    string getmarca()
    {
        return Marca;
    }
    string getmodel()
    {
        return Modelo;
    }
    void mostrar(){
        Vehiculo::mostrar();
        cout<<Marca<<endl;
        cout<<Modelo<<endl;
    }
};

int main()
{
    Vehiculo v("V12016",2015);
    v.mostrar();
    Auto carro("V452017",2014,"Toyota","Corola");
    carro.mostrar();



}
