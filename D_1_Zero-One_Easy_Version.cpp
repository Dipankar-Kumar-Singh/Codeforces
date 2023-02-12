#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   	int n , x , y ;
   	cin >> n >> x >> y ;
    string a, b;
    cin >> a >> b;

    set<int> bad;
    for (int i = 0; i < n; i++) if(a[i] != b[i]) bad.insert(i);

    if (bad.size() & 1)
    {
        cout << -1 << nl;
        return;
    }

    int ans = 0;
    vector<int> v(all(bad)) ;
    
    if(v.size()==2)
    {
        int p = v.front();
        int q = v.back();
        if (p + 1 == q)
        {
            bool ExchangePoint = (p > 1 and q > 1) or ((n - 1 - p) > 1 and (n - 1 - q) > 1);
            if(ExchangePoint and (y + y < x) ) ans += y + y ;
            else ans += x ;
        }
        else ans += y ;
    }
    else 
    {
        ans += (v.size() / 2) * y;
    }

    cout << ans << nl;
}
signed main(){   FAST      TestCases      solve() ;  }



