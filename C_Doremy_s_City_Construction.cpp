#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n; cin >> n ;
    vector<int> v(n) , vcopy;

    int allN = n ;

    for(auto &x : v) cin >> x ;
    multiset<int> s(all(v)) ;

    int flip = 1 ;
    int extra = 0 ;
    vector<int> vec ; 

    while (s.size())
    {
        if (flip == 1)
        {
            flip = 0 ;
            int x =  *s.begin() ;
            s.erase(s.begin()) ;
            vec.push_back(x) ;

        }
        else
        {
            flip  = 1 ;
            int y = *(--s.end());
            s.erase(--s.end()) ;
            vec.push_back(y) ;
        }
    }
    
    v = vec ;
    while( v.size() > 1 and v[v.size() - 1] == v[v.size() - 2])
    {
        extra++ ;
        v.pop_back();
    }

    int extraNumebr = -1 ;

    if(extra)
    {
        int extraNumebr = v.back() ;
        v.pop_back() ; extra++ ;
    }

    n = v.size() ;
    vector<int> res(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        int add = (n - (i + 3) + 1)/2 ;
        add = max(0LL,add) ;
        res[i] = add  ;
    }

    int byGoodChoice = accumulate(all(res),0LL)  + v.size() - 1;
    int byExtra = max(n / 2, n - (n / 2))*extra ;


    int ans = byGoodChoice + byExtra ;

    if(extra == allN )
    {
        cout << allN/2 << nl ;
        return ;
    }
    cout << ans << nl ;
}

signed main() { FAST TestCases solve(); }
