#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int s;

    public:
    Queue(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        s = 0;
    }

    void enqueue(int x)
    {
        if (full())
        {
            cout << "Queue is full!\n";
        }
        else
            arr[s++] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
        }
        else
        {
            for(int i = 1; i < s; i++)
            {
            arr[i-1] = arr[i];
            }

            s--;
        }
        
    }

    int peek()
    {
        if (isEmpty()) return -1;
        else return arr[0];
    }

    bool isEmpty()
    {
        return s == 0;
    }

    int size()
    {
        return s;
    }

    bool full()
    {
        return s == capacity;
    }

    ~Queue()
    {
        delete[] arr;
    }


};

int main()
{
    Queue q(10);

    q.enqueue(1);
    cout << q.size() << endl;
    q.peek();
    q.enqueue(2);
    cout << q.size() << endl;
    q.isEmpty();

    return 0;
}