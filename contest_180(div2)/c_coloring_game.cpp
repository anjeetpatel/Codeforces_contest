#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long count_winning_ways = 0;

    for (int k = 2; k < n; k++)
    {
        long long threshold;
        if (k < n - 1)
        {
            threshold = max(a[k], a[n - 1] - a[k]);
        }
        else
        {
            threshold = a[k];
        }

        for (int j = 1; j < k; j++)
        {
            long long target_val_i = threshold - a[j];
            auto it = upper_bound(a.begin(), a.begin() + j, target_val_i);
            count_winning_ways += (a.begin() + j) - it;
        }
    }

    cout << count_winning_ways << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}