#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Implementing C++ upper_bound() method in binary search

ll upperBound(vector<ll> &arr, ll n, ll target)
{
    ll low = 0, high = arr.size() - 1;
    ll mid = low + (high - low) / 2;
    while (low < high)
    {
        if (arr[mid] > target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }

    if (arr[low] >= target)
    {
        return low;
    }
    if (arr[high] >= target)
    {
        return high;
    }
    return -1;
}

int main()
{
    ll n, target;
    cin >> n >> target;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << upperBound(arr, n, target);
}