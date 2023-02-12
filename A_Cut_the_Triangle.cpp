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
    set<int> v , h ;

    for(int i  = 0 ; i < 3 ; i++)
    {
        int x , y ;
        cin >> x >> y ;
        v.insert(y) ;
        h.insert(x) ;
    }

    if(v.size() == 3 or h.size() == 3)
        cout << "YES\n" ;
    else
        cout << "NO\n";
}

signed main() { FAST TestCases solve(); }
