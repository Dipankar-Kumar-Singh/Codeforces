#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v ;


bool check(vector<int> c){

    for(int i = 0 ; i < c.size() ; i++){

        // req of every ind element ..... 
        
    }

}


bool isPossible(int target){

    vector<int> heap [target] ;
    int point = 0 ; 

    vector<pair<int,int>> temp ;
    for(int i = target; i < v.size() ; i++){
        temp.push_back(v[i]) ;
    }

    sort(temp.begin(),temp.end()) ;

    stack<pair<int,int>> s  ; for(auto &x:temp) s.push(x) ;

    while (!s.empty())
    {
        auto e = s.top() ;
        s.pop() ;
        heap[point].push_back(e.first) ;  
        point++ ;
        if(point>=target)  point%= (target ) ;    
    }
    
    for( int i = 0 ;  i < target ; i++){

       if( !check( heap[i] ) ) return false ;

    }

} ;


int main(){


   
    int n  ; cin >> n ; 
    v.resize(n) ; 
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].first ; 
        v[i].second = i ;
    }

    sort(v.begin(),v.end()) ;
    reverse(v.begin(),v.end()) ;

    // for(int &x:v) cout << x << " " ; 



    

    


}