// // Q 4 - String

// // _Leetcode_49, Group Anagram
// //  

// // valid - ex - seat ... eats ... teas ...
// // nope - ex -   ... team ... meats

#include <iostream>
#include <string>
#include<vector>
#include<map>
#include <unordered_map>
#include <algorithm>

//#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair <int, int> pi;


// // fn declaration 
void checkGroupAnagram(vector<string>& str, vector< vector<string>>& result);
void printAnagrams(const vector< vector<string>>& result);

// // main fn 
int main( ) {

    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //string input;

    vector< vector<string> > result;
    checkGroupAnagram(str, result);

    cout << "Grouped Anagrams:\n";
    printAnagrams(result);

    return 0;
}


// fn definition
void checkGroupAnagram(vector<string>& str, vector< vector<string>>& result) {
    unordered_map<string, vector<string>> anagramMap;

    for (const string& s : str) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(s);
    }

    for (const auto& pair : anagramMap) {
        result.push_back(pair.second);
    }

}


// fn definition
void printAnagrams(const vector< vector<string>>& result) {
    
    for (const auto& group : result) {
        for (const string& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
}


/*
// vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
Grouped Anagrams:
bat
tan nat
eat tea ate
*/



/*
------------------------------
Your Code (sorted string key)
------------------------------

Let:
n = number of words
m = average length of a word

Step 1: Iterate over each word
TC: O(n)  // loop control
SC: O(1)  // no extra space yet

Step 2: Sort each word
TC: O(m log m) per word → O(n * m log m) total
SC: O(m) temporary for sorting

Step 3: Insert into unordered_map
TC: O(1) average per insert → O(n) total
SC: O(n * m) for storing all words

Step 4: Transfer values from map to result vector
TC: O(n) to push all words
SC: O(k) where k = number of groups (small vs total words)

Final TC: O(n * m log m)
Final SC: O(n * m)
*/



/*
3. Interview Tips (5–10)

Always clarify constraints — word length, number of words, allowed character set.

Mention that sorting approach is easier to code but slower (O(m log m)).

Frequency array key method is faster (O(m)) when alphabet size is small.

Use unordered_map for O(1) average grouping instead of map (O(log k)).

Preallocate (reserve) for map & vectors if large input to avoid reallocation.

Use move to avoid deep copies when transferring grouped words.

Be careful with case sensitivity — normalizing case may be required.

If interviewer expects Unicode — fallback to map<char32_t, vector<string>>.

Mention hash collisions possibility and worst-case complexity for unordered_map.

If memory is limited, consider streaming and outputting groups on the fly.

4. Interview Q&A (5–10)

Q1: How would you generate the key for grouping without sorting?
A1: Use a fixed-size frequency array for each letter and convert it to a string key.

Q2: Why is sorting slower than counting characters?
A2: Sorting is O(m log m) while counting is O(m) for fixed alphabet size.

Q3: Can you solve this in-place without extra space?
A3: Not directly, since grouping requires mapping between words.

Q4: How does unordered_map improve performance here?
A4: It reduces insertion/lookup from O(log k) to O(1) average.

Q5: What if the input contains uppercase and lowercase letters?
A5: Normalize to one case before generating keys.

Q6: How would you handle Unicode strings?
A6: Use map<char32_t, int> or specialized Unicode libraries to count code points.

Q7: How does the worst case of unordered_map affect performance?
A7: Worst case O(n*k) due to collisions, but rare with good hash functions.

Q8: How to sort the final groups by size?
A8: Apply sort(result.begin(), result.end(), cmp) after grouping.

Q9: What’s the space complexity of this solution?
A9: O(n * m) — storing all input words plus map keys.

Q10: Can this be parallelized?
A10: Yes, grouping different subsets of words in separate threads, then merging maps.
*/