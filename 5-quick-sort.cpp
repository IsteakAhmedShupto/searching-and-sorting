#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;

int partition(vector<ll> &arr, ll start, ll end)
{

    ll pivot = arr[start];

    ll count = 0;

    for (ll i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    ll pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    ll i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<ll> &arr, ll start, ll end)
{

    if (start >= end)
        return;

    ll p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}