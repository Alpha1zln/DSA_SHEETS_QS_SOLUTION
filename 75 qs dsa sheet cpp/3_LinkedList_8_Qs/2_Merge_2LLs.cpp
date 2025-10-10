// Q 2 Linked List - LL
// ltcd 21

// Merge 2 Sorted LL

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
pair<LinkedNode*, LinkedNode*> createLinkedList(vector<int>& vc, 
        LinkedNode* head, LinkedNode* tail);
// print LL 
void printLinkedList(LinkedNode* head);
//merge 2 sorted  LL
LinkedNode* merge2SortedLinkedList(LinkedNode* head1, LinkedNode* head2);
//


// main 
int main() {
    // ll 1
    vector<int> vc = {1,2,3,4};
    int n = vc.size();

    LinkedNode   *head = nullptr , *tail = nullptr;

    // create LL
    pair<LinkedNode*, LinkedNode*> pairNode;
    pairNode = createLinkedList(vc, head, tail);
    head = pairNode.first ;  tail = pairNode.second;
    cout << "Actual Linked List : " << endl;
    printLinkedList( head);

    // 
    // ll 2
    vector<int> vc2 = {0,2,4,6,8};
    int n2 = vc2.size();

    LinkedNode   *head2 = nullptr , *tail2 = nullptr;

    // create LL
    pair<LinkedNode*, LinkedNode*> pairNode2;
    pairNode2 = createLinkedList(vc2, head2, tail2);
    head2 = pairNode2.first ;  tail2 = pairNode2.second;
    cout << "Actual Linked List 2: " << endl;
    printLinkedList( head2);



    // merge
    cout << "Merged Linked List : " << endl;
    LinkedNode* headFinal = merge2SortedLinkedList(head,  head2);
    printLinkedList( headFinal);

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



//merge 2 sorted  LL
LinkedNode* merge2SortedLinkedList(LinkedNode* head1,  LinkedNode* head2) {

    if(!head1) return head2;
    if(!head2) return head1;
    
    LinkedNode *headFinal = new LinkedNode(-1);
    LinkedNode *curr = headFinal;  // dummyNode

    while(head1 || head2) {
        int val;
        if(head1 && head2) {
            if(head1->data <= head2->data)  {
                val = head1->data;
                if(head1) head1 = head1->next;
            }
            else {
                val = head2->data;
                if(head2) head2 = head2->next;
            }
        }
        else if(head1) {
            val = head1->data;
            if(head1) head1 = head1->next;
        }
        else if(head2) {
            val = head2->data;
            if(head2) head2 = head2->next;
        }
        

        LinkedNode *nextNode = new LinkedNode(val);

        if(!curr) curr = nextNode;
        else {
            if(curr->data != val) { // to remove duplicate
                curr->next = nextNode;
                curr = nextNode;
            }

            // curr->next = nextNode;  //  with duplicate 
            // curr = nextNode;            
        }


        
    }

    return headFinal->next;

}



// op --------------
/* 
Actual Linked List : 
1 -> 2 -> 3 -> 4
Actual Linked List 2:
0 -> 2 -> 4 -> 6 -> 8
Merged Linked List :
0 -> 1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 6 -> 8


PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\3_LinkedList_8_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\3_LinkedList_8_Qs\" ; if ($?) { g++ 2_Merge_2LLs.cpp -o 2_Merge_2LLs } ; if ($?) { .\2_Merge_2LLs }
Actual Linked List : 
1 -> 2 -> 3 -> 4
Actual Linked List 2: 
0 -> 2 -> 4 -> 6 -> 8
Merged Linked List :
0 -> 1 -> 2 -> 3 -> 4 -> 6 -> 8

*/