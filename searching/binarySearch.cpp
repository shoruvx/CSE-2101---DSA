#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;

    
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (key == arr[mid])
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    if (arr[end] == key) return end;
    else if (arr[start] == key) return start;
    else return -1;
}

int main()
{
    int n, key; cin >> n >> key;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << binary_search(arr,n,key);

    return 0;
}