// Q 5 Linked List - LL
// ltcd 2

// Add 2 no.s using LL 
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

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
//rev LL
pair<LinkedNode*, LinkedNode*> reverseLinkedList(LinkedNode* head);
//
// add 2 no.s 
void Add2Nums(LinkedNode *head1, LinkedNode *head2);

// main 
int main() {
    vector<int> vc1 = {1,2,3};
    int n1 = vc1.size();
    LinkedNode   *head1 = nullptr , *tail1 = nullptr;


    vector<int> vc2 = {8,9,9};
    int n2 = vc2.size();
    LinkedNode   *head2 = nullptr , *tail2 = nullptr;

    // create LL 1
    pair<LinkedNode*, LinkedNode*> pairNode1;
    pairNode1 = createLinkedList(vc1, head1, tail1);
    head1 = pairNode1.first ;  tail1 = pairNode1.second;
    cout << "Actual Linked List 1 : " << endl;
    printLinkedList( head1);

    // ll 2
    pair<LinkedNode*, LinkedNode*> pairNode2;
    pairNode2 = createLinkedList(vc2, head2, tail2);
    head2 = pairNode2.first ;  tail2 = pairNode2.second;
    cout << "Actual Linked List 2 : " << endl;
    printLinkedList( head2);


    // rev 1
    cout << "Reverse Linked List 1 : " << endl;
    pair<LinkedNode*, LinkedNode*> pairNodeRev1;
    pairNodeRev1 = reverseLinkedList(head1);
    LinkedNode *headRev1 = pairNodeRev1.first , *tailRev1 = pairNodeRev1.second;
    printLinkedList( headRev1);

    // rev 2
    cout << "Reverse Linked List 2 : " << endl;
    pair<LinkedNode*, LinkedNode*> pairNodeRev2;
    pairNodeRev2 = reverseLinkedList(head2);
    LinkedNode *headRev2 = pairNodeRev2.first , *tailRev2 = pairNodeRev2.second;
    printLinkedList( headRev2);


    // 
    Add2Nums(headRev1, headRev2);
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



/// rev LL
pair<LinkedNode*, LinkedNode*> reverseLinkedList(LinkedNode* head) {
    
    LinkedNode *prev = nullptr, *curr = head,  *ahead = head->next;

    while(curr) {
        ahead = curr->next;  // store ahead

        curr->next = prev;  // shift next of curr

  
        prev = curr;       // move prev 
        curr = ahead;      //  move curr
    }

    LinkedNode *headRev = prev, *tailRev = head;
    pair<LinkedNode*, LinkedNode*> ansPr = {headRev, tailRev};
    
    return ansPr;
}


// add 2 no.s 
void Add2Nums(LinkedNode *revHead1, LinkedNode *revHead2) {
    LinkedNode *head_add = new LinkedNode(-1);
    LinkedNode *dummy_head_add = head_add;

    int carry = 0;

    while( revHead1 || revHead2 ) {
        int s = carry;
        if(revHead1) {
            s += revHead1->data;
        }
        if(revHead2) {
            s += revHead2->data;
        }

        int dgt = s%10;    carry = s/10;
        LinkedNode *nextNode = new LinkedNode(dgt);
        head_add->next = nextNode;
        head_add = nextNode;
        
        if(revHead1) revHead1 = revHead1->next;
        if(revHead2) revHead2 = revHead2->next;
    }

    if(carry) {
        //int dgt = s%10;    carry = s/10;
        LinkedNode *nextNode = new LinkedNode(carry);
        head_add->next = nextNode;
        head_add = nextNode;        carry = 0;
    }

    pair<LinkedNode*, LinkedNode*> ansPr =  reverseLinkedList(dummy_head_add->next);
    LinkedNode *rev_head_add = ansPr.first;

    cout << "LL of 2 add no.s : " << endl;
    printLinkedList(rev_head_add);

}


// 
// Actual Linked List 1 : 
// 1 -> 2 -> 3
// Actual Linked List 2 :
// 8 -> 9 -> 9
// Reverse Linked List 1 :
// 3 -> 2 -> 1
// Reverse Linked List 2 :
// 9 -> 9 -> 8
// LL of 2 add no.s :
// 1 -> 0 -> 2 -> 2