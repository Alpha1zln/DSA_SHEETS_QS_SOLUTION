
// 4
// Search in Rotated Sorted Array I


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

    vector<int> vc = {18,28,34, 2,4,6,8,10,14};
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
Found elt : 14 at index 8

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 4_Search_RotatedArr.cpp -o 4_Search_RotatedArr } ; if ($?) {
 .\4_Search_RotatedArr }
Enter elt : 34
Found elt : 34 at index 2

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 4_Search_RotatedArr.cpp -o 4_Search_RotatedArr } ; if ($?) {
 .\4_Search_RotatedArr }
Enter elt : 15
Not found

*/