#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

bool isPossible(multiset<int> s , int k)
{

    for(int stage = 1; stage <= k ; stage++)
    {
        int curr = k - stage + 1 ;
        auto it = s.lower_bound( -curr ) ;

        if(it != s.end())
        {
            s.erase(it) ;

            if(s.size())
            {
                auto it2 = --s.end() ;
                s.erase(it2) ;
                s.insert((*it2) - curr) ;
            }
        }
        else return 0 ;

    }

    return 1 ;
}

void solve()
{
   int n;   cin >> n;
   multiset<int> s ;
   vector<int> v(n);  for (auto &x : v) cin >> x , s.insert(-x) ;

   int l = -1 , r = n + 1; 
   while (r - l > 1)
   {
        int mid = (l + r) / 2 ;
        if(isPossible(s,mid)) l = mid ;
        else r = mid ;
   }

   cout << l << nl ;
   




}
signed main(){   FAST      TestCases      solve() ;  }



