#include<bits/stdc++.h>
using namespace std;

// Q 2 c - Stack using queue ... 2 qu.s
// leetcode 225


class Stack {

public :
    int maxSize;  int currSize;
    //vector<int> vec;
    queue<int> q1, q2;
    int frontI, rearIdx, topIdx;
    

    Stack(int size) {
        topIdx = -1;
        currSize = 0;   maxSize = size;
    }

    void push(int val) {
        if( isFull() ) {
            return;
        }
        q1.push(val);
        currSize++;
    }

    bool isEmpty() {
        if(q1.empty() && q2.empty()) return true;
        else return false;
    }

    bool isFull() {
        if(currSize == maxSize) return true;
        else return false;
    }

    int top() {
        if(isEmpty() ) return -1;

        if(q1.empty() && !q2.empty() ) {
            return q2.front();
        }
        else if(!q1.empty() && q2.empty()) {
            vector<int> v;
            while(!q1.empty() ) {
                int e = q1.front();  q1.pop();    // 1 2 3
                v.push_back(e);                   // 3 2 1  end to first idx
            }

            for(int i=v.size()-1; i>=0; i--) {
                q2.push(v[i]);
            }
            return q2.front();
        }
        else if(!q1.empty() && !q2.empty() ) {
            // ! q1 
            vector<int> v1;
            while(!q1.empty() ) {
                int e = q1.front();  q1.pop();    // 7 8
                v1.push_back(e);                   
            }

            // ! q2  
            vector<int> v2;
            while(!q2.empty() ) {
                int e = q2.front();  q2.pop();    // 5 4 3 2 1
                v2.push_back(e);                   
            }

            // v1
            for(int i=v1.size()-1; i>=0; i--) {
                q2.push(v1[i]);
            }
            
            // v2 
            for(auto e : v2) {
                q2.push(e);
            }

            return q2.front();
        }
    }

    int size() {
        if(isEmpty()) return 0;
        return currSize;     // vec.size();
    }


    int pop() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }

        top();    // call top so that elt mvs from q1 to q2
        currSize--;

        int e;
        if(!q2.empty() ) {
            e = q2.front(); q2.pop();
        }
        return e;
    }

    void print() {
        if(isEmpty() ) return;

        top();

        vector<int> vc;
        while(!q2.empty() ) {
            int e = q2.front();  cout << e << " ";
            vc.push_back(e);
            q2.pop();
        }
        for(auto e : vc) q2.push(e);
        cout << endl;
    }
    

};



int main() {
    Stack stk(5) ;  // = new Stack();

    //cout << "1.Push\t 2.Pop\t 3.Top\t \n" ;

    while(true) {
        cout << "\nStack operations ::  " << endl;
        cout << "1.Push\t\t  2.Pop\t\t  3.Top\t \n" ;
        cout << "4.isEmpty\t  5.isFull\t  6.Size\t \n" ;
        cout << "7.Print\t\t  8.Exit\n";
        
        cout << "Enter choice : " ;
        int choice; cin >> choice;

        switch(choice) {
            case 1 :  { // push
                        if( stk.isFull() ) {
                            cout << "Stack is full" << endl;
                            break;  
                        }
                        else { 
                            cout << "enter val : " ;  int val; cin>> val;
                            stk.push(val);  
                            cout << "Elt entered : " << val ;
                            cout << endl;   break;
                        }
                    }
        
            case 2 :  {   // pop
                            if(stk.isEmpty()) cout << "Empty " << endl;
                            else {
                                cout << "Elt : " << stk.top() << " is popped out";
                                stk.pop();
                            }
                              
                            cout << endl; break; 
                        }
            
            case 3 :  {   // top
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


            default : cout << "Invlaid choice";
        }
    } 

    return 0;
}


/*
Stack operations ::  
1.Push            2.Pop           3.Top  
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 2
Empty 


Stack operations ::  
1.Push            2.Pop           3.Top  
4.isEmpty         5.isFull        6.Size         
7.Print           8.Exit
Enter choice : 7
Empty


Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 11
Elt entered : 11

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 22
Elt entered : 22

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 33
Elt entered : 33

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 3

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
33 22 11


Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 33 is popped out

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
22 11


Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 44
Elt entered : 44

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 66
Elt entered : 66

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 88
Elt entered : 88

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
Stack is full

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 3
Top elt : 88

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 4
Not Empty

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 5
Full

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 5

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
88 66 44 22 11


Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 88 is popped out

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 2
Elt : 66 is popped out

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 101
Elt entered : 101

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 1
enter val : 201
Elt entered : 201

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 6
size : 5

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 5
Full

Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 7
Elts of Stack  :
201 101 44 22 11


Stack operations ::
1.Push            2.Pop           3.Top
4.isEmpty         5.isFull        6.Size
7.Print           8.Exit
Enter choice : 8
Exiting

*/
