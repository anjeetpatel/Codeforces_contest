#include <bits/stdc++.h>
using namespace std;

int solveTest(vector<vector<int>> &mat, int n, int m)
{
    int maxVal = INT_MIN;
    vector<pair<int, int>> maxPositions;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j] > maxVal)
            {
                maxVal = mat[i][j];
                maxPositions.clear();
                maxPositions.push_back(make_pair(i, j));
            }
            else if (mat[i][j] == maxVal)
            {
                maxPositions.push_back(make_pair(i, j));
            }
        }
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            bool coversAll = true;
            for (auto &p : maxPositions)
            {
                int i = p.first, j = p.second;
                if (i != r && j != c)
                {
                    coversAll = false;
                    break;
                }
            }
            if (coversAll)
                return maxVal - 1;
        }
    }

    return maxVal;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> mat[i][j];
        cout << solveTest(mat, n, m) << '\n';
    }
    return 0;
}
