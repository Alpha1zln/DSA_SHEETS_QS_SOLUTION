
// Q 10 .. 
// _Leetcode_48  .. ROTATE IMAGE [clockwise 90 degree]


#include <iostream>   // for cout, endl
#include <vector>     // for std::vector
#include <algorithm>  // for reverse, swap
// #include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void rotateImageClockWise(vvi& image, vvi& rotatedImage);
void printArr(vvi& rotatedImage);


// main fn
int main() {
    
    vvi image;   vvi rotatedImage;
    image = { {1,2,3}, {4,5,6}, {7,8,9} } ;
    
    cout << "Initial Image :: " << endl;
    printArr( image);  cout << endl;

    rotateImageClockWise( image,  rotatedImage);

    cout << "Rotated Image :: " << endl;
    printArr( rotatedImage);

    return 0;
}



// fn defntn
void rotateImageClockWise(vvi& image, vvi& rotatedImage) {
    rotatedImage = image;
    int n_rows = rotatedImage.size();
    int n_cols = rotatedImage[0].size();

    // dignl swap  ,     Transpose
    for(int i=0; i<n_rows; i++) {
        for(int j=i+1; j<n_cols; j++) {
            swap(rotatedImage[i][j], rotatedImage[j][i]);
        }
    }

    printArr( rotatedImage);

    // rev each rows
    for(auto& rowsVec : rotatedImage) {
        reverse(rowsVec.begin(), rowsVec.end() );
    }

}


void printArr(vvi& rotatedImage){
        

    for(auto vc : rotatedImage) {
        for(int i=0; i<vc.size(); i++) {
            cout << vc[i] ;
            if(i != vc.size()-1)
                cout << " ";
        }
        cout << "," << endl;
    }
}


// //  
// Initial Image :: 
// 1 2 3,
// 4 5 6,
// 7 8 9,

// 1 4 7,     // swapd img
// 2 5 8,
// 3 6 9,
// Rotated Image ::
// 7 4 1,
// 8 5 2,
// 9 6 3,



/*

1. Time Complexity (TC) & Space Complexity (SC)
Step-by-step plain explanation:

Let the matrix be N × N.

Time Complexity:

Transpose step (swap along diagonal): We visit each cell in the upper triangle of the matrix once → about N × N / 2 swaps → O(N²).

Reverse each row: Each row has N elements and there are N rows → O(N²).

Printing → O(N²).

So Total TC = O(N²).




Space Complexity:

rotatedImage stores another N × N matrix → O(N²) extra space.

No extra space for reversing or swapping (in-place inside rotatedImage).

So SC = O(N²) due to rotatedImage.
If we did the rotation directly on image without making a copy, it would be O(1) extra space.




Space Complexity details

Memory space required for input matrix:
If the matrix size is n × n, each int takes 4 bytes → total space = n × n × 4 bytes.
Example: For a 3×3 matrix → 3 × 3 × 4 = 36 bytes.

Memory space required for output matrix:
Same as above → n × n × 4 bytes.

Auxiliary space (extra):
The algorithm uses O(1) extra space apart from the new matrix, because:

The transpose is done in-place on rotatedImage.

Only temporary variables (int, loop counters) are used.

Total space usage:

mathematica
Copy
Edit
Space = Space(input) + Space(output) + O(1) aux space
      = O(n²) + O(n²) + O(1)










2. Improvements Needed & Updated Code
Problems in given code:

Unnecessary extra matrix rotatedImage.

Too much printing in between (debug prints in rotateImageClockWise).

Could be done in-place to save space.

typedef clutter isn’t needed for small code.

Output format has extra commas.

Improved In-Place Version (Space O(1)):


3. 5 Interview Tips for This Question
Mention the in-place approach — interviewers like optimizations from O(N²) space → O(1) space.

Explain transpose + reverse logic before coding — shows structured thinking.

Avoid unnecessary prints during the interview — only print final output if needed.

If interviewer asks for rectangular matrices, note that the transpose logic changes.

Be ready to extend logic for anticlockwise rotation — shows adaptability.

4. 5 Questions Based on This Code (with Answers)
Q1: What’s the time complexity of rotating an N×N matrix?
A1: O(N²), because both transpose and row reversal require visiting each element once.

Q2: Can this be done without extra space?
A2: Yes, by doing transpose and reverse in-place on the original matrix (SC = O(1)).

Q3: What happens if the matrix is not square?
A3: This exact transpose method won’t work; for rectangular, we need extra space or more complex swaps.

Q4: Which step changes the orientation from transpose to rotation?
A4: The row reversal step.

Q5: How to rotate anticlockwise using the same idea?
A5: Transpose first, then reverse each column instead of each row.

5. 5 Pro-Level Questions (with Answers)
Q1: How would you rotate a matrix by 180° in-place?
A1: Reverse rows & columns directly OR do 90° rotation twice.

Q2: How to rotate a huge image (10k×10k) without exceeding memory?
A2: Use an in-place approach and avoid creating an extra matrix.

Q3: How to rotate an image stored as a 1D array?
A3: Map (row, col) to index = row * N + col, then compute new position after rotation.

Q4: If the matrix has odd dimensions, which element stays in place during rotation?
A4: The exact middle element (center cell).

Q5: How to rotate a sparse matrix efficiently?
A5: Store non-zero elements in coordinate form and rotate coordinates instead of whole matrix.

*/