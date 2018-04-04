#include <iostream>
#include <math.h>
using namespace std;
void cae(char *cad)
{
   int i=0,num2=0,tam=0,j=0;
   float num=0;
   while(cad[j]!='\0')
   {
       tam++;
       j++;
   }
    for(int i=tam-1;i>=0;i--)
    {
        if(cad[i]=='.')
       {
           num=num/pow(10,num2);
           num2=-1;
       }
       else
       {
          num=num+(cad[i]-'0')*pow(10,num2);
       }
       num2++;
    }
   cout<<num<<endl;


}
int main()
{
    char *cadena1,*cadena2;
    cadena1="4.66";
    cadena2="55";
    cout<<"Caso Flotante"<<endl;
    cae(cadena1);
    cout<<"Caso Entero"<<endl;
    cae(cadena2);
}
