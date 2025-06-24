#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    vector<int> month(12);
    for (int i = 0; i < 12; i++)
    {
        cin >> month[i];
    }

    sort(month.begin(), month.end(), greater<int>());
    int sum = 0,cnt=0;
    for(int i=0;i<12;i++){
        if(sum>=a) break;
        sum+=month[i];
        cnt++;
    }
    if(sum>=a){
    cout<< cnt;
    }else{
    cout<< -1;
    }
    return 0;
}