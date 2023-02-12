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
   vector<int> v (n) ; 
   for(auto &x : v) cin >> x ;


   for(auto &x : v)
   {
        int moves = 0 ;
        cin >> moves ;
        while(moves--)
        {
            char c ; cin  >> c ;
            if(c=='D') c = 'U' ; else c = 'D' ;
            if(c=='D')
            {
                x-- ;
                if(x==-1) x = 9 ;
            }

            else 
            {
                x++ ;
                if(x==10) x = 0 ;
            }
        }

   }

   for(auto x : v) cout << x << " " ; 
   cout << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }



