#include <iostream>

using namespace std;
void isort(int A[5])
{
    int aux,p;
    for(int i=0;i<5;i++)
    {
        p=i;
        aux=A[i];
        while(p>0 && A[p-1]>aux)
        {
            A[p]=A[p-1];
            p--;
        }
        A[p]=aux;
    }
}
void qsort(int A[5],int l,int r)
{
    int i,j,aux,p;
    i=l;
    j=r;
    p=A[(l+r)/2];
    while(i<=j)
    {
        while(p>A[i])
        {
            i++;
        }
        while(p<A[j])
        {
            j--;
        }
        if(i<=j)
        {
            aux=A[i];
            A[i]=A[j];
            A[j]=aux;
            i++;
            j--;
        }
    }
    if(l<j)
    {
        qsort(A,l,j);
    }
    if(i<r)
    {
        qsort(A,i,r);
    }
}
void merges(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merges(arr, l, m, r);
    }
}
int main()
{
    int B[]={1,3,8,9,5};
    int C[]={1,7,5,4,3};
    int A[]={2,8,7,1,3};
    isort(B);
    cout<<"INSERT SORT"<<endl;
    for(int k=0;k<5;k++)
    {
        cout<<B[k]<<" ";
    }
    cout<<endl;
    qsort(C,0,4);
    cout<<"QUICK SORT"<<endl;
    for(int l=0;l<5;l++)
    {
        cout<<C[l]<<" ";
    }
    cout<<endl;
    mergeSort(A,0,4);
    cout<<"MERGE SORT"<<endl;
    for(int w=0;w<5;w++)
    {
        cout<<A[w]<<" ";
    }

}
