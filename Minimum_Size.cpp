
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


vector<int> a , b , pa, pb;
int p ;

bool isPossible(int len )
{
	int s1 = pa[len] ;
	int s2 = pb[len] ;

	int n = a.size() , m = b.size() ;
	int ma = -1 , mb = -1 ;	
	for(int i = len-1 ; i < n  ;i++)
	{
			if( i- len >= 0 )
			{
				s1 -= a[i-len] ;
				s1 += a[i] ;
			}
			
			ma = max(s1,ma) ;
	}
	
	for(int i = len-1 ; i < m  ;i++)
	{
			if( i- len >= 0 )
			{
				s2 -= b[i-len] ;
				s2 += b[i] ;
			}
			
			mb = max(s2,mb) ;
	}
	
	return (ma*mb>=p) ;
	
}
 

void solve()
{
    int n , m ; cin >> n >> m ;
    p = 0 ;
	a.clear() , b.clear() , pa.clear() , pb.clear() ; 
	a.resize(n) , b.resize(m) , pa.resize(n+1,0) , pb.resize(m+1,0);

    for(auto &x : a ) cin >> x ;
    for(auto &x : b ) cin >> x ;
    
    for(int i  = 0 ; i < n ; i++)  pa[i+1] = pa[i] + a[i]  ;
    for(int i = 0  ; i < m ; i++)  pb[i+1] = pb[i] + b[i] ; 

    cin >> p ;
    int l = 0  , r = min(n,m) + 1; 
   
    while(r-l>1)
    {
        int mid = (l+r)/2 ;
        if(isPossible(mid)) r = mid ;
        else l = mid ;
    }
    
    cout << r << nl; 
   

}

signed main()
{   FAST  

    TestCases  
    solve() ;  
}

