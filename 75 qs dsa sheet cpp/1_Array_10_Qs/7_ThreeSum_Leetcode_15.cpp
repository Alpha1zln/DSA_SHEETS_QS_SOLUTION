
// Q 7 .. 
// _Leetcode_15  .. THREE SUM QS

#include <iostream>
#include <vector>
#include <algorithm>
// #include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void find3Sum(vi& nums, int& target, vvi& threeSumVec);
void printArr(vvi& threeSumVec);



int main() {
    
    // vector<int> nums = {1, 2, 0,  3, 4, 5}; // wtt reptn  
    //   0 1 2 3 4 5 ... 0 1 5, 0 2 4, 1 2 3

    vector<int> nums = {1, 2, 0, 1, 3, 4, 2, 5}; // wth reptn 

    int target = 6;

    int n = nums.size();
    vvi threeSumVec;
    
find3Sum(nums,  target, threeSumVec);
printArr(threeSumVec);

    return 0;
}


// fn defntn
void find3Sum(vi& nums, int& target, vvi& threeSumVec) {
    sort( nums.begin(), nums.end() );
    int n = nums.size();
    int sm = 0;

    for(int i=0; i<n; i++) {
        sm = nums[i];
        int l = i+1,  r=n-1;

        if(i>=1) { // check duplication
            if(nums[i]==nums[i-1]) 
                continue;
        }

        while(l < r) {
            while(l+1<=n-1 && nums[l] == nums[l+1]) l++;  // handle reptn
            while(r+1<=n-1 && nums[r] == nums[r+1]) r--;  // handle reptn
             
            int sm2 = nums[l] + nums[r];
            int totalSum = sm + sm2;

            if(totalSum == target) {
                threeSumVec.push_back({nums[i], nums[l], nums[r] });
                l++;
            }
            else if(totalSum < target) {
                l++;
            }
            else {
                r--;
            }
            
        } // while end 
    } // for 
}


void printArr(vvi& threeSumVec) {
   // int idx;

    for(auto vc : threeSumVec) {
        for(auto e : vc) {
            cout << e  ;
            cout <<  " " ;
        }
        cout << endl;
    }
}



// op ------
// 0  1  5  
// 0  2  4
// 1  1  4
// 1  2  3


/*
Steps of the Algorithm
Sort array → makes duplicate skipping and two-pointer approach possible.

Loop i from 0 to n-3:

Skip duplicates for i.

Set two pointers: l = i+1, r = n-1.

While l < r:

If sum == target → store triplet, move l and r skipping duplicates.

If sum < target → increment l.

If sum > target → decrement r.

Time Complexity
Sorting: O(n log n)

Outer loop: O(n)

Two-pointer inner loop: O(n)

Total: O(n²)

Space Complexity
O(1) extra (excluding result storage).

5 Interview Tips
Always mention sorting first and why it helps with duplicate removal + two-pointer approach.

Stress time complexity improvement from O(n³) to O(n²).

Be ready to handle duplicate numbers cleanly — it’s a common trap.

Mention that result triplets are always in sorted order (inside the triplet).

Be aware of edge cases — less than 3 numbers, all numbers same, no triplets found.

5 Sample Q&A
Q1: Why sort the array first?
A: Sorting enables the two-pointer technique and makes duplicate removal easy.

Q2: Could you do this without sorting?
A: Yes, with a hash set, but sorting is simpler and often faster due to better constants.

Q3: How do you ensure no duplicate triplets?
A: Skip identical elements for i, and also after finding a triplet skip identical l and r.

Q4: What’s the output order of triplets?
A: In ascending order within each triplet, and lexicographically sorted because of sorted input.

Q5: How to extend to k-sum?
A: Use recursion to reduce k-sum to (k-1)-sum, and base case to 2-sum with two pointers.
*/



/*
Code Review & Improvements
✅ What’s good in your code

Correctly uses sorting + two pointers → optimal O(n²) approach.

Has duplicate skipping logic — both for i and inside l/r loop.

Uses vector<vector<int>> to store triplets — good for direct return.

🔹 Improvements I’d suggest

Includes

Avoid <bits/stdc++.h> (not standard). Use:

cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <algorithm>
Duplicate Skipping Logic

Your while loops for skipping duplicates inside l/r are in the wrong place.
They run before checking sums, which can skip valid results.
The standard approach: move l and r after finding a valid triplet, then skip duplicates.

Uninitialized Variable idx in printArr

You declare int idx; but never assign it, so (idx != 2) is undefined behavior.

You probably wanted to use a loop counter.

Redundant sm variable

sm = nums[i] is fine, but you could just directly use nums[i] when summing.

Pass by Const Reference

find3Sum doesn’t modify target, so int& target should be const int& target.

printArr can take const vvi& since it doesn’t modify.
*/







/*
Pass by Const Reference ... why ...whats benefit


ChatGPT said:
Ahh, the "Pass by Const Reference" thing — let’s talk like two dev buddies over chai ☕.

1️⃣ What It Means
When you pass a parameter in C++ like this:

cpp
Copy
Edit
void func(const vector<int>& nums);
You are doing two things:

Reference (&) → you pass the actual object, no copy is made.

Const → you promise not to change it inside the function.

2️⃣ Why It’s Better
🚀 Performance
Without reference:

cpp
Copy
Edit
void func(vector<int> nums);
⬆️ This copies the entire vector into the function.
If nums has 10 million integers… ouch — that's 40 MB copied for no reason.

With reference:

cpp
Copy
Edit
void func(vector<int>& nums);
Only a pointer-size reference (8 bytes) is passed — much faster.

🛡 Safety (Const part)
If you use:

cpp
Copy
Edit
void func(vector<int>& nums);
You could accidentally modify nums inside the function — maybe by typo.

Using:

cpp
Copy
Edit
void func(const vector<int>& nums);
Compiler stops you if you try to modify it:

cpp
Copy
Edit
nums.push_back(10); // ❌ compile error
This makes it clear to anyone reading the code:
“Hey, this function won’t change your data.”

📝 Example
Bad (copying unnecessarily):

cpp
Copy
Edit
void printVec(vector<int> v) { // copies full vector ❌
    for (auto x : v) cout << x << " ";
}
Better (fast & safe):

cpp
Copy
Edit
void printVec(const vector<int>& v) { // no copy, no modification ✅
    for (auto x : v) cout << x << " ";
}
3️⃣ TL;DR
Reference → avoids expensive copy

Const → prevents accidental modification

Together = fast + safe

Use for large objects (vector, string, map, struct, etc.)


*/
