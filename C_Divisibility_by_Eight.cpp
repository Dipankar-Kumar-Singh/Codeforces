#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


string s ; 
int limit = 3 ; 

bool kp(int id , int used, string final){
    
    long long num = 1 ;
    if(!final.empty()) num = stoi(final) ;
    
    bool okay = num%8==0 ;

    if(id==s.size() and !okay) return 0 ;
    if(used > 3) return 0 ;
    
    if( okay and used>=1) 
    {   
        cout << "YES\n" ; 
        for(auto &x : final ) cout << x ;
        exit(0) ;
        return 1 ;
    }
    
    int curr = s[id]-'0' ;

    bool A  = 0 , B = 0 ;
    
    if(id<s.size()) 
    {
        A = kp(id+1, used , final) ;
        final.push_back(s[id]) ;
    }

    if(id + 1 <= s.size())
    {
        B = kp(id+1 , used+1 ,  final) ;
    }
    return (A or B)  ;
}

signed main()
{
    FAST 
    cin >> s ;
    string temp ;
    if(!kp(0,0,temp)) cout << "NO" ;
}

