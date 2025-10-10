
// 1
// ltcd 704

#include<bits/stdc++.h>
using namespace std;

int binSearch(vector<int>& vc, int k) {
    int n = vc.size();
    int l = 0, h = n-1;
    int mid = l + (h-1)/2; 

    while(l <= h) {
        mid = l + (h-l)/2; 

        if(k == vc[mid]) 
            return mid;
        else if(k < vc[mid]) {
            h = mid -1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;

}

int main() {

    vector<int> vc = {2,4,6,8,10,14,18,28};
    int target; cout << "Enter elt : " ;
    cin >> target;

    int searchIdx = binSearch(vc, target);
    if(searchIdx == -1) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found elt : " << vc[searchIdx] << " at index " << searchIdx << endl;

    }

    return 0;
}



// op--------
// Enter elt : 18
// Found elt : 18 at index 6
//

//PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 1_BinarySearch.cpp -o 1_BinarySearch } ; if ($?) { .\1_BinarySearch }
// Enter elt : 15
// Not found