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

   int best = -1 ;

   for(int i = 0 ; i < n ; i++)
   {
      best = max(best,v[n-1]-v[i]) ;
   }

   for(int i = 0 ; i < n ; i++)
   {
      best = max(best,v[i]-v[0]) ;
   }

    for(int i = 0 ; i < n + 10; i++)
    {
        best = max(best,v.back()-v.front()) ;
        std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
         best = max(best,v.back()-v.front()) ;
    }

    cout << best << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }



vector<vector<int>>adj(n+1);
while(!vcis[node]){

}
