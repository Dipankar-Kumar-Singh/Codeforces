#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    int n ; cin >> n ;

    int cap = 0  ;

    int ans = 0 ;

    for(int kk = 0 ; kk < n ;kk++){

        int out , in ; cin >> out >> in ; 

        cap -=  out ; cap += in ; 

        ans = max(ans,cap) ;

    }

    cout << ans ;
}

