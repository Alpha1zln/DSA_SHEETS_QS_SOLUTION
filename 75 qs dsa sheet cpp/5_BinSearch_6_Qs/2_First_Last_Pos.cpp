// 2
// ltcd 34

#include<bits/stdc++.h>
using namespace std;


int findFirstPos(vector<int>& vc, int k) {
    int n = vc.size();
    int l = 0, h = n-1;
    int mid; //  = l + (h-1)/2; 
    int ans = -1;

    while(l <= h) {
        mid = l + (h-l)/2; 

        if(k == vc[mid]) {
            ans =  mid;     h = mid - 1;
        }  
        else if(k < vc[mid]) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;

}


int findLastPos(vector<int>& vc, int k) {
    int n = vc.size();
    int l = 0, h = n-1;
    int mid ;   // = l + (h-1)/2; 
    int ans = -1;

    while(l <= h) {
        mid = l + (h-l)/2; 

        if(k == vc[mid])  {
            ans =  mid;  l = mid + 1;
        }
            
        else if(k < vc[mid]) {
            h = mid -1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;

}


int main() {

    vector<int> vc = {2,4,6,8,8,8,8,8,8,8,10,14,18,28};
    int target; cout << "Enter elt : " ;
    cin >> target;

    int firstPos = findFirstPos(vc, target);
    if(firstPos == -1) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found first elt : " << vc[firstPos] << " at index " << firstPos << endl;

    }


    int lastPos = findLastPos(vc, target);
    if(lastPos == -1) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found last elt : " << vc[lastPos] << " at index " << lastPos << endl;

    }

    return 0;
}



// op ----------
// Enter elt : 18
// Found first elt : 18 at index 12
// Found last elt : 18 at index 12

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\5_BinSearch_6_Qs\" ; if ($?) { g++ 2_First_Last_Pos.cpp -o 2_First_Last_Pos } ; if ($?) { .\2_First_Last_Pos }
// Enter elt : 8
// Found first elt : 8 at index 3
// Found last elt : 8 at index 9


