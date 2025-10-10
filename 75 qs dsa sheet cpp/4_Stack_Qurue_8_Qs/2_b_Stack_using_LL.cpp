#include<bits/stdc++.h>
using namespace std;

// Q 2 b - Stack using LL
// 


class LinkedNode {
public : 
    int data;
    LinkedNode* next;

    LinkedNode() {
        data = -1; 
        next = nullptr;
    }

        LinkedNode(int val) {
        data = val; 
        next = nullptr;
    }

        LinkedNode(int val, LinkedNode* nd) {
        data = val; 
        next = nd;
    }
};


class Stack {

    public :
    LinkedNode* topNode;
    int maxSize;  
    int curr_size;

    Stack() {
        topNode = nullptr;
        maxSize = 5;  
        curr_size = 0;
    }

    void push(int val) {
        if( isFull() ) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = topNode;
        topNode = newNode;
        curr_size++;
        //vec.push_back(val);
    }

    bool isEmpty() {
        //if(vec.empty()) return true;
        if(!topNode) return true;
        else return false;
    }

    bool isFull() {
        //if(vec.size() == maxSize) return true;
        if(curr_size == maxSize) return true;
        else return false;
    }

    int top() {
        if(isEmpty()) return -1;
        //int n = vec.size();
        //return vec[n-1];
        return topNode->data;
    }

    int size() {
        if(isEmpty()) return 0;
        //return vec.size();
        return curr_size;
    }

    void pop() {
        if(isEmpty()) {
            return;
        }
        //int n = vec.size();
        //int et = vec[n-1];   //vec.pop_back();
        topNode = topNode->next;
        curr_size--;
    }

    void print() {
        // //vector<int> temp;        
        // int n = vec.size();  int idx = n-1;
        // while(idx >= 0) {
        //     int elt = vec[idx];  idx--;
        //     cout << elt << " " ;
        //   //  temp.push_back(elt);
        // }
        if(isEmpty()) return;
        LinkedNode* temp = topNode;
        while(temp) {
            cout << temp->data << " ";   
            temp = temp->next;
        }
        cout << endl;
    }
    

};



int main() {
    Stack stk ;  // = new Stack();

    //cout << "1.Push\t 2.Pop\t 3.Top\t \n" ;

    while(true) {
        cout << "\nStack operations ::  " << endl;
        cout << "1.Push\t\t  2.Pop\t\t  3.Top\t \n" ;
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
                            cout << "enter val : " ;  int val; cin>> val;
                            stk.push(val);  
                            cout << "Top Elt : " << stk.top() ;
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
                                if(!stk.isEmpty()) cout << "Top elt : " << stk.top();
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
                            cout << "size : " << stk.size(); cout << endl;
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
            default :   cout << "Invlaid choice";
        }
    } 

    return 0;
}



// op=======
// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 1
// enter val : 12
// Top Elt : 12

// Stack operations ::  
// 1.Push            2.Pop           3.Top  
// 4.isEmpty         5.isFull        6.Size         
// 7.Print           8.Exit
// Enter choice : 1
// enter val : 22
// Top Elt : 22

// Stack operations ::  
// 1.Push            2.Pop           3.Top  
// 4.isEmpty         5.isFull        6.Size         
// 7.Print           8.Exit
// Enter choice : 1
// enter val : 33
// Top Elt : 33

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 1
// enter val : 44
// Top Elt : 44

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 1
// enter val : 55
// Top Elt : 55

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 1
// Stack is full

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 6
// size : 5

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 7
// Elts of Stack  :
// 55 44 33 22 12


// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 5
// Full

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 2
// Elt : 55 is popped out

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 7
// Elts of Stack  :
// 44 33 22 12


// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 6
// size : 4

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 1
// enter val : 66
// Top Elt : 66

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 1
// Stack is full

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 6
// size : 5

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 3
// Top elt : 66

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 7
// Elts of Stack  :
// 66 44 33 22 12


// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 5
// Full

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 4
// Not Empty

// Stack operations ::
// 1.Push            2.Pop           3.Top
// 4.isEmpty         5.isFull        6.Size
// 7.Print           8.Exit
// Enter choice : 8
// Exiting