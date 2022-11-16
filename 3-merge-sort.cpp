#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(vector<ll> &arr, ll start, ll end)
{
    ll mid = start + (end - start) / 2;

    ll len1 = mid - start + 1;
    ll len2 = end - mid;

    vector<ll> first(len1);
    vector<ll> second(len2);

    ll mainArrayIndex = start;
    for (ll i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (ll i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    ll index1 = 0;
    ll index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    first.erase(first.begin(), first.end());
    second.erase(second.begin(), second.end());
}

void mergeSort(vector<ll> &arr, ll start, ll end)
{
    if (start >= end)
    {
        return;
    }

    ll mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);

    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
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

    mergeSort(arr, 0, arr.size() - 1);

    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}