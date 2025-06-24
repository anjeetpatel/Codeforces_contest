#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << 0 << endl;
            return;
        }
    }
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        long long min_val_merged = min(a[i], a[i + 1]);
        long long max_val_merged = max(a[i], a[i + 1]);

        if (i > 0)
        {
            long long target_min = a[i - 1] - 1;
            long long target_max = a[i - 1] + 1;

            if (max(min_val_merged, target_min) <= min(max_val_merged, target_max))
            {
                cout << 1 << endl;
                return;
            }
        }

        if (i < n - 2)
        {
            long long target_min = a[i + 2] - 1;
            long long target_max = a[i + 2] + 1;

            if (max(min_val_merged, target_min) <= min(max_val_merged, target_max))
            {
                cout << 1 << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
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