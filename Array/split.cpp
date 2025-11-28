#include <iostream>
using namespace std;

int main()
{
    int size; cin >> size;
    int idx; cin >> idx;
    int arr[10000];

    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int size1 = size - idx;

    for(int i = 0; i < idx; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    for(int i = idx; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << endl;

}