//성의 첫글자가 같은 선수 5명선발
//만약 5명 없다면 기권
// 선수의 수 N
// 입력범위 : 1~ 150
// 소문자로만, 최대 30글자
// 선발할 수 있는 경우 가능한 성의 첫글자를 사전순 공백없이 모두 출력
// 선발 x 경우 PREDAJA 출력

#include <bits/stdc++.h>
using namespace std;

int N, Pre;
int alpa[26];
string s;

int main(){
    cin.tie(NULL);

    cin >> N ;
    
    for(int i=0; i<N; i++){
        cin >> s;
        alpa[s[0] -97]++;  
    }

    for(int i=0; i<26 ; i++){
        if(alpa[i]>=5){
            Pre = 1;
            cout << (char)(i+97); 
        }
    }
    if(Pre==0)
        cout << "PREDAJA" << "\n";
    
    return 0;
}