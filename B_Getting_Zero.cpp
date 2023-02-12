#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int  const N = 32768 ;

int add(int n , int x )
{
    return ((n+x)%N) ;
}

bool mul(int n , int x)
{
    while (x--) n = (n * 2 )%N ;
    return n ; 
}

bool isPossible(int n , int target)
{
    for(int i = 0 ; i <= target ; i++)
    {
        int x = target - i ;
        int y = i ;

        int n1 = add(n,x) ; 
        n1 = mul(n1,y) ;

        if(n1 ==0 ) return 1 ;  

        swap(x,y) ;

        int n2 = mul(n,x) ;
        n2 = add(n2,y) ;
        
        if(n2==0)  return 1 ;
    }

    return 0 ;
}

void solve()
{
   int n ; cin >> n ; 

    for(int t = 0 ; t < 1000 ; t++)
    {
        if(isPossible(n,t))
        {
            cout << t << " " ;
            return ;
        }
    }   
}

signed main(){   FAST      TestCases    solve() ; }

