#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

bool ok(int num , int odd, int days)
{
    int c1 = days/2 +  (days&1)  ;
    int c2 = days/2 ;

    if(odd>c1) return 0 ;
    return ((c1 + 2*c2) >= num) ;
}

int min_Day_Required( vector<int> v, int hight)
{
    for(auto &x : v) x = (hight - x) ;

    int sm = 0 ;
    int odd{} ;
    for(auto &x  : v) 
    { 
        if(x&1) odd++ ; sm += x ;  
    }

    int ans = 0 ; 
    int l = 0 , r = 1e18 ;
    while (r-l>1)
    {
        int mid = (l+r)/2 ;
        (ok(sm,odd,mid) ? r : l) = mid ;
    }

    if(ok(sm,odd,l)) return l ;
    else return r ; 
}

void solve()
{
   
    int n ; cin >> n ;
    vector<int> v (n) ;
    int maxHight = 0 ;
    for(auto &x : v) { cin >> x ; maxHight = max(maxHight,x) ;}

    int ans = numeric_limits<long long>::max() ;

    for(int Hight = maxHight ; Hight <  maxHight + 10 ; Hight++)
    {
        ans = min(ans , min_Day_Required(v,Hight)) ;
    } 

    cout << ans << nl ;
}

signed main()
{   FAST  

    TestCases  
    solve() ;  
}

