#include<bits/stdc++.h>
using namespace std;

// 5  - Find peak elt in rotated sorted arr  
//
// ltcd 162

#include<bits/stdc++.h>
using namespace std;

int findPeakElt(vector<int>& vc) {
    int n = vc.size();
    int lw = 0, h = n-1;
    int mid = lw + (h-lw)/2; 
    int pkIdx, pkElt = INT_MIN;

    while(lw <= h) {
        mid = lw + (h-lw)/2; 

        // if(k == vc[mid]) 
        //     return mid;
        if(vc[lw] <= vc[mid]) {
            if(vc[mid] > pkElt) {
                pkIdx = mid;
                pkElt = vc[pkIdx];
            } 
            lw = mid + 1;
        }
        else if(vc[mid] <= vc[h]){
            if(vc[h] > pkElt) {
                pkIdx = h;
                pkElt = vc[pkIdx];
            }
            h = mid - 1;
        }
    }

    return pkIdx;

}

int main() {

    vector<int> vc = {12,12,12, 14,18,28, 34,50,64, 2,4,6, 8,10,12, 12,12,12};
    
    int peakIdx = findPeakElt(vc);
    
    cout << "Peak elt : " << vc[peakIdx] << " at index " << peakIdx << endl;

    
    return 0;
}


// op===
// Peak elt : 64 at index 8