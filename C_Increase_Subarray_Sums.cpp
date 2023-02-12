#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n"  

void solve()
{
    int n , k ; cin >>  n >> k ;
    vector<int> v(n) ; for(auto &x : v){ cin >> x ; } ;

    int max_sum = 0 ;
    vector<int> val(n+10,LONG_LONG_MIN) ; 

    for(int i{0} ; i < n ; i++)
    {  
        int sum = 0 ;
        for(int j = i ; j < n  ; j++)
        {
            int len = j - i + 1 ;
            sum += v[j] ;
            val[len] = max(val[len],sum) ;
            max_sum = max(sum,max_sum) ;
        }
    }

    for(int len = n ; len >= 1 ; len-- )   
        val[len]  = max(val[len] , val[len+1]) ;
    
    cout << max_sum << " " ;

    for(int len = 1 , mx = 0  ; len <= n ; len++)
    {
        mx = max(mx, val[len] + (len * k));
        cout << mx << " " ;
    }
    cout << nl ;
}

signed main(){   FAST      TestCases      solve() ;  }