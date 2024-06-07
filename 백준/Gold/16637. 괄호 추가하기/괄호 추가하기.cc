#include <bits/stdc++.h>
using namespace std;

int n, num;
int ret = -987654321;
char o;
vector<int> nums;
vector<char> opers;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int operate(char c, int a, int b ){
    if(c == '+') return a+b;
    else if(c == '-') return a-b;
    else if(c == '*') return a*b;
}

void go(int here, int sum){

    if(here == nums.size()-1){
        ret= max(ret, sum);
        return;
    }

    go(here+1, operate(opers[here], sum, nums[here+1]));
    if( here+2 <= nums.size()-1){
       int temp= operate(opers[here+1], nums[here+1], nums[here+2]);
       go(here+2, operate(opers[here], sum, temp));
        
    }
    return;
}


int main(){

    fastIO();

    cin >> n; 

    for(int i=0; i<n; i++){
        if(i%2==0) {
            cin >> num;
            nums.push_back(num);
        }
        else if(i%2==1) {
            cin >> o;
            opers.push_back(o);
        }
    }

    go(0,nums[0]);

    cout << ret <<"\n";

    return 0;
    
    
}