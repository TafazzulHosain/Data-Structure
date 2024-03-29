#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linked_list
{
    node *head,*tail;

public:
    linked_list()
    {
        head = tail = NULL;
    }
    ///Insert at the beginning of the list
    void insertBeginning(int n);
    ///Insert at the middle of the list
    void insertMiddle(int n ,int pos);
    ///Insert at the end of the list
    void insertEnd(int n);

    ///Delete at Beginning
    void deleteBeginning()
    {
        head = tail = head->next;
    }
    ///Delete at Middle
    void deleteMiddle(int pos)
    {
        tail = head;
        for(int i = 1; i<pos-1; i++)
        {
            tail = tail->next;
        }
        tail->next = tail->next->next;
    }

    ///Delete at end
    void deleteEnd()
    {
        tail = head;
        while(tail->next->next !=NULL)
        {
            tail = tail->next;
        }
        tail->next = NULL;
    }
    int length(); ///Length prototype

    void print(); ///Print prototype

};
///Insert at the beginning of the list
void linked_list::insertBeginning(int n)
{
    node *newNode = new node();
    newNode->data = n;
    newNode->next = head;
    head = newNode;

}
///Insert Middle
void linked_list :: insertMiddle(int n , int pos)
{
    node *newNode = new node;
    newNode ->data = n;
    newNode ->next = NULL;
    tail = head;
    for(int i = 1; i<pos-1; i++)
    {
        tail = tail->next;
    }
    newNode->next = tail->next;
    tail->next = newNode;

}
///Insert at the end of the list
void linked_list :: insertEnd(int n)
{
    node *newNode = new node();
        newNode->data = n;
        newNode->next = NULL;

        tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
}

///Find the length of the list.
int linked_list::length()
{
    tail = head;
    int counter = 0;
    while(tail != NULL)
    {
        counter ++;
        tail= tail->next;
    }
    return counter;
}

///To print the list
void linked_list ::print()
{
    tail = head;
        cout<<"\nThe list is : ";
        while(tail != NULL)
        {
            cout<<tail->data<<" ";
            tail = tail->next;
        }
        cout<<endl;

}

int main()
{
    linked_list obj; ///create linked_list
    int n,val,pos;

    while(1)
    {
        cout<<" To append beginning 1\n";
        cout<<" To append middle 2\n";
        cout<<" To append end 3\n";
        cout<<" To Display nodes 4\n";
        cout<<" To Delete beginning 5\n";
        cout<<" To Delete middle 6\n";
        cout<<" To Delete End 7\n";
        cout<<" To exit from program 8\n";
        cout<<"Choose your option : ";
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Enter Value : ";
            cin>>val;
            obj.insertBeginning(val);
            obj.print();
            break;
        case 2:
            cout <<"Enter position : ";
            cin>>pos;
            if(pos > obj.length() or pos <=0) ///For invalid case
            {
                cout<<"Invalid Index "<<endl;
            }
            else if(pos == 1) ///If you enter at the beginning using it
            {
                cout<<"Enter Value : ";
                cin>>val;
                obj.insertBeginning(val);
                obj.print();
            }
            else ///If you enter at middle
            {
                cout<<"Enter Value : ";
                cin>>val;
                obj.insertMiddle(val ,pos);
                obj.print();
            }
            break;
        case 3:
            cout<<"Enter Value : ";
            cin>>val;
            obj.insertEnd(val);
            obj.print();
            break;
        case 4:
            obj.print();
            break;
        case 5:
            obj.deleteBeginning();
            obj.print();
            break;
        case 6:
            cout <<"Enter position : ";
            cin>>pos;
            if(pos > obj.length() or pos <=0) ///For invalid case
            {
                cout<<"Invalid Index "<<endl;
            }
            else if(pos == 1) ///If you delete at the beginning using it
            {
                obj.deleteBeginning();
                obj.print();
            }
            else ///If you delete at middle
            {
                obj.deleteMiddle(pos);
                obj.print();
            }
            break;
        case 7:
            obj.deleteEnd();
            obj.print();
            break;
        case 8:
            exit(0);

        }

    }
    return 0;
}
