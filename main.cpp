#include <iostream>
#include<stdlib.h>
#include<ctime>
#include<malloc.h>
#include<fstream>
using namespace std;

int mergenow(int arr[],int l,int m,int r)
{
    int count =0;
    int i,j,k,temp[r-l+1];
    i=l;
    j=m+1;
    k=0;
    while(i<=m && j<=r)
    {
        count++;
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=l;i<=r;i++)
        arr[i]=temp[i-l];
        return count;
}
void mergesort(int arr[],int l,int r)
{

    int x;
    ofstream myfile;
    myfile.open("fileformergesort");
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        x=mergenow(arr,l,m,r);
    }
    myfile<<x;

}
void printarray(int A[],int size)
{
    int i;
    for(i=0;i<size;i++)
       cout<<A[i]<<" ";
    cout<<"\n";
}
int main()
{
    int *a,i,n,k;

    for(k=0;k<3;k++)
    {
        cout<<"\nEnter the number of elements ";
        cin>>n;
        srand(int(time(0)));
        a=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            a[i]=rand()%100;
        cout<<"\nGiven array is ";
        printarray(a,n);
        mergesort(a,0,n-1);
        cout<<"\nSorted array is ";
        printarray(a,n);
    }
    return 0;
}

