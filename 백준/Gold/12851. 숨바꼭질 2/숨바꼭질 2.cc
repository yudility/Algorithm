#include <bits/stdc++.h>
using namespace std;

const int MAX = 100004;
int n, k, here;
int w[100004], visitied[100004];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visitied[n] = 1;
    w[n] = 1;

    while(q.size()){
        here = q.front();
        q.pop();

        for(int i=0; i<3; i++){
            int there;
            if(i==0)there = here+1;
            if(i==1) there = here-1;
            if(i==2) there = here*2;

            if(there < 0 || there >= MAX) continue;

            if(visitied[there] == visitied[here]+1){
                w[there] += w[here];
            }
            else if (visitied[there]==0)
            {
                visitied[there] = visitied[here]+1;
                w[there] += w[here];
                q.push(there);
            }
        }

    }

    cout << visitied[k]-1 << "\n" << w[k] << "\n";

}