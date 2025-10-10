
// 5 - Rotting Oranges
// Leetcode 200

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// fn prototype
void numofIslandsBFS(int& ct, int rows, int cols, vector<vector<int>>& grid, 
    vector<vector<int>>& vis, queue<pair<int, int>>& qu);

void printGraph(int rows, int cols, vector<vector<int>>& grid);
    
bool validMove(int r, int c, int rows, int cols);


int main() {
    vector<vector<int>> grid;
    // frsth oranges = 1 ... rotten orng = 2 
    grid =  {   {1,1,2,1},
                {1,1,0,0},
                {0,0,0,2},
                {1,0,1,1}
            };   
    int rows = grid.size();
    int cols = grid[0].size();

    // vector<vector<int>> vis(rows, vector<int>(cols, 0) );
    vector<vector<int>> vis = grid;

    //int ct = 0;  
    int numFreshOrange = 0;
    int i,j;  
    
    queue<pair<int, int>> qu;

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(grid[i][j] == 2) {
                qu.push({i,j});
            }

            if(grid[i][j] == 1) {
                numFreshOrange++;
            }
        }
    }

    int ct = 0;
    // while(!qu.empty()) {
        numofIslandsBFS(ct, rows, cols, grid, vis, qu);
        
    // } // for

    cout << "Actual grid : " << endl;
    printGraph(rows, cols, grid); 

    cout<<"Is all fresh oranges are rotten now: "<< (ct==numFreshOrange) << endl;    
    cout << "fresh orng: " << numFreshOrange << endl;
    cout << "Affected orng in oprtn: " << ct << endl; 
    cout << endl;
    
    cout << "grid after oprtn : " << endl;
    printGraph(rows, cols, vis); 

    
} // main


// fn definition

void numofIslandsBFS(int& ct, int rows, int cols, vector<vector<int>>& grid, 
    vector<vector<int>>& vis, queue<pair<int, int>>& qu)
{
    
    while(!qu.empty()) {
        auto pr = qu.front();  qu.pop();
        int r = pr.first, c=pr.second;

        int rowDir[] = {-1,0,1,0};
        int colDir[] = {0,1,0,-1};

        for(int i=0; i<4; i++) {
            int nr = r + rowDir[i];
            int nc = c + colDir[i];

            if(validMove(nr, nc, rows, cols) == false) {
                continue;
            }
            if(grid[nr][nc]==1 && vis[nr][nc]==1) {
                vis[nr][nc] = 2;  ct++; 
                qu.push({nr, nc});
            }
        } // for
    } // wl
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
    cout << endl;
}


bool validMove(int r, int c, int rows, int cols) {
    if( (r>=0 && r<rows) && (c>=0 && c<cols) ) {
        return true;
    }
    return false;
}



/*

For your Rotting Oranges BFS solution:
________________________________________
Time Complexity (TC)
Let:
•	mmm = number of rows
•	nnn = number of columns
Reasoning:
1.	We visit each cell at most once (either initially when finding rotten oranges or when BFS rots a fresh one).
2.	Each cell has at most 4 neighbors to check.
3.	All operations inside the loop are O(1)O(1)O(1).
So:
TC=O(m×n)\text{TC} = O(m \times n)TC=O(m×n) 
________________________________________
Space Complexity (SC)
Extra space comes from:
1.	Queue in BFS: in the worst case, it can hold all cells at once → O(m×n)O(m \times n)O(m×n)
2.	vis matrix: also O(m×n)O(m \times n)O(m×n)
(Here vis is basically another grid copy; if you modify the original grid directly, this space can be saved.)
So:
SC=O(m×n)(queue + visited grid)\text{SC} = O(m \times n) \quad \text{(queue + visited grid)}SC=O(m×n)(queue + visited grid) 
If you remove vis and mark rotten oranges directly in grid, extra space becomes:
SC=O(m×n)(queue only)\text{SC} = O(m \times n) \quad \text{(queue only)}SC=O(m×n)(queue only)


*/