
// Q 10 .. 
// 48  .. ROTATE IMAGE [clockwise 90 degree]

#include<bits/stdc++.h>
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

    // dig swap
    for(int i=0; i<n_rows; i++) {
        for(int j=i+1; j<n_cols; j++) {
            swap(rotatedImage[i][j], rotatedImage[j][i]);
        }
    }

    printArr( rotatedImage);

    // rev rows
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