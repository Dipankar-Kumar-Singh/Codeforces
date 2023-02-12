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

   int a , b , c ; cin >>  a >>  b >> c ;

   int t1 = abs(a - 1);
   int t2 = abs(b - c) + abs(c - 1);

   if(t1 < t2)
   {
        cout << 1 << nl ;
   }

   else if( t1 > t2)
   {
        cout << 2 << nl ;
   }

   else if(t1 == t2) cout << 3 << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }



