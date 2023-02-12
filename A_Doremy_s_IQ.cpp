#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int INF = 1e9 + 10;
int _case = 1 ;

int IQ = 0;
int n ;
vector<int> v ;

bool isPossible(int id)
{
    int iq = IQ ;
    bool vis_last = false ;

    for(int i = id ; i < n ; i++)
    {
        
        if(v[i] > iq)
        {
            if(i==n-1 and iq) vis_last = true ;
            iq--;
            if((iq==0) and (i < n - 1)) return 0 ;
        }

        if (v[i] <= iq and iq)
        {
            if (i == n - 1)   vis_last = 1;
        }
    }

    return vis_last ;

}

void solve()
{
    cin >> n >> IQ ;
    v = vector<int> (n) ; 
    for(auto &x : v) cin >> x ; 

    vector<int> s(n);
    int l = -1 , r = n ;

    int ans = 0 ;
    while(r - l > 1)
    {
        int m = midpoint(l,r) ;
        if(isPossible(m))
        {
            r = m ;
            ans = m ;
        }
        else l = m ;
    }

    for (int i = 0; i < ans; i++)   s[i] = (v[i] <= IQ);
    for(int i = ans  ; i < n ; i++ ) s[i] = 1 ;

    for(auto x : s) cout << x ;  cout << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



