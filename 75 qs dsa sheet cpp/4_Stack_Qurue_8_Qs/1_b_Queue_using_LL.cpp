#include<bits/stdc++.h>
using namespace std;

// Q 1 b - Queue using LL
// 


class LinkedNode {
public : 
    int data;
    LinkedNode* next;

    LinkedNode() : data(-1), next(nullptr) {}
    LinkedNode(int val) : data(val), next(nullptr) {}
    LinkedNode(int val, LinkedNode* nd) : data(val), next(nd) {}
    
    // or
    // LinkedNode() {
    //     data = -1; 
    //     next = nullptr;
    // }

    //     LinkedNode(int val) {
    //     data = val; 
    //     next = nullptr;
    // }

    //     LinkedNode(int val, LinkedNode* nd) {
    //     data = val; 
    //     next = nd;
    // }
};


class Queue {

public :
    LinkedNode* frontNode, *rearNode, *startNode, *endNode;
    int maxSize;  
    int curr_size;

    Queue(int size) {
        frontNode = nullptr;    rearNode = nullptr;
        //LinkedNode* rearNode = new LinkedNode(-1);
        startNode = nullptr;    // move when front = null
        endNode = nullptr;      // move when it is full
        maxSize = size;         curr_size = 0;
    }

    // Destructor to free all memory  ... by gemini
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int val) {
        if( isFull() ) {
            return;
        }
        
        // if(curr_size == maxSize) {      // if already at endNd but not full
        //     endNode->next = startNode ;      // make it circular queue
        //     rearNode = endNode;         // make it null again
        // }
        
        LinkedNode* newNode = new LinkedNode(val);
        if(isEmpty() ) {   //   (frontNode == nullptr) {      // at null ... move to 1st postion
            frontNode = newNode;  startNode = newNode;
        }
        else {
            rearNode->next = newNode;
        }
        rearNode = newNode;
        curr_size++;

        if(curr_size == maxSize) {
            endNode = rearNode;
            endNode->next = startNode ;      // make it circular queue
        }
        //vec.push_back(val);
    }

    bool isEmpty() {
        //if(vec.empty()) return true;
        if(curr_size == 0) return true;
        else return false;
    }

    bool isFull() {
        //if(vec.size() == maxSize) return true;
        if(curr_size == maxSize) return true;
        else return false;
    }

    int front() {
        if(isEmpty()) return -1;
        //int n = vec.size();
        //return vec[n-1];
        return frontNode->data;
    }

    int back() {
        if(isEmpty()) return -1;
        //int n = vec.size();
        //return vec[n-1];
        return rearNode->data;
    }

    int size() {
        if(isEmpty()) return 0;
        //return vec.size();
        return curr_size;
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        //int n = vec.size();
        //int et = vec[n-1];   //vec.pop_back();
        if(curr_size == 1) {
            frontNode = rearNode = nullptr;
            startNode = nullptr;   endNode = nullptr;
            // curr_size = 0;
        }

        int poppedValue  = frontNode->data;  
        LinkedNode* temp = frontNode; 
        frontNode = frontNode->next;  // fr = (fr+1) % mxSz ... here circular qu handled it
        curr_size--;
        
        delete temp; // Free the memory
        return poppedValue ;
    }

//     Memory Management (The Big Fix):
// In the pop() method, after moving frontNode to the next element, 
// a temporary pointer temp is used to hold the address of the node being removed. 
// delete temp; is then called to free the memory, preventing a memory leak.

// A destructor ~Queue() is added to ensure that if the Queue object goes out of scope, 
// all remaining nodes in the linked list are also deallocated. 
// This is crucial for robust C++ programming.


    void print() {
        // //vector<int> temp;        
        // int n = vec.size();  int idx = n-1;
        // while(idx >= 0) {
        //     int elt = vec[idx];  idx--;
        //     cout << elt << " " ;
        //   //  temp.push_back(elt);
        // }
        if(isEmpty()) return;

        LinkedNode* temp = frontNode;
        while(temp != rearNode) {
            cout << temp->data << " ";   
            temp = temp->next;
        }
        cout << rearNode->data ;
        cout << endl;
    }
    

};

/*
A memory leak is a type of resource leak that happens when a program allocates memory 
from the heap but fails to deallocate it when the memory is no longer needed. 
This causes the program's memory usage to continuously increase over time, 
which can lead to performance degradation or even a system crash.

In your C++ code, when you used new to create a LinkedNode, 
you were allocating memory from the heap. However, in your pop() method, 
you were only changing the pointers (frontNode = frontNode->next;) 
and not using delete to free the memory of the node that was just removed. 
This left the old node floating in memory, with no pointers referencing it, 
making it impossible to access or deallocate later. 
This is the classic definition of a memory leak.
*/

int main() {
    Queue qu(5) ;  // = new Stack();

    //cout << "1.Push\t 2.Pop\t 3.Top\t \n" ;

    while(true) {
        cout << "\nQu operations ::  " << endl;
        cout << "1.Push\t\t  2.Pop\t\t  3.Front\t 4.Back\t\n" ;
        cout << "5.isEmpty\t  6.isFull\t  7.Size\t \n" ;
        cout << "8.Print\t\t  9.Exit\n";
        
        cout << "Enter choice : " ;
        int choice; cin >> choice;

        switch(choice) {
            case 1 :  {  // push
                        if( qu.isFull() ) {
                            cout << "qu is full" << endl;
                            break;  
                        }
                        else { 
                            cout << "enter val : " ;  int val; cin>> val;
                            qu.push(val);  
                            cout << "Elt Enqueued : " << qu.back() ;
                            cout << endl;   break;
                        }
                    }
        
            case 2 :  {   // pop
                            if(qu.isEmpty()) cout << "Empty " << endl;
                            else {
                                cout << "Elt : " << qu.front() << " is dequeued";
                                // 1st show front elt ... then pop it 
                                qu.pop();
                            }
                              
                            cout << endl; break; 
                        }
            
            case 3 :  {     // front
                            if(qu.isEmpty()) cout << "Empty " ;
                            else {
                                if(!qu.isEmpty()) cout << "Front elt : " << qu.front();
                            }
                            cout << endl; break;
                        }
            
            case 4 :  {     // back
                            if(qu.isEmpty()) cout << "Empty " ;
                            else {
                                if(!qu.isEmpty()) cout << "Back elt : " << qu.back();
                            }
                            cout << endl; break;
                        }
            

            case 5 :  {
                            if(qu.isEmpty()) cout << "Empty" ;
                            else cout << "Not Empty" ;
                            cout << endl; break;
                        }
            
            case 6 :  {
                            if(qu.isFull()) cout << "Full" ;
                            else cout << "Not Full" ;
                            cout << endl; break;
                        }

            case 7 :  { 
                            cout << "size : " << qu.size(); cout << endl;
                              break;
                        }
            case 8 :  {    // print
                            if(qu.isEmpty()) cout << "Empty" << endl;
                            else 
                            {
                                cout << "Elts of Queue  : " << endl;
                                qu.print() ;
                            }
                            cout << endl;  break;
                        }
            case 9 :  {
                            cout << "Exiting " ; choice = 0;
                            exit(0);
                            break;
                        }
            default :   cout << "Invlaid choice";
        }
    } 

    return 0;
}

/*

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
enter val : 11
Elt Enqueued : 11

Qu operations ::  
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size         
8.Print           9.Exit
Enter choice : 1
enter val : 22
Elt Enqueued : 22

Qu operations ::  
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice :
1
enter val : 33
Elt Enqueued : 33

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
enter val : 44
Elt Enqueued : 44

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
enter val : 55
Elt Enqueued : 55

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
qu is full

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 5
Not Empty

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 6
Full

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 7
size : 5

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 8
Elts of Queue  :
11 22 33 44 55


Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 3
Front elt : 11

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 4
Back elt : 55

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 2
Elt : 11 is dequeued

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 2
Elt : 22 is dequeued

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
enter val : 9
Elt Enqueued : 9

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
enter val : 8
Elt Enqueued : 8

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 1
qu is full

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 6
Full

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 7
size : 5

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 8
Elts of Queue  :
33 44 55 9 8


Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 3
Front elt : 33

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 4
Back elt : 8

Qu operations ::
1.Push            2.Pop           3.Front        4.Back
5.isEmpty         6.isFull        7.Size
8.Print           9.Exit
Enter choice : 9
Exiting
*/