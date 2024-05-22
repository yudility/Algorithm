#include <bits/stdc++.h>
using namespace std;

//첫째줄: 골이 들어간 횟수 N(1<=N<=100)
//둘째줄부터 N개의 줄에 득점 정보
//득점 정보는 득점한 팀의 번호와 득점한 시간
//팀 번호는 1 또는 2

//분은 0보다 크거나 같고, 47보다 작거나 같으며, 초는 0보다 크거나 같고, 59보다 작거나 같다. 득점 시간이 겹치는 경우는 없다.

//첫째 줄에 1번 팀이 이기고 있던 시간, 둘째 줄에 2번 팀이 이기고 있던 시간을 출력한다. 시간은 입력과 같은 형식(MM:SS)으로 출력한다.

//팀 번호 / 득점한 시간
//이기고 있던 시간을 담을 곳
//팀 번호 별 득점 수 담을 곳

string s; 
int a, b, n, t;
int asum, bsum, prevs;

int changeStringToInt(string str);

void go(int &sum, string s);

string changeIntToSring(int sum);

int main(){
    
    cin >> n;

    for(int i=0; i<n; i++){
        
        cin >> t >> s;
        if(a > b) go(asum, s);
        else if( a < b) go(bsum, s);
        
        t == 1? a++: b++;
        prevs = changeStringToInt(s);
    }

    if(a > b) go(asum, "48:00");
    else if( a < b) go(bsum, "48:00");

    cout << changeIntToSring(asum) << "\n";
    cout << changeIntToSring(bsum) << "\n";

    return 0;
}

int changeStringToInt(string str){

    int min= atoi(str.substr(0,2).c_str());
    int sec= atoi(str.substr(str.size()-2, 2).c_str());

    return min*60+sec;
}

void go(int &sum, string s){   
    sum += (changeStringToInt(s) - prevs);
}

string changeIntToSring(int sum){
    
    string mins = "00"+to_string(sum/60);
    string secs = "00"+to_string(sum%60);

    return mins.substr(mins.size()-2, 2)+":"+secs.substr(secs.size()-2, 2);
}