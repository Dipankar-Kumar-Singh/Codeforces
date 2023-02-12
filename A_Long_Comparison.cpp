#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


void print(char c){
    if(c=='b'  ) cout << ">\n" ;
    else if(c=='s') cout << "<\n" ;
    else if(c=='e') cout << "=\n" ;
}


void comp_and_print(string s1 , string s2){

    if(s1 == s2) print('e') ;
    else if(s1 > s2) print('b') ;
    else if(s2>s1) print('s') ; 

}

signed main()
{
    FAST 
    t_case
    {   
        string s1 , s2 ;
        int x1 , p1 , x2 , p2 ; cin >> s1 >> p1 >> s2 >> p2  ;

        int d1 = s1.size() + p1 ;
        int d2 = s2.size() + p2 ;

        x1 = stoi(s1) , x2 = stoi(s2) ;

        if(d1>d2){
            print('b') ;
        }

        else if(d1 < d2 ) print('s') ;

        else if(d1==d2){

            if(p1 == p2)
            {
                comp_and_print(s1,s2) ;
            }

            else if(p1 > p2){

                int m = min(p1,p2) ;
                int append = p1 - m ;
                for(int i = 0 ; i < append ; i++) s1.push_back('0') ;
                //by this time s1 == s2 in size ;
                comp_and_print(s1,s2) ;

            }

            else if(p1 < p2 ){

                int m = min(p1,p2) ;
                int append = p2 - m ;
                for(int i = 0 ; i < append ; i++) s2.push_back('0') ;
                //by this time s1 == s2 in size ;
                comp_and_print(s1,s2) ;

            }
            
        }


        
        
                                  
                                        
                                       
    }
}

