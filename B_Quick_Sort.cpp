#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


long long ceil(long long a, long long b) {    if (a == 0) return 0;    return (a - 1)/b + 1;}

void solve(int& __case__)
{
    int n ; cin >> n ; 
    int k ;  cin >> k ;
    vector<int> v(n) ;

    for(auto &x : v) cin >> x ;

    map<int,int> loc ;
    for(int i = 0 ; i < n; i++)
    {
        loc[v[i]] = i + 1 ;
    }

    vector<int> a ; 

    for(int i = 1 ; i <= n ; i++)
    {
        a.push_back(loc[i]) ;
    }

    int chain = 1 ;
    for(int i = 1 ; i < a.size() ; i++)
    {
        if( a[i - 1 ] < a[i])
        {
            chain++ ;
        }

        else break ;
    }

    int total = n - chain ;
    cout << ceil(total , k ) << nl;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
