// Console_TwoSum_IV_Input_is_a_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
#include <vector>

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

void In_order_Traverse(TreeNode *root){
    // // use recursive to solve (PASS)
    // {
    //     if (root == NULL)
    //     {
    //         return;
    //     }
        
    //     In_order_Traverse(root->left);
    //     printf("%d,", root->val);
    //     In_order_Traverse(root->right);
    // }

    // use stack to solve (PASS)
    {
        stack<TreeNode*> store_tn_stack;
        TreeNode *cur_tn = root;
        
        vector<TreeNode*> res;
        while ( cur_tn || store_tn_stack.size())
        {
            // STEP1: traverse left-node first and store it
            while (cur_tn)
            {
                // if exist, push into stack
                store_tn_stack.push(cur_tn);
                cur_tn = cur_tn->left;
            }

            // STEP2: get current root value from last stored
            cur_tn = store_tn_stack.top();
            store_tn_stack.pop();
            res.push_back(cur_tn);

            // STEP3: traverse right-node secondly
            cur_tn = cur_tn->right;  
        }

        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]->val);
        }
           
    }
}
 
class Solution {
private:
    TreeNode *first_tn = NULL;
    int first = 0;
    int second = 0;
    int target = 0;
    TreeNode *origin_root = NULL;

    bool DFS_Search(TreeNode* root, int val){
        if (root == NULL)
        {
            return false;
        }
        
        if (root->val == val)
        {
            if (root != first_tn)
            {
                return true;
            }
        }
        
        auto res = false;
        if (val > root->val){
            res = DFS_Search(root->right, val);
        }else{
            res = DFS_Search(root->left, val);
        }
        
        return res;
    }

    bool DFS_Inorder_Traverse(TreeNode *root){
        if (root == NULL)
        {
            return false;
        }

        // STEP1: traverse left node
        auto res = DFS_Inorder_Traverse(root->left);
        if (res)
        {
            return true;
        }
        
        // STEP2: figure out if current node exist some node that (cur-node + some-node) = target value
        // printf("%d,", root->val);
        {
            first_tn = root;
            first = root->val;
            second = target - first ;
            if (DFS_Search(origin_root, second))
            {
                return true;
            }
            if (DFS_Search(origin_root, second))
            {
                return true;
            }
        }

        // STEP3: traverse right node
        res = DFS_Inorder_Traverse(root->right);

        return res;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        target = k;
        origin_root = root;
        return DFS_Inorder_Traverse(root);
    }
};

int main()
{
    std::cout << "Hello LeetCode - TwoSum IV, Input is a BST, DataStructure(Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/two-sum-iv-input-is-a-bst/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [5,3,6,2,4,null,7], k = 9\n");
    printf("expected result: output = true\n");
    {
        
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn2, tn4);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn6 = new TreeNode(6, NULL, tn7);
        TreeNode *tn5 = new TreeNode(5, tn3, tn6);
        TreeNode *root = tn5;
        int k = 9;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.findTarget(root, k);
        printf("res(%d), true(%d), false(%d)\n", res, true, false);
        
        delete tn2;
        delete tn4;
        delete tn3;
        delete tn7;
        delete tn6;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [5,3,6,2,4,null,7], k = 28\n");
    printf("expected result: output = false\n");
    {
        
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn2, tn4);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn6 = new TreeNode(6, NULL, tn7);
        TreeNode *tn5 = new TreeNode(5, tn3, tn6);
        TreeNode *root = tn5;
        int k = 28;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.findTarget(root, k);
        printf("res(%d), true(%d), false(%d)\n", res, true, false);
        
        delete tn2;
        delete tn4;
        delete tn3;
        delete tn7;
        delete tn6;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1], k = 2\n");
    printf("expected result: output = false\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *root = tn1;
        int k = 2;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.findTarget(root, k);
        printf("res(%d), true(%d), false(%d)\n", res, true, false);
        
        delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [2,1,3], k = 4\n");
    printf("expected result: output = true\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *root = tn2;
        int k = 4;
        
        Solution solution;
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        auto res = solution.findTarget(root, k);
        printf("res(%d), true(%d), false(%d)\n", res, true, false);
        
        delete tn1;
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
