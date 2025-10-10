// Q 1 Linked List - LL
// ltcd 206

// Reverse LL 

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


// main 
int main() {
    vector<int> vc = {1,2,3,4};
    int n = vc.size();

    LinkedNode   *head = nullptr , *tail = nullptr;

    // create LL
    pair<LinkedNode*, LinkedNode*> pairNode;
    pairNode = createLinkedList(vc, head, tail);
    head = pairNode.first ;  tail = pairNode.second;
    cout << "Actual Linked List : " << endl;
    printLinkedList( head);

    // rev
    cout << "Reverse Linked List : " << endl;
    pair<LinkedNode*, LinkedNode*> pairNodeRev;
    pairNodeRev = reverseLinkedList(head);
    LinkedNode *headRev = pairNodeRev.first , *TailRev = pairNodeRev.second;
    printLinkedList( headRev);

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

/*
🧠 Time & Space Complexity

Metric	Value
Time	O(n)
Space	O(1)

In-place and linear — optimal.

*/ 







// ************************************
// how to do in JAVA ... without pointer .???

// You're right — Java has no pointers like C++, but references in Java work similarly under the hood.

// Let’s walk through how to build and return both head and tail in Java, and how it compares to your C++ code using *&.

// ✅ Java Equivalent of Your C++ Code
// ✅ Create a ListNode class
// java
// Copy
// Edit
// class ListNode {
//     int data;
//     ListNode next;

//     ListNode(int data) {
//         this.data = data;
//         this.next = null;
//     }
// }
// ✅ Main Logic
// Since Java passes object references by value, you can’t directly modify the caller’s reference like C++ with Node*&. So we use a return type (e.g. Pair, or a custom wrapper).

// ✅ Full Code (With head & tail access)
// java
// Copy
// Edit
// import java.util.*;

// public class LinkedListBuilder {

//     static class ListNode {
//         int data;
//         ListNode next;

//         ListNode(int data) {
//             this.data = data;
//             this.next = null;
//         }
//     }

//     // Helper class to return both head and tail
//     static class HeadTailPair {
//         ListNode head;
//         ListNode tail;

//         HeadTailPair(ListNode head, ListNode tail) {
//             this.head = head;
//             this.tail = tail;
//         }
//     }

//     // Build linked list and return head & tail
//     static HeadTailPair createLinkedList(List<Integer> values) {
//         ListNode head = null, tail = null;

//         for (int val : values) {
//             ListNode newNode = new ListNode(val);

//             if (head == null) {
//                 head = tail = newNode;
//             } else {
//                 tail.next = newNode;
//                 tail = newNode;
//             }
//         }

//         return new HeadTailPair(head, tail);
//     }

//     // Print the list
//     static void printList(ListNode head) {
//         while (head != null) {
//             System.out.print(head.data);
//             if (head.next != null)
//                 System.out.print(" -> ");
//             head = head.next;
//         }
//         System.out.println();
//     }

//     public static void main(String[] args) {
//         List<Integer> values = Arrays.asList(1, 2, 3, 4);

//         HeadTailPair result = createLinkedList(values);
//         ListNode head = result.head;
//         ListNode tail = result.tail;

//         printList(head);

//         // Add 5 at the end
//         tail.next = new ListNode(5);
//         tail = tail.next;

//         System.out.println("After adding 5:");
//         printList(head);
//     }
// }
// ✅ Output:
// rust
// Copy
// Edit
// 1 -> 2 -> 3 -> 4
// After adding 5:
// 1 -> 2 -> 3 -> 4 -> 5
// 🔍 How Java Differs from C++:
// Concept	C++	Java
// Pointer	✅ Yes	❌ No
// Reference	✅ By using &, *&	✅ All objects are references
// Modify caller's pointer	✅ With *&	❌ Not possible directly
// Solution	Pass *& to modify	Return a wrapper (like Pair)

// ✅ Summary:
// Java has no pointers, but all objects (like ListNode) are passed by value of reference.

// To return both head and tail, create a helper class (HeadTailPair).

// Equivalent logic to C++ *& works using object containers in Java.

// Let me know if you want Java versions of insert/delete/reverse too!