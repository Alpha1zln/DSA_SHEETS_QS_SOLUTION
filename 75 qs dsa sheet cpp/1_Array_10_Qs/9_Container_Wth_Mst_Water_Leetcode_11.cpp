
// Q 9 .. 
// _Leetcode_11  .. CONTAINER WITH MOST WATER 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void findContainerMostWater(vi& container, int& mostWater);
// void printArr(vvi& mergedIntervalsVec);


// main fn
int main() {
    
    vi container;       container = { 1, 2, 3, 2, 3, 2 } ;
    int mostWater = INT_MIN;

    findContainerMostWater(container, mostWater);

    return 0;
}



// FN DEFNTN
void findContainerMostWater(vi& container, int& mostWater) {

    int n = container.size();
    int l=0, r=n-1;
    int curr_water = 0;

    while(l < r) { 
        int ht = min(container[l], container[r]);
        int wd = r-l;   // width
        curr_water = ht * wd; 
        mostWater = max(curr_water, mostWater);

        if(container[l] <= container[r]) {
            l++;
        }
        else {
            r--;
        }
    }

    cout << "Most Water :: " << mostWater << endl;

}


/*
Time & Space Complexity
pgsql
Copy
Edit
Time Complexity: O(n)
Reason: We use two pointers, each moving at most n steps, so total operations are proportional to n.

Space Complexity: O(1)
Reason: We use only a few extra variables (l, r, curr_water, etc.) regardless of input size.
Improvements & Updated Code
Issues in your code:

INT_MIN is not ideal for initial mostWater — better to start with 0 because area is always non-negative.

Function should return value instead of modifying int& mostWater (makes it cleaner).

typedef lines aren’t actually needed here.

Extra function call passing mostWater by reference is less readable for such a simple calculation.

Added input flexibility in case you want to test easily.

Updated Code:

cpp
Copy
Edit
#include <bits/stdc++.h>
using namespace std;

int findContainerMostWater(const vector<int>& container) {
    int n = container.size();
    int l = 0, r = n - 1;
    int mostWater = 0;

    while (l < r) {
        int ht = min(container[l], container[r]);
        int wd = r - l;
        mostWater = max(mostWater, ht * wd);

        if (container[l] <= container[r]) {
            l++;
        } else {
            r--;
        }
    }
    return mostWater;
}

int main() {
    vector<int> container = {1, 2, 3, 2, 3, 2};
    cout << "Most Water :: " << findContainerMostWater(container) << endl;
    return 0;
}
5 Interview Tips
Explain Your Approach First – Don’t start coding immediately; outline your logic so the interviewer follows your thought process.

Dry Run With Examples – Use a small test case to validate before coding fully.

Handle Edge Cases – Mention empty input, single element, or all equal heights.

Time & Space Complexity – Always mention it before finalizing your answer.

Clean & Readable Code – Use meaningful variable names like left and right instead of l and r for interviews.

5 Moderate Questions Based on Code (with Answers)
Q1. Why do we move the pointer at the smaller height in each step?
A1. Moving the larger height doesn’t help because the area is limited by the smaller height; only moving the smaller height can potentially increase area.

Q2. What happens if all container heights are equal?
A2. The maximum water will be (n-1) * height (first and last elements chosen).

Q3. What’s the minimum possible output for any non-empty input?
A3. 0, when there’s only one bar or no container at all.

Q4. Why is O(1) space possible here?
A4. We only use two pointers and constant extra variables.

Q5. Could a brute force method work here?
A5. Yes, by checking all pairs (i, j) → O(n^2) time, but it’s inefficient for large inputs.

5 Professional/Challenging Questions (with Answers)
Q1. Modify this solution to also return the indices of the two lines forming the maximum container.
A1. Keep track of (l, r) whenever a new max is found, and return them with the area.

Q2. Can this problem be solved using Divide & Conquer?
A2. Yes, but it would be less efficient (~O(n log n)), so the two-pointer greedy approach is better.

Q3. If container heights are in a file too large to fit in memory, how would you adapt the algorithm?
A3. Use a streaming approach with two-pointer logic while reading from both ends of the file in chunks.

Q4. How would you modify the code if the "width" was not (j-i) but a given array of distances?
A4. Replace (r-l) with distance[r] - distance[l] in the area calculation.

Q5. If water could be "stacked" above shorter lines (like in rainwater trapping), how would the logic change?
A5. That becomes the "Trapping Rain Water" problem, which needs prefix/suffix max arrays or two-pointer cumulative approach.

*/