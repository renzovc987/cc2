#include <iostream>

using namespace std;
void suma_r(int &n)
{
    n=n+1;
}
int suma_v(int n)
{
    return n+1;
}
int main()
{
    int x=8;
    suma_r(x);
    cout<<"variable por referencia "<<x<<endl;
    x=8;
    cout<<"variable por valor "<<suma_v(x)<<endl;
}
