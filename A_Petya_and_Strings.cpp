#include <bits/stdc++.h>
using namespace std; 
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void convert( string &s ){

    for(auto &x:s)
        if(isupper(x))  
            x  =  char(tolower(x)) ; 
    
}

signed main()
{
    FAST 
    string a , b  ; cin >> a >> b ; 
    convert(a) ; convert(b) ;

    if      (a>b)    cout << 1  ;
    else if (b>a)    cout << -1 ; 
    else if (a==b)   cout << 0 ;
   
}

