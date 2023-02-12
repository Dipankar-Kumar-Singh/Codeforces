#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int f(int x , int a)
{
    return ((x/a) + x%a) ;
}

void solve()
{
    int l, r, a;
    cin >> l >> r >> a;

    int best = (a*(r/a)) - 1  ;
    int ans = 0 ;

    if(best>=l)
    { 
        ans = max(ans,f(best,a)) ;
        if(best-1>=l)ans = max(ans,f(best-1,a)) ;
        if(best+1<=r)ans = max(ans,f(best+1,a)) ;
    }

    best = r ;

    if((f(best,a)==0) and (l<r)) best-- ;
    ans = max(ans,f(best,a)) ;
    if(best-1>=l)ans = max(ans,f(best-1,a)) ;
    if(best+1<=r)ans = max(ans,f(best+1,a)) ;

    cout << ans << "\n" ;
    return ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  



}

