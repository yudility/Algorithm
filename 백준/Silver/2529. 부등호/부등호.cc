#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> result;
vector<char> nums={'0','1','2','3','4','5','6','7','8','9'};
int k;
vector<char> b;
char c;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

bool go(char bu, char l, char r){

    // int left=atoi(l.c_str());
    // int right=atoi(r.c_str());

    if(bu == '<'){
        return l<r;    
    }
    else if( bu == '>'){
        return l>r;
    }

}

int main(){

    fastIO();

    cin >> k;

    for(int i=0; i<k; i++){
        cin >> c;
        b.push_back(c);
    }

    do{
        //만들어진 순열 부등호에 넣어서 비교
        //모두 통과했다면, (부등호 결과가 모두 참이라면)-> result 에 해당 순열 string으로 바꿔서 저장하기

        bool flag=1;
        for(int i=0; i<k; i++){
            flag = go(b[i], nums[i], nums[i+1]); 
            if(!flag) break;
        }

        if(flag){
            string ret="";
            for(int i=0; i<k+1; i++) ret+=nums[i];
            result.push_back(ret);
        }

    }while(next_permutation(nums.begin(), nums.end()));

    //result sort하고
    //첫번째와 마지막 string으로 출력하기

    sort(result.begin(), result.end());

    cout << result.back() << "\n";
    cout << result.front() << "\n";


    return 0;
}