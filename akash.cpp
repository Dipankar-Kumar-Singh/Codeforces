#include <bits/stdc++.h>
using namespace std;
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

int decimalToOctal(int decimalNumber);

void solve(){

    string s;
    cin >> s ;

    int sum = 0 ;

    for(auto& c : s){
        c = toupper(c) ;
        auto r = toascii(c) ;
        sum += __builtin_popcount(r) ;
    }

    sum %= 26 ;

    for(auto &c : s){
        c = c + sum ;
        if(c > 90){
            c %= 91 ;
            c += 65 ;
        }
    }

    int octSum = decimalToOctal(sum) ;
    string prefix = to_string(octSum) ;

    string ans = prefix + s ; 

    cout << ans << nl ;


}

int main()
{
    solve() ;
    
  
}

// Function to convert decimal number to octal
int decimalToOctal(int num)
{
    int rem, i = 1, res = 0;
    while (num != 0)
    {
        rem = num % 8;
        num /= 8;
        res += rem * i;
        i *= 10;
    }
    return res;
}