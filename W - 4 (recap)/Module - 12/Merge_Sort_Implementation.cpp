#include<bits/stdc++.h>
using namespace std;


void merge_sort(int a[], int f, int m, int l)
{
    int Lsize = m - f + 1;
    int Rsize = l - (m + 1) + 1;
    int L_array[Lsize], R_array[Rsize];
    int k = 0;
    for (int i = f; i <= m; i++)
    {
        L_array[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= l; i++)
    {
        R_array[k] = a[i];
        k++;
    }

    int i = 0, j = 0;
    int cur=f;

    while (i < Lsize && j < Rsize)
    {

        if (L_array[i] <= R_array[j])
        {
            a[cur] = L_array[i];
            i++;
        }
        else
        {
            a[cur] = R_array[j];
            j++;
        }
        cur++;
    }


    while(i<Lsize)
    {
        a[cur]=L_array[i];
        i++;
        cur++;
    }

    while(j<Rsize)
    {
        a[cur]=R_array[j];
        j++;
        cur++;
    }
}


void devide(int a[],int f,int l)
{

    if(f<l)
    {
        int mid=(f+l)/2;
        devide(a,f,mid);
        devide(a,mid+1,l);
        merge_sort(a,f,mid,l);
    }
}


int main()
{

    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    devide(a,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}