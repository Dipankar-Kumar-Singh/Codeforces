#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

int const N = 1e6 + 100 ;
int a , b , c , d ;

void solve()
{
    cin >> a >> b >> c >> d;
    vector<int> v(N);

    for (int x = a; x <= b; x++)
    {
        int l_sum = x + b;
        int r_sum = x + c;

        v[l_sum]++;
        v[r_sum + 1]--;
    }

    for (int i = 1; i < N - 3; i++)  v[i] += v[i - 1];
    for (int i = N - 1; i >= 1; i--)  v[i - 1] += v[i];

    int ans = 0;
    for (int z = c; z <= d; z++)
    {
        ans += v[z + 1];
    }
    cout << ans << nl;
}

signed main() { FAST  solve(); }
