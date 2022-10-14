// problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll first_pos(vector<ll> &arr, ll n, ll target)
{
    ll first_pos = -1;

    ll low = 0;
    ll high = arr.size() - 1;
    ll mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (arr[mid] == target)
        {
            first_pos = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }

    return first_pos;
}

ll last_pos(vector<ll> &arr, ll n, ll target)
{
    ll last_pos = -1;

    ll low = 0;
    ll high = arr.size() - 1;
    ll mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (arr[mid] == target)
        {
            last_pos = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }

    return last_pos;
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

    cout << first_pos(arr, n, target) << " ";
    cout << last_pos(arr, n, target);
}