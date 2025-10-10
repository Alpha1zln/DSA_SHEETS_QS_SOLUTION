#include<bits/stdc++.h>
using namespace std;

// class Node{

// }

class TreeNode{
public : 
    int data;
    TreeNode *lt;
    TreeNode *rt;
    
    TreeNode() {
        data = -1;
        lt = nullptr;  rt = nullptr;
    }

    TreeNode(int val) :  data(val), lt(nullptr),  rt(nullptr) {};


    // TreeNode(int val) {
    //     data = -1;
    //     lt = nullptr;  rt = nullptr;
    // }

    static TreeNode* createNewNode() {
        // int addElt() {
            cout << "Enter elt : " ;  
            int elt; cin >> elt;
          //  return elt;
        //}

        //int elt = addElt();
        TreeNode *newNode = new TreeNode(elt);
        return newNode;
    } 

    

    static TreeNode*  createBinTree(TreeNode * root) {
   
        if(!root) {
            root = createNewNode();
        } 
        
        cout << "For left child of " << root->data << " (1 to add / 0 to skip): ";
        int lflag; cin >> lflag;
        if (lflag) 
            root->lt = createBinTree(root->lt);
        else root->lt = nullptr;
        
        // if(!root->lt) {
        //     cout << "for left side : Press 1 to add, 0 to exit";
        //     int flag; cin>>flag;
        //     if(flag)
        //         root->lt = createNewNode();
        //     else 
        //         root->lt = nullptr;
        // }

        cout << "For right child of " << root->data << " (1 to add / 0 to skip): ";
        int rflag; cin >> rflag;
        if (rflag) {
            root->rt = createBinTree(root->rt);
        } 
        else root->rt = nullptr;
        // if(!root->rt) {
        //     cout << "for right side : Press 1 to add, 0 to exit";
        //     int flag; cin>>flag;
        //     if(flag)
        //         root->rt = createNewNode();
        //     else 
        //         root->rt = nullptr;
        // }
        
        return root;
    }

};

// class Extra {
//     public:
       //static 
 
// };


class PropTree {
public: 

    static void inOrderTraversal(TreeNode* root) { //
        if(!root) return;

        inOrderTraversal(root->lt);
        cout << root->data; cout << endl;
        inOrderTraversal(root->rt);

        return;
    }


    static void preOrderTraversal(TreeNode* root) { //
        if(!root) return;

        cout << root->data; cout << endl;
        preOrderTraversal(root->lt);
        preOrderTraversal(root->rt);

        return;
    }

    static void levelOrderTraversal(TreeNode* root) { //
        if(!root) return;

        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> allEltsVc;  vector<int> levelVc;
            
        while(!qu.empty()) {
            int size = qu.size(); 
            
            for(int i=0; i<size; i++) {
                TreeNode* nd = qu.front();   qu.pop();
                int dt = nd->data;
                levelVc.push_back(dt);

                if(nd->lt) qu.push(nd->lt);
                if(nd->rt) qu.push(nd->rt);
            }
            allEltsVc.push_back(levelVc);
            levelVc.clear();
        }

        for(auto vc : allEltsVc) {
            for(auto et  : vc) {
                cout << et << " ";
            }
            cout << endl;
        }

        return;
    }



    static int findHt(TreeNode* root) {
        if(!root) return 0;

        int lt = findHt(root->lt);
        int rt = findHt(root->rt);

        int ht = max(lt, rt) + 1;

        return ht;
    }
};



int main( ) {

    // create bin tree
    cout << "--- Create Binary Tree ---" << endl;
    TreeNode* mainRoot = nullptr;

    // bool choice = true;
    // while(choice) {
    mainRoot = TreeNode::createBinTree(mainRoot);
            
    //     cout << "Enter 1 - To Continue to Add Elt, 0 - To Exit : ";
    //     if(choice == 0) {
    //        choice = false;  break;
    //     }
    // }



    // preOrder Traversal
    cout << endl;
    cout << "Pre-Order Traversal : " << endl;
    PropTree::preOrderTraversal(mainRoot);




    return 0;
}



/*

--- Create Binary Tree ---
Enter elt : 10
For left child of 10 (1 to add / 0 to skip): 1
Enter elt : 5
For left child of 5 (1 to add / 0 to skip): 1
Enter elt : 2
For left child of 2 (1 to add / 0 to skip): 0
For right child of 2 (1 to add / 0 to skip): 0
For right child of 5 (1 to add / 0 to skip): 0
For right child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 30
Enter elt : 30
For left child of 30 (1 to add / 0 to skip): 0
For right child of 30 (1 to add / 0 to skip): 1
Enter elt : 40
For left child of 40 (1 to add / 0 to skip): 0
For right child of 40 (1 to add / 0 to skip): 0

In-Order Traversal :
2
5
10
20
30
40

Pre-Order Traversal :
10
5
2
20
30
40

Level-Order Traversal :
10
5 20
2 30
40

Ht of Tree : 4

*/