#include <bits/stdc++.h>
using namespace std;

    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
    // Keep Going, Never Give up .

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n ; cin >> n ;
    set<int, greater<>> s;
    s.insert(-1) ;
    vector<vector<int>> big(n);

    for(auto &vec : big)
    {
        int k ; cin >> k ;
        vec = vector<int>(k) ;

        for (auto &x : vec)
            cin >> x, s.insert(x);

        reverse(all(vec)) ;
    }

    int moves = 0 ; 
    for(auto v : big)
    {
        int n = v.size() ;
        for(int i = 0 ; i < n; i++)
        {
            if (s.upper_bound(v[i]) != s.end())
            {
                int next = *s.upper_bound(v[i]);
               
                if(i + 1 < n and v[ i + 1 ] != next)
                {
                    int v_1 = v[i  + 1 ] ;
                    moves++ ;
                }
            }
        }
    }

    cout << moves  <<  " " << big.size() + moves  - 1 << nl ;
}

signed main() { FAST  solve(); }
