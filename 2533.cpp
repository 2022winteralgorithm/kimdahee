#include <iostream>
#include <vector>
using namespace std;
 
int n;
int dp[1000001][2]; 
vector<vector<int> > edges;
vector<int> visited;
 
void solve(int node){
    visited[node] = 1;
    dp[node][0] = 0; 
    dp[node][1] = 1; 
    
    for(int i=0; i<edges[node].size(); i++){
        int child = edges[node][i]; 
        if(visited[child]) continue;  
        solve(child);
        dp[node][0] += dp[child][1]; 
        dp[node][1] += min(dp[child][0], dp[child][1]); 
    }
}
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // visited 초기화, 1부터 탐색할거니까 크기는 n+1
    edges.resize(n+1); 
    visited.resize(n+1);
    // edges 초기화
    int u, v;
    for(int i=1; i<n; i++){ 
        cin >> u >> v;
        // 양방향 그래프 생성
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    solve(1);
    cout << min(dp[1][0], dp[1][1]);
}