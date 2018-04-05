#include <iostream>
#include <stdlib.h>

using namespace std;
void concat1(char *cad1,char *cad2,char *cad3)
{
    int i=0,tam1=0,tam2=0,j=0,st;
    while(cad1[i]!='\0')
    {
        tam1++;
        i++;
    }
     while(cad2[j]!='\0')
    {
        tam2++;
        j++;
    }
    st=tam1+tam2;
    cad3=new char[st];
    for(int l=0;l<tam1;l++)
    {
        cad3[l]=cad1[l];
    }
    for(int h=tam1;h<st;h++)
    {
        cad3[h]=cad2[h-tam1];
    }
    cout<<cad3<<endl;

}
void concat2(char *cad1, char *cad2)
{
    char *p1,*p2,*cad3;
    int tam;
    for(tam=0,p1=cad1;*p1!='\0';tam++,p1++);

    for(p1=cad2;*p1!='\0';tam++,p1++);

    cad3=(char*)malloc(tam+1);
    for(p1=cad3,p2=cad1;(*p1=*p2)!='\0';p1++,p2++);
    for(p2=cad2;(*p1=*p2)!='\0';p1++,p2++);

    cout<<cad3<<endl;

}
int main()
{
    char *cadena1,*cadena2,*cadena3;
    cadena1="hola";
    cadena2="renzo";
    concat1(cadena1,cadena2,cadena3);
    concat2(cadena1,cadena2);
}
