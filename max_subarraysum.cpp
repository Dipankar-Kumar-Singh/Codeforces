#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"

vector<int> v = {5, 4, -9, 0, 10, 6};

int getSum(int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += v[i];
    }
    return sum;
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.first != p2.first)
    {
        return p1.first < p2.first;
    }

    return p2.second < p1.second;
}

int firstUniqChar(string s)
{
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
+
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 1)
            return i;
    }
    return -1;
}

signed main()
{

    string s;
    cin >> s;

    cout << firstUniqChar(s);
}
