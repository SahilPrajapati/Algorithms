#include<iostream>
#include<cstdlib>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int counter=0;
int x=0;
void maxHeapify(int A[],int s,int i)
{
    int l=2*i;
    int r=2*i+1;
    int largest;
    if(l<=(s-1)&&A[l]>A[i])
        largest=l;
    else
        largest=i;

    counter++;

        if(l>s-1)
            counter--;
    if(r<=(s-1)&&A[r]>A[largest])
        largest=r;
    counter++;

    if(r>s-1)
        counter--;


    if(largest!=i)
    {
        swap(A[i],A[largest]);
     // if(2*largest<s-1)//for excluding the leaf nodes to run the max heapify as leaf nodes will not satisfy the condition
         maxHeapify(A,s,largest);
    }

}

void buildMaxHeap(int A[],int s)
{
    for(int i=s/2;i>0;i--)
        maxHeapify(A,s,i);
}


void heapSort(int A[],int s)
{
    int n=s+1;
    buildMaxHeap(A,n);


    for(int i=n-1;i>1;i--)
    {
        swap(A[1],A[i]);

        maxHeapify(A,s,1);
         s=s-1;
    }
}

int main()
{
    int arr[100]={0,50,30,40,100,10,2};
    int n=100;
    int s=n-1;

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
           heapSort(temparr,arr[i]);

           cout<<", Comparison : "<<counter<<endl<<endl;

    ofstream file1("fileHeapSort.csv",std::ios_base::app);

    if(!file1)
    {
        cout<<"Can't open the file ";

    }

    file1<<arr[i]<<","<<counter<<","<<arr[i]*log2(arr[i])<<"\n";

        }



}
