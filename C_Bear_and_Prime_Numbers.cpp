#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
const int N = 10000010;

vector< int > count_(N), lp(N + 1), pr;

// Linear sieve🔥🔥🔥🔥⏩⏩⏩⏩ .... CP algorithm sey uthaya hai ........................
// pr --> all prime noumers in pr till N = 1e7 ....
void sv()
{
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)  lp[i] = i , pr.push_back(i);  
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)    lp[i * pr[j]] = pr[j];      
    }
}

signed main()
{
    FAST   sv() ; int n ; cin >> n; 
    vector<int> v(n) ; for(auto& x : v ){ cin >> x  ; count_[x]++ ;}
    vector<int> fc(pr.size()) ;

    for(int k = 0 ; k < pr.size() ; k++)
    {
        int p = pr[k] ;
        int ans = 0 ;
        for (int i = 1;  (i * p) < N;  i++  )  ans += count_[ i * p ];
        fc[k] = ans ;
    }

    vector<int> pf(fc.size()+10) ;
    for(int i = 1 ; i <= fc.size() ; i++) pf[i] = (pf[i-1]+ fc[i-1]) ;

    int m ; cin >> m; 
    while (m--)
    {
        int l , r ; cin >> l >> r ; 
        int a = lower_bound(all(pr),l) - pr.begin() ;
        int b = upper_bound(all(pr),r) - pr.begin() - 1 ;
        int ans = 0 ;
        ans = pf[++b] - pf[a] ; // 🪖 1 basesd index .. thus pf[b+1] - pf[[a+1]-1] ⏩> sum[l,r] =pf[r] - pf[l-1]
        cout << ans << nl ;
    }
}