#include<bits/stdc++.h>
using namespace std;

#define int long long 

int req_marks = 0 ; 

bool check(int n , int marks  , int avg){
    return (marks >= req_marks) ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , r , avg ; 
    cin >> n >> r >> avg ;

    int sum_of_marks{} ;

    vector<pair<int,int>> v(n) ;

    for(int i = 0 ; i < n ; i++){

        cin >> v[i].first  ; // ai  
        cin >> v[i].second ; // bi

        sum_of_marks += v[i].first ; 

    }


    sort(

        v.begin() , v.end() ,
        [](pair<int,int> &x , pair<int,int> &y)
        {   
            int b1 = x.second , b2 = y.second ;
            int a1 = x.first  , a2 = y.first  ;

            if(b1!=b2) return b1 < b2 ;
            else return a1 < a2 ;

        }

    );

    vector<int> prefix_limit(n+1,0),  x(n+1,0) , y(n+1,0) , b(n+1,0) ; 

    for(int i = 1 ; i <= n ; i ++){

        int ai =  (r - (v[i].first)) ;
        int bi = (v[i].second) ;
        b[i-1] = bi ;
        prefix_limit[i] = ai +  prefix_limit[i-1] ;
        x[i] = ai*bi  ;
        y[i] = y[i-1] + x[i] ;
    }

    req_marks = avg*n ;
  
    if(sum_of_marks>=req_marks){ cout << 0 ; return 0 ; } 
                               
    int essay {} ;

    for(int i = 0 ; i < n ; i ++){

        int old_marks = sum_of_marks ;
        int old_essay = essay ;
        
        int limit  = (r - v[i].first) ;
        int essayPerMarks = v[i].second  ; 
        int essy_req =  limit*essayPerMarks ;


        sum_of_marks += limit;

        essay += essy_req ;
        
        if(check(n,sum_of_marks,avg)){

            sum_of_marks = old_marks ;
            essay  = old_essay ;


           while(true){
            
                sum_of_marks ++ ;
                essay += essayPerMarks  ;

                if(check(n,sum_of_marks,avg)){
                    cout << essay ;
                    return 0 ;
                }
            }

        }
    }    

}
