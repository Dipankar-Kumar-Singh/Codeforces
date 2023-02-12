#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

bool isPossible(int targetDays , int n , int m , vector<int> &masterin)
{
    int remainingtask = m ;

    for(int worker = 1 ; worker <= n ; worker++)
    {
        int under1HR = min( targetDays, masterin[worker]);

        remainingtask -= under1HR;
   
        if(under1HR < targetDays)
        {
            int under2HR  = (targetDays - under1HR) / 2 ;
            remainingtask -= under2HR;
        }
    }

    return remainingtask<=0 ;
}



void solve()
{
    int n , m ; cin >> n >> m ;
    // n -> no of workers , m -> no of jobs

    vector<int> proficient(m) ;
    for(auto &x : proficient) cin >> x ; 
    // proficient[i] -> Index of workers who can do job i

    vector<int> masterin(n+10) ;
    for(int i = 0 ; i < m ; i++) masterin[proficient[i]]++ ;

    int l = 0 , r = 1e10 ;
    while(r-l>1)
    {
        int mid = (l+r)/2 ;
        if(isPossible(mid,n,m,masterin))
            r = mid ;
        else
            l = mid ;
    }

   cout << r << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



