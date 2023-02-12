#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void print(bool ans)
{
    cout << "Case #" << _case << ": " << (ans ? "YES" : "NO") << nl;
}

void solve()
{
    int n , k ; cin >> n >> k;
    map<int,int> m ;
    vector<int> v(n);  for (auto &x : v) cin >> x , m[x]++;

    for(auto &[x,fr] : m)
    {
        if(fr > 2)
        {
            print(false) ;
            return ;
        }
    }

    bool isPossible = (n <= 2 * k);
    print(isPossible) ;
 
}
signed main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/Input.txt", "r", stdin);
    // freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/error.txt", "w", stderr);
    // freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/output.txt", "w", stdout);
    // #endif

    FAST
        TestCases
        solve();
}
