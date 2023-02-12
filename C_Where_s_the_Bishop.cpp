#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

void solve()
{
    vector<vector<char>> v(8, vector<char>(8));

    for (auto &row : v)
        for (auto &e : row)
            cin >> e;

    char x = '#';

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == x)
            {
                if ((i + 1 >= 8 or j + 1 >= 8))
                    continue;
                if ((i - 1 < 0 or j - 1 < 0))
                    continue;

                if (v[i + 1][j + 1] == x and v[i - 1][j + 1] == x and v[i + 1][j - 1] == x and v[i - 1][j - 1] == x)
                {
                    cout << i + 1 << " " << j + 1 << nl;
                    return;
                }
            }
        }
    }
}
signed main(){   FAST      TestCases      solve() ;  }
