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

void print_line(int n ) ;
int M = 0 ;

void print_pattern_rev(int n)
{   
    n-- ;
    while (n>=0)
    {
        print_line(n) ; --n;
        cout << "\n" ;
    }
}


void print_line(int n){

    for(int i = 1  ; i <= M-n ; i++){ cout << " " << " " ;}

    if(n==0){ cout << 0 ; return ;} 
    for(int i = 0 ; i < n ; i++){ cout << i << " " ;}
    cout << n << " " ;
    for(int i = n-1 ; i >= 0 ; i--){if(i==0){ cout << 0 ; break ; } cout << i << " " ;}

} 


void print_pattern(int n){ 
    
    if(n<0) return ;
    
    print_pattern(n-1) ;    
    
    print_line(n) ;         cout << "\n" ;

    if(n==M){   
       print_pattern_rev(n) ;
    } 

    if(n==0) {return ;} 
}



signed main()
{
    FAST 
    int n ; cin >> n ;
    M = n  ;

    print_pattern(n) ;
    
}

