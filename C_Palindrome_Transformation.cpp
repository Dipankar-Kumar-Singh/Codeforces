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


void split_s( string &half , string &otherhalf , string s) ;
void split_s( string &half , string &otherhalf , string s) {
    
    int  n = s.length() ;

    if(n%2==0)
    {
            half = s.substr(0, s.length()/2);
            otherhalf = s.substr(s.length()/2);
    }

    else {
            half = s.substr(0, s.length()/2);
            otherhalf = s.substr(s.length()/2+1);
    }
    
}


void flip_p(int &p , int n){

    if(n&1)
    {
        int mid = n/2 ; 
        int dis = p - mid ;
        p =     mid - dis ;
    }

    else if(n%2==0)
    {
        int mid = n/2 ;
        int dis = (p-mid)+1 ;
        p = mid - dis ;

    }


}


int dis(char a , char b){
    
    if(a<b) swap(a,b) ; 

    int p1 = a - 'a' + 1    ;
    int p2 = b - 'a' + 1    ;

    // cout << "\na = " << a << "   b = " << b << "\n" ;
    // cout << "id(a) = " << p1 << "   id(b) = " << p2 << "\n" ;

    int path1 = abs(p1 - p2) ;
    int path2 = 26 - path1 ;

    // cout << "\npath 1 = " << path1 << "\n";
    // cout << "\npath 2 = " << path2 << "\n";
    

    return min(path1 , path2 ) ;
}

signed main()
{
    FAST 
    int n , p ; cin >> n >> p ; p-- ;
    string s ; cin >> s ; 

    string half , otherhalf ;

    split_s(half,otherhalf,s)   ;
    reverse(all(otherhalf))     ;

    if(half==otherhalf){cout << 0 ; return 0 ;}

    // cout <<  "1 half =  " << half << endl; 
    // cout <<  "2 half =  " << otherhalf << endl; 

    vector<int> flag ;

    for(int i = 0 ; i < half.length() ; i++){

        char c1 = half[i] ;
        char c2 = otherhalf[i] ;

        // cout << "\nc1 = " << c1 << "    c2 = " << c2 << "\n" ;

        if(c1!=c2)
        {
            // cout << "# c1 != c2 :   " << i <<  "\n" ; 
            flag.push_back(i) ;
        }
    }



    // cout << "Printing Flag vec : \n " ;
    // for(auto &x  :  flag ){  cout << x << " " ;  } 

    int start   = flag.front()  ;
    int end     = flag.back()   ;

    // if(start==end){ cout << dis(otherhalf[start] , half[start]) ; return 0 ;}

    // cout << "\n\n\nstart : " <<start << "  end : " << end ; 

    int vmoves = 0 ;

    for(int i = start ; i <= end ; i++ ){
        vmoves += dis(otherhalf[i] , half[i]) ;
    }           

    int hmoves = 0 ;

    // cout << "\nVertical Moves =  " << vmoves << "\n" ;

    if(n&1 and p == n/2 ) {p--; hmoves++;}
        
    // if(n%2==0 and p>= n/2){ p -= n/2 ;  }
    // if(n&1 and p > n/2){ p -= (n/2+1) ;} 

    if(n%2==0 and p>= n/2){ flip_p(p,n) ;  }
    if(n&1 and p > n/2){ flip_p(p,n) ;} 


    


    // cout << "\n\n p = " ;
    // cout << p << "\n"   ;


    
    if( ( p>=start ) and (p <= end) ) {
        // cout << "\n😂\n" ;
        int a =  p-start ;
        int b =  end-p   ;
        hmoves += min ( ( (2*b) + a), (b +  2*a)  ) ;
    } 

    else if(p<start) hmoves+= (end - p) ;

    else if(p>end) hmoves+= (p-start) ;

    // cout 
    // << "\nP = " << p 
    // << "\nHorizotnal moves = " << hmoves 
    // << "\nVertical Moves = " << vmoves << "\n" ;
    

    cout << hmoves + vmoves ;



    



}

/*
    5 --> 0 1      (2)    3 4
                    |
                 ( 5/2 )

    3 -->  0        1     2
                    |
                 ( 3/2 )

    6 -->   0 1 2    |      3 4 5 
    4 -->   0 1      |      2 3
    
    if(n==odd and pointer == n/2 ) {p--; horizontal_move++;}
    
    if(n==even and p>= n/2){ p - n/2 ;  }
    else if(n==even p<n/2) { p = p ;}


    if(n==odd and p > n/2){ p = p - (n/2+1)} ;
    else if(n==odd and p<n/2){ p = p ;}
*/

