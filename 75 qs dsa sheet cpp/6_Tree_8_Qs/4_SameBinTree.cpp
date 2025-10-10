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


class SameBinTree {
public : 
    static bool isSameTree(TreeNode* mainRoot1, TreeNode* mainRoot2 ) {
        TreeNode* r1 = mainRoot1, *r2  = mainRoot2;

        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;

        if(r1->data != r2->data) return false;

        bool left =  isSameTree(r1->lt, r2->lt);
        bool right = isSameTree(r1->rt, r2->rt);
        
        if(left && right) return true;
        else return false;
    }
};


int main( ) {

    // create bin tree
    cout << "--- Create Binary Tree ---" << endl;
    cout << "For Tree 1 : " << endl;
    TreeNode* mainRoot1 = nullptr;
    mainRoot1 = TreeNode::createBinTree(mainRoot1);

    cout << "For Tree 2 : " << endl;
    TreeNode* mainRoot2 = nullptr;
    mainRoot2 = TreeNode::createBinTree(mainRoot2);

    // levelorder Traversal
    cout << endl ;
    cout << "Level-Order Traversal of Tree 1 : " << endl;
    PropTree::levelOrderTraversal(mainRoot1);
    cout << endl;
    cout << "Level-Order Traversal of Tree 2 : " << endl;
    PropTree::levelOrderTraversal(mainRoot2);

    bool isSame = SameBinTree::isSameTree(mainRoot1, mainRoot2);
    cout << (isSame == true ? "Same Tree" : "Not Same Tree") << endl;

    return 0;
}



/*
op-------------------
--- Create Binary Tree ---
For Tree 1 :
Enter elt : 10
For left child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0
For right child of 10 (1 to add / 0 to skip): 1
Enter elt : 30
For left child of 30 (1 to add / 0 to skip): 0
For right child of 30 (1 to add / 0 to skip): 0
For Tree 2 : 
Enter elt : 10
For left child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0
For right child of 10 (1 to add / 0 to skip): 1
Enter elt : 30
For left child of 30 (1 to add / 0 to skip): 0
For right child of 30 (1 to add / 0 to skip): 0

Level-Order Traversal of Tree 1 :
10
20 30

Level-Order Traversal of Tree 2 :
10
20 30
Same Tree

*/