#include <bits/stdc++.h>
using namespace std;

string s, ret;

int main(){


    getline(cin, s);

    for(int i=0; i < s.length() ; i++){

        if( s[i] <= 'Z' && s[i] >= 'A'){
            if((s[i]+13) > 'Z' ) 
                ret += (s[i]+13 - 26);
            else 
                ret += (s[i]+13);
        }
        else if(s[i]>='a' && s[i] <='z'){
            if((s[i]+13) > 'z') 
                ret += (s[i]+13 - 26);
            else 
                ret += (s[i]+13);
        }
        else{
            ret += s[i];
        }

    }
    cout << ret <<"\n";
    

    return 0;

}