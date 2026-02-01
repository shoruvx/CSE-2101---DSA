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
    ll.push_front(10);
    ll.push_front(12);
    ll.push_back(7);
    ll.pop_front();
    ll.print();

    return 0;
}