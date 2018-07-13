#include<iostream>
#include<math.h>
using namespace std;

int* CountingSort(int *UnsortedList , int Size , int col)
{
    int x =  pow(10,col);
    int y = pow(10 , col -1);
    int Max =( ( UnsortedList[0] % x) / y );

    int *SortedList = new int[Size];

    //find max element in unsorted list
    for(int i = 0 ;i<Size;i++)
    {
            if(Max <((UnsortedList[i] % x)/y))
            Max = (UnsortedList[i] % x)/y;
    }

    //initialize count array
    int count_list[Max + 1] = {0};

    //put values in count array
    for(int i = 0 ;i<Size;i++)
    {
            count_list[((UnsortedList[i] % x)/y)]++;
    }


        //cummulative array
        for(int i = 1 ;i<(Max + 1);i++)
    {
            count_list[i] = count_list[i] + count_list[i-1];
    }


    //put values in sorted array
     for(int i = Size - 1 ;i>=0;i--)
    {
            count_list[((UnsortedList[i] % x)/y)]--;
            SortedList[count_list[((UnsortedList[i] % x)/y)]] = UnsortedList[i];
    }

    return SortedList;

}

int FindColumn(int *UnsortedList , int Size)
{
    int col = 0 , Max = UnsortedList[0];

    for(int i = 0;i<Size;i++)
    {
        if(Max < UnsortedList[i])
        Max = UnsortedList[i];
    }

    while(Max!=0)
    {
        Max = Max/10;
        col++;
    }

    return col;

}

int* RadixSort(int *UnsortedList , int Size , int col)
{
    for(int i =1;i<=col;i++)
    {
        UnsortedList = CountingSort(UnsortedList , Size , i);
    }

    return UnsortedList;

}

int main()
{
    int Size , Col = 0;
    cout<<"Enter Size : ";
    cin>>Size;

    int UnsortedList[Size];
    cout<<"Enter The Elements : "<<endl;

    for(int i = 0;i<Size;i++)
    {
        cin>>UnsortedList[i];
    }

        cout<<endl<<"Your List : ";
    for(int i = 0;i<Size;i++)
    {
        cout<<UnsortedList[i]<<"  ";
    }

    Col = FindColumn(UnsortedList , Size);


    int *SortedList;

    SortedList = RadixSort(UnsortedList, Size , Col);

     cout<<"Sorted List  : ";
    for(int i = 0;i<Size;i++)
    {
        cout<<SortedList[i]<<"  ";
    }

    return 0;
}
