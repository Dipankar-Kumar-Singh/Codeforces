#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

char give(char c1 , char c2 , int k ){

    k-- ;

    for(int i = 0 ; i <= k ; i++){
        
        char c = 'A' + i ;
        if( c1 == c2 and c1 !=c) return c ;
        if(c1 != c and c2 !=c ) return c ;
        if(i==k){i=0;}
    }

    return 'A' ;
}


char give(char c1 , char c2 , char c3, int k ){

    k-- ;

    for(int i = 0 ; i <= k ; i++){
        
        char c = 'A' + i ;
        if( c1 == c2 and c3 == c2 and c1 !=c) return c ;
        if(c1 != c and c2 !=c and c3 !=c ) return c ;
        if(i==k){i=0;}
    }

    return 'A' ;
}

signed main()
{
    FAST 
    
    int n ,  k_limit ; cin >> n >> k_limit ;

    string s ; cin >> s ; 
    string ans ;
    int changes = 0 ;
    for(int i = 0 ; i + 1 < n  ; i++){

        if(s[i]==s[i+1])
        {   
            char cur = s[i] ;
            int len = 0 ;
            int k = i  ;

            for( ; k < n ; k++){
                if( s[k] == cur ) len++ ;
                else if( s[k] != s[i]  ){  ; break ;  }
            }

            k-- ;
           
            dbg(k,i,k,len) ;
        
            char f = s[i] , l = s[k] ; 
 
            cerr << "f = " << f << "     l = " << l << "\n" ; 

            if(len&1){
               // odd len --> change in middle ...

                for(int j = 0 ; j < len ; j++){
                    if( j&1 ) s[i+j] = give(s[i],s[i],k_limit) ;
                }

            }

            else 
            {

                char back_char = s[i], front_char = s[i];
                bool f_exist = 0 , b_exitst = 0 ;

                if(i-1>=0) { back_char = s[i-1] ; b_exitst =1 ; } 
                if(k+1<n) { front_char = s[k+1] ; f_exist = 1 ;}

                if(f_exist and b_exitst)
                {   
                    char c1  = give(s[i],back_char,k_limit) ;
                    char c2 = give(s[i],front_char,k_limit) ;

                    if(k_limit>2)
                    {  
                        for(int j = 0 ; j < len ; j++){
                            if( !(j%2==0) ) {s[i+j] = c1 ;}
                            dbg(j) ;
                        }
                    }

                    else if(k_limit<=2)
                    {
                        if(s[i]!='A' and s[i]!='B')
                        {
                            for(int j = 0 ; j < len ; j++)
                            {
                                if( (j%2==0) ) {s[i+j] = c1 ;}
                            }
                        }

                        else if(s[i]=='A' and back_char == 'B' )
                        {

                            for(int j = 0 ; j < len ; j++)
                            {
                                if( !(j%2==0) ) {s[i+j] = 'B' ;}
                            }
                        }

                        else if(s[i]=='B' and back_char == 'A')
                        {
                            for(int j = 0 ; j < len ; j++)
                            {
                                if( !(j%2==0) ) {s[i+j] = 'A' ;}
                            }
                        }

                        else if((s[i]=='A' or s[i]=='B') and back_char!='A' and back_char!='B' )
                        {
                            for(int j = 0 ; j < len ; j++)
                            {   
                                if( !(j%2==0) ) {s[i+j] = give(s[i],s[i],k_limit) ;}
                            }
                        }

            

                    }
                }

                else if(b_exitst and !f_exist)
                {

                    for(int j = 0 ; j < len ; j++)
                    {
                        if( j%2==0 ) s[i+j] = give(s[i],back_char,k_limit) ;
                    }

                }

                else if(f_exist and !b_exitst )
                {   
                    cerr << "🎉f_exist and !b_exitst\n" ;

                    if(!((s[i]=='A' and front_char=='B') or (s[i]=='B' and front_char=='A')))
                        for(int j = 0 ; j < len ; j++)
                        {
                            if( !(j%2==0) ) s[i+j] = give(s[i],front_char,k_limit) ;
                        }
                    // else if()
                }

                else if( !f_exist and !back_char )
                {
                    for(int j = 0 ; j < len ; j++)
                    {
                        if( j%2==0 ) s[i+j] = give(s[i],s[i],k_limit) ;
                    }
                }

            }

           i = k;
           changes += len/2 ;
        }
    } 

    cout << changes << "\n" << s ;          


}

