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
void intercambiar1(char *cad,int t)
{
	char aux;
    for(int i=0;i<t/2;i++)
	{
		aux=cad[i];
		cad[i]=cad[t-1-i];
		cad[t-1-i]=aux;
	}

}

char*intercambiar2(char *cade1)
{
	int t=tam(cade1);
	char*aux=new char[t];
	aux+=t-1;
    while(*cade1!='\0')
	{

		*aux=*cade1;
		cade1++;
		aux--;

    }
	aux++;
	return aux;



}
int main()
{
    char *cadena;
    char *cadena2;
	cadena=new char[100];
	cadena2=new char[100];
	cin>>cadena;
    cin>>cadena2;
	int t=tam(cadena);
	cout<<"CON ARREGLOS:"<<endl;
    intercambiar1(cadena,t);
    for(int i=0;i<t;i++)
    {
        cout<<cadena[i];
    }
    cout<<endl;
    cout<<"SOLO PUNTEROS:"<<endl;
    cout<<intercambiar2(cadena2)<<endl;
}
