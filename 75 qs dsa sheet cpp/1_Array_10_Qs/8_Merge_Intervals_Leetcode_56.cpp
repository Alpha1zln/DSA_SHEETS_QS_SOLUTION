
// Q 8 .. 
// _Leetcode_56  .. MERGE INTERVALS

#include <iostream>
#include <vector>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void mergeIntervals(vvi& intervals, vvi& mergedIntervalsVec);
void printArr(vvi& mergedIntervalsVec);


// main fn
int main() {
    
    vvi intervals;   vvi mergedIntervalsVec;
    intervals = { {1,6}, {4,8}, {10,14}, {12,16}, {18,20} } ;
    
    mergeIntervals( intervals, mergedIntervalsVec);
    printArr( mergedIntervalsVec);

    return 0;
}




// fn defntn
void mergeIntervals(vvi& intervals, vvi& mergedIntervalsVec) {
    if (intervals.empty()) return;
    int n =  intervals.size();

    vvi sortedIntervals = intervals; // copy to sort
    sort(sortedIntervals.begin(), sortedIntervals.end());

    for(int i=0; i<n; i++) {
        if(mergedIntervalsVec.empty() || mergedIntervalsVec.back()[1] < sortedIntervals[i][0]) {
            mergedIntervalsVec.push_back(sortedIntervals[i]);
        }
        else {
            //mergedIntervalsVec.back()[1] = sortedIntervals[i][1];
            mergedIntervalsVec.back()[1] = max(mergedIntervalsVec.back()[1], sortedIntervals[i][1]);

        }
    } // for
}


void printArr(vvi& mergedIntervalsVec) {
    cout << "Merged Intervals :: " << endl;

    for(const auto& vc : mergedIntervalsVec) { /// & ... to avoid making its copy and taking extra mem space 
        for(int i=0; i<vc.size(); i++) {
            cout << vc[i] ;
            if(i != vc.size()-1)
                cout << " ";
            // or  
            // cout << vc[i] << (i <= vc.size()-2 ? " " : "");
        }
        cout << endl;
    }
}



/*

1️⃣ Time Complexity (TC)
We’ll trace the steps:

Copying intervals → sortedIntervals = intervals

O(n)

Sorting the intervals → sort(sortedIntervals.begin(), sortedIntervals.end())

Sorting n intervals based on start time: O(n log n)

Merging intervals in one pass → for (i=0 to n-1)

One linear traversal: O(n)

✅ Final TC:

𝑂
(
𝑛
log
⁡
𝑛
)
(
sorting dominates
)
O(nlogn)(sorting dominates)
2️⃣ Space Complexity (SC)
Sorted copy of intervals → sortedIntervals

O(n)

Merged intervals result vector → mergedIntervalsVec

Worst case, no merge happens → stores all n intervals → O(n)

✅ Final SC:

𝑂
(
𝑛
)
(
ignoring input storage
)
O(n)(ignoring input storage)
3️⃣ Code Review & Tips
Sorting Copy vs Sorting in Place
Instead of making a copy sortedIntervals, you could sort intervals directly if original order doesn’t matter.
That will save O(n) extra space.

Merging Condition
Currently:

cpp
Copy
Edit
mergedIntervalsVec.back()[1] = sortedIntervals[i][1];
This assumes intervals are overlapping and we always take the current end.
But safer merge is:

cpp
Copy
Edit
mergedIntervalsVec.back()[1] = max(mergedIntervalsVec.back()[1], sortedIntervals[i][1]);
This handles cases where current interval is partially overlapping.

Pass by Reference for Printing
You already used const auto& vc in printArr — good for memory efficiency.

Use struct for readability (optional)
Instead of vector<vector<int>>, you could use a struct Interval {int start, end;} for clarity.

4️⃣ 10 Interview Q&A Related to Merge Intervals
Q1: Why do we sort intervals before merging?
A: Sorting ensures intervals are processed in increasing start time, which guarantees that once you check an interval, you only need to compare it with the last merged one for possible overlap.

Q2: What’s the time complexity of your approach?
A:

Sorting: O(n log n)

Merge pass: O(n)

Final: O(n log n)

Q3: Could we do this in O(n) without sorting?
A:
Only if the intervals are already sorted by start time. Otherwise, sorting is necessary.

Q4: How would you handle if intervals are unsorted but we can't sort due to constraints?
A:
We could use a sweep-line algorithm with a map or bucket sort (if bounded range), but in most cases, sorting is unavoidable.

Q5: How do you check if two intervals overlap?
A:
Two intervals [a,b] and [c,d] overlap if:

𝑐
≤
𝑏
c≤b
assuming a ≤ c.

Q6: How do you modify the solution to also return the count of merged intervals?
A:
Just return mergedIntervalsVec.size() after merging.




*/




/*
Interview Tips (7 total)
Sort first, always — unless input is guaranteed sorted (mention this in interview).

Check overlaps carefully — condition is current.start <= lastMerged.end.

Use max() when merging ends — handles the "contained interval" case.

Pass by const reference for large inputs to avoid copies unless you need sorting.

Edge case mindset — empty list, single interval, all disjoint, all overlapping.

Output order — merged intervals remain sorted by start time automatically.

Explain complexity upfront — Sorting O(n log n) dominates.

5 Moderate-Level Interview Q&A
Q1: How do you detect if two intervals [a,b] and [c,d] overlap?
A1: If c <= b and intervals are sorted by start time.

Q2: Can we merge intervals in O(n) time?
A2: Only if input is already sorted by start time.

Q3: Why use max(end1, end2) while merging?
A3: Because one interval may fully contain another.

Q4: What’s the space complexity of your solution?
A4: O(n) for the output list; O(1) extra if merged in-place.

Q5: What’s the worst-case number of merged intervals?
A5: If no intervals overlap, output will have n intervals.

5 Pro-Level Interview Q&A
Q6: How would you merge intervals if they are streaming (coming one by one)?
A6: Use an ordered data structure (like std::map or balanced BST) to insert and merge in O(log n) per insert.

Q7: How to extend this to merge k sorted lists of intervals?
A7: Use a min-heap to merge them like merging k sorted arrays, then merge overlaps.

Q8: How to handle merging 2D intervals (rectangles)?
A8: Check overlaps in both x and y dimensions; might need line sweep or segment trees.

Q9: How to adapt for finding gaps between intervals?
A9: After merging, iterate through merged list and record [end_i, start_{i+1}] gaps.

Q10: How to merge when intervals can have open/closed boundaries?
A10: Overlap check changes — e.g., [1,3) and (3,5] don’t overlap if both ends are open.

Dry Run Example
Input:

Copy
Edit
{ {1,6}, {4,8}, {10,14}, {12,16}, {18,20} }
Sorted (already):

Copy
Edit
{ {1,6}, {4,8}, {10,14}, {12,16}, {18,20} }
Processing:

{1,6} → push to merged.

{4,8} → overlap (4 ≤ 6) → merge → {1,8}.

{10,14} → push new.

{12,16} → overlap → {10,16}.

{18,20} → push new.

Output:

Copy
Edit
{ {1,8}, {10,16}, {18,20} }

*/