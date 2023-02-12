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


vector<int> vec ;

void solve()
{
    int n ; cin >> n ; 
    int t ; cin >> t ;
    vector<int> v(n) ;

    for(int i = 0 ; i < n ;i++)
    {
        v[i] = vec[i] ;
    }

    for(int i = n - 1 ;i >= 0 ; i--)
    {
        int x = v[i] ;
        
        int seats = n - 1 - i ;
        
        if(t - x >= seats)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                v[j] = ++x ;
            }

            break;
        }
    }


    for(auto x : v) cout << x << " " ; cout << nl ;
    
}

signed main() {
    FAST

    int num = 1 ;
    for(int i = 1 ; ; i++)
    {
        vec.push_back(num) ;
        num += i ;
        if(vec.size() > 45 ) break;
    }



    TestCases
    solve();
}
