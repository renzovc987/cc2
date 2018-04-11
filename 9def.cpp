#include <iostream>

using namespace std;
int tam(char*cad)
{
    int i=0,t=0;
    while(cad[i]!='\0')
    {
        t++;
        i++;
    }
    return t;
}
bool palindromo(char *cad)
{
    int tama=tam(cad);
    for(int i=0;i<tama;i++)
    {
        if(cad[i]!=cad[tama-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char *cad1;
    char *cad2;
    cad1=new char[100];
    cad2=new char[100];
    cad1="oso";
    cad2="onno";
    if(palindromo(cad2)==true)
    {
        cout<<"Es palindromo"<<endl;
    }
    else
    {
        cout<<"No es palindromo"<<endl;
    }
}
