#include<iostream>
using namespace std;

class matrix
{
    public:
        int** a;
    matrix(int v)
    {
        a = new int*[v];
    for(int i = 0; i < v; ++i)
    a[i] = new int[v];

    cout<<"Enter y if there is an edge b/w the 2 vertices other wise no"<<endl<<endl;
    char ch;

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {

            cout<<endl<<"B/W "<<i+1<<" and "<<j+1<<" : ";
            cin>>ch;

            if(ch=='y'||ch=='Y')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }

    }



    void print(int v)
    {
        cout<<endl<<endl<<"The matrix is : "<<endl<<endl<<"    ";
        for(int i=0;i<v;i++)
            cout<<i+1<<"  ";

        cout<<endl<<endl;
        for(int i=0;i<v;i++)
        {
            cout<<i+1<<"   ";
            for(int j=0;j<v;j++)
            {
                cout<<a[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

};


int main()
{
    int v;
    cout<<endl<<"Enter the no. of vertices of directed graph: ";
    cin>>v;

    matrix obj(v);
    obj.print(v);


}
