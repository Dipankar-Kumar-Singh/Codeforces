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
   vector<int> v(n);  for (auto &x : v) cin >> x;

   vector<pair<int,int>> ans ;

   int curr = 0 ; 
   int s = 0 , e = 0 ;  
   
   for(int i = 0 ; i < n ; i++)
   {
        if(curr == 0 and v[i] == 0 ) ans.push_back({i,i}) ;
        else if(curr == 0 )
        {
            if( i + 1  < n)
            {
                curr = v[i] - v[i + 1] ;
                if(curr == 0)
                {
                    ans.push_back({i,i}) ;
                }

            }
        }
   }




}
signed main(){   FAST      TestCases      solve() ;  }



