#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int optimized(vector<int> &v)
{
    int ans = 0 ;
    int n = v.size() ;
    for(int i = 0 , curr = 0 , len = 0 ; i < n ; i++) 
    {
        if(v[i]== curr) len++  ;

    }
    return ans ;
}

int result(vector<int> &v)
{   
    int n = v.size() ;

    int curr = -1 ;

    int ans = 0 ;

    // for(auto x : v) cerr << x << " " ; 
    // cerr << nl ;

    for(int i = 0 ; i < n; i++)
    {
        if(curr==v[i]) continue ;
        else 
        {
            ans++ ;
            curr = v[i] ;
        }
    }

    // cerr << "     ans = " << ans << nl  ; 

    return ans ;
}

int bruteForce(vector<int> &v)
{
    int n = v.size() ;
    int ans = 0 ;
    for(int i = 0 ; i < n; i++)
    {
        vector<int> a ;
        for(int j = i ; j < n ; j++)
        {
            a.push_back(v[j]) ;
            ans += result(a) ;
        }
    }

    return ans ;
}


signed main()
{
    int n ; cin >> n  ;
    vector<int> v(n) ;
    for(int &i : v) cin >> i ;
    cout << bruteForce(v) << nl ;

}