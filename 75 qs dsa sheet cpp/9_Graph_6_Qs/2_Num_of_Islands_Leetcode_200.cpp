
// Num of Islands
// Leetcode 200

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// fn prototype
void numofIslandsDFS(int r, int c, int rows, int cols, 
    vector<vector<int>>& grid, vector<vector<int>>& vis);

void printGraph(int rows, int cols, vector<vector<int>>& grid);
    
bool validMove(int r, int c, int rows, int cols);


int main() {
    vector<vector<int>> grid;
    grid =  {   {1,0,1,1},
                {1,0,0,0},
                {1,0,1,1},
                {0,0,1,0}
            };   
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> vis(rows, vector<int>(cols, 0) );
    int ct = 0;
    int i,j;

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(grid[i][j] == 1  && vis[i][j]==0) {
                ct++;
                numofIslandsDFS(i, j, rows, cols, grid, vis);
            }
        }
    } // for

    cout << "Actual grid : " << endl;
    printGraph(rows, cols, grid);

    cout << "Num of Islands : " << ct << endl;
    
    
} // main


// fn definition
void numofIslandsDFS(int r, int c, int rows, int cols, 
    vector<vector<int>>& grid, vector<vector<int>>& vis)
{
    vis[r][c] = 1;

    int rowDir[] = {-1,0,1,0};
    int colDir[] = {0,1,0,-1};

    for(int i=0; i<4; i++) {
        int nr = r + rowDir[i];
        int nc = c + colDir[i];

        if(validMove(nr, nc, rows, cols) == false) {
            continue;
        }
        if(grid[nr][nc]==1 && vis[nr][nc]==0) {
            //vis[nr][nc] = 1; 
            numofIslandsDFS(nr, nc, rows, cols, grid, vis);
             
        }
    }
}


void printGraph(int rows, int cols, vector<vector<int>>& grid) 
{
    int i,j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            cout << grid[i][j] << "";
        }
        cout << endl;
    } // for
}

bool validMove(int r, int c, int rows, int cols) {
    if( (r>=0 && r<rows) && (c>=0 && c<cols) ) {
        return true;
    }
    return false;
}



/*

Actual grid : 
1011
1000
1011
0010

Num of Islands : 3


*/


// TC AND SC
// Time Complexity (TC)
// •	Each cell (i, j) in the grid is visited at most once.
// •	DFS from that cell explores in 4 directions, but since each neighbor is also only visited once, the total work is O(rows × cols).
// TC=O(m×n)where m = rows, n = cols\text{TC} = O(m \times n) \quad \text{where m = rows, n = cols}TC=O(m×n)where m = rows, n = cols 
// ________________________________________
// Space Complexity (SC)
// There are two sources of extra space usage:
// 1.	Visited Matrix vis → O(m × n)
// 2.	DFS recursion stack → Worst-case O(m × n) (e.g., if all cells are land, recursion depth equals number of cells in a connected component).
// So:
// SC=O(m×n)(visited matrix)+O(m×n)(stack space worst case)\text{SC} = O(m \times n) \quad \text{(visited matrix)} + O(m \times n) \quad \text{(stack space worst case)}SC=O(m×n)(visited matrix)+O(m×n)(stack space worst case) SC=O(m×n)\text{SC} = O(m \times n)SC=O(m×n) 
// If you remove the vis matrix and mark visited cells directly in grid, space becomes O(m × n) only due to recursion stack (or O(1) extra space if using BFS with queue and modifying grid).
