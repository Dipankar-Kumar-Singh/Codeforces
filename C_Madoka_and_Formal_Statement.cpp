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
   vector<int> a(n);  for (auto &x : a) cin >> x;
   vector<int> b(n);  for (auto &x : b) cin >> x;

   for (int i = 0; i < n; i++)
   {
       if (a[i] == b[i])  continue;

       if (a[i] > b[i])
       {
           cout << "NO\n";
           return;
       }
       if ( b[i] > b[(i + 1) % n] + 1)
       {
           cout << "NO\n";
           return;
       }
   }

   cout << "YES\n";
}
signed main(){   FAST      TestCases      solve() ;  }



