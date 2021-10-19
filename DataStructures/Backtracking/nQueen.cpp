#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> &vis, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == true){
                cout << "Q ";
            }else{
                cout << ". ";
            }
        }
        cout << '\n';
    }
    cout << "\n\n";
}

bool safe(vector<vector<bool>> &vis, int row, int col, int n){
    // up
    for(int i = row; i >= 0; i--){
        if(vis[i][col] == true) return false;
    }
    // up left diagonal 
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(vis[i][j] == true) return false;
    }
    // up right diagonal

    for(int i = row, j = col; i >= 0 && j <= n; i--, j++){
        if(vis[i][j] == true) return false;
    }
    // if vis is marked true then false
    return true;
}

int ans = 0;
void check(int n, vector<vector<bool>> &vis, int row){
    if(row == n){
        ans++;
        display(vis, n);
        return;
    }
    for(int j = 0; j < n; j++){
        if(safe(vis, row, j, n)){
            vis[row][j] = true;
            check(n, vis, row+1);
            vis[row][j] = false;
        }    
    }
}

int main(){
    
    int n = 4; // Board size
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    check(n, vis, 0);

    cout << ans << '\n';
    return 0;
}