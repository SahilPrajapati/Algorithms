#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node* next;
};

int Distance = 0 , GRAY = 0;


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

class Linked_list1
{
    public:

    Node* head = NULL;
    char element ,  parent;
    int distance;

    Node* create_node(char data)
    {

        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    void forward_traverse()
    {
    if(this->head == NULL)
        {
            return;
        }
        Node* temp = this->head;

        while(temp!=NULL)
        {
            cout<<"->"<<temp->data;
            temp = temp->next;
        }
    }

    void insertion(char key)
    {
        if(this->head == NULL)
        {
            this->head = create_node(key);
        }
        else
        {
            Node* temp = this->head;

            while(temp->next!=NULL)
            temp = temp->next;

            temp->next = create_node(key);
        }
}
    void getdata(int a)
    {
        char ch;
        cout<<" Enter the vertices present in the list "<<endl;

        do
        {
            char vertex;
            cin>>vertex;
            if(vertex == '0')
            {}
            else
            this->insertion(vertex);

            cout<<endl<<"Do you want to continue , press 1 for continue else 2"<<endl;
            cin>>ch;
        }
        while(ch == '1');
    }

    void update(Linked_list1 *adj_list,char parent ,char name, int vertices)
    {
            for(int i = 0;i<vertices;i++)
            {
                if(adj_list[i].element == name)
                {
                    adj_list[i].distance = Distance;
                    adj_list[i].parent = parent;
                }
            }
    }

};

void print(Linked_list1 *adj_list , char v , int vertices)
    {
        for(int i = 0;i<vertices;i++)
            {
                if(adj_list[i].element == v)
                {
                    cout<<"\t"<<adj_list[i].element <<"\t"<<adj_list[i].distance<<"\t"<<adj_list[i].parent<<endl;
                }
            }
    }

void BFS(Linked_list1 *adj_list , int vertices , char *Queue_gray , char *Queue_norm , char source)
{
    Node *temp = NULL;
    int i =0;


  do
  {
    if(is_visited(Queue_gray , adj_list[i].element) == false)
    {
     int rear = 0 ,Front = 0;

            //enqueue source in list and change it's color
               visited(Queue_gray , source);// visit or color change

                Queue_norm[rear] = source;  // enqueue the source in the list
                rear++;

                Distance = 0;
                adj_list->update(adj_list ,'0', source,vertices); //update the data of source vertix
                Distance++;

            while(Front<rear)
            {
                char v = Queue_norm[Front]; // dequeue
                Front++;
                print(adj_list,v,vertices);

                //search vertix from list
                for(int i = 0;i<vertices;i++)
                    {
                        if(adj_list[i].element == v)
                        {
                            temp = adj_list[i].head;
                            break;
                        }
                    }

                while(temp!=NULL)
                    {
                        if(is_visited(Queue_gray , temp->data) == false) // check color if 0  visited else not visited
                        {
                            visited(Queue_gray , temp->data); // visit or change the color

                            adj_list->update(adj_list,v,temp->data,vertices); //update the data of adjancy list


                            Queue_norm[rear] = temp->data;
                            rear++; //Enqueue the vertix
                        }

                        temp = temp->next;
                    }
                    Distance++;

            }
            }
            source = adj_list[i].element;

    }while(++i<vertices);
}

int main()
{
    int vertices;
    cout<<endl<<"Enter number of vertices present in graph"<<endl;
    cin>>vertices;

    char Queue_gray[vertices];

    char Queue_norm[vertices];

    Linked_list1 adj_list[vertices];

    for(int i=0;i<vertices;i++)
    {
        adj_list[i].element = (char)(65+i);
    }

    //create adjancy list
    for(int i = 0 ;i<vertices;i++)
    {
        cout<<endl<<" For vertex "<<(char)(65+i)<<endl;
        adj_list[i].getdata(vertices);
    }

    //print
    cout<<endl<<"Adjancy List is :"<<endl;
     for(int i = 0 ;i<vertices;i++)
    {
        cout<<endl<<adj_list[i].element;
        adj_list[i].forward_traverse();
    }

    char source;
    cout<<endl<<"Enter the Source Name"<<endl;
    cin>>source;

        cout<<" Vertix name "<<" Distance "<<" Parent "<<endl;
    BFS(adj_list,vertices,Queue_gray,Queue_norm,source);

}

