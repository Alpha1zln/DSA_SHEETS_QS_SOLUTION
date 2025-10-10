#include<bits/stdc++.h>
using namespace std;

// 3 b - Search in a 2D Un-Sorted matrix 
// 

pair<int,int>  searchMatrix(vector<vector<int>>& vc, int k) {
    pair<int,int> ans = {-1,-1};
    int nRows = vc.size();
    int nCols = vc[0].size();

    int r=0; 
    for(auto v : vc) {
        int c=0;
        for( auto e : v) {
            if(e == k) {
                ans = {r,c}; break; //r*c - 1;
            }
            c++;
        }
        r++;
    }
    return ans;
}

int main() {
    // vector<vector<int>> vc = { {1,5,9},
    //                            {11,15,19}, 
    //                             {21,27,31}  };

    vector<vector<int>> vc = { {11,5,19},
                            {1,25,9}, 
                            {21,7,3}  };
    
    int k; cout << "Enter target : "; cin>>k;  cout << endl;
    pair<int,int> ans = searchMatrix(vc, k);

    if(ans.first == -1 ) {
        cout << "Not found " << endl;
    }
    else {
        cout << "Found k : "<< k <<" at idx : (" <<ans.first << "," <<ans.second << ")";
        cout << endl;
    }
    
}



/*
Enter target : 7
Found k : 7 at idx : (2,1)

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 3b_Search2D_UnSorted.cpp -o 3b_Search2D_UnSorted } ; if ($?) { .\3b_Search2D_UnSorted }
Enter target : 1
Found k : 1 at idx : (1,0)

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 3b_Search2D_UnSorted.cpp -o 3b_Search2D_UnSorted } ; if ($?) { .\3b_Search2D_UnSorted }
Enter target : 2
Not found

*/