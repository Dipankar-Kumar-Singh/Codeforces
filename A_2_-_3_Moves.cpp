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
   int n = 0 ;   
   cin >> n;

   if(n==1)
      cout << 2 << nl ;
   
   else if(n==2) 
      cout << 1 << nl ;
   
   else if(n==3)
      cout << 1 << nl ;

   else 
   {
      if(n%3==0) cout << n/3 << nl ;

      else if(n%3==2) cout << n/3 + 1 << nl ;

      else
      {
            cout << ((n/3)-1) + 2 << nl ;
      }
   }

}
signed main(){   FAST      TestCases      solve() ;  }



