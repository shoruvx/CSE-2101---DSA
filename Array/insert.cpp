#include <iostream>
using namespace std;

int main()
{
    int size; cin >> size;
    int idx, elem;
    cin >> idx >> elem;
    int arr[1000000];

    for(int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }


    for(int i = size; i >= idx; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[idx-1] = elem;
    ++size;
    

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}