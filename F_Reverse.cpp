#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


string trim_f(string s)
{
    reverse(s.begin(),s.end()) ;

    while(s.back() == '0') s.pop_back() ;

    reverse(s.begin(),s.end()) ;

    return s ;

}

set<string> memo ;

bool ans = 0 ;
string to_reach ;

void dfs(string s)
{   
    s = trim_f(s) ;

    if(memo.count(s)) { return ;}
    memo.insert(s) ;
    if(s.size()>100) {return ;}

    // was getting Wrong answer due to this ceck s in t case .
    // string rs = s ; reverse(all(rs)) ; rs = trim_f(rs) ;
    
    // if  (   
    //         (to_reach.find(s) == string::npos)  
    //                         and 
    //         (to_reach.find(rs) == string::npos)
    //     )
    //     {return ;} 



    if(s == to_reach)
    {
        cout << "YES" ; 
        exit(0) ;
    }

    string s1 , s2 ;

    s1 = s + '0' ;  
    s2 = s + '1' ;

    reverse(all(s1)) , reverse(all(s2)) ;
    dfs(s1) ; dfs(s2) ;

}


signed main()
{

    int x_num {} , y_num{} ; 
    cin >> x_num >> y_num;


    string x = bitset<100>(x_num).to_string() ;
    string y = bitset<100>(y_num).to_string() ;

    x = trim_f(x) , y = trim_f(y) ;

    cerr << x << " \n" << y << "\n";


    to_reach = y ;

    if(x == to_reach){ cout << "YES" ; exit(0) ; }
    dfs(x) ;

    if(ans) cout << "YES\n" ; 
    
    cout << "NO"  ;
 


}