#include <bits/stdc++.h>
using namespace std;

// 분할정복


int n; // 0 < n < 65
int a[70][70]; 
string s;

string divCon(int y, int x, int size){
    if(size == 1) return string(1, a[y][x]);

    char b = a[y][x];
    string ret ="";
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j ++){
            if(b != a[i][j]){
                ret += "(";
                ret += divCon(y, x, size/2) ; // 죄측 위
                ret += divCon(y, x+size/2, size/2); // 우측 위
                ret += divCon(y+size/2, x, size/2); // 좌측 아래 
                ret += divCon(y+size/2, x+size/2, size/2); // 우측 아래
                ret += ")";
                return ret;
            }
        }
    }
    return string(1,a[y][x]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >>  n; 
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            a[i][j] = s[j];
        }
    }
    cout << divCon(0, 0, n) << "\n";

    return 0;
}