#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int long long 
signed main()
{
    FAST 
    int n , k ;  cin >> n >> k ; 
    vector<int> v(n) ; for(auto &x : v) cin >> x ;   sort(v.begin(),v.end())  ;

    int low{} , curr {} ;
    pair ans = {0,0} ;

    for(int i = 0 ; i < n ; i++)
    {
        if (i)
        {
            curr += (i - low) * (v[i] - v[i - 1]);
        }

        while (curr > k)
        {
            curr -= (v[i] - v[low++]);
        }

        ans = max(ans, {i - low + 1, -v[i]});
    }

    auto &[x,y] = ans ;
    cout << x << " " << -y ;
}

