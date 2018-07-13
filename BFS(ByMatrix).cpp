#include<iostream>
using namespace std;

int DISTANCE = 0 , GRAY = 0;

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


struct Adj_Matrix
{
    int distance;
    char parent;
    char name;
    int connection;
};

void create_matrix(Adj_Matrix **Adj_matrix,int vertices , int i)
{
    for(int j = 1 ;j<vertices + 1;j++)
    {
        Adj_matrix[i][j].name = (char)(64 + j);
        Adj_matrix[i][j].distance = 0;
        Adj_matrix[i][j].parent = '0';

        cout<<"IS "<<Adj_matrix[i][0].name <<" is connected to "<<Adj_matrix[i][j].name<<endl;
        cin>>Adj_matrix[i][j].connection;
    }
}

void update(Adj_Matrix **Adj_Matrix,char parent,char name,int vertices)
{
     for(int i = 0;i<vertices;i++)
            {
                if(Adj_Matrix[i][0].name == name)
                {
                    Adj_Matrix[i][0].distance = DISTANCE;
                    Adj_Matrix[i][0].parent = parent;
                }
            }
}

void print(Adj_Matrix **Adj_Matrix , char v , int vertices)
    {
        for(int i = 0;i<vertices;i++)
            {
                if(Adj_Matrix[i][0].name == v)
                {
                    cout<<"\t"<<Adj_Matrix[i][0].name <<"\t"<<Adj_Matrix[i][0].distance<<"\t"<<Adj_Matrix[i][0].parent<<endl;
                }
            }
    }

void BFS(Adj_Matrix **Adj_Matrix , int vertices , char *Queue_gray,char *Queue_norm,char source)
{
    int temp = 1;
    int i =0;


  do
  {
    if(is_visited(Queue_gray , Adj_Matrix[i][0].name) == false)
    {
     int rear = 0 ,Front = 0;

            //enqueue source in list and change it's color
               visited(Queue_gray , source);// visit or color change

                Queue_norm[rear] = source;  // enqueue the source in the list
                rear++;

                DISTANCE = 0;
                update(Adj_Matrix ,'0', source,vertices); //update the data of source vertix
                DISTANCE++;

            while(Front<rear)
            {
                char v = Queue_norm[Front]; // dequeue
                Front++;
                print(Adj_Matrix,v,vertices);

                //search vertix from list
                for(int i = 0;i<vertices;i++)
                    {
                        if(Adj_Matrix[i][0].name == v)
                        {
                            temp = i;
                            break;
                        }
                    }

                    int col = 1;

                while(col < (vertices+1))
                    {
                        if(Adj_Matrix[temp][col].connection == 1)
                        {
                          if(is_visited(Queue_gray , Adj_Matrix[temp][col].name) == false) // check color if 0  visited else not visited
                          {
                              visited(Queue_gray , Adj_Matrix[temp][col].name); // visit or change the color

                              update(Adj_Matrix,v,Adj_Matrix[temp][col].name,vertices); //update the data of adjancy list


                              Queue_norm[rear] = Adj_Matrix[temp][col].name;
                              rear++; //Enqueue the vertix
                          }
                        }

                        col++;
                    }
                    DISTANCE++;

            }
            }
            source = Adj_Matrix[i][0].name;

    }while(++i<vertices);
}

int main()
{
    int vertices;
    cout<<"Enter number of vertices"<<endl;
    cin>>vertices;

    char source;
    cout<<endl<<"Enter the name of source"<<endl;
    cin>>source;

     char Queue_gray[vertices];
     char Queue_norm[vertices];


    cout<<endl<<" Press 1 if there is a connection between two vertex else Press 1"<<endl;

    Adj_Matrix *Adj_matrix[vertices+1];
    for(int i = 0;i<vertices;i++)
    {
        Adj_matrix[i] = new Adj_Matrix[vertices +1];
    }

    //create matrix
    for(int i = 0;i<vertices;i++)
    {
        Adj_matrix[i][0].name = (char)(65 + i);
        Adj_matrix[i][0].connection = 0;
        Adj_matrix[i][0].distance = 0;
        Adj_matrix[i][0].parent = '0';

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

     cout<<" Vertix name "<<" Distance "<<" Parent "<<endl;
    BFS(Adj_matrix,vertices,Queue_gray,Queue_norm,source);

}
