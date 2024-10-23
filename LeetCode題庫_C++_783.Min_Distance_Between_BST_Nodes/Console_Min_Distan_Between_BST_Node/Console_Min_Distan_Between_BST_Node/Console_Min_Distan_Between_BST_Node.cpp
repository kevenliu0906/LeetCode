// Console_Min_Distan_Between_BST_Node.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<int> nums_vec;
    int pre_num = -1;       // assume a number that not exist in nums
    int miniDiff = INT_MAX; // assume a number with very large value

    void DFS_InOrder_BST(TreeNode *root){

        if (root == NULL) return;
        
        DFS_InOrder_BST(root->left);
        if (pre_num != -1){
            miniDiff = min(miniDiff, abs(pre_num - root->val));
        }
        pre_num = root->val;
        nums_vec.push_back(root->val);
        DFS_InOrder_BST(root->right);
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        // solution 1 (using DFS to solve)
        {
            DFS_InOrder_BST(root);
            // for (size_t i = 0; i < nums_vec.size(); i++)
            // {
            //     printf("%d,", nums_vec[i]);
            // }
            // printf("\n");

            // printf("miniDiff:%d\n", miniDiff);
            
            return miniDiff;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Minimum Distan Between BST Node!\n";
    cout << "https://leetcode.com/problems/minimum-distance-between-bst-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [4,2,6,1,3]\n");
    printf("expected result: output = 1\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *tn6 = new TreeNode(6, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, tn2, tn6);
        TreeNode *root = tn4;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.minDiffInBST(root);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        printf("res is :%d\n", res);
        
        if (tn1)
            delete tn1;
        if (tn2)
            delete tn2;
        if (tn3)
            delete tn3;
        if (tn4)
            delete tn4;
        if (tn6)
            delete tn6;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,0,48,null,null,12,49]\n");
    printf("expected result: output = 1\n");
    {
        
        TreeNode *tn12 = new TreeNode(12, NULL, NULL);
        TreeNode *tn49 = new TreeNode(49, NULL, NULL);
        TreeNode *tn48 = new TreeNode(48, tn12, tn49);
        TreeNode *tn0 = new TreeNode(0, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn0, tn48);
        TreeNode *root = tn1;
        
        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        Solution solution;
        auto res = solution.minDiffInBST(root);

        printf("------ In-order Traverse (START)------\n");
        In_order_Traverse(root);
        printf("\n------ In-order Traverse (END)------\n");

        printf("res is :%d\n", res);
        
        if (tn0)
            delete tn0;
        if (tn1)
            delete tn1;
        if (tn12)
            delete tn12;
        if (tn48)
            delete tn48;
        if (tn49)
            delete tn49;
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
