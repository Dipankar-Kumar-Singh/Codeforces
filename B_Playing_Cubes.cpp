#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int red , blue ; cin >> red >> blue ;
    int a = max(red , blue) , b = min(red , blue) ;

    string s  ;

    // cout << "a = " << a << endl; cout << "b = " << b << endl;

    int sum  = a + b ;
    bool c = false ;

    // TODO  a --> 0  ; b --> 1

    if(a==b){
        if(a==1){cout << 0 << " " << 1 ; return 0 ;} 
        // cout << a << " " << b +1; return 0 ; 
        cout << a -1  << " " << b ; return 0 ; 
    }


    if(b==1){ 
        cout << a-1 << " " <<  1 ; return 0 ;
    }

    else {
        // if(!b&1)
        {
            int capsule = (b)/2 ;
            // int atLast = (a - (b-1) -1 )   ;
            // int inBtwa =  a - (capsule*2 -1 ) ;

            int same_b = b/2 ;
            int same_a = (capsule -1 +   (a -  (capsule*2-1)))  -1 ;


            int db = capsule*2 ;

            // cout << "\n(a -  (capsule*2-1)) = " << (a -  (capsule*2-1)) << "\n\n" ;
            cerr << "Capsule :  " << capsule << "\n\n" ; 

            // cout << "a : " << a << "\nb = " << b << "\nsame_a = " << same_a << "\nsame_b = " << same_b << "\n\n" ;

            // cout << b*2 -1 << " " << a - (b-1) -1 ; return 0 ;
            cout << same_a + same_b << " " << db ; return 0 ;
        }

        // else {

        // }

    }


   
    // cout << s << endl ;

    // int same = 0, differnt = 0;

    // for(int i = 0 ; i < s.size() -1 ; i ++ ){
    //     s[i] == s[i+1] ? same++ : differnt++ ;  
    // }

    // cout << same << " "  << differnt << endl ;
    


 
}
