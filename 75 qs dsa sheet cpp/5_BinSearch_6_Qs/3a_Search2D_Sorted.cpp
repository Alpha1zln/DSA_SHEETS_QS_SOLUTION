#include<bits/stdc++.h>
using namespace std;

// 3 - Search in a 2D sorted matrix 
// leetcode 74 

int  searchMatrix(vector<vector<int>>& vc, int k) {
    int ans = -1;
    int nRows = vc.size();
    int nCols = vc[0].size();

    int lt = 0, rt = (nRows * nCols  - 1);
    int mid;

    while(lt <= rt ) {
        mid = lt + (rt-lt)/2;
        int midIdxVal = vc[mid/nRows][mid%nCols];

        if(k == midIdxVal) {
            ans = mid; break;
        }
        else if(k < midIdxVal) {
            rt = mid - 1;
        } 
        else {
            lt = mid + 1;
        }
    }

    return ans;
}

int main() {

    vector<vector<int>> vc = { {1,5,9},
                               {11,15,19}, 
                                {21,27,31}  };

    
    int k; cout << "Enter target : "; cin>>k;  cout << endl;
    int ans = searchMatrix(vc, k);

    if(ans == -1 ) {
        cout << "Not found " << endl;
    }
    else {
        cout << "Found k : " << k << " at idx " << ans << endl;
    }
    
}



/*
Enter target : 27

Found k : 27 at idx 7
PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 3_Search2D.cpp -o 3_Search2D } ; if ($?) { .\3_Search2D }
Enter target : 5

Found k : 5 at idx 1
PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 3_Search2D.cpp -o 3_Search2D } ; if ($?) { .\3_Search2D }   
Enter target : 12

Not found

*/