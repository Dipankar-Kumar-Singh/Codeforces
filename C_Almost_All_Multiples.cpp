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
    int x ; cin >> x ;

    vector<int> v(n + 1);
    iota(all(v),0) ;

    vector<int> cycle { x } ;

    if(n % x )
    {
        cout << -1 << nl ;
        return;
    }

    if(x == n)
    {
        for(int i = 1 ; i <= n;  i++)
        {
            if(i==1) cout << n << " " ; 
            else if(i==n) cout << 1 << " " ;
            else cout << i <<  ' ' ; 
        }
        cout << nl ;
        return ;
    }

    int curr = x ;

    while(curr < n )
    {
        bool found = 0 ;
        for(int f = 2 ; f * curr <= n ; f++)
        {
            if (n % (f * curr) == 0)
            {
                curr = curr * f ;
                cycle.push_back( curr) ;
                found = 1 ;
                break; 
            }
        }

        if(curr * 2 >= n) break;
    }

    cycle.push_back(n) ;
    set<int> cy (all(cycle)) ;

    v[n] = 1;

    for(int i = 1 ; i < n ; i++)
    {
        if(cy.count(i))
        {
            for(int j = 0 ; j < cycle.size() ; j++)
            {
                if(cycle[j] == i)
                {
                    v[i] = cycle[ j + 1] ;
                    break;
                }
            }
        }
    }

   v[1] = x ;
   for(int i = 1 ;i <= n ; i++) cout << v[i] << " " ; cout << nl ;
    
}

signed main() { FAST TestCases solve(); }
