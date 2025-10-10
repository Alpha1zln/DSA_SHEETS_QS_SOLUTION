
#include<bits/stdc++.h>
using namespace std;    


// Q 7 
// Find the index of first occurence of a string in big string
// ltcd 28

// fn declaration
int firstOccurence(string needle, string haystack) ;


int main() {

    string needle;    cout << "Enter needle string : " << endl;
    getline(cin, needle);

    string haystack;    cout << "Enter haystack big string : " << endl;
    getline(cin, haystack);

    int first_Occ = firstOccurence(needle, haystack);
    cout << "First Occ index of string - " << needle << " is : " << first_Occ << endl;
    
    return 0;
}




// fn definition
int firstOccurence(string needle, string haystack)  {
    int len_h = haystack.length();
    int len_n = needle.length();
    
    if(len_n > len_h ) return -1;

    for(int i=0; i<= len_h - len_n; i++) {      // 10 -3 = 7 .. 7 8 9
        string sub = haystack.substr(i, len_n);
        if(sub == needle) {
            return i;
        }    
    }

    return -1;

} // fm
