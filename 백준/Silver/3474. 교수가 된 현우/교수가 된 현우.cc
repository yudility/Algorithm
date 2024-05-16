#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//자연수 N이 주어지면 N!의 오른쪽 끝에 있는 0의 개수를 알려주기로 하였다.
// 첫째 줄에 테스트 케이스의 개수 T가 주어지고, 이어서 T개의 줄에 정수 N이 주어진다(1 <= N <= 1000000000).
// int도 안되고... long long도 안될 것 같은데?
// 2랑 5가 있으면 0이 나오는걸 이용해보자...

//1,000,000,000 10억...
//굳이 이렇게 안하고 곱해 나가면서 2나 5로 나누어지는 경우 나눈다음에 곱해도 되지 않을까?


int t, n;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> t;

    for(int i =0 ; i<t ; i++){

        cin >> n;
        int ct=0, cf=0;
        for( int j=2; j<=n; j*=2 ){
            ct += (n/j);
        }
        for( int j=5; j<=n; j*=5 ){
            cf += (n/j);
        }
        cout << min(cf, ct) << "\n";
    }

    return 0; 

}