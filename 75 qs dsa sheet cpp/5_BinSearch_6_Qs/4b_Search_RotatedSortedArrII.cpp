
// 4 b
// leetcode 81
// Search in Rotated Sorted Array II ....
// same dup eltd in arr 


#include<bits/stdc++.h>
using namespace std;

int searchRotatedSortedArr(vector<int>& vc, int k) {
    int n = vc.size();
    int l = 0, h = n-1;
    int mid = l + (h-1)/2; 

    while(l <= h) {
        mid = l + (h-l)/2; 

        if(k == vc[mid]) 
            return mid; 
        else if(vc[l] <= vc[mid]) {
            if(k>=vc[l] && k<vc[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        else if( vc[mid] <= vc[h]){
            if(k>vc[mid] && k<=vc[h]) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
    }

    return -1;

}

int main() {

    vector<int> vc = {16,16, 16,16,16, 16,16,16, 16,16,16, 18,28,34, 8,10,14, 16, 16,16};
    int target; cout << "Enter elt : " ;
    cin >> target;

    int searchIdx = searchRotatedSortedArr(vc, target);
    if(searchIdx == -1) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found elt : " << vc[searchIdx] << " at index " << searchIdx << endl;

    }

    return 0;
}



// op--------
/*

Enter elt : 14
Found elt : 14 at index 16

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 4b_Search_RotatedSortedArrII.cpp -o 4b_Search_RotatedSortedArrII } ; if ($?) { .\4b_Search_RotatedSortedArrII }
Enter elt : 18
Found elt : 18 at index 11

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 4b_Search_RotatedSortedArrII.cpp -o 4b_Search_RotatedSortedArrII } ; if ($?) { .\4b_Search_RotatedSortedArrII }
Enter elt : 16
Found elt : 16 at index 9

*/