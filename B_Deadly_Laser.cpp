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
   int n , m , sx , sy , d ;
   cin >> n >> m >> sx >> sy >> d ;

   int upClear = (sx - d) > 1;
   int downClear = (sx + d) < n;

   int leftClear = sy - d > 1;
   int rightClear = (sy + d) < m;

   bool pathA = leftClear and downClear ; 
   bool pathB = upClear and rightClear ;

   if(pathA or pathB) 
   {
        cout << m + n - 2 << nl ;
   }

   else 
   {
        cout << -1 << nl ;
   }




}
signed main(){   FAST      TestCases      solve() ;  }



