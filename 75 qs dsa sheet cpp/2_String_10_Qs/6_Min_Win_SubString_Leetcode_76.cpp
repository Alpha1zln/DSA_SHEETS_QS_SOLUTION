// // Q 6 - String

// // _Leetcode_76, Min. Win. SubString
// //  

// // valid - ex - t="abc" ... s = "ddaabbca" ...
// // 

#include <iostream>
#include <string>
#include<vector>
#include<map>
#include <unordered_map>
#include <algorithm>
#include <climits>   // fr INT_MAX
//#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair <int, int> pi;


// // fn declaration 
string minWinSubString(string& s, string& t);

// // main fn 
int main( ) {

    string t; // = // {"abc"};      
    cout << "Enter t string : " << endl;
    getline(cin, t);
    
    string s; // = //{"ddaabbca"};
    cout << "Enter s string : " << endl;
    getline(cin, s);

    //string input;

    string minSubStr = minWinSubString( s, t);

    cout << "Min Sub Str : " << minSubStr;

    return 0;
}



// fn definition
string minWinSubString(string& s, string& t) {
    int lnS = s.length(), lnT = t.length();
    int minLen = INT_MAX, startIdx = 0; 
    unordered_map<char, int> freqT;
    unordered_map<char, int> freqWin;   string minStr = "";

    // 0
    if (lnS == 0 || lnT == 0 || lnT > lnS) return "";
    
    // 1 
    for(auto ch : t) {
        freqT[ch]++;                // a1 b1 c1     // tc = m = lnT
    }

    int totalRequired = freqT.size();  // Unique chars to match


    // 2 
    int r=0, l=0, matchedCount =0;
    while(r < lnS) {
        char ch = s[r]; 
        freqWin[ ch ]++;
        
        if(freqT.count(ch) && freqT[ch] == freqWin[ch]) {
            matchedCount++;
        }

        while(l<=r && matchedCount == totalRequired) {    //3==3      // dnt use lnT = 4      
            int len = r-l+1;
            if(len < minLen) {
                minLen = min(minLen , len );
                startIdx = l;
            }

            char ltCh = s[l];     //   l .. char ltch ...not int ltCh 
            freqWin[ltCh]--;

            
            if(freqT.count(ltCh) && freqWin[ltCh] < freqT[ltCh]) {
                matchedCount--;
            }

            l++;
        }

        r++;
    }

    // 
    string sub_string = "";
    
    if(minLen != INT_MAX) {
        sub_string = s.substr(startIdx, minLen);
    }

    return sub_string;

}



// op
// Enter t string : 
// abbc
// Enter s string : 
// ddddddaaaaaaaaaaabccccbbbbbbbbaccbbbaaa
// Min Sub Str : bbac

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 6_Min_Win_SubString.cpp -o 6_Min_Win_SubString } ; if ($?) { .\6_Min_Win_SubString }
// Enter t string : 
// abc
// Enter s string :
// ddaabbcaaaccbbaa
// Min Sub Str : bca

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 6_Min_Win_SubString.cpp -o 6_Min_Win_SubString } ; if ($?) { .\6_Min_Win_SubString }
// Enter t string : 
// abcd
// Enter s string :
// ddaaabbccddee
// Min Sub Str : abbccd



/*
2. Step-by-step TC & SC
--------------------------------
 Code (Sliding Window)
--------------------------------

Let:
n = length of s
m = length of t
u = number of unique characters in t

Step 1: Build freqT from t
TC: O(m)
SC: O(u) for freqT

Step 2: Sliding window with two pointers (l, r)
    - Each character visited at most twice
TC: O(n)
SC: O(u) for freqWin

Step 3: String operations (substr in the end)
TC: O(minLen) ≤ O(n)
SC: O(minLen) for substring result

Final TC: O(n + m)
Final SC: O(u)

*/



// ⏱️ Time Complexity:
// Part	Time
// Building tFreq map	O(m)
// Sliding window over s	O(n)
// Inside while loop (shrink part)	O(n) in total (each char is processed once)
// Total Time Complexity	O(n + m)

// 🧠 Space Complexity:
// Component	Space
// tFreq and windowFreq maps	O(256) → constant for ASCII
// Total Space	O(1) (constant, since char count is limited)

// ✅ Efficient for large strings and suitable for interviews!




/*
//  Explanation (Step-by-step):
// Use two maps:

// tFreq → to store frequency of each character in t.

// windowFreq → to track character frequencies in the current window.

// Use a sliding window with left and right pointers.

// formed tells how many characters (with correct frequency) have been matched so far.

// When all required characters are matched (formed == required), try to shrink the window from the left to find the smallest valid substring.


*/






/*
1. Improvements to Your Code

Your implementation is already a sliding window optimal approach (O(n + m)) and interview-ready.
Still, we can make small refinements:

Use const string& for s and t to avoid unnecessary copies.

Remove unused variables (minStr).

Use a single unordered_map<char,int> for freqT and freqWin is fine, but can replace freqWin with just int[128] for slightly faster lookups.

Early return when t.length() > s.length().

Minor naming cleanup for readability.


Improved Code
#include <bits/stdc++.h>
using namespace std;

string minWinSubString(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    if (m == 0 || n == 0 || m > n) return "";

    unordered_map<char, int> freqT;
    for (char c : t) freqT[c]++;

    int required = freqT.size();
    unordered_map<char, int> window;
    int formed = 0, left = 0, minLen = INT_MAX, startIdx = 0;

    for (int right = 0; right < n; right++) {
        char c = s[right];
        window[c]++;

        if (freqT.count(c) && window[c] == freqT[c]) formed++;

        while (left <= right && formed == required) {
            int len = right - left + 1;
            if (len < minLen) {
                minLen = len;
                startIdx = left;
            }
            char leftChar = s[left];
            window[leftChar]--;
            if (freqT.count(leftChar) && window[leftChar] < freqT[leftChar]) formed--;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
}

int main() {
    string t, s;
    cout << "Enter t string: ";
    getline(cin, t);
    cout << "Enter s string: ";
    getline(cin, s);

    cout << "Min Sub Str: " << minWinSubString(s, t) << "\n";
}

--------------------------------
Improved Code
--------------------------------

Same algorithm → same complexities:

Final TC: O(n + m)
Final SC: O(u)




3. Interview Tips (5–10)

Always clarify whether characters are case-sensitive and if spaces matter.

Mention three approaches: brute force (O(n²·m)), sliding window (O(n + m)), optimized array lookup for small char sets.

If t contains characters not in s → early return "".

Sliding window works because once you satisfy all required characters, shrinking window only loses validity.

freqT stores needed counts, window tracks current counts.

formed counts how many unique chars match their required frequency.

Use ASCII arrays (int arr[128]) for faster fixed-char problems.

Avoid recomputing substring inside loop for speed.

Always track start index + min length for final substring extraction.

This problem is a template for many substring problems (like "longest substring with at most k distinct characters").



4. Interview Q&A (5–10)

Q1: Why use two pointers?
A1: They allow expanding and contracting the window in O(n) total time.

Q2: Why track formed instead of checking window validity each time?
A2: It avoids scanning the frequency map for every step, keeping it O(1) per move.

Q3: What’s the worst-case scenario for this algorithm?
A3: Still O(n + m), even if all chars match, because each pointer moves at most n times.

Q4: Could you solve this without extra space?
A4: Not exactly — we must store counts for t to know when the requirement is satisfied.

Q5: How to handle Unicode characters?
A5: Use unordered_map<wchar_t,int> or a hash with Unicode support instead of fixed array.

Q6: Why do we need required = freqT.size()?
A6: It ensures we match each unique character count exactly once.

Q7: How to modify for "minimum window containing all words"?
A7: Treat each word as a token and use the same frequency + sliding window logic.

Q8: What if s or t is empty?
A8: Return "" immediately.

Q9: How does this compare to brute-force?
A9: Brute-force checks all substrings → O(n²·m), this is O(n + m).

Q10: Is unordered_map always faster?
A10: For small fixed char sets (ASCII), array lookup is faster; unordered_map shines for large or sparse sets.

*/

