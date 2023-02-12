#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e18 
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void sub_seq(vector<int> arr, int n)
{
    vector< multiset <int>> vvv ;

    for(int i = 0 ; i < n ; i++)
    {
        multiset<int> s ;
        for(int j = i ; j < n ; j++)
        {

            s.insert(arr[j]) ;
            vvv.push_back(s) ;
        }
    }

    long long ans = 0 ;

    for(auto &v : vvv)
    {
        ans += v.size() ;
        ans+= v.count(0) ;
    }

    cout << ans << nl ;
}


signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        vector<int> v (n) ;
        for(int & i : v)
            cin >> i  ;

        sub_seq(v,n) ;
                                
                                       
    }
}

