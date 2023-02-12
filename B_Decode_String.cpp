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
   string s ; cin >> s ; 
   string ans ;


   reverse(all(s)) ;

   for(int i = 0 ; i < n ; i++)
   {
        if(s[i] == '0')
        {
            string t = s.substr(i,3) ;
            reverse(all(t)) ;
            t.pop_back() ;
            int id = stoi(t) ;
            id-- ;
            char c = id + 'a' ;
            ans.push_back(c) ;
            i += 2 ;
        }

        else 
        {
            int id =  (s[i] - '0')   ;
            id-- ;
            char c =  id +  'a' ;
            ans.push_back(c) ;
        }
   }

   reverse(all(ans)) ;
   cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



