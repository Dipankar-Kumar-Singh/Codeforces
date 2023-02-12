#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

signed main()
{
    FAST int vol;

    cin >> vol;

    vector<pair<int, int>> prices;

    for (int i = 1; i <= 9; i++)
    {
        int x;
        cin >> x;
        prices.push_back({x, i});
    }

    sort(all(prices),
        [](pair<int, int> a, pair<int, int> b)
        {
            auto &[c1, n1] = a;
            auto &[c2, n2] = b;

            if (c1 == c2)
                return n1 > n2;

            else
                return c1 < c2;
        });

    auto [c1, num1] = prices.front();

    int len_max = vol / c1;

    vol -= len_max * c1;

    if (len_max == 0)
    {
        cout << -1;
        return 0;
    }

    string s;

    for (int i = 1; i <= len_max; i++)
    {
        s.push_back(char(num1 + '0'));
    }

    sort(all(prices),
         [](pair<int, int> a, pair<int, int> b)
         {
             auto [c1, n1] = a;
             auto [c2, n2] = b;
             return n1 > n2;
         });

    for (int i = 0; i < s.size(); i++)
    {
        for (auto [c, num] : prices)
        {
            if (c <= vol + c1)
            {
                vol -= c;
                vol += c1;
                s[i] = char(num + '0');
                break;
            }
        }
    }

    cout << s;
}
