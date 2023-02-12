#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n ; cin >> n; 
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;
    
    vector<int> org = v ;

    for(int i = 1 ; i < n ; i++)
    {
        int curr = v[i] ;
        for(int j = i ; j >= 0 ; j--)
        {
            if(v[j]==v[i]) continue;
            else if(org[j] == curr) continue;
            else 
            {
                swap(v[i],v[j]) ;
                break;
            }
        }
    }

    for(auto &x : v) cout << x << " " ;
    cout << "\n" ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

