#include <bits/stdc++.h>
using namespace std;
//범위 100 , 100
//JOI시는 남북방향이 H 킬로미터, 동서방향이 W 킬로미터인 직사각형 모양
//높이 H, 폭 W인 직사각형 모양, 각각 1km*1km의 구역들
//위에서부터 i, 왼쪽에서부터 j -> (i,j)

//각 구역의 하늘 구름 있을 수도 없을수도 있음
//모든 구름은 1분이 지날때 1킬로씩 동쪽으로 이동
// 구름은 외부에서 오는 경우 없음

//각 구역, 몇분뒤 처음으로 하늘에 구름이 오는지 예측
//구름 C / 맑음 .

//처음부터 구름이 떠있으면 -> 0 
//몇분이 지나도 구름이 뜨지 않을 경우 -1

int h, w; // h 높이, w 폭, t분뒤 구름 옴
string s; //한 줄씩 입력 받기 위함
int ret[104][104]; //출력 할 곳

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    
    fill(&ret[0][0], &ret[103][104], -1);

    for(int i=0; i<h; i++){
        cin >> s; //각 행을 입력받고
        bool isC=false;
        for(int j=0; j<w; j++){
            if(s[j]=='c'){
                isC=true;
                ret[i][j]=0;
            }
            else if(isC==true) ret[i][j]= ret[i][j-1]+1;
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w ;j++){
            cout << ret[i][j] << " ";
        }
        cout<< "\n";
    }
}