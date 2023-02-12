#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int n , l , kk ;

map<pair<int,int>,int> dp ;

int kp(int i , int k , int time ,  vector<int> &d , vector<int> &a , int prev_speed)
{
    if(i==n) return time ;
    if(i==0)
    {
        return kp(i+1 , k , a[0]*(d[1]-d[0]),d,a,a[0]) ;

    }

    if(dp[{i,k}]) return dp[{i,k}] ;
    
    int len = 0 ;
    if(i<n-1)
    {
        len = d[i+1] - d[i] ;
    }

    if(i==n-1)
    {
        len = l - d[i] ;
    }

    int this_ans = INF ;

    int cur_speed  = a[i] ;

    int time_after_removing_cur_flag  = time+ len*prev_speed ;
    int time_after_not_removing_cur_flag  = time + len*cur_speed ;

    int &t1 = time_after_removing_cur_flag ;
    int &t2 = time_after_not_removing_cur_flag ;

    if(k>0)
    {
        int choiceA  = kp(i+1 , k-1 , t1 , d,  a , prev_speed ) ;
        int choiceB  = kp(i+1 , k   , t2   , d , a , cur_speed ) ;
        this_ans = min(choiceA,choiceB) ;
    }

    int choiceB  = kp(i+1 , k , t2  , d , a , cur_speed) ;

    this_ans = min(this_ans,choiceB) ;
    
    return dp[{i,k}] = this_ans ;
   
}

signed main()
{
    FAST 
    cin >> n >> l >> kk ;
   
    vector<int> d (n) ; for(auto &x : d) cin >> x ; 
    vector<int> a (n) ; for(auto &x : a) cin >> x ; 

    int start = a[0]*(d[1]-d[0]) ;

    if(n==1 or kk>=n-1)
    {
       cout << a.front() * l ; return 0 ;
    }

                                  
    // cout <<  a[0]*(d[1]-d[0]) +  kp(1,kk,0,d,a,a.front()) ;            
    cout <<               kp(0,kk,0,d,a,a.front()) ;  
                                       
    
}

