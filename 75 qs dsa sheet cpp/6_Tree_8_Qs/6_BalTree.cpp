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


class BalBinTree {
public : 
    static int isBalTree(TreeNode* r1) {
        if(!r1) return 0;
        
        
        int left =  isBalTree(r1->lt);
        if(left == -1) return -1;
        int right = isBalTree(r1->rt);
        if(right == -1) return -1;

        if(abs(left - right) >= 2) return -1;

        return max(left, right) + 1;
    }
};


int main( ) {

    // create bin tree
    cout << "--- Create Binary Tree ---" << endl;
    cout << "For Tree 1 : " << endl;
    TreeNode* mainRoot1 = nullptr;
    mainRoot1 = TreeNode::createBinTree(mainRoot1);


    // levelorder Traversal
    cout << endl ;
    cout << "Level-Order Traversal of Tree 1 : " << endl;
    PropTree::levelOrderTraversal(mainRoot1);  

    // is bal tree
    cout << endl ;
    int isBal = BalBinTree::isBalTree(mainRoot1);  
    cout << (isBal != -1 ? "Bal Tree" : "Not Bal Tree") << endl;

    return 0;
}




/*
--- Create Binary Tree ---
For Tree 1 : 
Enter elt : 10
For left child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0
For right child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0

Level-Order Traversal of Tree 1 :
10
20 20

Bal Tree
PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\6_Tree_8_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\6_Tree_8_Qs\" ; if ($?) { g++ 6_BalTree.cpp -o 6_BalTree } ; if ($?) { .\6_BalTree }
--- Create Binary Tree ---
For Tree 1 :
Enter elt : 10
For left child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 1
Enter elt : 30
For left child of 30 (1 to add / 0 to skip): 0
For right child of 30 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0
For right child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0

Level-Order Traversal of Tree 1 :
10
20 20
30

Bal Tree
PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\6_Tree_8_Qs> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\DSA_SHEETS_QS_SOLUTION\75 qs dsa sheet cpp\6_Tree_8_Qs\" ; if ($?) { g++ 6_BalTree.cpp -o 6_BalTree } ; if ($?) { .\6_BalTree }
--- Create Binary Tree ---
For Tree 1 :
Enter elt : 10
For left child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 1
Enter elt : 30
For left child of 30 (1 to add / 0 to skip): 1
Enter elt : 40
For left child of 40 (1 to add / 0 to skip): 0
For right child of 40 (1 to add / 0 to skip): 0
For right child of 30 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0
For right child of 10 (1 to add / 0 to skip): 1
Enter elt : 20
For left child of 20 (1 to add / 0 to skip): 0
For right child of 20 (1 to add / 0 to skip): 0

Level-Order Traversal of Tree 1 :
10
20 20
30
40

Not Bal Tree

*/