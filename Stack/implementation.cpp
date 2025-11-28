#include <iostream>
using namespace std;

class Stack
{
    int size;
    int topIdx;
    int *arr;

    public:

    Stack(int size = 1000)
    {
        this->size = size;
        topIdx = -1;
        arr = new int[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return topIdx == -1;
    }

    void push(int x)
    {
        arr[++topIdx] = x;
    }

    void pop()
    {
        topIdx--;
    }

    void top()
    {
        cout << arr[topIdx] << endl;
    }

};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.top();
    s.pop();
    s.top();

    return 0;
}