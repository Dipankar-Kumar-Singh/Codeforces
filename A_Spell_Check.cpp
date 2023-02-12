#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

string NAME = "Timur" ;

void solve()
{
   int n;   cin >> n;
   string s ; 
   cin>> s ;

   sort(all(s)) ; 


   if(n==5 and s==NAME)
   {
        cout << "YES\n" ;
   }

   else cout << "NO\n" ;


}
signed main()
{
    FAST

        sort(all(NAME));
    TestCases solve();
}
