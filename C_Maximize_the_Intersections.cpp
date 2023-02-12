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
   int n , k ; cin >> n >> k ;
   vector<pair<int,int>> input(k) ; 
   vector<int> vis(2*n+1,-1) ;

   vector<pair<int,int>> v ;
   for(auto& [ x , y ] : input)
   {
      cin >> x >> y ;
      if(x > y) swap(x , y ) ;
      v.push_back({x,y}) ; 
      vis[x] = vis[y] = 1 ;
   }

   vector<int> unused ;
   for(int i = 1 ; i <= 2*n ; i++){
      if(vis[i] == -1) {
         unused.push_back(i) ;
      }
   }

   vector<int> a(begin(unused), begin(unused) + unused.size() / 2);
   vector<int> b(begin(unused) + unused.size() / 2, end(unused));

   for(int i = 0 , n = a.size() ; i < n ; i++)   v.push_back({a[i],b[i]}) ;

   int intersection = 0 ;
   for (auto [x, y] : v)
   {
      for (auto [p, q] : v)
      {
         if (x == p and q == y) continue;
         if (x < p and y > p and y < q) intersection++;
      }
   }

   cout << intersection << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



