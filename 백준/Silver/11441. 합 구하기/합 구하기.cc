#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100001], psum[100001], x, y;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n ;
    for(int i=0; i<n ; i++){
        cin >> a[i+1];
        psum[i+1] = psum[i] + a[i+1];
    }

    cin >> m;
    for(int i =0; i <m; i ++){
        cin >> x >> y;
        cout << psum[y]-psum[x-1]<< "\n";
    }
    
     return 0;
}