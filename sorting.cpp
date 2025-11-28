#include <iostream>
using namespace std;

void print(const vector<int> &v);
void selection_sort(vector<int> &v);
void bubble_sort(vector<int> &v);
void insertion_sort(vector<int> &v);

int main()
{
    int n; cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    insertion_sort(v);

    print(v);

    return 0;
}

void print(const vector<int> &v)
{
    for(auto x : v) cout << x << " ";
    cout << endl;
}

void selection_sort(vector<int> &v)
{
    int n = v.size();

    for(int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        
        for(int j = i+1; j < n; j++)
        {
            if (v[j] < v[minIdx])
            {
                minIdx = j;
            }
        }

        int temp = v[i];
        v[i] = v[minIdx];
        v[minIdx] = temp;
    }
}

void bubble_sort(vector<int> &v)
{
    int n = v.size();

    for (int i = n - 1; i > 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j+1])
            {
                didSwap = 1;
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }

        if (!didSwap) break;
    }
}

void insertion_sort(vector<int> &v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        int j = i;

        while ( j > 0 && v[j-1] > v[j])
        {
            int temp = v[j-1];
            v[j-1] = v[j];
            v[j] = temp;
            j--;
        }
    }
}