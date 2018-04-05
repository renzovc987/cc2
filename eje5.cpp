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
int tam2(char*cad){
	char*p1;
	p1=cad;
	while(*cad!='\0'){
		cad++;
	}
	return cad-p1;
}
int main()
{
   string cadena;
   char *cadena2;
   cadena2="Juan";
   cadena="Renzo";
   cout<<"El tamaño de la cadena usando solo arreglos es "<<tam1(cadena)<<endl;
   cout<<"El tamaño de la cadena usando solo punteros es "<<tam2(cadena2)<<endl;
}
