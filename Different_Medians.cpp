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
   vector<int> a , b  ; 
   for(int i = 1 ; i <= n/2 ; i++) a.push_back(i) ;
   for(int i = n/2 + 1 ; i <= n ; i++ ) b.push_back(i) ;

   reverse(all(b)) ;

   int i = 0 ; int j = 0 ; 

    while(i < a.size() and j < b.size() )
    {
        cout << b[j++] << " ";
        cout << a[i++] << " ";
    }

    if (n & 1)
        cout << n / 2 + 1 << " ";

    cout << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



