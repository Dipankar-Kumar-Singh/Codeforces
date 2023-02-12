#include<bits/stdc++.h>
using namespace std ; 

#ifdef LOCAL
#include"/home/dk/Code/debug/debugging.h"
#else 
#define dbg(...) 42
#endif


string manacher(string s){

    int n = s.length();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
 
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }

    // D1 --> OLD LEN [ Center at Current Index ] 
    /// D2 --> Even Len [  A , B  , this(B) , A ] ===>  d2[this] =  2
    // MAX PREFIX THAT IS A PALINDROME ... 

    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\t Index " << i << "\n" ;
        cout << "c = " << s[i] << " d1 = " << d1[i] <<  "\n" ;
        cout << "c = " << s[i] << " d2 = " << d2[i] <<  "\n\n"  ;

        if (d1[i] == i + 1)
            maxi = max(2 * i + 1, maxi);
        if (d2[i] == i)
            maxi = max(2 * i, maxi);
    }
    return s.substr(0,maxi);
 
}

string solve_palindrome(const string &s)
{
    // String == > pipthis ==> will return maxLen palandrome starting with first character ..
    // Longest Lenghth Palandrome from start ..
    string a = s;
    vector<int> pref(2 * s.size() + 1000);
    int c = 0 ;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])  c = pref[c - 1];
        if (a[c] == a[i]) c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}


int main()
{

    // BOTH GIVING THE SAME OUTPUT ..
    // string s = "ddiioojooiidd36546" ;
    string s = "mDDm" ;

    for(int i = 0 ; i < s.size() ; i++)
    {
        cout << s[i] << " " ;
    }

    cout << endl ;

    for(int i = 0 ; i < s.size() ; i++)
    {
        cout << i << " " ;
    }

    cout << endl ;
    

    // cout << solve_palindrome(s) << endl ;
    cout << manacher(s) << endl ; 

}