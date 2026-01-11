#include <iostream>
using namespace std;

class Stack
{
    
    int topIdx;
    int *arr;

    public: 
    int sz;

    Stack(int sz = 1000)
    {
        this->sz = sz;
        topIdx = -1;
        arr = new int[sz];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int val)
    {
        if (topIdx > sz)
        {
            cout << "Overflowed!\n";
            return;
        }
        arr[++topIdx] = val;
    }

    bool isEmpty()
    {
        return topIdx == -1;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "No Element Found!\n";
            return -1;
        }
        return arr[topIdx];
    }

    void display()
    {
        cout << endl << "Stack = [";
        for (int i = 0; i <= topIdx; i++)
        {
            cout << arr[i];

            if (i != topIdx) cout << ",";
        }
        cout << "]" << endl << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "No Element Found to Delete!\n";
            return;
        }
        topIdx--;
    }

    int size()
    {
        return topIdx + 1;
    }

};

int main()
{

    int choice;
    Stack s;
    
    do
    {    
        s.display();
        cout << "Stack Operations\n";
        cout << "1.Push\n2.Pop\n3.Exit\n";
        cout << "Choose a option: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            int val;
            cout << "Enter a value to input: ";
            cin >> val;
            s.push(val);
            break;

            case 2:
            s.pop();
            break;

            case 3:
            cout << "Program Exiting....\n";
            return 0;

            default:
            cout << "Invalid Choice.\n";
        }
    

    }
    while (choice != 3);
    return 0;
}