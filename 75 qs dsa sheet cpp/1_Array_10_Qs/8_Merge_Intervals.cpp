
// Q 8 .. 
// 56  .. MERGE INTERVALS

#include<bits/stdc++.h>
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
    int n =  intervals.size();

    for(int i=0; i<n; i++) {
        if(mergedIntervalsVec.empty() || mergedIntervalsVec.back()[1] < intervals[i][0]) {
            mergedIntervalsVec.push_back(intervals[i]);
        }
        else {
            mergedIntervalsVec.back()[1] = intervals[i][1];
        }
    } // for
}


void printArr(vvi& mergedIntervalsVec) {
    cout << "Merged Intervals :: " << endl;

    for(auto vc : mergedIntervalsVec) {
        for(int i=0; i<vc.size(); i++) {
            cout << vc[i] ;
            if(i != vc.size()-1)
                cout << " ";
        }
        cout << endl;
    }
}
