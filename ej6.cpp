#include <iostream>

using namespace std;
void copiar1(char*cad1,char*cad2)
{
    int tam1=0,i=0;
    while(cad1[i]!='\0')
    {
        tam1++;
        i++;
    }
    cad2=new char[tam1];
    int j=0;
    while(cad1[j]!=0)
    {
        cad2[j]=cad1[j];
        j++;
    }
    cout<<cad2<<endl;
}
void copiar2(char *cad1,char *cad2)
{
    cad2=cad1;
    while(cad2=='\0')
    {
        cad2++;
    }
    cout<<cad2<<endl;
}

int main()
{
    char*cadena1,*cadena2;
    cadena2=new char[100];
    cadena1="Juan";
    copiar1(cadena1,cadena2);
    copiar2(cadena1,cadena2);
}
