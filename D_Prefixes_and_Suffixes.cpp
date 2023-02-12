#include <bits/stdc++.h>
using namespace std;
bool check()
{
    string s, t;
    int n;
    map<int, int> Q;
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i)
        Q[min(s[i], t[n - 1 - i]) * 10 + max(s[i], t[n - 1 - i])]++;

    int cnt = 0;
    for (auto i : Q)
        if (i.second % 2 == 1)
        {
            cnt++;
            if (i.first / 10 != i.first % 10)
                return false;
        }
    return cnt <= 1;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        puts(check() ? "YES" : "NO");
}