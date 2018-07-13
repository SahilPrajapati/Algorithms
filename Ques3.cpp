#include<iostream>
#include<cstdlib>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right,int *comparison)
{


      int i = left;
      int j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {

            while (arr[i] < pivot)
            {
                *comparison = *comparison + 1;
                i++;
            }
              *comparison= *comparison + 1;
            while (arr[j] > pivot)
            {
                *comparison= *comparison + 1;
                j--;
            }
            *comparison= *comparison + 1;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quickSort(arr, left, j,comparison);
      if (i < right)
            quickSort(arr, i, right,comparison);

}

int main()
{
    int arr[100]={0,50,30,40,100,10,2};

 for(int i=0;i<100;i++)
        {
            arr[i]=(rand()%(1000-30+1)+30);
            int temp=arr[i]-1;//for passing temp as the last index
            int temparr[arr[i]];
            cout<<endl<<i+1<<". Size : "<<arr[i];
            for(int j=0;j<arr[i];j++)
                {
                    temparr[j]=(rand()%1000);
                }
                int counter = 0;
           quickSort(temparr,0,temp,&counter);

           cout<<", Comparison : "<<counter<<endl<<endl;

    ofstream file1("fileQuickSort.csv",std::ios_base::app);

    if(!file1)
    {
        cout<<"Can't open the file ";

    }

    file1<<arr[i]<<","<<counter<<","<<arr[i]*log2(arr[i])<<"\n";

        }
}
