#include<bits/stdc++.h>
using namespace std;

// Q 1 a - Queue using vec
// 

class Queue {
public:
    int maxSize;
    vector<int> vec;
    int front, rear, curr_size;
    
    Queue(int size) {
        front = -1;   rear = -1;  vec.resize(size);
        curr_size=0;  maxSize = size;
    }

    void push(int val) {
        if( isFull() ) {
            return;
        }
        if(front == -1) {
            front = rear = 0;
        }
        else rear = (rear+1) % maxSize;

        curr_size++;
        vec[rear] = val;   // vec.push_back(val);
    }

    bool isEmpty() {
        if(curr_size == 0) return true;
        else return false;
    }

    bool isFull() {
        if(curr_size == maxSize) return true;
        else return false;
    }

    int top() {
        if(isEmpty()) return -1; cout << endl;
        // int n = vec.size();
        //return vec[n-1];  
        return vec[front];
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
        //int n = vec.size();
        //int et = vec[n-1];   //cout<< et <<  "is popped " << endl;
        //vec.pop_back();  
        int idx;  idx = front; int temp = vec[idx];  vec[idx] = -1;
        if(curr_size == 1) {
            front = rear = -1;
        } 
        else {
            front = (front+1) % maxSize;
        }

        curr_size--;
        return temp;
    }

    void print() {
        // //vector<int> temp;
        //int n = vec.size();  int idx = n-1;
        //while(idx >= 0) {
          //  int elt = vec[idx];  idx--;
          //  cout << elt << " " ;
          // //  temp.push_back(elt);
        //}
        int idx = front;
        if(rear >= front) {
            while(idx <= rear) {     // front ... to ... rear
                cout << vec[idx] << " " ;    idx++;
            }
        }
        else {
            idx = front;  int i=0;
            while(idx <= maxSize-1) {      //  front ...to ... lastIdx
                cout << vec[idx] << " " ;    idx++;
            }
            while(i <= rear) {            //  0 idx .... to ... rear
                cout << vec[i] << " " ;     i++;
            }
        }

        // or **
        // int count = 0;
        // int idx = front;
        // while (count < curr_size) {
        //     cout << vec[idx] << " ";
        //     idx = (idx + 1) % maxSize;
        //     count++;
        // }
        // cout << endl; 
        
        cout << endl;
    }
    

};



int main() {
    Queue qu(5) ;  // = new Stack();

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
                            cout << "enter val : " ;  int val; cin>> val;
                            qu.push(val);  
                            cout << "Entered Elt : " << qu.vec[qu.rear] ;
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
                                if(!qu.isEmpty()) cout << "Top elt : " << qu.top();
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
                                cout << "Elts of Stack  : " << endl;
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
enter val : 12
Entered Elt : 12

Queue operations ::  
1.Push            2.Pop           3.Top  
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 1
enter val : 22
Entered Elt : 22

Queue operations ::  
1.Push            2.Pop           3.Top  
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 1
enter val : 33
Entered Elt : 33

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 44
Entered Elt : 44

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 55
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

Top elt : 12

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 4
Not Empty

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
Enter choice : 6
size : 5

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
12 22 33 44 55


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 12 is popped out

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
size : 3

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 5
Not Full

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
33 44 55


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 33 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 2

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 1234
Entered Elt : 1234

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 7894
Entered Elt : 7894

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 4

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
44 55 1234 7894


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 44 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 55 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 2

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
1234 7894


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 1234 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 1

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
7894


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 7894 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 0

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Empty


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 4
Empty

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 5
Not Full

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Empty

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Empty


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Empty


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 98
Entered Elt : 98

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 1

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
98


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 1247
Entered Elt : 1247

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3

Top elt : 98

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 2

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
98 1247


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 98 is popped out

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 1

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
1247


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 963
Entered Elt : 963

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 2

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
1247 963


Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 9
Invlaid choice
Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3

Top elt : 1247

Queue operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 8
Exiting

*/