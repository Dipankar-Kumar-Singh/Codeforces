#include <bits/stdc++.h>

using namespace std;




int main(){
    vector<pair<int,int>> v ;

    int s = 0; cin >> s ; int n ; cin>> n ;
    vector<int> a(n), b(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;  cin >> b[i] ; 
    }


    for(int i = 0 ; i < n ; i++){
        v.push_back({a[i],b[i]}) ;
    }

    sort(v.begin(),v.end(),
    [](pair<int,int> &a , pair<int,int> &b)
        { 
            if(a.first != b.first){ return a.first < b.first;}  
            else return a.second > b.second ;
        }
    );

    bool c = true ;
    for(int i = 0 ; i < n ; i++){
         if(s>v[i].first ){
             s+= v[i].second ;
         }    

         else {c = false ; break ; }   ; 
    }  

    if(c) cout << "YES" ; else cout << "NO" ;



}