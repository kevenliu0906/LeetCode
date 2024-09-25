// ConsoleApp_Validate_BinarySearchTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
 
class Solution {
public:
    void InOrder_BST(TreeNode *root, vector<int> &in_order_bst){
        if (root == NULL){
            return;
        }
        
        InOrder_BST(root->left, in_order_bst);
        in_order_bst.push_back(root->val);
        InOrder_BST(root->right, in_order_bst);
    }
    bool isValidBST(TreeNode* root) {
        // solution 0 (keven, using in-order to judgement if BST)
        {
            vector<int> in_order;
            InOrder_BST(root, in_order);
            // for debug
            // printf("in-order >>>>> \n");

            for (size_t i = 0; i < in_order.size() - 1; i++)
            {
                // printf("%d,", in_order[i]);
                if ( in_order[i] >= in_order[i+1] )
                {
                    return false;
                }
            }
            // printf("\n");
            
            return true;
        }

        // solution 1 (keven, force directly, has bug in test case 5)
        {
            if (root == NULL){
                return true;
            }
            
            if (root->left)
            {
                if (root->left->val >= root->val){
                    return false;
                }
            }
            if (root->right)
            {
                if (root->right->val <= root->val){
                    return false;
                }
            }

            if (!isValidBST(root->left))
            {
                return false;
            }
            if (!isValidBST(root->right))
            {
                return false;
            }
            
            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Validate Binary Search Tree, Algorithm(Binary Search Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/validate-binary-search-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [2,1,3]\n");
    printf("expected result: output = true\n");
    {
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *root = tn2;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.isValidBST(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        
        delete tn1;
        delete tn3;
        delete tn2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [5,1,4,null,null,3,6]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn4 = new TreeNode(4, tn3, tn6);
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn5 = new TreeNode(5, tn1, tn4);
        TreeNode *root = tn5;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.isValidBST(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete tn3;
        delete tn6;
        delete tn4;
        delete tn1;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1,null,1]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *tn1_1 = new TreeNode(1);
        TreeNode *tn1_2 = new TreeNode(1, NULL, tn1_1);
        TreeNode *root = tn1_2;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.isValidBST(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete tn1_1;
        delete tn1_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [1,1]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *tn1_1 = new TreeNode(1);
        TreeNode *tn1_2 = new TreeNode(1, tn1_1, NULL);
        TreeNode *root = tn1_2;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.isValidBST(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete tn1_1;
        delete tn1_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: root = [5,4,6,null,null,3,7]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn6 = new TreeNode(6, tn3, tn7);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn5 = new TreeNode(5, tn4, tn6);
        TreeNode *root = tn5;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.isValidBST(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete tn3;
        delete tn7;
        delete tn6;
        delete tn4;
        delete tn5;
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
