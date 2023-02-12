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

   vector<char> v(4) ;
   for(auto &x : v) cin >> x ;

   set<char> s(all(v));

   if(s.size()==1)
   {
        cout << 0 << nl ;
   }

   else if(s.size() == 2)
   {
        cout << 1 << nl  ;
   }

   else if(s.size() == 3)
   {
        cout << 2 << nl ;
   }

   else if(s.size() == 4)
   {
        cout << 3 << nl ;
   }




}
signed main(){   FAST      TestCases      solve() ;  }



