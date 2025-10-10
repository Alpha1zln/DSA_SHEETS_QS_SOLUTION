// // Q 1 - String

// // _Leetcode_20 , Valid Parentheses
// //  

// // valid - ex - [ {} ] , []   , 
// // nope - { [ ]   ,   ] ]   ,   {{    ,   [ } 

#include <iostream>
#include <string>
#include<vector>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair <int, int> pi;


// // fn declaration 
bool checkValidParentheses(string& str);

// // main fn 
int main( ) {

    string str;
    // cin >> str;
    getline(cin, str); // imp rmr 

    bool isValid = checkValidParentheses(str);
    if(isValid) {
        cout << "Valid Parentheses\n";
    }
    else {
        cout << "Invalid Parentheses\n";
    }

    return 0;
}


// fn definition 
bool checkValidParentheses(string& str) {
    bool ans = true;
    int n = str.length();
    stack<char> stk;         // stack<int> nt ... 
    int r =0 ;

    if (str.size() % 2 != 0) return false; // odd length can't be valid

    while(r <= n-1) {
        if(str[r] == '[' || str[r] == '{' || str[r] == '(') {
            stk.push(str[r]);
        }
        else if (str[r] == ']' || str[r] == '}' || str[r] == ')') {
            if(stk.empty()) {     // case    }} ,   ]]  
                return  false; 
            }
            
            char ch = stk.top();   stk.pop();
            if( (str[r] == ')' && ch == '(')  || 
                (str[r] == ']' && ch == '[')  || 
                (str[r] == '}' && ch == '{') ) 
            {
                    ans = true;
                    // continue;         //   [ )  ,   { }
            }
            else {
                return false;      //   [ ) 
            }
        }

        r++;
    } // whl 


    
    if(!stk.empty()) {     // [] (
        return false;
    }

    return ans;


} // fn 


/*

Time Complexity
We will calculate each part and sum:

Loop over all characters → O(n)

Each push/pop is O(1).

Max n iterations.

Stack operations:

Push at most n/2 times → O(n/2) ≈ O(n).

Pop at most n/2 times → O(n/2) ≈ O(n).

Total TC:

mathematica
Copy
Edit
O(n) [loop] + O(n) [stack push/pop] = O(n)



Space Complexity
We’ll separate into memory to store input and auxiliary space:

Input string storage → O(n) (given by input).

Stack space:

Worst case: all characters are opening brackets → stack size = n → O(n) extra.

Total SC:

mathematica
Copy
Edit
O(n) [input] + O(n) [stack aux space] = O(n)
*/




// or 
// ****************************************

// #include <bits/stdc++.h>
// using namespace std;

// // Function to check if parentheses are valid
// bool checkValidParentheses(const string& str) {
//     stack<char> stk;

//     for (char ch : str) {
//         if (ch == '(' || ch == '[' || ch == '{') {
//             stk.push(ch);
//         } else if (ch == ')' || ch == ']' || ch == '}') {
//             if (stk.empty()) return false;
//             char top = stk.top(); stk.pop();

//             if ((ch == ')' && top != '(') ||
//                 (ch == ']' && top != '[') ||
//                 (ch == '}' && top != '{')) {
//                 return false;
//             }
//         }
//     }

//     return stk.empty();
// }

// int main() {
//     string str;
//     getline(cin, str);

//     if (checkValidParentheses(str)) {
//         cout << "Valid Parentheses\n";
//     } else {
//         cout << "Invalid Parentheses\n";
//     }

//     return 0;
// }



/*
✅ Time & Space Complexity:
Time Complexity: O(n) — where n is the length of the input string.

Space Complexity: O(n) — in the worst case, the stack holds all opening brackets.

*/



// or
// way 2 ... usng stack and map



/*

Improvements
Unnecessary ans variable — we can directly return when mismatch is found, no need to track separately.

Minor optimization — If length is odd, return false early (no odd-length string can be valid).

Stack type clarity — stack<char> is correct, but using unordered_map for matching pairs makes code cleaner.

Better input handling — use getline to handle spaces, but also trim any trailing spaces.

Readability — loop directly over characters with for (char c : str) instead of manual indexing.

Updated Code
cpp
Copy
Edit
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

bool checkValidParentheses(const string &str) {
    if (str.size() % 2 != 0) return false; // odd length can't be valid

    unordered_map<char, char> match = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
    stack<char> stk;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } 
        else if (match.count(c)) { 
            if (stk.empty() || stk.top() != match[c]) return false;
            stk.pop();
        }
        // ignoring non-bracket characters (optional)
    }

    return stk.empty();
}

string getTrimmedLine(string input) {

    // Trim leading spaces
    while (!input.empty() && (input.front() == ' ' || input.front() == '\t')) {
        input.erase(input.begin());
    }

    // Trim trailing spaces
    while (!input.empty() && (input.back() == ' ' || input.back() == '\t')) {
        input.pop_back();
    }

    return input;
}

int main() {
    string str;
    getline(cin, str);

    string actual_str = str;
    string str = getTrimmedLine(str);
     
   if (checkValidParentheses(str)) {
        cout << "Valid Parentheses\n";
    } else {
        cout << "Invalid Parentheses\n";
    }

    return 0;
}

Interview Tips (Specific to this Problem)
Always check for odd-length strings early — instant rejection saves time.

A stack is the most natural choice for matching brackets; don’t overcomplicate with counters.

Be ready to handle non-bracket characters if interviewer extends problem.

Show you can optimize for only 3 types of brackets — not generic grammar parsing.

Clarify if empty string is valid — most definitions say yes.

Mention edge cases in interview — "(", "[]", "", "([{}])", "{[}]".

Using a map for matching pairs is clean and reduces if checks.

Discuss trade-off: Using an array lookup instead of unordered_map for tiny set of keys is faster.

If interviewer asks for O(1) extra space — say it’s impossible for general case without modifying input.

Be comfortable writing this without STL for low-level environments.



Interview Q&A
Basic (directly related)
Q: Why use a stack for this problem?
A: Because we need LIFO order — the last opening bracket must be matched first with a closing one.

Q: What happens if you encounter a closing bracket when the stack is empty?
A: It's invalid — means there's no corresponding opening bracket.

Q: Can an odd-length string be valid?
A: No, because each valid pair has length 2.

Q: What's the time complexity of your solution?
A: O(n), where n is the string length.

Q: What if there are characters other than ()[]{}?
A: Either ignore them or handle based on problem constraints.

Pro-level (extensions)
Q: How would you modify your solution to return the index of the first mismatch?
A: Keep track of the current index; return it when mismatch or stack empty issue occurs.

Q: How to validate HTML/XML tags using similar approach?
A: Use a stack but store strings (tag names) instead of chars, and check matching closing tags.

Q: How would you check multiple types of symbols with precedence rules?
A: Extend match map, and possibly keep precedence metadata.

Q: Can we solve this in O(1) extra space?
A: Not in general — we need to store unmatched opening brackets, requiring O(n) in worst case.

Q: If input is a stream (real-time), can you validate without storing whole string?
A: Yes — process each char as it arrives, maintaining stack in memory (still O(n) space worst case).

*/ 