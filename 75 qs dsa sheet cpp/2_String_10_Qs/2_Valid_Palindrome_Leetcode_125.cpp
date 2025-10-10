// // Q 2 - String

// // _Leetcode_125, Valid Palindrome
// //  

// // valid - ex - radar 
// // nope - ex - hello

#include <iostream>
#include <string>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair <int, int> pi;


// // fn declaration 
bool checkValidPalindrome(string& str);
bool isAlphaDigit(char ch ) ;

// // main fn 
int main( ) {

    string str;
    // cin >> str;  
    cout << "Enter a string : " << endl;
    getline(cin, str);  // to read the entire line including spaces

    bool isValid = checkValidPalindrome(str);
    if(isValid) {
        cout << "Valid Palindrome\n";
    }
    else {
        cout << "Invalid Palindrome\n";
    }

    return 0;
}


bool isAlphaDigit(char ch ) {

    if( (ch>=65 && ch<=90) || (ch>=97 && ch<=122) 
        || (ch>=48 && ch<=57) ) {
            return true;
    }
    return false;
}


char convetTolower(char ch ) {
    char lwr = ch ;
    if(ch>=65 && ch<=90) {
        lwr = ch - 'A' + 'a';
    }
    return lwr;
}

// fn definition 
bool checkValidPalindrome(string& str) {
    int n = str.length();
    
    // ex -   "who 58  am   ma 85 ohw"
    
    string onlyStr = "";
    for(int i = 0; i < n; i++) {
        // if(isalnum(str[i])) {  // check if the character is alphanumeric
        // if(isalpha(str[i]) || isdigit(str[i])) {  // check if the character is alphabetic or digit
        if(isAlphaDigit(str[i])) {
            // onlyStr += tolower(str[i]);  // convert to lowercase and append
            onlyStr += convetTolower(str[i]);
        }   
    }

    int n_onlyStr = onlyStr.length();
    int l = 0, r = n_onlyStr - 1;

    while(l < r) {
        if(onlyStr[l] != onlyStr[r]) {
            return false;
        }
        l++; r--;
    }

    return true;
}



/*
Enter a string : 
radar
Valid Palindrome

Enter a string : 
ra 89 98 ar
Valid Palindrome

Enter a string : 
radar 45 radar 
Invalid Palindrome
*/


/*
Time Complexity (TC): O(n), where n is the length of the input string.

Space Complexity (SC): O(n), where n is the length of the input string (due to the creation of onlyStr).

*/

/*
Your Code (using loop to read and trim)

Time Complexity (TC):

Reading input with getline → O(n) where n = length of string

Loop from end to find last non-space char → O(n) in worst case (all spaces at end)

Erasing trailing spaces → O(k) where k = number of spaces removed (≤ n)
Total: O(n) + O(n) + O(n) = O(n)

Space Complexity (SC):

String storage → O(n)

No extra data structures → O(1) extra
Total: O(n) overall (dominated by input string)
*/



/*

5–10 Interview Tips Related to This Code
Mention edge cases — e.g., empty string, string with only spaces, numbers mixed with letters.

Discuss ASCII vs Unicode — this code works for ASCII; for Unicode, need wstring and locale-aware functions.

Explain two-pointer approach — saves memory compared to building a cleaned string.

Highlight input preprocessing — skip non-alphanumeric chars on the fly.

Show awareness of built-ins — isalnum and tolower are optimized.

Test tricky cases — "A man, a plan, a canal: Panama", "No lemon, no melon".

Talk about SC optimization — removing onlyStr improves SC.

Avoid unnecessary copying — prefer references (string&) to avoid string duplication.

Be prepared to handle large input — O(n) is optimal; O(n²) would be unacceptable.

Show maintainability — clean, readable names and clear loop structure.

5 Basic Interview Q&A
Q1: What’s the difference between isalnum and isalpha?
A1: isalnum checks for letters and digits, isalpha checks only for letters.

Q2: Why use two pointers instead of reversing the string?
A2: Saves memory (O(1) vs O(n)) and avoids extra copy.

Q3: What happens if input is empty?
A3: The function returns true, as an empty string is a valid palindrome.

Q4: Does this work for uppercase/lowercase letters?
A4: Yes, because we use tolower() before comparison.

Q5: What’s the time complexity?
A5: O(n), where n is the input length.

5 Pro-Level Interview Q&A
Q1: How would you handle Unicode characters?
A1: Use wstring with iswalnum and locale-aware lowercase conversion.

Q2: Can you solve it in O(1) extra space without modifying the string?
A2: Yes, with the two-pointer method as implemented here.

Q3: How to make it case-sensitive?
A3: Remove the tolower() conversion before comparison.

Q4: How to count palindrome mismatches instead of just boolean?
A4: Keep a mismatch counter instead of returning early.

Q5: How would you adapt this to ignore punctuation but count spaces as valid characters?
A5: Modify the while (!isalnum()) conditions to only skip punctuation, not spaces.

*/ 






// or *********************
// way 2 


/*

#include <iostream>
#include <string>
#include <cctype> // for isalnum, tolower
using namespace std;

bool checkValidPalindrome(string &str) {
    int l = 0, r = str.length() - 1;
    
    while (l < r) {
        while (l < r && !isalnum(str[l])) l++; // skip non-alphanumeric
        while (l < r && !isalnum(str[r])) r--; // skip non-alphanumeric
        
        if (tolower(str[l]) != tolower(str[r])) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string:\n";
    getline(cin, str);
    
    if (checkValidPalindrome(str))
        cout << "Valid Palindrome\n";
    else
        cout << "Invalid Palindrome\n";
}


*/




/*

gpt Code (using find_last_not_of)

Time Complexity (TC):

Reading input with getline → O(n)

find_last_not_of internally scans from end → O(n) worst case

Erasing trailing spaces → O(k) where k ≤ n
Total: O(n) + O(n) + O(n) = O(n)

Space Complexity (SC):

String storage → O(n)

No extra data structures → O(1) extra
Total: O(n) overall
*/