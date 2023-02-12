#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


int nb, ns, nc ;
int pb, ps, pc ; 
int B{} , C{} , S {} ;

bool isPossible (int t , int m)
{
        int total_b = t*B ;
        int total_c = t*C ;
        int total_s = t*S ;

        // buying B if needed 
        if(total_b > nb)
        {
            int b_req = total_b - nb ;
            m -=  pb*b_req ;
            if(m<0) return 0 ;
        }

        if(total_c > nc )
        {
            int c_req = total_c - nc ;
            m -=  pc*c_req ;
            if(m<0) return 0 ;
        }

        if(total_s > ns )
        {
            int s_req = total_s - ns ;
            m -=  ps*s_req ;
            if(m<0) return 0 ;
        }

        return m>=0 ;
} ;

signed main()
{
    FAST

    string s ; cin >> s ;

    cin >> nb >> ns >> nc ;
    cin >> pb >> ps >> pc ;

        B = count(all(s),'B') , 
        S = count(all(s),'S') , 
        C = count(all(s),'C') ;

    int money ; 
    cin >> money ;

    int ans = 0 ;
    int l = 0 , r = 1e15;

    while(r-l>1)
    {
        int mid = midpoint(l,r) ;
        if(isPossible(mid,money))
        {
            l = mid ; 
            ans = max(mid,ans) ;
        }
        else r = mid ;
    }

    cout << ans ;

}

