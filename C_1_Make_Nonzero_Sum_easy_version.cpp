#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   vector<int> v(n);  for (auto &x : v) cin >> x;

   if(n&1)
   {
        cout << -1 << nl ;
        return ;
   }

    vector<pair<int,int>> ans ;
   for(int i = 0 ; i + 1 < n; i+=2)
   {
        int x = v[i] , y = v[i + 1] ;
        if(x == y)
        {
            ans.push_back({i,i+1}) ;
        }

        else
            ans.push_back({i, i}), ans.push_back({i + 1, i + 1});
   }

   cout << ans.size() << nl;
   for (auto [x, y] : ans)
       cout << x + 1 << " " << y + 1 << nl;
}
signed main(){   FAST      TestCases      solve() ;  }



