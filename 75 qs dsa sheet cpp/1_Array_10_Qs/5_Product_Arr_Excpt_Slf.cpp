
// Q 6 .. 
// 238  .. PRODUCT OF ARRAY EXCEPT SELF 

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