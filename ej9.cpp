#include <iostream>

using namespace std;
bool palindromo(string cad,int t)
{
    for(int i=0;i<t;i++)
    {
        if(cad[i]==cad[t-i-1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    string cadena1,cadena2;
    cadena1="oso";
    cadena2="pedro";
    cout<<palindromo(cadena1,3)<<endl;
    cout<<palindromo(cadena2,5)<<endl;
}
