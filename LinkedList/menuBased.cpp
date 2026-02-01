#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node* head;

    public:

    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        while(head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;

        if (head==NULL)
        {
            head = newNode;
            return;
        }

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = NULL;
    }

    bool insert(int pos, int val)
    {
        if (pos < 0)
        {
            return false;
        }

        if (pos == 0)
        {
            push_front(val);
            return true;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                return false;
            }

            temp = temp->next;
        }

        if (temp == NULL)
        {
            return false;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        return true;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "The list is already Empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "The list is already Empty\n";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void print()
    {
        Node *temp = head;

        if(head==NULL)
        {
            cout << "The List is Empty\n";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    LinkedList ll;

    int choice;
    int val;
    
    do
    {
        cout << endl;
        ll.print();
        cout << "\n1. Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back\n5.Insert at position\n6.Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {

            case 1:
            cout << "\nEnter a value to input: ";
            cin >> val;
            ll.push_front(val);
            break;

            case 2:
            cout << "\nEnter a value to input: ";
            cin >> val;
            ll.push_back(val);
            break;

            case 3:
            ll.pop_front();
            break;

            case 4:
            ll.pop_back();
            break;

            case 5:
            int pos; 
            cout << "\nPosition: ";
            cin >> pos;

            cout << "\nEnter Value: ";
            cin >> val;


            if (!ll.insert(pos-1,val))
            {
                cout << "\nInvalid Position.";
            }
            break;

            case 6:
            cout << "Exiting....\n";
            break;

            default:
            cout << "Invalid Choice\n";

        }

    }
    while (choice != 6);

    return 0;
}