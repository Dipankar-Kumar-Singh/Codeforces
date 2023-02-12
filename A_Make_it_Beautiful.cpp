#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n;  cin >> n ; 
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    sort(begin(v),end(v) , greater<int>()) ;

    int diffLoc = v.front() ;
    for (int i = 0 ; i < n; i++)
        if (v[i] != diffLoc)
        {
            diffLoc = i;
            break;
        }

    if (diffLoc >= v.size())
        diffLoc = n - 1;

    if(v.size() > 2)
        if(v[0] == v[1])
            swap(v[0] , v[diffLoc]) ;
    
    int sum = v.front() ;

    for(int i = 1 ; i < n;  i++)
    {
        if(v[i] == sum)
        {
            cout << "NO" << nl ;
            return ;
        }

        sum += v[i] ;
    }

    cout << "YES" << nl ;
    for(auto x : v) cout << x << " " ; 
    cout << nl ;


}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
