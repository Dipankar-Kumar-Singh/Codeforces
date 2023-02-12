#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
   
   int n , m , k ; cin >> n >> m >> k ;
   string s1 , s2 ; cin >> s1 >> s2 ;

   sort(all(s1)) ; sort(all(s2)) ;
   string ans ; 
   
   int a {} , b {} ;

   int i = 0 , j = 0 ;
   while (i<n && j<m)
   {
       if (s1[i] < s2[j])
       {
            if(a<k)
            {
                a++ ;
                b = 0 ;
                ans += s1[i++] ; 
            }

            else 
            {
                a = 0 ;
                b = 1 ;
                ans += s2[j++] ;
            }
       }

       else if (s1[i] > s2[j])
       {
            if(b<k)
            {
                b++ ;
                a = 0 ;
                ans += s2[j++] ;
            }

            else
            {
                b = 0 ;
                a = 1 ;
                ans += s1[i++] ;
            }
       }
   }

   cout << ans << nl ;
   


}
signed main(){   FAST      TestCases      solve() ;  }
