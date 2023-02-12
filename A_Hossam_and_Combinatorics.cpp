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
    int n ; 
    cin >> n ;


    vector<int> v(n) ;

    map<int,int> m ; 

    for(auto &x : v)
    {
        cin >> x;
        m[x]++;
    }

    sort(all(v)) ;

    int diff = abs(v.back() - v.front()) ;

    int ans = 0 ;

    for(auto x : v)
    {
         int a = x + diff ;
         int b = x - diff ;

         
         ans +=  m[a] ;

         if(a!=b)
         ans +=  m[b] ;

         if(v.front() == v.back())
         {
            ans -= 1 ;

            if(a != b)
            ans -= 1 ;
         }
    }

    cout << ans << nl ;
}

signed main() { FAST TestCases solve(); }
