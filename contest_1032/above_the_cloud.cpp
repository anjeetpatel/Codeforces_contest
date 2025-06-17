#include <iostream>
#include <string>
using namespace std;

bool isValidSplit(const string &s)
{
    int n = s.length();
    for (int i = 1; i < n - 1; i++)
    {
        char b = s[i];
        string a = s.substr(0, i);
        string c = s.substr(i + 1);
        string ac = a + c;

        if (ac.find(b) != string::npos)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        if (isValidSplit(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
