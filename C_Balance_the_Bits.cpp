#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        
        int n ; cin >> n ;

        string s ; cin >> s ;

        string a  , b ;

        for(int i = 0 ; i < n ; i++)
        {
            a.push_back('?') , b.push_back('?') ;
        }


        if(n&1  or s.front() =='0' or s.back() == '0')
        {
            cout << "NO\n" ;
            continue ;
        } 

        int ct_zero = count(all(s),'0'); 
        int ct_one  = n - ct_zero ;

        if(ct_zero&1 or ct_one&1)
        {
            cout << "NO\n" ;
            continue ;
        }

        else cout << "YES\n" ;

        vector<int> ck(n) ;
 
        a.front() = '(' , a.back() = ')' ;

        for(int i = 1 ; i < n ; i++)
        {
            if(s[i] == s[i-1] and !ck[i-1])
            {
                a[i-1] = '(' ;
                a[i] = ')' ; 

                ck[i] = 1 ;
            }
        }

        int put = ')' ;

        for(auto &c : a)
        {
            if(c=='?'){
                c = put ;
                
                if(put == ')') put = '(' ;
                else put = ')' ;
            }
        }


        cerr << a << "\n" ;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i]=='0')
            {

                if(a[i]==')') b[i] = '(' ;
                else b[i] = ')' ;
            }

            else b[i] = a[i] ;
        }

        cout << a << "\n" << b << "\n" ;
     


                                  
                                        
                                       
    }
}

