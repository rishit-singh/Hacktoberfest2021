#include<bits/stdc++.h>
using namespace std;

// No of ways to place n not attacking knights(horse) in n * n board

void display(vector<vector<bool>> &grid, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]){
                cout << "K ";
            }else{
                cout << ". ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(int n, int i, int j, vector<vector<bool>> &grid){
    if(i < 0 and j < 0 and i > n and j > n and grid[i-1][j-2]) return false;
    if(i < 0 and j < 0 and i > n and j > n and grid[i-2][j-1]) return false;
    if(i < 0 and j < 0 and i > n and j > n and grid[i-2][j+1]) return false;
    if(i < 0 and j < 0 and i > n and j > n and grid[i-1][j+2]) return false;
    return true;
}
int ans = 0;
void nKnights(int n, int i, int j, int count, vector<vector<bool>> &grid){
    if(count == n){
        ans++;
        display(grid, n);
        return;
    }
    for(int r = i; r < n; r++){
        for(int c = (r==i)?j:0; c < n; c++){
            if(isSafe(n, r, c, grid)){
                grid[r][c] = true;
                nKnights(n, r, c+1, count+1, grid);
                grid[r][c] = false;

            }
        }
    }
    
}

int main(){
    int n = 2;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    nKnights(n, 0, 0, 0, grid);
    cout << ans << '\n';
    return 0;
}