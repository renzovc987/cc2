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
    while(*(cade1)!='\0'){
        cade1++;
    }

    for(int i=0;i<=t;i++){
        cade1--;
        cout<<*(cade1);


    }

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
