#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int Arreglo[]={1,5,4,6,2,9};
    set<int>myset;
    myset.insert(2);
    myset.insert(3);
    myset.insert(4);
    myset.insert(5);
    myset.insert(6);
    int element;
    cout<<"ELEMENTO A BUSCAR"<<endl;
    cin>>element;
    if(binary_search(myset.begin(),myset.end(),element))
    {
        cout<<"SE ENCONTRO EL ELEMENTO"<<endl;
    }
    else
    {
        cout<<"NO SE ENCONTRO EL ELEMENTO"<<endl;
    }
    sort(Arreglo,Arreglo+6);
    cout<<"ARREGLO ORDENADO"<<endl;
    for(int j=0;j<6;j++)
    {
        cout<<Arreglo[j]<<" ";
    }
    cout<<endl;
    cout<<"ARREGLO CON ROTACIONES"<<endl;
    rotate(Arreglo,Arreglo+2,Arreglo+6);
    for(int h=0;h<6;h++)
    {
        cout<<Arreglo[h]<<" ";
    }
    cout<<endl;
    cout<<"ARREGLO CON ROTACIONES INVERTIDO"<<endl;
    reverse(Arreglo,Arreglo+6);
    for(int k=0;k<6;k++)
    {
        cout<<Arreglo[k]<<" ";
    }
    cout<<endl;
    cout<<"SET DE ELEMENTOS"<<endl;
    set<int>::iterator it;
    for(it=myset.begin();it!=myset.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
