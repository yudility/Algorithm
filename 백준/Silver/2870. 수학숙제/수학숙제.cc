#include <bits/stdc++.h>
using namespace std;

int n;
string s, ret;
vector<int> a;
vector<string> result;

void go(){
    while(true){
        if(ret.size() && ret.front() =='0') ret.erase(ret.begin());
        else break;
    }
    if(ret.size()==0) ret="0";
    result.push_back(ret);
    ret="";
}


bool cmp(string a, string b){
    if(a.size() == b.size()) return a< b;
    return a.size() < b.size();
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n ; 
    
    for(int i=0; i<n ; i++){

        cin >> s;
        ret= "";

        for(int j=0; j<s.size(); j++){
            if(s[j]<'a') ret+=s[j];
            else if( ret.size()) go(); //ret에 저장된게 남아있다면 숫자로 만들기(?) 함수 실행
        }
        if(ret.size()) go();
    }   
    sort(result.begin(), result.end(), cmp);
    for(auto v: result){
        cout<< v << "\n";
    }

    return 0;
}

