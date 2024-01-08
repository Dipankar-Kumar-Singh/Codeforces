#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   \
    int TOTALTC;    \
    cin >> TOTALTC; \
    for (_case = 1; _case <= TOTALTC; _case++)
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define nl "\n"
int _case = 1;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0 ; j <= n; j++)
        {
            for (int k = 0 ; k <= n; ++k)
            {
                if (i + j + k <= n)
                {
                    cout << i << " " << j << " " << k << nl;
                }
            }
        }
    }
}
signed main() { FAST solve(); }
