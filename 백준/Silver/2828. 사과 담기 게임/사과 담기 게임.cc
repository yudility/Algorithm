#include <bits/stdc++.h>
using namespace std;

int n, m, j, a, p, ret; //a 사과 떨어지는 위치, p 바구니 위치, m 바구니 사이즈

int main(){
    cin.tie(NULL);
    cin >> n >> m; 
    cin >> j;
    p = 1;

    for(int i = 0; i<j ; i++){
        cin >> a; //사과 위치 받기

        if(p<=a && (p+m-1)>=a){
            continue; 
        }
        else if((p+m-1)<a){
            for(int k=p; k<=n-m+1 ; k++){
                if((p+m-1)>=a){
                    break;
                }else{
                    p++;
                    ret++;
                }

            }
        }
        else if(a<p){
             for(int k=p; k>0 ; k--){
                if(p<=a){
                    break;
                }else{
                    p--;
                    ret++;
                }
            }
        }
    }

    cout << ret << "\n";

    return 0;
    
}