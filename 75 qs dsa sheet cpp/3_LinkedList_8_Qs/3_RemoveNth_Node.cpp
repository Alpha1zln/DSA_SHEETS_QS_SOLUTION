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

// remove nth node from start
LinkedNode* removeNthNodeFromStart(LinkedNode* head, int k);
// remove nth node from end 
LinkedNode* removeNthNodeFromEnd(LinkedNode* head, int k);


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

    // 
    // remove nth node from start
    // cout << "Enter the node no. to be removed  from start : " << endl ;
    // int k;    cin >> k; 
    // head = removeNthNodeFromStart(head, k);
    // cout << "LL after removing node from start : " << endl;
    // printLinkedList( head);

    // remove nth node from end 
    cout << "Enter the node no. to be removed  from end : " << endl ;
    int k1;    cin >> k1;
    head = removeNthNodeFromEnd(head, k1);
    cout << "LL after removing node  from end : " << endl;
    printLinkedList( head);
    

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

    while(tempHead) {
        cout << tempHead->data ;
        if(tempHead->next != NULL) {
            cout << " -> " ;
        }
        tempHead = tempHead->next;
    }

    cout << endl ; 
}

// find len of LL 
int findLength(LinkedNode* head) {
    LinkedNode* temp = head;
    if(!temp) return 0;

    int len = 0;
    while(temp) {
        len++;
        temp= temp->next;
    }
    return len;
}



// remove nth node from start
LinkedNode* removeNthNodeFromStart(LinkedNode* head, int k) {
    // cout << "Enter the node no. to be removed : " << endl ;
    // int k;    cin >> k;

    int lt = findLength(head);
    
    if(k==0) return head; 
    
    if(k > lt )   {
       if(k%lt != 0)  k = k % lt;    // 4->1      8->2
       else {
        k = lt;     // 6-> 3  9->3
       }
    }
    
    if(k==1)  {
        head = head->next;
        return head;
    }


    int jump = k-1;
    LinkedNode* temp = head, *back = nullptr;
    for(int i=1; i<=jump; i++) {
        back = temp;
        temp = temp->next;
    }

    back->next = temp->next;
    return head;
}


// remove nth node from end 
LinkedNode* removeNthNodeFromEnd(LinkedNode* head, int k) {
    
    int lt = findLength(head);

    if(k==0) return head; 
    if(!head) return head;
    if(!head->next) {
        head = head->next;  
        return head;
    }
    
    if(k > lt )   {
       if(k%lt != 0)  k = k % lt;    // 4->1      8->2
       else {
        k = lt;     // 6-> 3  9->3
       }
    }
    
    if(k== lt)  {
        head = head->next;
        return head;
    }
    
    int k_start = lt - k + 1;
    head = removeNthNodeFromStart(head, k_start);
    return head;

    // or 
    // int jump = k-1;
    // LinkedNode* fast = head, *slow = head, *back = nullptr;
    // for(int i=1; i<=jump; i++) {
    //     back = fast;
    //     fast = fast->next;
    // }

    // while(fast->next) {
    //     back = slow;
    //     fast = fast->next;
    //     slow = slow->next;
    // }

    // back->next = slow->next;
    // return head;
}
