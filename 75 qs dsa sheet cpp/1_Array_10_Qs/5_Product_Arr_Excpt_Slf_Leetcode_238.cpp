
// Q 5 .. 
// _Leetcode_238  .. PRODUCT OF ARRAY EXCEPT SELF 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void productArrExcptSelf(vector<int>& nums, vector<int>& prodArrExptSlf);
void printArray(vector<int>& prodArrExptSlf);


int main() {

    vector<int> nums = {1, 2, 0,  3, 4, 5};   //  with 0 
    // vector<int> nums = {1, 2, -1,  3, 4, 5};     // wtt 0
    int n = nums.size();
    vector<int> prodArrExptSlf(n, 1);
    
    productArrExcptSelf( nums, prodArrExptSlf);
    printArray(prodArrExptSlf);

    return 0;
}


// fn defntn
void productArrExcptSelf(vector<int>& nums, vector<int>& prodArrExptSlf) {
    int lt = 1 , rt = 1;
    int n = nums.size();
    int endIdx = n-1;   int stIdx = 0;
    

    while(stIdx <=n-1   &&   endIdx >=0 ) {
        prodArrExptSlf[stIdx] *= lt;
        lt *= nums[stIdx];   stIdx++;

        prodArrExptSlf[endIdx] *= rt;
        rt *= nums[endIdx]; endIdx--;
    }

}




void printArray(vector<int>& prodArrExptSlf) {

    cout << "product Arr Excpt Self :: " << endl;
    for(auto e : prodArrExptSlf) {
        cout << e << " " ;
    }
}



/*

Method – Two-Pointer Prefix & Suffix Product (Without Division)
How It Works (Step-by-Step)
Step 1: Create a result array prodArrExptSlf initialized with 1 for all elements.

Step 2: Use a left product variable lt starting at 1.

Traverse from left to right.

For each index i, multiply prodArrExptSlf[i] by lt (which represents product of all elements before i).

Update lt by multiplying it with nums[i].

Step 3: Use a right product variable rt starting at 1.

Traverse from right to left.

For each index i, multiply prodArrExptSlf[i] by rt (which represents product of all elements after i).

Update rt by multiplying it with nums[i].

Step 4: At the end, prodArrExptSlf[i] contains the product of all numbers except nums[i].

Time Complexity
Left pass: O(n)

Right pass: O(n)

Total: O(n)

Space Complexity
Output array: O(1) extra (excluding result array)

No extra prefix/suffix arrays → space efficient.

Pros
O(n) time complexity — optimal.

No division used (works with zero values).

Handles negative numbers correctly.

Space-optimized — no extra prefix/suffix arrays.

Works for both small and large arrays efficiently.

Cons
Slightly more tricky to understand for beginners compared to prefix/suffix array method.

Multiplication overflow possible for very large numbers (unless using long long).

Does not short-circuit if array is huge but has many zeros — still does full pass.

Requires careful handling of lt and rt to avoid logic errors.

Not suitable for floating-point precision-sensitive applications.

Interview Tips
If interviewer allows division and no zeros → simpler method is (total_product / nums[i]).

If zeros are present → you need to handle cases separately (0 count == 1 or >1).

This two-pointer approach is considered the "best" because it is O(n) and O(1) extra space.

Always confirm integer overflow constraints with interviewer.

Be ready to explain the logic without code using an example array.

5 Interview Questions & Answers
Q1: Why not just use division?
A1: Division fails if there’s a zero in the array, and can lead to integer division rounding issues.

Q2: How would you handle exactly one zero in the array?
A2: Multiply all non-zero elements, and set the product at the zero index to that value, all others to 0.

Q3: What if there are more than one zero?
A3: The entire result array becomes all zeros because every product will include at least one zero.

Q4: Why is this method O(1) extra space?
A4: We only use two variables (lt, rt) in addition to the result array — no additional arrays.

Q5: Can this be done in-place in the input array?
A5: Not directly if we must preserve the input; but if overwriting is allowed, we can reuse nums for the result.




*/