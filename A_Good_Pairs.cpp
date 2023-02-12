#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   
    int n ; cin >> n;
    vector<pair<int,int>> v(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        // int x ; cin >> x ;
        cin >> v[i].first ;
        v[i].second =  i ;
    }


    sort(all(v)) ;

    cout << v.front().second + 1 << " " <<  v.back().second+1  << "\n" ;



    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

