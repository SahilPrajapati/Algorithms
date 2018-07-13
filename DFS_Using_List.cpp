#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node* next;
};

int GRAY = 0 , TIME = 0;

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

class Linked_list2
{
    public:

    Node* head = NULL;
    char element ,  parent;
    int disc_time , fin_time;

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

};

void DFS_VISIT(Linked_list2 *adj_list ,char vertex ,char parent ,int vertices , char *Queue_gray)
{
    TIME++;
    int i = 0;

    for(int j = 0;j<vertices;j++)
    {
        if(adj_list[j].element == vertex)
            i = j;
    }

    adj_list[i].parent = parent;
    adj_list[i].disc_time = TIME;
    visited(Queue_gray , adj_list[i].element);

    Node *temp = adj_list[i].head;

    while(temp!=NULL)
    {
        if(is_visited(Queue_gray , temp->data) == false)
        {
            DFS_VISIT(adj_list,temp->data,adj_list[i].element,vertices,Queue_gray);
        }

        temp = temp->next;
    }

    TIME++;
    adj_list[i].fin_time = TIME;
}

void DFS(Linked_list2 *adj_list , int vertices , char *Queue_gray)
{
    for(int i = 0;i<vertices;i++)
    {
        if(is_visited(Queue_gray , adj_list[i].element) == false)
        {
            DFS_VISIT(adj_list,adj_list[i].element,'0',vertices,Queue_gray);
        }
    }

}


void print(Linked_list2 *adj_list , int vertices)
{
 cout<<endl<<" Vertix name "<<" Discovery Time "<<" Parent "<<" Finishing Time "<<endl;

  for(int i = 0;i<vertices;i++)
    {
    cout<<"\t"<<adj_list[i].element <<"\t"<<adj_list[i].disc_time<<"\t\t"<<adj_list[i].parent<<"\t\t"<<adj_list[i].fin_time<<endl;

    }
}


int main()
{
     int vertices;
    cout<<endl<<"Enter number of vertices present in graph"<<endl;
    cin>>vertices;

    char Queue_gray[vertices];

    Linked_list2 adj_list[vertices];

    for(int i=0;i<vertices;i++)
    {
        adj_list[i].element = (char)(65+i);
        adj_list[i].parent = '0';
        adj_list[i].disc_time = 0;
        adj_list[i].fin_time = 0;
    }

    //create adjancy matrix
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

    DFS(adj_list,vertices,Queue_gray);

    print(adj_list , vertices);

}
