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

int const N = 999999 ;

vector<int> v ;

void solve()
{
    int x ; cin >> x ;
    int id = upper_bound(all(v) , x) - v.begin() ;
    cout << id << nl ;
}

signed main() { 
    FAST 

    vector<vector<int>> layers = {{ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } }; 

    for(int t = 0 ; t < 8 ;  t++)
    {
        auto vec = layers.back() ;
        for(auto &x : vec) x *= 10 ;
        layers.push_back(vec) ;
    }

    v.clear() ;

    for(auto& vec : layers) 
        for(auto& x : vec) v.push_back(x) ;


    TestCases solve(); 
}
