#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   


}

signed main()
{   FAST  

    int n ; cin >> n ;
    vector<int> items(n,0) ;
    for(auto &x : items) cin >> x ;

    int ans = 0 ;

    for (int i = 0; i < items.size(); i++)
    {
        for (int j = i; j < items.size(); j++)
        {
            set<int> t ;
            for (int k = i; k <= j; k++)
            {
                t.insert(items[k]) ;
                // cerr << items[k] << " " ;
            }

            // cerr << nl ;

            if(t.size()<=1) continue; 

            int f = *t.begin() ;
            int l = *(--t.end()) ;
            
            ans +=  abs(*t.begin() - *(--t.end())) ;
        }
    }


    cout << ans ;
}

