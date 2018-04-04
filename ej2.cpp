#include <iostream>

using namespace std;
int sumarrec(int A[5],int t)
{
    if(t==0)
    {
        return 0;
    }
    else
    {
        return A[t-1]+sumarrec(A,--t);
    }

}
int sumait(int A[5],int t)
{
    int s=0;
    for(int i=0;i<t;i++)
    {
        s+=A[i];
    }
    return s;
}
int main()
{
    int B[5]={1,2,3,4,5};
    cout<<"Resultado Suma Recursiva: "<<sumarrec(B,5)<<endl;
    cout<<"Resultado Suma Iterativa: "<<sumait(B,5)<<endl;
}
