#include <iostream>

using namespace std;
void mmatrices(int A[][10],int B[][10],int C[][10],int f1,int c2,int m)
{
    for(int i=0;i<f1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            C[i][j]=0;
            for(int k=0;k<m;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int h=0;h<f1;h++)
    {
        for(int l=0;l<c2;l++)
        {
            cout<<C[h][l]<<" ";
        }
        cout<<endl;
    }
}
void mostrar(int M[][10],int f,int c)
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int M1[10][10];
    M1[0][0]=1;
    M1[0][1]=2;
    M1[0][2]=3;
    M1[1][0]=3;
    M1[1][1]=2;
    M1[1][2]=1;
    int M2[10][10];
    M2[0][0]=1;
    M2[0][1]=2;
    M2[1][0]=3;
    M2[1][1]=2;
    M2[2][0]=1;
    M2[2][1]=1;
    int M3[10][10];
    mmatrices(M1,M2,M3,2,2,3);

}
