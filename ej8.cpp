#include <iostream>

using namespace std;
int tam(char *cad)
{
   int i=0,tama=0;
   while(*(cad+i)!='\0')
   {
       tama++;
       i++;
   }
   return tama;

}
void intercambiar1(string cad)
{
    for(int i=4;i>=0;i--)
    {
        cout<<cad[i];
    }
    cout<<endl;
}

void intercambiar2(char *cade1)
{
   char *p2;
   int t=tam(cade1);
   p2=new char[t];
   for(int i=0;i<t;i++)
   {
       *(p2+i)=*(cade1+t-i-1);
   }
   cout<<p2<<endl;

}
int main()
{
    string cadena;
    char *cadena2;
    cadena2="Juan";
    cadena="Renzo";
    intercambiar1(cadena);
    intercambiar2(cadena2);
}
