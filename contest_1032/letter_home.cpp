#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        int minX = x[0];
        int maxX = x[n - 1];

        int steps = (maxX - minX) + min(abs(s - minX), abs(s - maxX));
        cout << steps << endl;
    }
    return 0;
}
