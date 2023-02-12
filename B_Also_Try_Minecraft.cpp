#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
    int n ; cin >> n ;
    int m ; cin >> m;
    vector<int> v(n) ; for (auto &x : v) cin >> x ;

    vector<int> gofront(n);
    vector<int> goback(n);

    for (int i = 0; i + 1 < n; i++)
        gofront[i] = max(0LL,  v[i] - v[i + 1] );

    for (int i = 0; i + 1 < n; i++)
        goback[i] = max(0LL,  v[i + 1] - v[i]);

    vector<int> fp(n+1) ;
    vector<int> bp(n+1) ;

    partial_sum(all(gofront),fp.begin()+1) ;
    partial_sum(all(goback),bp.begin()+1) ;

    // for(auto x : fp) cerr<< x << " " ; cerr << nl ;
    // for(auto x : bp) cerr << x << " " ; cerr << nl ;
    


    while (m--)
    {
        int s, t;
        cin >> s >> t;
        // s--, t--;

        if(s<t)
        {
            t-- ;
            cout << fp[t] - fp[s-1] << nl;
        }

        else
        {
            s-- ;
            cout << bp[s] - bp[t-1] << nl ;
        }

        

    }
}
signed main(){   FAST    solve() ;  }



