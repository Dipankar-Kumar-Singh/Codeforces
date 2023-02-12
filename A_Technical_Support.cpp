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
   vector<int> vis(n) ;

   vector<int> ctt(n) ;
   
   for(int i = 0 , ct = 0  ; i < n ; i++)
   {
        if(s[i]=='Q')
        {
            ct++ ;
            int j = i + 1 ;
            for( ; j < n ; j++)
            {
                if(vis[j]==0 and s[j]=='A')
                {
                    vis[j] = ct ;
                    ctt[i] = ct ;
                    break;
                }
            }
        }
   }

   for(int i = n-1 ; i >= 0 ; i--)
   {
        if(s[i]=='Q')
        {
            // for(int j = i + 1 ; j < n ; j++)
            // {
            //     if(s[j] == 'A')
            //     {
            //         cout << "Yes" << nl ;
            //         return ;
            //     }
            // }

            if(ctt[i]!=0)
            {
                cout << "Yes" << nl ;
                return ;
            }

            else
            {
                cout << "No" << nl;
                return ;
            }

            break;
        }
   }

   

   

}
signed main(){   FAST      TestCases      solve() ;  }



