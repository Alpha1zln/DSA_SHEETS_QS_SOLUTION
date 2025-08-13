
// Q .. 3        // mergeSortedArray
// _Leetcode_88 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

// function protoype
void mergeSortedArray(vector<int>& nums1, vector<int>& nums2 , int m, int n);
void printArray(vector<int>& nums1);


int main() {

    int m=6, n=2;
    vector<int> nums1(m);     vector<int> nums2; 
    nums1 = {2, 4, 0 , 0 ,0 , 0};
    nums2 = {1, 5, 6, 8};
    // cout << nums1.size() << endl;
    // cout << nums2.size();
    
    mergeSortedArray(nums1, nums2, m , n);
    printArray(nums1);
    return 0;
}


// function definition
void mergeSortedArray(vector<int>& nums1, vector<int>& nums2 , int m, int n) 
{
    int n1_total = m-1;    int n2 = nums2.size();
    int n1_part = n ;
    
    // cout << "n1_part : " << n1_part << " & n1_total : " << m <<endl;
    // cout<< nums1[5] << " 5th" << endl;

    // for(auto e : nums1) 
    //     n1_part++;

    int r1=n1_part-1, r2=n2-1; 
 
    while(r1>=0 && r2>=0) {
        if(nums1[r1] > nums2[r2]) {        // imp
            nums1[ n1_total ] = nums1[r1];
            r1--;
        }
        else {
            nums1[n1_total] = nums2[r2];
            r2--;
        }
        cout << nums1[n1_total] << endl;
        n1_total--;
    }

     while(r1>=0 ) {
            nums1[n1_total] = nums1[r1];
            cout << nums1[n1_total] << endl;
            r1--;
            n1_total--;
            
    }


    while(r2 >= 0 ) {
        nums1[n1_total] = nums2[r2];
        cout << nums1[n1_total] << endl;
        r2--;
        n1_total--;
    }

}


void printArray(vector<int>& nums1) {

    cout << "Merge sorted elts :: " << endl;
    for(auto e : nums1) {
        cout << e << " " ;
    }
}


/*
Method – Merge from the End (Two Pointer Backward Merge)
How It Works (Step-by-Step):
Step 1: We have two sorted arrays: nums1 (with extra space at the end) and nums2. The task is to merge them into nums1 in sorted order.

Step 2: Use three pointers:

r1 → points to the last actual element in nums1 (before the extra zeros).

r2 → points to the last element in nums2.

n1_total → points to the last position in nums1 (including extra space).

Step 3: Compare elements at nums1[r1] and nums2[r2]. Place the larger one at nums1[n1_total].

Step 4: Move the pointer (r1 or r2) from which you took the element, and also move n1_total one step left.

Step 5: If one array is exhausted, copy remaining elements from the other array into nums1.

Step 6: At the end, nums1 will be fully sorted and contain all elements.

Time Complexity:
Comparing and inserting each element → O(m + n)

Total: O(m + n)

Space Complexity:
We do merging in-place in nums1 → O(1) extra space.

Pros:
Works in-place, no extra memory required.

Linear time complexity O(m + n).

Maintains sorted order perfectly.

Avoids shifting multiple elements (compared to forward merge).

Well-suited for large datasets where extra memory is expensive.

Cons:
Slightly tricky for beginners because of backward indexing.

Only works when nums1 has enough trailing space to hold all elements.

Extra care needed to handle pointer boundaries.

Not directly applicable if merging into a separate array is required.

Requires both arrays to be already sorted.

Interview Tip:
If interviewer says “nums1 has extra space at the end” → immediately think backward merge to avoid shifting elements.
If both arrays are sorted and extra space is not available, use an auxiliary array → O(m + n) space.
Mention that forward merge in-place would be O(m × n) in worst case due to repeated shifting.

5 Interview Questions & Answers
Q1: Why do we merge from the back instead of the front?
A1: Merging from the back avoids overwriting unprocessed elements in nums1 and eliminates the need for repeated shifting of elements, which could make it O(m × n).

Q2: What if nums1 doesn’t have enough extra space?
A2: We’d need to create a new array to hold merged results (O(m + n) space) or shift elements manually, which increases complexity.

Q3: What’s the best case time complexity here?
A3: Still O(m + n) because we must look at every element at least once to place it in sorted order.

Q4: Can we use this if the arrays are not sorted?
A4: No — first you’d have to sort both arrays (O(m log m + n log n)), then merge.

Q5: How can we adapt this if nums1 and nums2 are linked lists?
A5: We’d merge forward (since linked lists can’t be indexed backward) using a dummy head pointer to build the merged list.

*/