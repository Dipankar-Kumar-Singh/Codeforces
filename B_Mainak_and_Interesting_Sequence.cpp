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
   int m ; cin >> m ;

   vector<int> v(n,1);  

   v.back() = 0 ;

   int sum = accumulate(all(v),0LL) ;

   int req = m - sum ;


   if(n==1)
   {
        cout << "Yes\n" ;
        cout << m << nl ;
        return ;
   }

   if( n > m)
   {
        cout << "No\n" ;
        return ;
   }

   else 
   {
       if ((n - 1) % 2 == 0)
       {
           cout << "Yes\n";

           v.back() = m - sum;

           for (auto x : v)
           {
               cout << x << " ";
           }

           cout << nl;
       }

       else 
       {
            req = m - (n-2) ;
            if(req%2==0)
            {
                cout << "Yes\n" ;
                v[n-1] = v[n-2] = req/2 ;

                for(auto x : v) cout << x << " " ;
                cout << nl ;
            }

            else 
            {
                cout << "No\n" ;
            }
            
       }
   }

   

   


   




}
signed main(){   FAST      TestCases      solve() ;  }



