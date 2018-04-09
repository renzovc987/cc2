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
	char tem;
	char*aux=new char[t];
    for(int i=0;i<t/2;i++)
	{
		tem=cad[i];
		aux[i]=cad[t-i-1];
		aux[t-i-1]=tem;
	}
	cout<<aux<<endl;
	
	
}

void intercambiar2(char *cade1)
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
	cout<<aux<<endl;


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
    intercambiar1(cadena,t);
    intercambiar2(cadena2);
}
