#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;
vector<int> p ;

int longest(vector<int> &v , int len)
{
    vector<int> mota = {len}; 
    int n = v.size() ;
    int target = 0 ;
    for(int i = 0 ; i < len ; i++) target += v[i] ;

    for(int i = len ; i < n ; i++)
    {
        int sum = 0 ;
        int thick = 0 ;
        while(sum < target and i < n ) 
        {
            sum += v[i] ;
            thick++ ;
            i++ ;
        }

        i-- ;

        if(sum == target)
        {
            mota.push_back(thick) ;
        }

        else 
        {
            return -1 ;
        }
    } 

    sort(all(mota)) ;
    return mota.back() ;
}

void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 
    vector<int> thicknes ;
    p = vector<int>(n+1) ;
    partial_sum(all(v), p.begin() + 1);

    for(int len = 1 ; len <= n ; len++)
    {
        int max_size = longest(v,len) ;
        if(max_size == - 1 ) continue;
        thicknes.push_back(max_size) ;
    }
    
    sort(all(thicknes)) ;
    cout << thicknes.front() << nl ;

}

signed main(){  FAST    TestCases    solve() ; }