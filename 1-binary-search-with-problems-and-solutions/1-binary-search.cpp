#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Time complexity of binary search = O(log n)

int main()
{
    ll n;

    cin >> n;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll target;

    cin >> target;

    // Binary search is used for monotonic functions only
    // A monotonic function is a function which is either entirely nonincreasing or nondecreasing

    sort(arr.begin(), arr.end());

    ll low = 0;

    ll high = arr.size() - 1;

    ll mid = low + (high - low) / 2;

    while (low <= high)
    {

        if (arr[mid] == target)
        {
            cout << mid;
            return 0;
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

    cout << -1;
}