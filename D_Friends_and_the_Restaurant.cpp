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
   vector<int> a(n) , b(n) ;
   for(auto &x : a) cin >> x ; 
   for(auto &x : b) cin >> x ; 

   multiset<int> s1 , s2 ;

   for(int i = 0 ; i < n; i++)
   {
        int m = b[i] ;
        int spend = a[i] ;

        if(m >= spend)
        {
            s1.insert({m - spend}) ;
        }

        else 
        {
            s2.insert({spend-m}) ;
        }
   }

   int ans = 0 ;

   while(s2.size())
   {
        int req = *s2.begin() ;
        s2.erase(s2.begin()); 

        auto it = s1.lower_bound(req) ;
        if(it == s1.end()) break;

        ans++ ;

        s1.erase(it) ;

   }


   ans += s1.size()/2 ;

   cout << ans << nl ;



}
signed main(){   FAST      TestCases      solve() ;  }



