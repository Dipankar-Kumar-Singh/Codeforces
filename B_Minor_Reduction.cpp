#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;


void print(string s , int a)
{
    int i = a ;
    int j = 0 ; 

    for(int k = 0 ; k < a ; k++)  cout << s[k] ;

    int n = (s[i]-'0' ) + (s[i+1] -'0') ; 
    cout << n ;
    for(int k = i + 2 ; k < s.size() ; k++) cout << s[k] ;
    cout << nl ; 

}

signed main()
{
    FAST 
    t_case
    {
        
       string s ;
       cin >>  s ;

        if(s.size()==2)
        {
            cout << (s.front()- '0') + (s.back() -'0')  << nl ;
            continue ;
        } 


        vector<int> two_to_two , two_to_one ;
        
        int a{-1} , b{INF} ;
        // a --> left most pos of two -> two 
        // b -> right most pos of two --> one

        for(int i = 0 ; i + 1< s.size() ; i++)
        {
            int c1 = s[i]-'0' ;
            int c2 = s[i+1] -'0' ;

            int n = c1 + c2 ;

            if(n/10 == 1)
            {
                two_to_two.push_back(i) ;
                a = i ;
            }

            else if(n/10 == 0)
            {
                b = min(i,b) ;
            }
        }

        int  k = 0 ;
        if(a != - 1) { k = a  ;} else k = b ;

        print(s,k) ;
                      
                                       
    }
}

