// problem link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findPeak(vector<ll> &arr)
{
    ll low = 0;
    ll high = arr.size() - 1;
    ll mid = low + (high - low) / 2;

    while (low < high)
    {
        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }

        mid = low + (high - low) / 2;
    }
    return low;
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
    cout << findPeak(arr);
}