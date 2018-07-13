#include<iostream>
#include<cstdlib>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

 void Insertion_Sort(int A[],int n)
  {
      int value,hole;

        int counter = 0;
      for(int i=1;i<n;i++)
      {
          value=A[i];
          hole=i;



          while(hole>0&&A[hole-1]>value)
          {
              counter++;
              A[hole]=A[hole-1];
              --hole;
          }

           if(A[hole-1]<=value)
            counter++;
          A[hole]=value;
      }

    cout<<" Size : "<<n<<" Comparison : "<<counter<<endl<<endl<<endl;

    ofstream file1("fileInsertion.csv",std::ios_base::app);

    if(!file1)
    {
        cout<<"Can't open the file ";

    }

    file1<<n<<","<<counter<<","<<n*log2(n)<<"\n";

  }

int main()
{
    int arr[100];


    for(int i=0;i<100;i++)
        {
            arr[i]=(rand()%(1000-30+1)+30);
            int temparr[arr[i]];
            cout<<endl<<"Array no. "<<i+1<<". ";
            for(int j=0;j<arr[i];j++)
                {
                    temparr[j]=(rand()%1000);
                   // cout<<temparr[j]<<"  ";
                }
            Insertion_Sort(temparr,arr[i]);
        }
}


