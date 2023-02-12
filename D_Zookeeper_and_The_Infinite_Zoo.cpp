#include <bits/stdc++.h>
using namespace std;

#define LOCAL 

#ifdef LOCAL
    #include"/home/dk/Code/debug/debugging.h"
#else 
    #define dbg(...) 42 
#endif

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int x , y ;
    cin >> x >> y ;
    bitset<30> s(x) , d(y) ; // source --> destination .. type : Bitset

    dbg(s,d) ;

    int activeBuffer = 0 ;
    int possible = (x <= y);

    for(int bit = 0 ; bit < 30 ; bit++)
    {
        activeBuffer += s[bit] ;
        activeBuffer -= d[bit] ;

        if(activeBuffer < 0 ) {possible = 0  ; break ; }
    }

    cout << ( possible ?  "YES" : "NO") << nl ;
    
}

signed main() { FAST TestCases solve(); }
