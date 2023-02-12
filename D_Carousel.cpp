#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int flip(int color)
{
	return !color ;
}

void print(vector<int> color)
{
	cout << set<int>(all(color)).size() << nl ;
	for(auto x : color ) cout << x + 1 << " " ; cout << nl ;
}

void solve()
{
    int n;   cin >> n;
    vector<int> v(n);  for (auto &x : v) cin >> x;
    vector<int> c(n) ;
    
    if(set<int>(all(v)).size() == 1)
    {
            print(c) ;
            return ;
    }
    
    int prev = -1 ; 
    int color = 0 ;
    
    for(int i = 0 ; i < n ; i++)
    {
            if(v[i] != prev) color = flip(color) ;	
            c[i] = color ;
            prev = v[i] ;
    }
            
    if(c.front() == c.back() and v.front() != v.back())
    {
            int isSwitch = -1 ;
            for(int i = n - 1 ; i > 0 ; i--)
            {
                if(v[i] == v[i-1])
                {
                    isSwitch = i ;
                    break ;
                }
            }
            
            if(isSwitch == -1)
            {
                c.back() = 2 ;
            }
            
            else 
            {
                color = c[isSwitch] ;
                int prev = -1 ;
                for(int i = isSwitch ; i < n ; i++)
                {
                    if(v[i] != prev) color = flip(color) ;	
                    c[i] = color ;
                    prev = v[i] ;
                }  			
            }
    }
    
    print(c) ;
   
}
signed main(){   FAST      TestCases      solve() ;  }



