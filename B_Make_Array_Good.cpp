    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
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
    int n ; cin >> n;
    vector<pair<int,int>> v(n) ;
    

    for(int i = 0 ; i < n ; i++)
    {
        int x ; cin >> x ;
        v[i] = {x , i} ;
    }

    map<int,int> need ;

    sort(all(v)) ;

    for(int i = 1 ; i < n ; i++)
    {
        int prev = v[i - 1].first ;
        
        int x = prev ; 
        int limit = v[i].first ;

        int nextNumber = ((limit/x) * x ) ;

        if(nextNumber < limit) nextNumber += x ;

        int diff = nextNumber - limit ;

        need[v[i].second] = diff ;
        v[i].first = nextNumber ;

    }

    cout << n << nl ;
    for(int i = 0 ; i < n ; i++)
    {
        cout << i + 1 << " " << need[i] << nl ;
    }

}

signed main() { FAST TestCases solve(); }
