#include <bits/stdc++.h>
using namespace std; 
int N; 
long long B; 
vector<int> matrixMultiply(vector<int> &A, vector<int> &B){
    vector<int> C(N * N); 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
               	C[i*N+j] = (C[i*N+j] + A[i*N+k] * B[k*N+j]) % 1000;
            }
        }
    }	
    return C;
}
vector<int> divideNconquer(vector<int> & A, long long p){
    if(p == 1) return A; 
    vector<int> C = divideNconquer(A, p / 2); 
    C = matrixMultiply(C , C); 
    if(p % 2) C = matrixMultiply(C, A); 
    return C; 
}   
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B;
    vector<int> A(N * N), ans; 
    for(int i = 0; i < N * N; i++) cin >> A[i];
    ans = divideNconquer(A, B);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i * N + j] % 1000 << ' ';
        }
        cout << '\n';
    }   
    return 0; 
} 
