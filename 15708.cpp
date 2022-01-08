#include <bits/stdc++.h>
using namespace std;
int T,N,P,ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>T>>P;

    long long sum=0;
    priority_queue<int> pq;
    for(int i=0;i<N;i++){
        int cur;
        cin>>cur;
        sum+=cur;
        pq.emplace(cur);
        long long cnt=T-(long long)i*P;

        while(!pq.empty()&&sum>cnt){
            sum-=pq.top();
            pq.pop();
        }
        ans=max(ans,(int)pq.size());
    }
    cout<<ans;
}