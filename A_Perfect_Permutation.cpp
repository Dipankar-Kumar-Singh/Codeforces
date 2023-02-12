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
   int n ; cin >> n ;
   vector<int> v(n) ;

   if (n == 1)
   {
       cout << 1 << nl;
       return;
   }

   if(n&1)
   {
        cout << n << " " ;
        for(int i = 1 ; i < n ; i++) cout << i << " ";
        cout << nl ;
        return ;
   }

   else 
   {
        for(int i = 0 ; i < n ; i++) 
        if((i%2)==0) v[i] = i + 2 ;
        else v[i] = i ;
   }

   for(auto x : v) cout << x <<  " " ; cout << nl ;
   

   


}
signed main(){   FAST      TestCases      solve() ;  }



