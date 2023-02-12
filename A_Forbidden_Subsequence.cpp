#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


bool is(string s , string t)
{   
    if(t.size()>s.size()) return 0 ;
    
    char p = t[0] ;
    int j = 0 ;
    int match = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(p == s[i])
        {
            match++ ; 
            j++  ;
            if(j>=t.size()){break;}
            p = t[j] ;
        }
    }

    return match == t.size() ;

}

signed main()
{
    FAST 




    t_case
    {
        
        string s , t ; 
        cin >> s  >> t ;

        string ans ;
        sort(all(s)) ;
        string tt  =  t ;
        sort(all(tt)) ;

        
        if(s.size()<3){ cout << s << "\n" ; continue ; }

        bool isA {0}, isB {0}, isC {0} ;

        for(auto &ch : s)
        {
            if(ch == 'a') isA =  1 ;
            if(ch == 'b') isB = 1 ;
            if(ch == 'c') isC =  1 ;
        }

        if( (!isA or !isB or !isC) ) 
        {
            cout << s << "\n" ;
            continue ;
        }

        if(tt==t){
            next_permutation(all(tt)) ;

        }

        string a , b , c ;





        for(char &x : s)
        {
            if(x == 'a') a.push_back(x) ;
            if(x == 'b') b.push_back(x) ;
            if( x== 'c' ) c.push_back(x) ;
        }


        for(char &x : tt)
        {
            if(x=='a')
            {
                for(auto &ch : a ) cout << ch ;

            }

            else if(x=='b')
            {
                for(auto &ch : b ) cout << ch ;

            }

            else  if(x=='c')
            {
                for(auto &ch : c ) cout << ch ;

            }

        }

        for(auto &m : s)
        {
            if(m == 'a' or m == 'b' or m == 'c') continue ;
            cout << m ;
        }

        cout << "\n" ;

                                         
                                       
    }
}

