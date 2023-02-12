#include <bits/stdc++.h>
using namespace std;

// #include"C:\Users\dipan\OneDrive\ProCode\CP\debugging.h" 
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; cerr << (a)  << "  " ; err(++it, args...);}
// #define dbg error


#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


// bool isPossible(vector<int> &prefix ,int &n , int &budget, int &day, int &id)
// {
//     int len = id ;
//     int cost = prefix[id] ;
//     cost += (len*day) ;
//     return (cost <= budget) ;
// }

bool isPossible(vector<int> &prefix ,int &n , int &budget, int &day,int len)
{
    // maxDay * len <= (budget - prefix[len]) 
    day-- ;
    return (day*len <= budget - prefix[len]) ;
}

void solve()
{
   int n , budget ; 
   cin >> n >> budget ;

   vector<int> v(n) ; for(auto &x : v) cin >> x ;

   sort(all(v)) ;

    if(budget<v.front()) {
        cout << 0 << nl ;
        return ;
    }

    vector<int> prefix(n+1) ;
    for(int i = 1 ; i <= n ; i++)
    {
        prefix[i] = prefix[i-1] + v[i-1] ;
    }

    int ans = 0 ;
    int sumOfPreviousDays = 0 ; 

    for(int curlen = n ; curlen >= 1 ; curlen--)
    {
        // maxDay * len <= (budget - prefix[len]) 

        int maxDay = 0 ;

        int l = 0 , r = budget - v.front() + 1 ;

        // dbg(l,r) ;

        while (r-l>1)
        {
            int mid = (r+l)/2 ;
            if(isPossible(prefix,n,budget,mid,curlen))   l = mid ;
            else r = mid ;
        }

        maxDay = l  ;
        int netday = maxDay - sumOfPreviousDays ;
        netday = max(netday,0LL) ;
        sumOfPreviousDays += netday ;

        // dbg(curlen,maxDay,netday) ;
        ans += netday*curlen ;
        // dbg(ans) ;
        // cerr << "\n" ;
    }

    // cerr << "-------------" << nl << nl ;
    

    cout << ans << nl ;
    return ;




    // int DAYS = budget - v.front() ;

    // int ans = 0 ;

    // for(int d = 0 ; v.front() + d <= budget ; d++)
    // {
    //     int l = 0 , r = n + 1 ; 

    //     while(r-l>1)
    //     {
    //         int mid = (l+r)/2 ;
    //         if(isPossible(prefix,n,budget,d,mid)) l = mid ;
    //         else r = mid ;
    //     }

    //     // cerr << " Day =  " << d+1 << "    " ;
    //     // cerr << "len  = " << l << "  " ; 
    //     // cerr << nl ;
    //     ans += l ;
    // }

    
    // cout << ans << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

