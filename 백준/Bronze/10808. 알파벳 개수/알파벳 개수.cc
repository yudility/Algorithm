#include <bits/stdc++.h>
using namespace std;

string s;
int a[26];

int main(){
    cin >> s;

    for(int i=0; i<s.length(); i++){
        a[(int)s[i]-97] +=1;
    }

    for(int i=0; i<26; i++){
        cout << a[i] << " ";
    }

    return 0;
}