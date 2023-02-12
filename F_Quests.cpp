#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

int totalDays = 0 ;
int leastCost = 0 ;

bool isPossible(int k, multiset<int, greater<>> s)
{
    vector<int> d( totalDays + 10 , -1) ;
    int cost = 0 ;

    for(int i  = 1 ; i <= totalDays ; i++)
    {
        if(d[i] == -1 )
        {
            if(s.empty()) continue ;
            int bigget = *s.begin() ;
            s.erase(s.begin()) ;
            cost += bigget ;
            if( i + k  + 1 < d.size() ) d[ i + k + 1 ] = bigget ;
        }

        else 
        {
            cost += d[i] ;
            if (i + k + 1 < d.size())
                d[i + k + 1] = d[i];
        }

        if(cost >= leastCost) return 1 ;
    }

    return cost >= leastCost ;

}

void solve()
{
    int n ; 
    cin >> n >> leastCost >> totalDays ;
    vector<int> rewards(n) ;
    for(auto &x : rewards) cin >> x ;
    sort(all(rewards)) ;
    reverse(all(rewards)) ;

    multiset<int , greater<>> s(all(rewards)) ;
    
    int biggest = rewards.front() ;
    if(biggest * totalDays < leastCost ) 
    {
        cout << "Impossible\n" ;
        return ;
    }

    int sumOverDdays = 0 ;
    for(int i = 0 ; i < min(totalDays , n) ; i++) sumOverDdays += rewards[i] ;

    if(sumOverDdays >= leastCost)
    {
        cout << "Infinity\n" ;
        return ;
    }

    int l = 0 ; 
    int r = numeric_limits<int>::max() ;

    while (r - l > 1)
    {
        int mid = midpoint(l , r) ;
        if(isPossible(mid,s)) l = mid ;
        else r = mid ;
    }

    cout << l << nl ;
}

signed main() { FAST TestCases solve(); }
