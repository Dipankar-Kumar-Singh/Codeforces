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
   vector<int> v(n) , ans(n);
   for(auto &x : v) cin >> x ;

    for(int i = 0 ; i < n ; i++)
    {
        int curr = i + 1;
        if(v[i] >= curr)
        {
            ans[i] = 1 ;
        }
        else ans[i] = 0 ;
    }

//    if(v.front() < v.size())
//    {
//        if(accumulate(all(ans),0)==ans.size())
//        {
//            ans[(n)/2] = 0 ;
//        }
//    }

   for(auto &x : ans) cout << x << " " ;
   cout << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

