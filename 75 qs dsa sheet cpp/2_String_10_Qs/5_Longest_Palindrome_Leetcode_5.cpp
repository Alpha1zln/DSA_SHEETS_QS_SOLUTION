// Q 5 - String

// _Leetcode_5, Longest Palindromic Substring  
//  new cpt - tgh $$


#include <iostream>
#include <string>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;    



// approach 1: Brute Force ... 
// using nested loops to find all substrings and check if they are palindromes.

// This is a simple but inefficient method, especially for long strings.
// It checks all possible substrings and finds the longest palindrome among them.
// string longestPalindrome(string s) {
//     int maxLen = 0;
//     string result = "";
    
//     for (int i = 0; i < s.size(); i++) {
//         for (int j = i; j < s.size(); j++) {
//             string sub = s.substr(i, j - i + 1);
//             string rev = sub;
//             reverse(rev.begin(), rev.end());
//             if (sub == rev && sub.size() > maxLen) {
//                 maxLen = sub.size();
//                 result = sub;
//             }
//         }
//     }
//     return result;
// }



// int main() {
//     string s;
//     cout << "Enter a string: ";
//     getline(cin, s);  // to read the entire line including spaces   
//     string longestPalin = longestPalindrome(s);

//     if (longestPalin.empty()) {
//         cout << "No palindrome found." << endl;
//     } else {
//         cout << "Longest Palindrome: " << longestPalin << endl;
//     }

//     return 0;
// }


// 🔍 Time Complexity   :   
// O(n^3), where n is the length of the string.
// The algorithm checks all substrings, and for each substring, 
// it checks if it is a palindrome by reversing it.        
// This results in a cubic time complexity due to the nested loops and 
// the string reversal operation.

// 🔍 Space Complexity  :   
// O(n), where n is the length of the longest palindrome found.
// The space complexity is mainly due to the storage of the longest palindrome substring, which can be at most n characters long.
//// The space used for the substring and its reverse is also O(n) in the worst case.



// ex - pqraraidiant  ... op=> aidia
// ex - raidar ...  op=>  r
// ex - 12321 ... op=>   12321

// 🧠 Tip for Interviews / Practice:
// This brute-force approach is simple but inefficient for large strings. 
// In practice, you might want to implement a more efficient algorithm like Manacher's algorithm or expand around center technique for finding the longest palindromic substring in O(n) time.  
// However, this brute-force method is a good starting point for understanding the problem and can be useful for small inputs or educational purposes.
// It also helps in understanding the basic properties of palindromes and substring manipulation in C++. 
// Always consider edge cases like empty strings or strings with no palindromes when testing your solution. 



// approach 2 : **********************************************

// fn declaration
string longestPalindrome(string& s);
void checkPalindrome(const string &s, int left, int right, int &start, int &maxLen);




int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);  // to read the entire line including spaces   
    string longestPalin = longestPalindrome(s);

    if (longestPalin.empty()) {
        cout << "No palindrome found." << endl;
    } else {
        cout << "Longest Palindrome: " << longestPalin << endl;
    }

    return 0;
}



// approach 2 : 
string longestPalindrome(string& s) {
    int start = 0, maxLen = 0;

    for (int i = 0; i < s.length(); i++) {  // ex - pqraraidiant  ... op=> aidia
        checkPalindrome(s, i, i, start, maxLen);     // Odd-length
        checkPalindrome(s, i, i + 1, start, maxLen); // Even-length
    }

    return s.substr(start, maxLen);
}

void checkPalindrome(const string &s, int left, int right, int &start, int &maxLen) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    
    // // since last valid was one step before break
    left++; // Move left back to the last matching character
    right--; // Move right back to the last matching character

    // Calculate the length of the palindrome found
    int len = right - left + 1 ; // Length of the palindrome
    
    // Update start index and max length if this palindrome is longer
    if (len > maxLen) {
        start =  left;
        maxLen = len;
    }
}



/*
--------------------------------
 Code (Expand Around Center)
--------------------------------

Let:
n = length of string

Step 1: Loop over each index as center
TC: O(n)

Step 2: Expand for odd-length palindromes
TC: O(n) in worst case for each center
SC: O(1)

Step 3: Expand for even-length palindromes
TC: O(n) in worst case for each center
SC: O(1)

Total expansions: 2 per index → O(2n * n) = O(n^2)

Final TC: O(n^2)
Final SC: O(1)

*/


// 🔍 Time Complexity   :
// O(n^2), where n is the length of the string.
// The algorithm iterates through each character in the string and 
// expands around it to find palindromes, 
// which takes O(n) time for each character, resulting in O(n^2) overall.        

// 🔍 Space Complexity  :
// O(1), since we are using a constant amount of space for variables like start, maxLen, left, and right.   

// This approach is efficient and works well for reasonably sized strings,
// making it suitable for interview scenarios where you need to find the longest palindromic substring quickly.
// It avoids the overhead of checking all substrings explicitly, thus improving performance significantly compared to the brute-force method.

// 🧠 Tip for Interviews / Practice:
// This approach is efficient and works well for reasonably sized strings.
// It avoids the overhead of checking all substrings explicitly, thus improving performance significantly compared to the brute-force method.
// Always consider edge cases like empty strings or strings with no palindromes when testing your solution.
// This method is a good balance between simplicity and efficiency, making it a popular choice for interview questions related to palindromes.



// ex - racecar ... op=> racecar
// ex - abba ... op=> abba
// ex - 12321 ... op=> 12321
// ex - a ... op=> a
// ex - abcd ... op=> a (or b, c, d as they are all single characters and palindromes)


// op=>

// Enter a string: abracadabra
// Longest Palindrome: aca

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 5_Longest_Palindrome.cpp -o 5_Longest_Palindrome } ; if ($?) { .\5_Longest_Palindrome }
// Enter a string: abcd
// Longest Palindrome: a

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 5_Longest_Palindrome.cpp -o 5_Longest_Palindrome } ; if ($?) { .\5_Longest_Palindrome }
// Enter a string: abbabcbc
// Longest Palindrome: abba

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 5_Longest_Palindrome.cpp -o 5_Longest_Palindrome } ; if ($?) { .\5_Longest_Palindrome }
// Enter a string: racecar
// Longest Palindrome: racecar


/*
3. Interview Tips (5–10)

Always clarify what counts as a palindrome (case sensitivity, spaces).

Mention 3 approaches: brute-force (O(n³)), expand-around-center (O(n²)), Manacher’s (O(n)).

For interviews, expand-around-center is easiest to code and explain.

Always check for odd and even lengths separately.

Edge cases: empty string, all same letters, length 1.

Explain why O(n²) is acceptable for n ≤ 2000.

Avoid extra string copies inside loop to keep O(1) space.

Store n = s.length() once to save function calls.

In brute-force, reversing substrings inside loop is wasteful → use two-pointer palindrome check.

If constraints are huge (n > 10⁵), mention Manacher’s Algorithm.

4. Interview Q&A (5–10)

Q1: Why do we check both odd and even length palindromes?
A1: Palindromes can have one or two center characters (e.g., "aba" vs "abba").

Q2: How do you optimize the O(n³) brute-force method?
A2: Use expand-around-center to avoid checking all substrings explicitly.

Q3: What’s the space complexity of your approach?
A3: O(1) — only a few integer variables used.

Q4: Can you get better than O(n²) time?
A4: Yes, Manacher’s Algorithm achieves O(n) time.

Q5: How would you modify for case-insensitive palindrome search?
A5: Convert string to lowercase before processing.

Q6: What if there are multiple longest palindromes?
A6: Return the first one found; can store all if required.

Q7: Why store maxLen and start instead of substring directly?
A7: Avoids extra memory allocations and string copying.

Q8: How does Manacher’s Algorithm work in simple terms?
A8: It uses previously computed palindrome radii to skip redundant comparisons.

Q9: What’s the worst-case scenario for expand-around-center?
A9: When the string is all same letters, every expansion runs to full length.

Q10: Can you solve this problem in a streaming fashion (one char at a time)?
A10: Not exactly — we need full string to determine longest palindrome.

*/