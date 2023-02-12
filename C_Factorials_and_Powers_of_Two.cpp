#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int const MAX = 1e12 + 10 ;
set<pair<int,int>> s ;

void dfs( int id , int sm , int taken ,vector<int> &v )
{
    if(id>=v.size())
    {
        s.insert({sm,taken}) ;
        return ;
    }

    if(sm>=MAX){
        s.insert({sm,taken}) ;
        return ;
    }

    dfs(id+1,sm,taken,v) ;
    taken++ ;
    sm += v[id] ;
    dfs(id+1,sm+v[id],taken+1,v) ;
}


void solve()
{
    int n ; cin >> n ;

    int mn = LONG_LONG_MAX ;
  

    for(auto [sm,num] : s)
    {
        int m = n - sm ; 
        if(m<0) break; 

        cerr <<  "sm = " <<  sm << " \n" ;

        mn = min( ( __popcount(m) + num) , mn ) ;
    }


    cerr << "-----------------\n\n\n" ;
    cout << mn << "\n" ;
    
}


signed main()
{   FAST  


    vector<int> v ;
    int ff = 1 ; 
    for(int i = 1 ; i <  17 ; i++)
    {
        ff *= i ;
        if(ff<=MAX) v.push_back(ff) ;
    }

    cout << " --->>> " << v.back() << "\n" ;

    dfs(0,0,0,v) ;

    TestCases  
    solve() ; 








}

