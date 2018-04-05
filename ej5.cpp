#include <iostream>

using namespace std;
int tam1(string cad)
{
    int i=0;
    int t=0;
    while(cad[i]!='\0')
    {
        t++;
        i++;
    }
    return t;
}
int tam2(char cad[])
{
    char *p1=&cad[0];
    char *p2;
    int i=0;
    do
    {
        if(cad[i]=='\0')
        {
            p2=&cad[i];
        }
    }while(cad[i++]!='\0');

    return p2-p1;


}
int main()
{
   string cadena;
   char cadena2[1000]={"Hola Renzo"};
   cadena="Renzo";
   cout<<"El tamaño de la cadena usando solo arreglos es "<<tam1(cadena)<<endl;
   cout<<"El tamaño de la cadena usando solo punteros es "<<tam2(cadena2)<<endl;
}
