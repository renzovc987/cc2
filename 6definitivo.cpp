#include <iostream>

using namespace std;
int tam(char*cad)
{
    int i=0,t=0;
    while(*(cad+i)!='\0')
    {
        t++;
        i++;
    }
    return t;
}
char*copiar1(char*cad1,char*cad2)
{
    int tam1=0,i=0;
    while(cad1[i]!='\0')
    {
        tam1++;
        i++;
    }
    cad2=new char[tam1];
    int j=0;
    while(cad1[j]!='\0')
    {
        cad2[j]=cad1[j];
        j++;
    }
    return cad2;
}
char*copiar2(char *cad1,char *cad2)
{
   int t;
   t=tam(cad1);
   cad2=new char[t];
   while(*cad1!='\0')
   {   
       *cad2=*cad1;
       cad1++;
       cad2++;
   }
   cad2-=t;
   return cad2;

}

int main()
{
    char*cadena1,*cadena2;
    cadena1=new char[100];
    cin>>cadena1;
    cadena2=new char[100];
    cout<<"USANDO ARREGLOS"<<endl;
    cout<<copiar1(cadena1,cadena2)<<endl;
    cout<<"SOLO PUNTEROS"<<endl;
    cout<<copiar2(cadena1,cadena2)<<endl;;

}
