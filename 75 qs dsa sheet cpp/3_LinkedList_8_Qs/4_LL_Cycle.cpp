#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;


// Q 3 Linked List - LL
// ltcd 19


// 3 a 
// Remove nth node from start 





// fn prototype
class LinkedNode {

public: 
    int data;
    LinkedNode  *next;

    LinkedNode() {
        data = -1;
        next = NULL;
    }

    LinkedNode(int dt) {
        data = dt;
        next = nullptr;
    }

    LinkedNode(LinkedNode* nodeNext) {
        data = -1;
        next = nodeNext;
    }

};

// fn prototype 
// create LL 
pair<LinkedNode*, LinkedNode*> createLinkedList(vector<int>& vc, LinkedNode* head, LinkedNode* tail);
// print LL 
void printLinkedList(LinkedNode* head);
// find len of LL 
int findLength(LinkedNode* head);

// is LL Cycle
bool isLLCycle(LinkedNode* head);


// main 
int main() {
    vector<int> vc = {1,2,3,4, 5,6,7,8};
    int n = vc.size();

    LinkedNode   *head = nullptr , *tail = nullptr;

    // create LL
    pair<LinkedNode*, LinkedNode*> pairNode;
    pairNode = createLinkedList(vc, head, tail);
    head = pairNode.first ;  tail = pairNode.second;
    cout << "Actual Linked List : " << endl;
    printLinkedList( head);

    // find len of LL 
    int len_LL =  findLength(head);
    cout << "Len of LL : " << len_LL << endl;

      // tail->next = head->next->next; // add cycle in LL 
      // printLinkedList( head);
    bool isCycle = isLLCycle(head);
    if(isCycle) cout << "Cycle present" << endl;
    else  cout << "No Cycle present" << endl;


    return 0;
}


// fn defntn ***

// create LL 
pair<LinkedNode*, LinkedNode*> createLinkedList(vector<int>& vc, LinkedNode* head, LinkedNode* tail) {
    LinkedNode* temp = head;
    int n = vc.size();

    for(int i=0; i<n; i++) {
        LinkedNode* newNode = new LinkedNode(vc[i]);

        if(head == nullptr) {
            head = newNode;  tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return {head, tail};
     
}

// print LL 
void printLinkedList(LinkedNode* head) {
    LinkedNode* tempHead = head;

    int i=0, lt = findLength(head);
    while(tempHead) {
        cout << tempHead->data ;
        if(tempHead->next != NULL) {
            cout << " -> " ;
        }
        tempHead = tempHead->next;
        i++;  
        if(i>lt) break; // for cycle 
    }

    cout << endl ; 
}

// find len of LL 
int findLength(LinkedNode* head) {
    LinkedNode* temp = head;
    unordered_map<LinkedNode*, int> visMp;
    if(!temp) return 0;

    int len = 0, i=0;
    while(temp) {
        len++;
        //if(vis.empty() || vis[temp] == 0) vis.push_back(temp) = 1;
        //else break;

        // if(visMp.find(temp) == visMp.end()) 
        //     break;
        // else {
        //     visMp[temp] = 1;
        // }

        temp= temp->next;
    }
    return len;
}


// cycle 
bool isLLCycle(LinkedNode* head) {
    // approach 1 : 
    // bool cycle = false;
    // int lt = findLength(head);

    // // approach 1  ... vis arr
    // int vis[lt+1] = {0};
    // LinkedNode *temp = head; 
    // int i=0;
    // while(temp) {
    //     if(vis[i] == 0 ) {
    //         vis[i] = 1;
    //     }
    //     else {
    //         cycle = true;
    //         return cycle;
    //     }
    //     if(i==lt+1) break;
    //     if(temp->next)
    //         temp = temp ->next;
    //     i++;
    // }
    // return cycle;

    // approach 2 : 
    // slow and fast ptr. 

    LinkedNode* slow = head, *fast = head; 

    while( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }

    return false;
    
}

// 
// Actual Linked List : 
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
// Len of LL : 8
// No Cycle present


// 
// Actual Linked List : 
// 1 -> 2 -> 
// Len of LL : 1
// 1 -> 2 -> 
// Cycle present