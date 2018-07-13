#include<iostream>
#include<cstdlib>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

#include<stdlib.h>
#include<stdio.h>

 int counter=0;
void merge(int arr[], int l, int m, int r)
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
        counter++;
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

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[100];


    for(int i=0;i<100;i++)
        {
            counter=0;
            arr[i]=(rand()%(1000-30+1)+30);
            int temp=arr[i]-1;//for passing temp as the last index
            int temparr[arr[i]];
            cout<<endl<<i+1<<". Size : "<<arr[i];
            for(int j=0;j<arr[i];j++)
                {
                    temparr[j]=(rand()%1000);
                }
           mergeSort(temparr,0,temp);

           cout<<", Comparison : "<<counter<<endl<<endl;

    ofstream file1("fileMergeSort.csv",std::ios_base::app);

    if(!file1)
    {
        cout<<"Can't open the file ";

    }

    file1<<arr[i]<<","<<counter<<","<<arr[i]*log2(arr[i])<<"\n";

        }
}
