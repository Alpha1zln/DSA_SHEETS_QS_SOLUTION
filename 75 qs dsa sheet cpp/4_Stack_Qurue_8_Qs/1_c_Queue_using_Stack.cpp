#include<bits/stdc++.h>
using namespace std;

// Q 1 c - Queue using stack      
// leetcode 232

class Queue {
public:
    int maxSize;
    stack<int> stk1, stk2;
    int frontIdx, rearIdx, curr_size;
    
    Queue(int size) {
        frontIdx = -1;   rearIdx = -1;  // vec.resize(size);
        curr_size=0;  maxSize = size;
    }

    void push(int val) {
        if( isFull() ) {
            return;
        }

        stk1.push(val);
        curr_size++;
    }

    bool isEmpty() {
        if(stk1.empty() && stk2.empty()) return true;
        // if(curr_size == 0) return true;
        else return false;
    }

    bool isFull() {
        if(curr_size == maxSize) return true;
        else return false;
    }

    int front() {
        if(isEmpty()) return -1; cout << endl;  
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());  stk1.pop();
            }
        }

        return stk2.top();
    }

    int size() {
        if(isEmpty()) return 0;
        //return vec.size();
        return curr_size;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }
        else if(stk2.empty()) {
            int a = front(); // trf fron s1 to s2
        }

        int temp = stk2.top();    stk2.pop();
        curr_size--;
        return temp;
    }

    void print() {
        vector<int> tempV;  stack<int> tempS;
        if(isEmpty()) return;

        // stk2
        while(!stk2.empty()) {
            int et = stk2.top();  tempS.push(et); stk2.pop();
            tempV.push_back(et);
        } 
        while(!tempS.empty()) {      
            stk2.push(tempS.top());  // fill  stk2 again
            tempS.pop();
        }

        // stk1
        while(!stk1.empty()) {
            int et = stk1.top();  
            tempS.push(et); stk1.pop();
        } 
        while(!tempS.empty()) {
            int et = tempS.top();  tempS.pop();
            stk1.push(et); // add in stk1 again
            tempV.push_back(et);
        }
        
        int idx = 0;
        for(auto et : tempV) {
            cout << et ;
            if(idx <= tempV.size()-2) cout << " ";  idx++;
        }
        //delete tempS;  delete tempV;
        cout << endl;
    }
    

};



int main() {
    Queue qu(5) ;  // = new Stack();

    //cout << "1.Push\t 2.Pop\t 3.Top\t \n" ;

    while(true) {
        cout << "\nQueue operations ::  " << endl;
        cout << "1.Push\t\t  2.Pop\t\t  3.Front\t \n" ;
        cout << "4.isEmpty\t  5.isFull\t  6.Size\t \n" ;
        cout << "7.Print\t\t  8.Exit\n";
        
        cout << "Enter choice : " ;
        int choice; cin >> choice;

        switch(choice) {
            case 1 :  {  // push
                        if( qu.isFull() ) {
                            cout << "Queue is full" << endl;
                            break;  
                        }
                        else { 
                            cout << "enter val : " ;  int val; cin>> val;
                            qu.push(val);  
                            cout << "Entered Elt : " << val ;
                            cout << endl;   break;
                        }
                    }
        
            case 2 :  {     // pop
                            if(qu.isEmpty()) cout << "Empty " << endl;
                            else {
                                cout << "Elt : " << qu.pop() << " is popped out";
                            }
                              
                            cout << endl; break; 
                        }
            
            case 3 :  {    // top
                            if(qu.isEmpty()) cout << "Empty " ;
                            else {
                                //if(!qu.isEmpty()) 
                                    cout << "Front elt : " << qu.front() ;
                            }
                            cout << endl; break;
                        }
            
            case 4 :  {    // is empty
                            if(qu.isEmpty()) cout << "Empty" ;
                            else cout << "Not Empty" ;
                            cout << endl; break;
                        }
            
            case 5 :  {
                            if(qu.isFull()) cout << "Full" ;
                            else cout << "Not Full" ;
                            cout << endl; break;
                        }

            case 6 :  { // size 
                            cout << "size : " << qu.size(); cout << endl;
                              break;
                        }
            case 7 :  { // print
                            if(qu.isEmpty()) cout << "Empty" << endl;
                            else {
                                cout << "Elts of Queue  : " << endl;
                                qu.print() ;
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
Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 11
Entered Elt : 11

Queue operations ::  
1.Push            2.Pop           3.Front        
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 1
enter val : 22
Entered Elt : 22

Queue operations ::  
1.Push            2.Pop           3.Front        
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 1
enter val : 33
Entered Elt : 33

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 44
Entered Elt : 44

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 55
Entered Elt : 55

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Queue is full

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 4
Not Empty

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 5
Full

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 5

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Queue  :
11 22 33 44 55


Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3

Front elt : 11

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 11 is popped out

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 22 is popped out

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3

Front elt : 33

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 3

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Queue  :
33 44 55


Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 33 is popped out

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Queue  :
44 55


Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 77
Entered Elt : 77

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 88
Entered Elt : 88

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 4

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Queue  :
44 55 77 88


Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3

Front elt : 44

Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Queue  :
44 55 77 88


Queue operations ::
1.Push            2.Pop           3.Front
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 8
Exiting

*/