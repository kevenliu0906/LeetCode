// ConsoleApp_Delete_Node_in_a_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dbg_BT_node(TreeNode *root)
{

    // print by BT traversal(level-ordered traversal)
    queue<TreeNode*> nums_queue;

    printf("------- FINAL RESULT(dbg) -------\n");

    if (root == NULL)
    {
        printf("tn is NULL\n");
        printf("\n---------------------------------\n");
        return;
    }
    
    nums_queue.push(root);
    while (nums_queue.size())
    {
        auto cur_tn = nums_queue.front();
        nums_queue.pop();
        if (cur_tn == NULL){
            printf("null,");
        }else{
            printf("%d,", cur_tn->val);
            if (cur_tn->left || cur_tn->right)
            {
                nums_queue.push(cur_tn->left);
                nums_queue.push(cur_tn->right);
            }          
        }
    }
    printf("\n---------------------------------\n");
}

void InOrder_BST(TreeNode *root){
    if (root == NULL)
    {
        return;
    }
    InOrder_BST(root->left);
    printf("%d,", root->val);
    InOrder_BST(root->right);
}
 
class Solution {
private:
    TreeNode *del_tn = NULL;
    TreeNode *del_parent_tn = NULL;
    
    void insert_other_node(TreeNode **root, TreeNode *parent_tn, TreeNode *del_tn){
        if (del_tn->val != (*root)->val){
            if (del_tn->val < parent_tn->val){
                // deletion is in left-side of parent_tn

                // step1: append del_tn->right first
                parent_tn->left = del_tn->right;
                while (parent_tn->left){
                    parent_tn = parent_tn->left;   // move to the end of left-side because need to append del_tn->left node
                }
                // step2: append del_tn->left second
                {
                    parent_tn->left = del_tn->left;
                }
            }
            else{
                // deletion is in right-side of parent_tn

                // step1: append del_tn->left first
                parent_tn->right = del_tn->left;
                while (parent_tn->right){
                    parent_tn = parent_tn->right;   // move to the end of right-side because need to append del_tn->right node
                }
                // step2: append del_tn->right second
                {
                    parent_tn->right = del_tn->right;
                }
            }
        }
        else
        {
            // deletion is in head
            printf("insert_other_node (deletion is in head) >>>  del_tn->val(%d), root(0x%x)->val(%d)\n", del_tn->val, root, (*root)->val);

            // step1: assign del_tn->right first
            *root = del_tn->right;
            // printf("insert_other_node (deletion is in head) >>> root(0x%x)->val(%d)\n", root, (*root)->val);

            auto tmp_root = *root;
            if (tmp_root){
                while ((tmp_root)->left){
                    tmp_root = (tmp_root)->left;   // move to the end of left-side because need to append del_tn->left node
                }
            }

            // step2: append del_tn->left second
            if (tmp_root)
            {
                tmp_root->left = del_tn->left;
            }else{
                *root = del_tn->left;
            }
        }
    }

    void DFS_Search(TreeNode *root, int key){
        if (root == NULL)
        {
            return;
        }

        if (root->val == key){
            del_tn = root;
            return;
        }else{
            TreeNode *cur_root = root;
            del_parent_tn = cur_root;
            DFS_Search(root->left, key);
            if (del_tn != NULL)
                return;
            del_parent_tn = cur_root;
            DFS_Search(root->right, key);
            if (del_tn == NULL){
                del_parent_tn = NULL;
            }
        }
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // solution 1 (keven, force directly)
        {
            TreeNode *origin_root = root;
            // STEP1: found the del node & del_parent node
            DFS_Search(root, key);

            // if (del_parent_tn){
            //     printf("del_parent_tn(0x%x)->val:%d\n", del_parent_tn, del_parent_tn->val);
            // }else{
            //     printf("del_parent_tn(NULL)\n");
            // }

            // if (del_tn){
            //     printf("del_tn(0x%x)->val:%d\n", del_tn, del_tn->val);
            // }else{
            //     printf("del_tn(NULL)\n");
            // }
            

            // STEP2: replace the relations
            //        1. change the relations within del_parent_tn & del_tn 
            //        2. insert the node after deleted-node
            if (del_tn)
            {
                if (del_parent_tn){
                    if (del_tn->val < del_parent_tn->val){
                        del_parent_tn->left = NULL;
                    }else{
                        del_parent_tn->right = NULL;
                    }
                }
                // printf("deleteNode (before insert) >>> root(0x%x)->val(%d)\n", root, root->val);
                insert_other_node(&root, del_parent_tn, del_tn);
                // printf("deleteNode (after insert) >>> root(0x%x)->val(%d)\n", root, root->val);
            }

            // // STEP3: delete below items
            // if (del_tn)
            // {
            //     // delete the node
            //     delete del_tn;
            //     del_tn = NULL;
            // }

            return root;
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - Delete Node in a BST, DataStructure(Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/delete-node-in-a-bst/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [5,3,6,2,4,null,7], key = 3\n");
    printf("expected result: output = [5,4,6,2,null,null,7] or [5,2,6,null,4,null,7]\n");
    {
        
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn2, tn4);
        TreeNode *tn6 = new TreeNode(6, NULL, tn7);
        TreeNode *tn5 = new TreeNode(5, tn3, tn6);
        TreeNode *root = tn5;
        int key = 3;
        
        Solution solution;
        dbg_BT_node(root);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(root);
        printf("\n<< Inorder_BST END>>\n");
        auto result = solution.deleteNode(root, key);
        dbg_BT_node(result);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(result);
        printf("\n<< Inorder_BST END>>\n");
        
        delete tn2;
        delete tn4;
        delete tn7;
        if (tn3)
        {
            printf("delete tn3 (1)\n");
            delete tn3;
            printf("delete tn3 (2)\n");
        }
        delete tn6;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: roots = [5,3,6,2,4,null,7], key = 0\n");
    printf("expected result: output = [5,3,6,2,4,null,7]\n");
    {
        
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn2, tn4);
        TreeNode *tn6 = new TreeNode(6, NULL, tn7);
        TreeNode *tn5 = new TreeNode(5, tn3, tn6);
        TreeNode *root = tn5;
        int key = 0;
        
        Solution solution;
        dbg_BT_node(root);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(root);
        printf("\n<< Inorder_BST END>>\n");
        auto result = solution.deleteNode(root, key);
        dbg_BT_node(result);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(result);
        printf("\n<< Inorder_BST END>>\n");
        
        delete tn2;
        delete tn4;
        delete tn7;
        delete tn3;
        delete tn6;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: roots = [], key = 0\n");
    printf("expected result: output = []\n");
    {
        TreeNode *root = NULL;
        int key = 0;
        
        Solution solution;
        dbg_BT_node(root);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(root);
        printf("\n<< Inorder_BST END>>\n");
        auto result = solution.deleteNode(root, key);
        dbg_BT_node(result);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(result);
        printf("\n<< Inorder_BST END>>\n");
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: roots = [8,5,12,3,6,10,15,1,null,null,7,null,11,13,null], key = 8\n");
    printf("expected result: output = [8,5,12,3,7,10,15,1,null,null,null,null,11,13,null]\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn1, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn6 = new TreeNode(6, NULL, tn7);
        TreeNode *tn5 = new TreeNode(5, tn3, tn6);

        TreeNode *tn11 = new TreeNode(11, NULL, NULL);
        TreeNode *tn10 = new TreeNode(10, NULL, tn11);
        TreeNode *tn13 = new TreeNode(13, NULL, NULL);
        TreeNode *tn15 = new TreeNode(15, tn13, NULL);

        TreeNode *tn12 = new TreeNode(12, tn10, tn15);

        TreeNode *tn8 = new TreeNode(8, tn5, tn12);
        TreeNode *root = tn8;
        int key = 8;
        
        Solution solution;
        dbg_BT_node(root);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(root);
        printf("\n<< Inorder_BST END>>\n");
        auto result = solution.deleteNode(root, key);
        dbg_BT_node(result);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(result);
        printf("\n<< Inorder_BST END>>\n");
        
        delete tn1;
        delete tn3;
        delete tn7;
        delete tn6;
        delete tn5;
        
        delete tn11;
        delete tn10;
        delete tn13;
        delete tn15;
        delete tn12;
        delete tn8;

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: roots = [0], key = 0\n");
    printf("expected result: output = []\n");
    {
        TreeNode *tn0 = new TreeNode(0, NULL, NULL);
        TreeNode *root = tn0;
        int key = 0;
        
        Solution solution;
        dbg_BT_node(root);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(root);
        printf("\n<< Inorder_BST END>>\n");
        auto result = solution.deleteNode(root, key);
        dbg_BT_node(result);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(result);
        printf("\n<< Inorder_BST END>>\n");

        delete tn0;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: roots = [2,1], key = 2\n");
    printf("expected result: output = [1]\n");
    {
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, NULL);
        TreeNode *root = tn2;
        int key = 2;
        
        Solution solution;
        dbg_BT_node(root);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(root);
        printf("\n<< Inorder_BST END>>\n");
        auto result = solution.deleteNode(root, key);
        dbg_BT_node(result);
        printf("<< Inorder_BST START>>\n");
        InOrder_BST(result);
        printf("\n<< Inorder_BST END>>\n");

        delete tn1;
        delete tn2;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
