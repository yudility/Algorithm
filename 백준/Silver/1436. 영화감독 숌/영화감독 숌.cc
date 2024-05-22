#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main(){

    cin >> n;

    for(int i=666; ; i++){
        if(to_string(i).find("666") != string::npos){
            cnt++;   
        }
        if(n==cnt){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}