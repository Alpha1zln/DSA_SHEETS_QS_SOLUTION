#include<bits/stdc++.h>
using namespace std;

// 8 ... Cicular Queue
// vec

class CircularQueue {
    public : 
        int frontIdx, rearIdx, currSize, maxSize;
        vector<int> vc;

        CircularQueue(int size) {
            frontIdx = -1;  rearIdx = -1; currSize = 0; maxSize = size;
            vc.resize(size);
        }

        void push(int val) {
            if(isFull()) return;

            if(currSize == 0) {
                frontIdx = rearIdx = 0;
            }
            else {
                rearIdx = (rearIdx+1) % maxSize;
            }
            vc[rearIdx] = val;
            currSize++;
        }

        void pop() {
            if(isEmpty()) return;
            int temp = vc[frontIdx];

            if(currSize == 1) {
                frontIdx = rearIdx = -1;
            }
            else {
                frontIdx =  (frontIdx+1) % maxSize;
            }
            currSize--;
        }

        bool isEmpty() {
            if(currSize == 0) return true;
            else return false;
        }

        bool isFull() {
             if(currSize == maxSize) return true;
            else return false;
        }

        int size() {
            return currSize;
        }

        void print() {
            if(isEmpty()) return;

            int idx = frontIdx;
            while(idx != rearIdx) {
                cout << vc[idx] << " ";
                idx = (idx+1) % maxSize;
            }
            cout << vc[rearIdx] << endl;
        }

};


int main() {

 CircularQueue qu(5) ;  // = new Stack();

    //cout << "1.Push\t 2.Pop\t 3.Top\t \n" ;

    while(true) {
        cout << "\nQueue operations ::  " << endl;
        cout << "1.Push\t\t  2.Pop\t\t  3.Top\t \n" ;
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
                            cout << "Enter val : " ;  int val; cin>> val;
                            qu.push(val);  
                            cout << "Entered Elt : " << qu.vc[qu.rearIdx] ;
                            cout << endl;   break;
                        }
                    }
        
            case 2 :  {     // pop
                            if(qu.isEmpty()) cout << "Empty " << endl;
                            else {
                                cout << "Elt : " << qu.vc[qu.frontIdx] << " is popped out";
                                qu.pop();
                            }
                              
                            cout << endl; break; 
                        }
            
            case 3 :  {    // front
                            if(qu.isEmpty()) cout << "Empty " ;
                            else {
                                //if(!qu.isEmpty()) 
                                cout << "Front elt : " << qu.vc[qu.frontIdx];
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
                            cout << "Size : " << qu.size(); cout << endl;
                              break;
                        }
            case 7 :  { // print
                            if(qu.isEmpty()) cout << "Empty" << endl;
                            else {
                                cout << "Elts of Cir. Qu.  : " << endl;
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
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 11
Entered Elt : 11

Queue operations ::  
1.Push            2.Pop           3.Top  
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 1
Enter val : 22
Entered Elt : 22

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 33
Entered Elt : 33

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 44
Entered Elt : 44

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 55
Entered Elt : 55

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Queue is full

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Front elt : 11

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Cir. Qu.  :
11 22 33 44 55


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 5

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 11 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 22 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 3

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Cir. Qu.  :
33 44 55


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Front elt : 33

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 123
Entered Elt : 123

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Enter val : 456
Entered Elt : 456

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Queue is full

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Front elt : 33

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 5

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Cir. Qu.  :
33 44 55 123 456


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 5
Full

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Front elt : 33

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
Size : 5

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Cir. Qu.  :
33 44 55 123 456


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 8
Exiting

*/
