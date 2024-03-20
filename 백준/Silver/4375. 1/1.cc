#include <bits/stdc++.h>

using namespace std;

int n;

int main(){

    while(true){
        int cnt = 0;

        cin >> n;
    
        if(cin.eof() == true) break;
        
        if(n==1 || n==11|| n == 111 || n == 1111){
            cnt++;
            n /= 10;
            while(n > 0){
                n /= 10;
                cnt++;
            }
            cout << cnt << "\n";
            continue;
        }


        int d = 10;
        cnt++;
        while(true){
            d = d % n;
            if(d==0){
                cout << cnt << "\n";
                break;
            }
            cnt++;
            d *=10;
            d +=10;
        }
    }
    return 0;
}