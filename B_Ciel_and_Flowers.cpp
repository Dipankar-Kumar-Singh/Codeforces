#include <bits/stdc++.h>
using namespace std;

int A , B , C ;

bool check_two_plus_two(int a , int b , int c) {

    if((a+3 <= A) and (b+3 <= B) and (c+3 <= C)){
        a+=3 ; b+=3 ; c+=3 ;
    }

    bool c1 = a==3 and b==5 and c==5 ;
    bool c2 = b==3 and a==5 and c==5 ;
    bool c3 = c==3 and a==5 and b==5 ;

    if(c1 || c2 || c3){ return true ;}
    return false ;
};

bool check_one_plus_two(int a , int b , int c) {

    if((a+2 <= A) and (b+2 <= B) and (c+2 <= C)){
        a+=2 ; b+=2 ; c+=2 ;
    }

    bool c1 = a==2 and b==4 and c==4 ;
    bool c2 = b==2 and a==4 and c==4 ;
    bool c3 = c==2 and a==4 and b==4 ;

    if(c1 || c2 || c3){ return true ;}
    return false ;

};

int main(){
    int a,b,c;
    cin >> a >> b >>  c ;
    A = a ; B = b ; C = c ;

    int ans = min({a,b,c}) ;
    a-=max(0,ans) ; b-=max(0,ans) ; c-=max(0,ans) ;

    ans+=(a/3) ;
    ans+=(b/3) ;
    ans+=(c/3) ;

    a%=3 ; b%=3 ; c%=3 ;

    // cerr << "a : " << a << "     |   b : " << b << "   |    c : " << c ;

    if(check_one_plus_two(a,b,c) || check_two_plus_two(a,b,c)){
        cout << ans + 1 ; return 0 ;
    }

    cout << ans ;

}
