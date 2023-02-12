#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
int n ;

// remove zero just after 1 from back ... 
int f(string &s){
    int fr = 0 ;
    for(int i = 0 ; i < n ; i++)
    {    
        if(s[i]=='1') fr++ ;
        else if(fr>=1 and s[i]=='0') return i ;
    }

    return  s.size() - 1  ;
}


void print(string &s , int id)
{
    for(int i = 0 ; i < n; i++)
    {
        if( i != id )
        {
            cout << s[i] ;
        }
    }

}

signed main()
{
    FAST 
    string s ; cin  >>  s ;
    n = s.size() ;
    int id = n-1 ;

    int one = count(all(s),'1') ;

    if(one == 0 or one == n ) 
    {    
        print(s,id) ;
        return 0 ; 
    }
    else if(one == 1 ){
        
        int id_of_one = find(all(s),'1') - s.begin() ;
        id = id_of_one ;
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='0'){ id = i ; break ;} 
        }
        print(s,id) ;
        return 0 ;
    }

    else 
    {
        id = f(s) ; 
        print(s,id) ;

    }
}

