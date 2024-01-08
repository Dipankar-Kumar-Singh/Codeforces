/* 
            ~~~~~~~~~~~~{ after 1 Year of Pause, I am back : ) }~~~~~~~~~~ 
    I will fall .... Yep free fall  : ) .... I will go up again ! ... 
    Always proud of my efforts in past - 2nd Year(Start of cp) -- 3rd Year(till 1st sem)
    Last 6 month of college ... want to look back and smile : ) , No Regret 
*/

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
#include"/home/dk/debugging.h"

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); 
int gen(int l, int r) {
    return l + rng() % (r - l + 1);
}

int cal(vector<int> v)
{
    int ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] < v[i])
            ans++;
    }
    return ans;
}

pair<vector<int>,vector<int>> check_MINE(vector<int>);
pair<vector<int>,vector<int>>  check_CORRECT(vector<int>);

void solve(int& __case__)
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    auto [a1 , b1] = check_CORRECT(v)  ;
    auto [a2 , b2] = check_MINE(v)  ;

    int r1 = cal(a1) + cal(b1) ;
    int r2 = cal(a2) + cal(b2) ;

    dbg(r1,r2) ;

    if (cal(a1) + cal(b1) < cal(a2) + cal(b2))
    {   
        cerr << "WRONG ANS ❤️‍🔥❤️‍🔥❤️‍🔥❤️‍🔥\n\n" ;
        cerr << "correct / ✅ ::::::::::::::\n" ;

        dbg(a1) dbg(b1) ;
        cerr << nl ;
        cerr << "wrong / mine ❌ ::::::::::::::\n" ;
        dbg(a2) dbg(b2) ;
    }

    cerr << nl << nl ;
}


pair<vector<int>,vector<int>>  check_MINE(vector<int> v) {
    int n = v.size() ;
    int const N = 1e8 ;
    vector<int> a {N} , b {N} ;

    for(int x : v) {

        if( x <= (int)min(a.back(),b.back()) ){
            (a.back() <= b.back() ?  a : b ).push_back(x) ;
            continue;
        }

        if(a.back() >= x) {
            a.push_back(x) ;
        } else if( b.back() >= x ) {
            b.push_back(x) ;
        } else {
            (a.back() <= b.back() ?  a : b ).push_back(x) ;
        }
    }

    return pair{a,b} ;
}

pair<vector<int>,vector<int>>  check_CORRECT(vector<int> v){
    int n = v.size() ;

    vector<pair<vector<int> ,vector<int>>> candidates ;

    function<void(int, vector<int>, vector<int>)> dfs = [&](int id, vector<int> a, vector<int> b) {
            if(id == n ) {
                candidates.push_back({a,b}) ;
                return ;
            }
            a.push_back(v[id]) ;
            dfs(id + 1 , a , b ) ;
            a.pop_back() ;
            b.push_back(v[id]) ;
            dfs(id + 1 , a , b );
            b.pop_back() ;
        };

    vector<int> a , b ;

    dfs(0,a,b) ;
    a.clear() ;  b.clear() ;

    int ans = 1e10 ;

    for(auto [aa,bb] : candidates){
        if(cal(aa) + cal(bb) < ans ) {
            a = aa ; 
            b = bb ;
            ans = min(ans  , cal(aa) + cal(bb)) ;
        } ;
    }

    return pair{a,b} ;   
}

void g(){
    int n = gen(0,20) ;
    vector<int> v(n) ;
    for(auto &x : v) {
        x = gen(0,100) ;
    } 

    cout << n << nl ;
    for(auto x : v) {
        cout << x << " " ; 
    } cout << nl ;
}


signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    g() ;
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

/*
            ██████╗ ██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ ██████╗ 
            ██╔══██╗██║██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝██╔══██╗██╔══██╗
            ██║  ██║██║██████╔╝███████║██╔██╗ ██║█████╔╝ ███████║██████╔╝
            ██║  ██║██║██╔═══╝ ██╔══██║██║╚██╗██║██╔═██╗ ██╔══██║██╔══██╗
            ██████╔╝██║██║     ██║  ██║██║ ╚████║██║  ██╗██║  ██║██║  ██║
            ╚═════╝ ╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
*/                                                          
