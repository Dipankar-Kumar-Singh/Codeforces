#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
const int N = 5e6 ; 

signed main()
{
    FAST 
    int n , k ; cin >> n >> k ;
    vector<int> pf(N) , arr(N) , v(n) ; for(auto &x:v) cin >> x ;

    for(int i = 0 ; i < n ; i++){
        pf[i+1] = pf[i] + v[i] ;
    }

    // I coun't solve ........

    int a{} , b {}, mx{-1} , pos {-1}, gsum = -1 ;

    for(int i = n ; i >= k ;  i--)
    {
        pf[i]-=pf[i-k] ;

        // grand sum .....

        if(  pf[i+k] >= mx  )
        {
            mx = pf[i+k] ;
            pos = i + k ;
        }

        if(gsum <= pf[i] + mx )
        {
            gsum = pf[i] + mx ;
            a = i , b = pos ;
        }
        // update b ...
    }
    a -= k , b-=k ;
    cout << a + 1 << " " <<  b+1 ;
}

