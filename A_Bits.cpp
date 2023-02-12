
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


bool ispow2(int i) { return i && (i & -i) == i; }
int BIG = 1e18 ;

void sv(int l , int r )
{
    auto ll = bitset<60>(l);
    auto rr = bitset<60>(r);
    auto maskk = (ll & rr);

    int firstdiffer = -1 ;

    for(int i = 59 ; i >= 0 ;i--)
    {
        if(ll[i]==rr[i] and ll[i]==maskk[i]) continue;
        else
        {
            firstdiffer = i ;
            break ;
        }
    }

    bitset<60>  mask2 = 0 ;

    for(int i = firstdiffer - 1  ; i >= 0 ; i--)
    {
        mask2[i] = 1 ;
    }

    auto ans  = (mask2 | maskk) ;

    for(int i  = max(l,r-10) ; i <= r ; i++)
    {
        if(__popcount(r)>ans.count())
        {
            ans = bitset<60>(i) ;
        }
    }
    cout << ans.to_ullong() << nl ;

}


void solve()
{
	
	int l , r ; cin >> l >> r ; 

    if(ispow2(r+1)) 
    {
        cout << r << nl ;
        return ;
    }

    int leftmostbit = max(__bit_width(l) , __bit_width(r)) ;
    int w1 = __bit_width(l) ;
    int w2 = __bit_width(r) ;

    if(w1!=w2)
    {
        int ans = ((1LL<<leftmostbit-1)-1)  ;
        cout << ans << nl; 
        return ;
    }

    else
    {
        sv(l,r) ;
        return ;
    }

}

signed main(){   FAST      TestCases      solve() ;  }
