#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


bool isLucky(int n)
{   
    if(n==0) return 0 ;

    while(n!=0){
        int x = n%10 ;
        n/=10 ;
        if(x==7 or x==4){}
        else return 0 ;
    }

    return 1 ;
}


bool is_Nearly_Lucky(int n)
{
    int count = 0 ;

    while (n!=0)
    {
        int x = n%10 ; n/=10 ;

        if(x==7 or x==4){ count++ ;}

    }

    return isLucky(count) ;
}

signed main()
{
    FAST 
    int n ; cin >> n ; 
    cout << ( is_Nearly_Lucky(n) ? "YES" : "NO" ) ;
}

