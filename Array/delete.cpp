#include <iostream>
using namespace std;

int main()
{
    int size; cin >> size;
    int idx;
    cin >> idx;
    int arr[10000];

    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }


    for(int i = idx-1; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }

    --size;
    

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}