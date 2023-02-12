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
     
        int j = 0 ;

        int dip =  0 ;

        int k = 0 ;


        for(int i = 1 ; i < n ; i++)
        {
            if(s[i]<s[i-1]){  k++ ;}
            else break ;
        }

        for(int i = 1 ; i < n ; i++)
        {
            if(s[i]<s[i-1]){dip++ ; j++ ; }
            else if(s[i]==s[i-1] ){ j++ ;}
            else break ;
        }

        string min_s(s.begin(),s.begin()+j+1) ; 
        string min_b(s.begin(),s.begin()+k+1) ; 

        string tt ; tt+=min_b ;reverse(all(min_b)) ;
        tt+=min_b ;

        string a ; 

        a += min_s ;

        reverse(all(min_s)) ; a+= min_s ;

        // cout << a << "\n" ;

        string ans =  a ;

        // if(dip == 0)
        // {
        //     cout << ans << "\n" ;
        // }


        cout << min(a , tt) << "\n" ;

        

                                                            
                                       
    }

    vector<string> v ;
    v.push_back("cbaaaaba") , v.push_back("cbaaba") ;

    sort(all(v)) ;

    for(auto X : v) cerr << X << "\n" ;
}

