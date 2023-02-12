#include <bits/stdc++.h>
using namespace std;
#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


bool isGood(vector<int> &v)
{
    for(int i = 0 ; i + 1< v.size() ; i++)
    {
        if(v[i+1] - v[i] < 0 ) return 0 ;
    }

    return 1 ;
}

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(int &i : v ) cin >> i ; 

    if(isGood(v)) 
    {
        cout << 0 << "\n" ;
        return ;
    }

    if(v.back() < v[n-2] )
    {
        cout << "-1\n" ;
        return ;
    }

    vector<tuple<int,int,int>> ans ;

    for(int i = n-3 ; i >= 0 ; i--)
    {
        int &next = v[i+1] ;
        int &now = v[i] ;

        int z = (v[n-1] - next) ;

        int req = min(now,next) ;

        now = -(v[n-1] - v[i+1]) ;
        ans.push_back({i,i+1,n-1}) ;

        if(now > next)
        {
            cout << -1 << "\n" ;
            return ;
        }
    }


    cout << ans.size() << nl ;

    for(auto &[i,x,y]:ans)
    {
        cout << i + 1  << " " << x + 1 << " " << y + 1 << nl ; 
    }

}

signed main()
{
    FAST 
    t_case
    {
     
        solve() ;

                                       
    }
}

