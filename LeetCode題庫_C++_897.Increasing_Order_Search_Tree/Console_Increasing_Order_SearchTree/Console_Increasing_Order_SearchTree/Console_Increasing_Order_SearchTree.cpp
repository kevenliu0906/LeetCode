// Console_Increasing_Order_SearchTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
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
 
class Solution {
public:
    void BT_in_order_traversal(TreeNode* root, vector<TreeNode*> &in_order_bt_vec)
    {
        if (root == NULL)
        {
            return;
        }
        
        BT_in_order_traversal(root->left, in_order_bt_vec);
        in_order_bt_vec.push_back(root);
        BT_in_order_traversal(root->right, in_order_bt_vec);
    }

    TreeNode* increasingBST(TreeNode* root) {

        // solution 1 (keven, using recursive to figure-out in-order then linked each node)
        {
            TreeNode *res_head = NULL;
            TreeNode *res_now = NULL;
            vector<TreeNode*> bt_inorder_vec;
            BT_in_order_traversal(root, bt_inorder_vec);
            // debug
            // printf("------ in-order traversal: ------\n");
            for (size_t i = 0; i < bt_inorder_vec.size(); i++)
            {
                // printf("%d,", bt_inorder_vec[i]->val);
                // reset each node ptr
                bt_inorder_vec[i]->left = NULL;
                bt_inorder_vec[i]->right = NULL;
                if (res_head == NULL)
                {
                    res_head = bt_inorder_vec[i];
                }else{
                    res_now->right = bt_inorder_vec[i];
                }
                res_now = bt_inorder_vec[i];
            }
            // printf("\n");
            
            return res_head;
        }

        return root;
    }
};


void dbg_BT_node(TreeNode *root)
{

    // print by BT traversal(level-ordered traversal)
    queue<TreeNode*> nums_queue;

    printf("------- FINAL RESULT(dbg) -------\n");

    if (root == NULL)
    {
        printf("tn is NULL\n");
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


int main()
{
    std::cout << "Hello LeetCode - Increasing Order Search Tree, Algorithm(Binary Tree)!\n";
    cout << "https://leetcode.com/problems/increasing-order-search-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]\n");
    printf("expected result: output = [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]\n");
    {
        TreeNode *TN1 = new TreeNode(1, NULL, NULL);
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN9 = new TreeNode(9, NULL, NULL);
        TreeNode *TN2 = new TreeNode(2, TN1, NULL);
        TreeNode *TN4 = new TreeNode(4, NULL, NULL);
        TreeNode *TN8 = new TreeNode(8, TN7, TN9);
        TreeNode *TN3 = new TreeNode(3, TN2, TN4);
        TreeNode *TN6 = new TreeNode(6, NULL, TN8);
        TreeNode *TN5 = new TreeNode(5, TN3, TN6);
        TreeNode *root = TN5;
        
        Solution solution;
        auto res = solution.increasingBST(root);
        dbg_BT_node(res);
        
        
        delete TN1;
        delete TN7;
        delete TN9;
        delete TN2;
        delete TN4;
        delete TN8;
        delete TN3;
        delete TN6;
        delete TN5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [5,1,7]\n");
    printf("expected result: output = [1,null,5,null,7]\n");
    {
        TreeNode *TN1 = new TreeNode(1, NULL, NULL);
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN5 = new TreeNode(5, TN1, TN7);
        
        TreeNode *root = TN5;
        
        Solution solution;
        auto res = solution.increasingBST(root);
        dbg_BT_node(res);
        
        
        delete TN1;
        delete TN7;
        delete TN5;
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
