#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n {} ; cin >> n ;
    unordered_map<char,int> m ;

    string s ; cin >> s ; for(auto x : s ){m[x]++ ; }

   

    string final ; bool c = true ;
    for(auto &[x,y] : m){
        if(y%n!=0){ c = false ; cout << -1 ;  return 0 ;  }
        string ss ;
        for(int i = 0 ; i < y/n ; i++){
            ss.push_back(x) ;
        }

        final += ss ; 
    }

    
    for(int i = 0 ; i < n ; i++ ){
        cout << final  ;
    }

}

