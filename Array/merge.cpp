#include <iostream>
using namespace std;

int main()
{
    int size; cin >> size;
    int arr[1000000];

    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int size2; cin >> size2;
    int arr2[10000];

    for(int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    int ans[10000];
    int totalSize = size + size2;

    for(int i = 0; i < size; i++)
    {
        ans[i] = arr[i];
    }

    for(int i = 0; i < size2; i++)
    {
        ans[size+i] = arr2[i];
    }

    for(int i = 0; i < totalSize; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}