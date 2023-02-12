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
   int m ;  cin >> m ;

   string a ; string b ; cin >> a >> b ;

   if(n<m)
   {
        cout << "NO\n" ;
        return ;
   }

   else if(n==m)
   {
        if(a==b) cout << "YES\n" ;
        else cout << "NO\n" ;
        return ;
   }

   else 
   {
        int i = n - 1 ;
        int j = m - 1 ;

        bool isOne = 0 , isZero = 0 ;

        for(int i = 0 ; i < n - m ; i++) 
        {
           if(a[i]=='1') isOne = 1 ;
           if(a[i]=='0') isZero = 1 ;
        }

        for( ; i >=0 and j>= 0 ; i-- , j--)
        {

            if(i==n-m)
            {
                if(b[j]!=a[i])
                {
                    if(b[j]=='1' and isOne) a[i] = b[j] ;
                    if(b[j]=='0' and isZero) a[i] = b[j] ;
                }
            }

            if(a[i]!=b[j])
            {
                cout << "NO\n" ;
                return ;
            }
        }

        cout << "YES\n" ;
        return ;
   }


}
signed main(){   FAST      TestCases      solve() ;  }



