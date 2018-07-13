#include<iostream>
using namespace std;

int Time = 0 , GRAY = 0;

void visited(char *gray ,char a)
    {
        gray[GRAY] = a;
        GRAY++;
    }

    bool is_visited(char *gray ,char a)
    {
        for(int  i =0 ;i<GRAY;i++)
        {
            if(gray[i] == a)
            {
               return true;
            }
        }

        return false;
    }


struct Adj_Matrix1
{
    int disc_time;
    int finh_time;
    char parent;
    char name;
    int connection;
};

void create_matrix(Adj_Matrix1 **Adj_matrix,int vertices , int i)
{
    for(int j = 1 ;j<vertices + 1;j++)
    {
        Adj_matrix[i][j].name = (char)(64 + j);
        Adj_matrix[i][j].parent = '0';
        Adj_matrix[i][j].finh_time = 0;
        Adj_matrix[i][j].disc_time = 0;

        cout<<"IS "<<Adj_matrix[i][0].name <<" is connected to "<<Adj_matrix[i][j].name<<endl;
        cin>>Adj_matrix[i][j].connection;
    }
}

void Print(Adj_Matrix1 **Adj_matrix,int vertices)
{
 cout<<endl<<" Vertix name "<<" Discovery Time "<<" Parent "<<" Finishing Time "<<endl;

  for(int i = 0;i<vertices;i++)
    {
    cout<<"\t"<<Adj_matrix[i][0].name <<"\t"<<Adj_matrix[i][0].disc_time<<"\t\t"<<Adj_matrix[i][0].parent<<"\t\t"<<Adj_matrix[i][0].finh_time<<endl;

    }
}

void DFS_visit(Adj_Matrix1 **Adj_Matrix ,char vertex ,char parent ,int vertices , char *Queue_gray)
{
    Time++;
    int i = 0;

    for(int j = 0;j<vertices;j++)
    {
        if(Adj_Matrix[j][0].name == vertex)
            i = j;
    }

    Adj_Matrix[i][0].parent = parent;
    Adj_Matrix[i][0].disc_time = Time;
    visited(Queue_gray , Adj_Matrix[i][0].name);

    int col = 1;

    while(col < (vertices + 1))
    {
        if(Adj_Matrix[i][col].connection == 1)
        {
            if(is_visited(Queue_gray , Adj_Matrix[i][col].name) == false)
            {
                DFS_visit(Adj_Matrix,Adj_Matrix[i][col].name,Adj_Matrix[i][0].name,vertices,Queue_gray);
            }
        }
        col++;
    }

    Time++;
    Adj_Matrix[i][0].finh_time= Time;
}

void DFS(Adj_Matrix1 **Adj_Matrix , int vertices , char *Queue_Gray)
{
    for(int i = 0;i<vertices;i++)
    {
        if(is_visited(Queue_Gray , Adj_Matrix[i][0].name) == false)
        {
           DFS_visit(Adj_Matrix,Adj_Matrix[i][0].name,'0',vertices,Queue_Gray);
        }
    }

}

int main()
{
    int vertices;
    cout<<"Enter number of vertices"<<endl;
    cin>>vertices;

     char Queue_gray[vertices];

    cout<<endl<<" Press 1 if there is a connection between two vertex else Press 1"<<endl;

    Adj_Matrix1 *Adj_matrix[vertices+1];
    for(int i = 0;i<vertices;i++)
    {
        Adj_matrix[i] = new Adj_Matrix1[vertices +1];
    }

    //create matrix
    for(int i = 0;i<vertices;i++)
    {
        Adj_matrix[i][0].name = (char)(65 + i);
        Adj_matrix[i][0].connection = 0;
        Adj_matrix[i][0].parent = '0';
        Adj_matrix[i][0].disc_time = 0;
        Adj_matrix[i][0].finh_time = 0;

        cout<<endl<<"Enter details for vertex "<<Adj_matrix[i][0].name<<endl;
        create_matrix(Adj_matrix,vertices, i);
    }

    cout<<endl<<" Adjancy matrix is "<<endl;
    for(int i = 0;i<vertices;i++)
    {
        cout<<Adj_matrix[i][0].name<<" ";
        for(int j = 1;j<vertices + 1;j++)
        {
            cout<<Adj_matrix[i][j].connection <<"  ";
        }
        cout<<endl;
    }

    DFS(Adj_matrix,vertices,Queue_gray);

    Print(Adj_matrix,vertices);

}
