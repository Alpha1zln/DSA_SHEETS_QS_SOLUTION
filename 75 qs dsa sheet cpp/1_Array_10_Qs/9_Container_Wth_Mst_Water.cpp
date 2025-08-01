
// Q 9 .. 
// ltcd 11  .. CONTAINER WITH MOST WATER 

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