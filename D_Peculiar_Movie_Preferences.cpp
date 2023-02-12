#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

string counterPart2(string s)
{
    string ans(s.begin() + 1 , s.end()) ; 
    reverse(all(ans)) ;
    return ans ;
}

bool counterPart3_present(string s , set<string> &st )
{
    reverse(all(s)) ;
    bool ans = 0 ;
    for(int i = 0 ; i < 26 ; i++)
    {
        char c = char('a' + i);
        string ss = s + c ;
        ans |= st.count(ss) ;
    }
    return ans ;
}
    

signed main()
{
    FAST 
    t_case
    {
        int n ; cin>> n ;
        set < string > s ;
        int pos = 0 ;

        for(int i =  0 ; i < n ; i++)
        {
            string s1 ; cin >> s1 ;

            string s2 = s1 ; reverse(all(s2)) ;

            pos |= (s1 == s2) or (s1.size() == 1) or s.count(s2) ;
            if(s1.size() == 3)
                pos |= (s.count(counterPart2(s1))) ;
            
            if(s1.size() == 2)
                pos |= (counterPart3_present(s1,s)) ;
        
            s.insert(s1) ;
        }

        cout << ( pos ?  "YES\n" : "NO\n" );                                                                           
    }
}

