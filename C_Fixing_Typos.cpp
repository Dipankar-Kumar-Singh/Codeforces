#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


char curr ;
int ct = 0 ;

signed main()
{
    FAST 
    string s ; cin >> s ;
    string a ;
    curr = s[0] ;
    a.push_back(curr) ;

    for(int i = 1 ; i < s.size(); i++){

        if(a.back()==s[i]){ct++ ;}
        if(a.back()==s[i] and ct<=1){
            a.push_back(s[i]) ;
            continue ;
        }
        else if(a.back()==s[i] and ct>1){continue ;}

        else if(a.back()!=s[i]){ct=0 ;}

        a.push_back(s[i]) ;
    }

    bool flag = true ;
    ct =  0 ;

    string ans  ;
    vector<int> v(s.size()+1 ,0 ) ;



    for(int i = 0 ; i < a.size() ; i++){

        char x = a[i] ;
        char y = ans.back() ;

        if(x!=y){
            ans.push_back(x) ;
            v[i] = 1;
        }

        if(x==y){

            if(v[i-2] == 2){ v[i] = 1 ;continue;}


            ans.push_back(x) ;
            v[i-1] = v[i] = 2 ;
        }
    }

    cout << ans ;

}

