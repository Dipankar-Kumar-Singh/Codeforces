#include <bits/stdc++.h>
using namespace std;

string update_string(string str){

    for(auto &c : str) {
        if(c >= 'a' && c <= 'z') {
            int id = c - 'a' ;
            id++ ; id %= 26 ;
            c = 'a' + id ;
        } 
        else if(c >= 'A' && c <= 'Z'){
            int id = c - 'A' ;
            id++ ; id %= 26 ;
            c = 'A' + id ;
        }
    }

    return str ;
}


signed main()
{   
    string s; cin >> s ;
    cout << update_string(s) << endl ;

}
