// Everything in the Universe is Balanced
// Every Disappointment you face in life will be balanced with something good for you
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC;  cin >> TOTALTC; for (__case__ = 1; __case__ <= TOTALTC; __case__++)
#define FAST ios_base::sync_with_stdio(0);cin.tie(NULL);    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define nl "\n"
int __case__ = 1;   

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    int org = accumulate(all(v), 0LL);

    if( n == 3 )
    {
        int a = max(v.front() , v.back()) * 3  ;
        int b = max( abs(v[0] - v[1]) , abs(v[1] - v[2])) * 3 ;
        int ans = max({org, a , b});
        
        cout << ans << nl;
        return ;
    }
    
    if(n == 2)
    {
        int a = abs(v[0] - v[1]) * 2 ;
        cout << max(org,a) << nl;
        return ;
    }

    cout << *max_element(all(v)) * n  << nl ;
    return;
}

signed main() { FAST TestCases solve(); }
