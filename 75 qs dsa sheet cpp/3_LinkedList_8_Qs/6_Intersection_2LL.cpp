// Q 6 Linked List - LL
// ltcd 160

// Intersection of 2 LLs 

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

// fn prototype ***

// create LL 
pair<LinkedNode*, LinkedNode*> createLinkedList(vector<int>& vc, LinkedNode* head, LinkedNode* tail);
// print LL 
void printLinkedList(LinkedNode* head);
//rev LL
pair<LinkedNode*, LinkedNode*> reverseLinkedList(LinkedNode* head);
//
// find len of LL 
int findLength(LinkedNode* head);

//
int findCommonValue2LL(LinkedNode *head1, LinkedNode *head2);
// Intersection of 2 LL
LinkedNode* intersectionLL(LinkedNode *head1, LinkedNode *head2);

// main 
int main() {
    vector<int> vc1 = {1,4,7,10};
    int n1 = vc1.size();

    LinkedNode   *head1 = nullptr , *tail1 = nullptr;

    // create LL
    pair<LinkedNode*, LinkedNode*> pairNode1;
    pairNode1 = createLinkedList(vc1, head1, tail1);
    head1 = pairNode1.first ;  tail1 = pairNode1.second;
    cout << "Actual Linked List : " << endl;
    printLinkedList( head1 );

    // rev
    // cout << "Reverse Linked List : " << endl;
    // pair<LinkedNode*, LinkedNode*> pairNodeRev1;
    // pairNodeRev1 = reverseLinkedList(head1);
    // LinkedNode *headRev1 = pairNodeRev1.first , *tailRev1 = pairNodeRev1.second;
    // printLinkedList( headRev1 );

    // cout << "h1" << endl;
    // printLinkedList(head1);

    // ll 2
    vector<int> vc2 = {2,4,6,8};
    int n2 = vc2.size();

    LinkedNode   *head2 = nullptr , *tail2 = nullptr;

    // create LL
    pair<LinkedNode*, LinkedNode*> pairNode2;
    pairNode2 = createLinkedList(vc2, head2, tail2);
    head2 = pairNode2.first ;  tail2 = pairNode2.second;
    cout << "Actual Linked List : " << endl;
    printLinkedList( head2 );

    // // rev
    // cout << "Reverse Linked List : " << endl;
    // pair<LinkedNode*, LinkedNode*> pairNodeRev2;
    // pairNodeRev2 = reverseLinkedList(head2);
    // LinkedNode *headRev2 = pairNodeRev2.first , *tailRev2 = pairNodeRev2.second;
    // printLinkedList( headRev2 );

    
    // cout << "h2" << endl;
    // printLinkedList(head2);
    // common value in 2 LLs
    int commonVal = findCommonValue2LL(head1, head2);
    if(commonVal != -1)
        cout << "Found commonVal : " << commonVal << endl;
    else 
        cout << "Not Found commonVal " << endl;


    // intersection of 2 ll
    LinkedNode *intersectNode = intersectionLL(head1, head2);
    if(intersectNode) cout << "found : " << intersectNode->data << endl;
    else cout << "not found" << endl;


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



// find common val in 2 ll 
int findCommonValue2LL(LinkedNode *head1, LinkedNode *head2){

    bool foundCommonValue = false;
    unordered_map<int, int> mpp;

    LinkedNode *temp1 = head1;
    int i=1;
    while(temp1) {
        //cout << " temp1  : " << temp1->data << " " ;
        mpp[temp1->data] = i;
        i++; temp1 = temp1->next;
    }
    //cout << endl;

    LinkedNode *temp2 = head2;  int j=1;
    while(temp2) {
      //  cout << "temp2 : " << temp2->data << " " ;
        if(mpp.count(temp2->data) ) { //find(temp2->data) != mpp.end()) {
            return temp2->data;
            cout << "map : " << temp2->data ;
        }
        j++; temp2 = temp2->next;
    }
    //cout << endl;
        

    return -1;
}


// Intersection of 2 LL
LinkedNode* intersectionLL(LinkedNode *head1, LinkedNode *head2) {
    LinkedNode *a = head1, *b = head2;

    int len1 = findLength(a);
    int len2 = findLength(b);

    while(len1 > len2) {
        a = a->next;
        len1--;
    }
    
    while(len2 > len1) {
        b = b->next;
        len2--;
    }

    while(a && b) {
        if(a == b) {
            return a;
        }

        a = a->next;
        b = b->next;
    } 

    return nullptr;
}



// op ===
// Actual Linked List : 
// 1 -> 4 -> 7 -> 10
// Actual Linked List : 
// 2 -> 4 -> 6 -> 8
// Found commonVal : 4
// not found intersection