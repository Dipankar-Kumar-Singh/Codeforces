    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n , m ; 
    cin >> n >> m;
    
    vector<int> v(n) ;
    
    long long time = 0 ; 
    for(auto &x : v) cin >> x , time += x + 1 ;

    std::multiset<int> s(all(v)) ;

    while(s.size())
    {
        int x = *(--s.end()) ;
        s.erase(s.find(x)) ;

        while (1)
        {
            // ek saaath do movies dekh saktey hai ... then ..
            auto it = s.upper_bound(m - x);
            if (it == s.begin())
                break;

            --it;
            x = *it;
            s.erase(it);
            time--;
        }
    }

    cout << time << nl ;
    
}

signed main() { FAST  solve(); }
