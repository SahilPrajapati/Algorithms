#include<iostream>
using namespace std;

struct vertex
{
    int v;
    struct vertex* next;
};


class List
{
public:
    List(int ver)
    {
        vertex *arr=new vertex[ver];

        for(int i=0;i<ver;i++)
        {
           arr[i].v=i+1;
           arr[i].next=NULL;
        }

        cout<<"Enter y if there is an edge b/w the 2 vertices other wise n"<<endl<<endl;
        char ch;

    for(int i=0;i<ver;i++)
    {
        vertex *head=arr[i].next;
        for(int j=0;j<ver;j++)
        {

            cout<<endl<<"B/W "<<i+1<<" and "<<j+1<<" : ";
            cin>>ch;

            if(ch=='y'||ch=='Y')
                {
                    head->v=j;
                    head=head->next;
                }
        }
    }


     for(int i=0;i<ver;i++)
    {
        cout<<arr[i].v<<"->";
        vertex *head1=arr[i].next;
        for(int j=0;j<ver;j++)
        {
            cout<<head1[i].v<<"->";
            head1=head1->next;
        }

        cout<<endl;

    }


    }
};

int main()
{
    int ver;
    cout<<" Enter the no. of vertex : ";
    cin>>ver;


    List obj(ver);
}
