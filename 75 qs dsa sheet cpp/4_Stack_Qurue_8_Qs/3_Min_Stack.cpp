#include<bits/stdc++.h>
using namespace std;

// Q 3 - Min. Stack Design using stack
// leetcode 155

// 1 
// using vec
// class Stack{
//     int topIdx;
//     vector<>
// }

class MinStack {
    public : 
            int topIdx;  int minVal;
            vector<pair<int, int>> vec; stack<pair<int, int>> stk; // val, mini
            int currSize; int maxSize;

            MinStack(int size) {
                currSize = 0;      maxSize = size;
                topIdx = -1;       vec.resize(size);
                minVal = INT_MAX;
            }

            void push(int val) {
                if(stk.empty()) {
                    minVal = val;
                    stk.push({val, val});
                    currSize++;
                    return;
                }

                minVal = min(val, stk.top().second);
                stk.push({val, minVal});
                currSize++;
            }

            int top() {
                if(stk.empty()) return -1;

                return stk.top().second;
            }

            bool isEmpty() {
                if(stk.empty()) return true ;
                else return false;
            }

            bool isFull() {
                if(currSize == maxSize) return true;
                else return false;
            }


            void pop() {
                if(stk.empty()) return ;
                
                int minTemp = stk.top().second;
                //cout << "minVal  popped : " << minTemp << endl;
                stk.pop();
                currSize--;
                //minVal = min(minTemp, stk.top().second)
            }

            int size() {
                return currSize;
            }

            void print() {
                if(isEmpty()) return;
                
                stack<pair<int, int>> sTemp = stk;
                while(!sTemp.empty()) {
                    cout << sTemp.top().first << " , " << sTemp.top().second << endl;
                    sTemp.pop();
                }
            }

};


int main() {
    MinStack stk(5) ;  // = new Stack();

    //cout << "1.Push\t 2.Pop\t 3.Top\t \n" ;

    while(true) {
        cout << "\nMin Stack operations ::  " << endl;
        cout << "1.Push\t\t  2.Pop\t\t  3.Min Top\t \n" ;
        cout << "4.isEmpty\t  5.isFull\t  6.Size\t \n" ;
        cout << "7.Print\t\t  8.Exit\n";
        
        cout << "Enter choice : " ;
        int choice; cin >> choice;

        switch(choice) {
            case 1 :  {
                        if( stk.isFull() ) {
                            cout << "Stack is full" << endl;
                            break;  
                        }
                        else { 
                            cout << "Enter val : " ;  int val; cin>> val;
                            stk.push(val);  
                            cout << "Elt Entered : " << val ;
                            cout << endl;   break;
                        }
                    }
        
            case 2 :  {
                            if(stk.isEmpty()) cout << "Empty " << endl;
                            else {
                                cout << "Elt : " << stk.top() << " is popped out";
                                stk.pop();
                            }
                            cout << endl; break; 
                        }
            
            case 3 :  {
                            if(stk.isEmpty()) cout << "Empty " ;
                            else {
                                if(!stk.isEmpty()) cout << "Top Min. elt : " << stk.top();
                            }
                            cout << endl; break;
                        }
            
            case 4 :  {
                            if(stk.isEmpty()) cout << "Empty" ;
                            else cout << "Not Empty" ;
                            cout << endl; break;
                        }
            
            case 5 :  {
                            if(stk.isFull()) cout << "Full" ;
                            else cout << "Not Full" ;
                            cout << endl; break;
                        }

            case 6 :  {
                            cout << "Size : " << stk.size(); cout << endl;
                              break;
                        }
            case 7 :  {
                            if(stk.isEmpty()) cout << "Empty" << endl;
                            else {
                                cout << "Elts of Stack  : " << endl;
                                stk.print() ;
                            }
                            cout << endl;  break;
                        }
            case 8 :  {
                            cout << "Exiting " ; choice = 0;
                            exit(0);
                            break;
                        }


            default : cout << "Invlaid choice";
        }
    } 

    return 0;
}

/*

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 12
Elt Entered : 12

Min Stack operations ::  
1.Push            2.Pop           3.Min Top      
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 3
Top elt : 12

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 45
Elt Entered : 45

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 12

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 5
Elt Entered : 5

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 5

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
5 , 5
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 78
Elt Entered : 78

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 5

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
78 , 5
5 , 5
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 2
Elt Entered : 2

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 2

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
2 , 2
78 , 5
5 , 5
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Stack is full

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 2 is popped out

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 4

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 5

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
78 , 5
5 , 5
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 5 is popped out

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 3

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
5 , 5
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 5

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 5 is popped out

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 12

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 2

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 1234
Elt Entered : 1234

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 12

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
1234 , 12
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 789
Elt Entered : 789

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 456789
Elt Entered : 456789

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Stack is full

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
456789 , 12
789 , 12
1234 , 12
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 5

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 12

Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
456789 , 12
789 , 12
1234 , 12
45 , 12
12 , 12


Min Stack operations ::
1.Push            2.Pop           3.Min Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 8
Exiting
*/