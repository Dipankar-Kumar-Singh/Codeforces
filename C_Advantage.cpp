#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n; 
    cin >>  n ;
    vector<int> v(n) ;
    for(int &x : v) cin >> x ;

    multiset<int> s (all(v)) ;
    
    for(int x : v)
    {
        s.erase(s.find(x)) ;
        int biggest = *(--s.end()) ;
        cout << x - biggest << " " ;
        s.insert(x) ;
    }

    cout << nl  ;
    
}

signed main() { FAST TestCases solve(); }
