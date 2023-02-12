#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int n ;
int x ;

int sum(int line){

    if(line<=n) return (line*(line+1))/2 ;

    else if( line > n)
    {
        int t = line - n ;
        int a = n-1 ;
        int an = t ;

        int sm =  (t * ( 2*a  + (t-1)*(-1) ))/2 ;

        return (n*(n+1))/2 + sm ;
    }

    return  0 ;
}

bool isPoosible(int target){

    int t = target ;
    int s =  sum(target -1) ;

    if( x > sum(target-1) and x <= sum(target)  ) return 1 ;
    if( x > s  ) return 1 ;
    return 0 ;
}


signed main()
{
    FAST 

    t_case
    {
        n = 0 , x = 0 ; 
        cin >> n >> x ; 

        int l = 1 , r = 2*n-1 ;
        int ans = 0 ;

        if(x >= sum(2*n-1)){ cout << 2*n -1  << "\n" ; continue ;} 
  
        if(isPoosible(l)) ans = max(ans,l) ;
        if(isPoosible(r)) ans = max(ans,r) ;

        while (r-l>1)
        {
           int m = midpoint(l,r) ;
            if(isPoosible(m))
            {
                ans = max(m,ans) ;
                l = m ;
            }

            else 
            {
                r = m ;
            }
        }

        cout << ans << "\n";             
                                       
    }
}

