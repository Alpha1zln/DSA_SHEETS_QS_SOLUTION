// // Q 3 - String

// // _Leetcode_242, Valid Anagram
// //  

// // valid - ex - team ... meat
// // nope - ex - radius  ... raised

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair <int, int> pi;


// // fn declaration 
bool checkValidAnagram(string& s, string& t);


// // main fn 
int main( ) {

    string s, t;
    // cin >> str;  
    cout << "Enter 1st strings : " << endl;
    getline(cin, s);  // to read the entire line including spaces

    cout << "Enter 2nd strings : " << endl;
    getline(cin, t);  // to read the entire line including spaces

    
    bool isValid = checkValidAnagram(s, t);

    if(isValid) {
        cout << "Valid Anagram\n";
    }
    else {
        cout << "Invalid Anagram\n";
    }

    return 0;
}



// **********************************************************
// or 


/// ✅ Approach 2: Using map<char, int>

bool checkValidAnagram(string& s, string& t) {
    int len_s = s.length();
    int len_t = t.length();

    if (len_s != len_t) {
        return false;  // Early exit if lengths differ
    }

//    Using map to count character frequencies
    map<char, int> mp;          
    // here char can be any character, not just lowercase letters, even Unicode characters
    // so we can use map instead of array of size 26
    for (char ch : s) 
        mp[ch]++;

    for (char ch : t) {
        mp[ch]--;
        if (mp[ch] < 0) return false;
    }

    // If all counts are zero, then it's an anagram
    return true;
}

/*
------------------------------
Your Code (using map<char,int>)
------------------------------

Step 1: Check lengths
TC: O(1)
SC: O(1)

Step 2: First loop to count characters in 's'
TC: O(n * log k)   // k = unique chars
SC: O(k)           // storing counts

Step 3: Second loop to decrement counts using 't'
TC: O(n * log k)   // map operations log k
SC: O(1) extra     // reusing map

Step 4: Return true if all counts match
TC: O(1)
SC: O(1)

Final TC: O(n log k)
Final SC: O(k)

*/


/*
Your Code (Approach 2: Using map<char, int>)

Time Complexity (TC):

Reading first string s → O(n) where n = length of s

Reading second string t → O(m) where m = length of t

If lengths differ, return immediately → O(1)

Building frequency map from s → O(n log k) where k = number of unique characters (log k from map insertion/updates)

Decreasing counts using t → O(m log k) for map lookups/updates

Final check (implicit) → O(1) since we verify while decrementing
Total TC: O(n log k + m log k), and since n = m here → O(n log k)



Space Complexity (SC):

Storage of strings s and t → O(n + m)

Map to store frequencies → O(k) where k ≤ min(n, m)

No additional large data structures
Total SC: O(n + m + k) → Since n = m and k ≤ n → O(n)
*/



// 🔍 Time Complexity:
// O(n log k), where k is the number of unique characters (since map is ordered → log k operations).

// Each insertion/update in map takes O(log k) time.

// 🔍 Space Complexity:
// O(k), where k is the number of unique characters.

// ⚖️ Comparison Summary
// Feature	Array (26-size)	map<char, int>
// Time Complexity	O(n)	O(n log k)
// Space Complexity	O(1) (fixed 26)	O(k) (variable, can be 256)
// Use case	Lowercase letters only	Any characters (Unicode too)
// Speed	Faster	Slower due to log ops
// Flexibility	Less flexible	More flexible

// 🧠 Tip for Interviews / Practice:
// Use the array when you're sure inputs are lowercase English letters (a-z).

// Use map (or unordered_map for faster avg. time) when input includes uppercase, punctuation, or Unicode characters.




/*
Enter 1st strings :
@ 132 read
Enter 2nd strings : 
dear 123 @
Valid Anagram

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 3_Valid_Anagram.cpp -o 3_Valid_Anagram } ; if ($?) { .\3_Valid_Anagram }
Enter 1st strings : 
@ 123 a
Enter 2nd strings : 
123a@
Invalid Anagram

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 3_Valid_Anagram.cpp -o 3_Valid_Anagram } ; if ($?) { .\3_Valid_Anagram }
Enter 1st strings : 
123@a
Enter 2nd strings :
a@123
Valid Anagram

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 3_Valid_Anagram.cpp -o 3_Valid_Anagram } ; if ($?) { .\3_Valid_Anagram }
Enter 1st strings : 
seat 12 
Enter 2nd strings :
12 eats !
Invalid Anagram

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\2_String_10_Qs\" ; if ($?) { g++ 3_Valid_Anagram.cpp -o 3_Valid_Anagram } ; if ($?) { .\3_Valid_Anagram }
Enter 1st strings : 
team
Enter 2nd strings :
meats
Invalid Anagram
*/




/*
Alright — I’ll break this into:

Improvements (your code → cleaned/optimized where possible)

Your code’s TC & SC vs my improved version’s TC & SC (plain, copy-paste ready)

5–10 short interview tips (topic-specific)

5–10 likely interview Q&A (around Valid Anagram)

1. Improvements to Your Code

Your code works fine, but here’s where we can make it cleaner and slightly more efficient:

Use unordered_map instead of map
→ map is balanced BST (O(log n) ops). unordered_map is hash table (O(1) avg ops).

Skip getline if spaces not needed
→ For competitive programming or LeetCode, spaces aren’t considered.

Use early exit on mismatch instead of traversing the whole string.

Lower memory alternative: If the string contains only lowercase English letters → use an array<int, 26> instead of map.
*/









// ********************************************************
// approach 1: Using array of size 26


// fn definition
// bool checkValidAnagram(string& s, string& t) {
//     int len_s = s.length();
//     int len_t = t.length();

//     transform(s.begin(), s.end(), s.begin(), ::tolower);
//     s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

//     transform(t.begin(), t.end(), t.begin(), ::tolower);
//     t.erase(remove_if(t.begin(), t.end(), ::isspace), t.end());


//     // check length
//     if(len_s != len_t) {
//         return false;
//     }

//     int countArr[26] = {0};

//     for(auto ch : s) {
//         countArr[ch-'a']++;
//     }

//     for(auto ch : t) { /// 
//         countArr[ch-'a']--;
//         if(countArr[ch-'a'] < 0) {
//             return false;
//         }
//     }

//     return true;


// }


/*
Enter 1st strings : 
123 i am
Enter 2nd strings :
i am 123
Valid Anagram


Enter 1st strings : 
456 i am
Enter 2nd strings :
i am 4
Invalid Anagram

Enter 1st strings : 
who am i
Enter 2nd strings :
i am how
Valid Anagram


Enter 1st strings :
team
Enter 2nd strings : 
meat
Valid Anagram



*/


// 🔍 Time Complexity:
// O(n), where n is the length of the strings.

// Two passes through the strings s and t.

// 🔍 Space Complexity:
// O(1) — because the array size is constant (26), regardless of string length.









/*
3. Interview Tips (5–10)

Clarify character set before coding (only lowercase? ASCII? Unicode?).

Use unordered_map for average O(1) lookups, but mention worst-case complexity.

Mention early exits to save time when mismatch found.

Always compare lengths first.

If constraints allow, prefer array counting for constant space.

Talk about trade-offs between map and unordered_map.

Handle case sensitivity if interviewer expects it.

Don’t sort unless explicitly told — sorting is O(n log n).

In interviews, state complexity out loud.

If interviewer wants Unicode-safe, stick to map or unordered_map.

4. Interview Q&A (5–10)

Q1: How would you solve if only lowercase a–z?
A1: Use an int[26] frequency array for O(1) space and O(n) time.

Q2: Can sorting be used to solve this?
A2: Yes, sort both strings and compare; TC O(n log n), SC O(1) or O(n) depending on sorting method.

Q3: Why unordered_map over map?
A3: unordered_map gives O(1) average time per operation vs O(log n) for map.

Q4: How would you handle Unicode characters?
A4: Use unordered_map<char32_t, int> or map after converting to UTF-32.

Q5: What if strings are very large (10⁶ chars)?
A5: Avoid sorting, use counting; also consider streaming approach if data can't fit in memory.

Q6: How to make it case-insensitive?
A6: Convert both strings to lowercase (or uppercase) before processing.

Q7: What if spaces and punctuation should be ignored?
A7: Filter out non-alphabetic chars before counting.

Q8: Can you solve in O(1) space?
A8: If fixed char set (e.g., lowercase), yes — fixed array is O(1) space.

Q9: Why check lengths first?
A9: Quick elimination — avoids unnecessary computation.

Q10: What's the worst case for unordered_map?
A10: O(n²) if all keys collide (very rare with good hash function).

*/