#include <bits/stdc++.h>
using namespace std;

int p[101];
int a, b, c, s, e, mi, mx;
int sum;

void count(int start, int end){
    for(int i=start; i<end; i++)
        p[i]++;
}

int main(){
    cin >> a >> b >> c;
    
    for(int i =0; i < 3 ; i++){
        cin >> s >> e;
        if(mi==0&&mx==0){
            mi=s;
            mx=e;
        }
        if(s<mi)mi=s;
        if(e>mx)mx=e;
        count(s, e);
    }
    
    for(int i=mi; i<=mx; i++){
        int cars = p[i];
        if(cars==1){
            sum+=a;
        }
        else if(cars==2){
            sum= sum+ b*2;
        }
        else if(cars==3){
            sum = sum+c*3;
        }
    }

    cout << sum;
    
    return 0;
}