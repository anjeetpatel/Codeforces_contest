#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Op;
vector<Op> ops;

void add_op(int type, int index)
{
    ops.emplace_back(type, index);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    ops.clear();

    // Step 1: Make sure a[i] < b[i]
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > b[i])
        {
            swap(a[i], b[i]);
            add_op(3, i + 1);
        }
    }

    // Step 2: Sort the pairs (a[i], b[i]) together
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 2; j >= i; --j)
        {
            if (a[j] > a[j + 1] || (a[j] == a[j + 1] && b[j] > b[j + 1]))
            {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                add_op(1, j + 1); // swap a
                add_op(2, j + 1); // swap b
            }
        }
    }

    // Output
    cout << ops.size() << '\n';
    for (auto &op : ops)
    {
        cout << op.first << ' ' << op.second << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
