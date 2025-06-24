#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_M_minus_1(int n, int m, const vector<vector<int>> &a, int M, const vector<pair<int, int>> &critical_points)
{
    if (critical_points.empty())
    {
        return true;
    }

    int x0 = critical_points[0].first;
    int y0 = critical_points[0].second;

    int required_y = -1;
    bool multiple_y_found = false;

    for (const auto &p : critical_points)
    {
        if (p.first != x0)
        {
            if (required_y == -1)
            {
                required_y = p.second;
            }
            else if (required_y != p.second)
            {
                multiple_y_found = true;
                break;
            }
        }
    }
    if (!multiple_y_found)
    {
        return true;
    }

    int required_x = -1;
    bool multiple_x_found = false;

    for (const auto &p : critical_points)
    {
        if (p.second != y0)
        {
            if (required_x == -1)
            {
                required_x = p.first;
            }
            else if (required_x != p.first)
            {
                multiple_x_found = true;
                break;
            }
        }
    }
    if (!multiple_x_found)
    {
        return true;
    }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    int max_val = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > max_val)
            {
                max_val = a[i][j];
            }
        }
    }

    vector<pair<int, int>> critical_points;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == max_val)
            {
                critical_points.push_back({i, j});
            }
        }
    }

    if (check_M_minus_1(n, m, a, max_val, critical_points))
    {
        cout << max_val - 1 << endl;
    }
    else
    {
        cout << max_val << endl;
    }
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