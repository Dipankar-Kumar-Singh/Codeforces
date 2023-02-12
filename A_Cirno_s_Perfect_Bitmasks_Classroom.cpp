#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n ; cin >> n ;
    bitset<32> num = bitset<32>(n) ;

    bitset<32> ans = 0 ;
    int donot = 0 ;

    for(int i = 0 ; i < 32 ; i++)
    {
        if(num[i]==1)
        {
            ans[i] = 1 ;
            donot = i ;
            break;
        }
    }

    int result = num.to_ullong()^ans.to_ullong() ;
    
    if(result>0)
    {
        cout << ans.to_ullong() << nl ;
        return ;
    }

    else
    {
        for(int i = 0 ; i < 32 ; i++)
        {
            if(i==donot) continue;
            if(num[i]==0)
            {
                ans[i] = 1 ;
                break;
            }

            else if(num[i]==1)
            {
                ans[i] = 0 ;
                break;
            }
        }

        cout << ans.to_ullong() << nl ;
    }
   


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

