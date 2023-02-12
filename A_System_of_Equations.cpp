#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   


}

signed main()
{   FAST  

    int n,m ; cin >> n >> m ;
    vector<int> v ;
    for(int i = 0 ; i < 33 ; i++)
    {
        v.push_back(i) ;
    }

    int ans =  0; 

    for(auto a : v) 
    {
        if(a + (n-(a*a))*(n-(a*a)) == m)
        {
            if (a >= 0 and n-(a*a)>= 0)
                ans++;
        }
    }

    cout << ans << nl ;

}

