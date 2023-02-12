#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int const INF = 1e10 ;

int ans = INF ;

bool len1(int s)
{
    
    for(int l1 = 0 ; l1 < 10 ; l1++)
    {
        if(s-l1==0)
        {
            string t ;
            t += l1 ; 
            ans= min(stoll(t),ans) ;
            return 1;
        }
    }

    return 0 ;
}

bool 



void solve()
{
   int n;   cin >> n;
   vector<int> v(n);  for (auto &x : v) cin >> x;




}
signed main(){   FAST      TestCases      solve() ;  }



