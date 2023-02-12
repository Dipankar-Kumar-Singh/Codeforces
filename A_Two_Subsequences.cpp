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


signed main()
{
    FAST 
    t_case
    {
        string s ; 
        string a , b ;
        cin >> s ;

        string ss = s ; sort(all(ss)) ; 
        a.push_back(ss[0]) ; 

        int ct = 1 ;

        for(int i = 0 ; i < s.size() ;i++){

            if(ct==1 and s[i]==ss[0]){ct++ ; continue ;} 
            b.push_back(s[i]) ;

        } 


        cout << a << " " << b << "\n" ;

        
        
                                  
                                        
                                       
    }
}

