// ConsoleApplication_Maximum_Binary_Tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


//   Definition for a binary tree node.
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

    TreeNode* constructMaxNode(vector<int> &nums, vector<int>::iterator &max_num_iter)
    {    
        auto left_iter = nums.begin();
        auto right_iter = nums.end();
        
        max_num_iter = std::max_element(left_iter, right_iter); // [left_iter, right_iter), note: the element on the right side does NOT contain in the judgement
        // printf("num size:%d, max num:%d, original nums:\n", (int)nums.size(), *max_num_iter);
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     printf("%d,", nums[i]);
        // }
        // printf("\n");
        TreeNode *current_node = new TreeNode(*max_num_iter);

        return current_node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // solution 1 (keven, using recursive to solve it)
        {
            TreeNode *res_head = NULL;
            auto left_iter = nums.begin();
            auto right_iter = nums.end();
            vector<int>::iterator max_iter;

            // STEP1: construct max node within nums
            res_head = constructMaxNode(nums, max_iter);
            if (nums.size() == 1){
                return res_head;
            }

            // printf("res_head->val:%d\n", res_head->val);
            
            // STEP2: construct left max node within left-sides nums and linked it
            TreeNode *left_ptr = NULL;
            // if max_iter = nums.begin() means there is no node ptr on left-side, so left_ptr = NULL
            if (max_iter != left_iter)
            {
                vector<int> left_nums(left_iter, max_iter);
                left_ptr = constructMaximumBinaryTree(left_nums);
            }
            res_head->left = left_ptr;
            // if (res_head->left){
            //     printf("res_head->val:%d, current_left_node->val:%d\n", res_head->val, res_head->left->val);
            // }else{
            //     printf("res_head->val:%d, current_left_node is NULL\n", res_head->val);
            // }

            // STEP3: construct right max node within right-sides nums and linked it
            TreeNode *right_ptr = NULL;
            // if max_iter = nums.end()-1 means there is no node ptr on right-side, so right_ptr = NULL
            if (max_iter != right_iter - 1)
            {
                vector<int> right_nums(max_iter+1, right_iter);
                right_ptr = constructMaximumBinaryTree(right_nums);
            }

            res_head->right = right_ptr;

            // printf("*************** final result ***************\n");
            // if (res_head->left && res_head->right){
            //     printf("res_head->val:%d, reshead_left_node->val:%d, reshead_right_node->val:%d\n", res_head->val, res_head->left->val, res_head->right->val);
            // }else{
            //     if (res_head->left == NULL && res_head->right == NULL){
            //         printf("reshead_node->val:%d, reshead_left_node is NULL, reshead_right_node is NULL\n", res_head->val);
            //     }
            //     else if (res_head->left == NULL){
            //         printf("reshead_node->val:%d, reshead_left_node is NULL, reshead_right_node->val:%d\n", res_head->val, res_head->right->val);
            //     }
            //     else{
            //         printf("reshead_node->val:%d, reshead_left_node->val:%d, reshead_right_node is NULL\n", res_head->val, res_head->left->val);
            //     }
            // }

            return res_head;
        }
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
    std::cout << "Hello LeetCode - Maximum Binary Tree, Algorithm & DataStructure(Binary Tree, Divide and Conquer, recursive)!\n";
    cout << "https://leetcode.com/problems/maximum-binary-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,2,1,6,0,5]\n");
    printf("expected result: output = [6,3,5,null,2,0,null,null,1]\n");
    {
        vector<int> nums{3,2,1,6,0,5};
        
        Solution solution;
        auto tree_node = solution.constructMaximumBinaryTree(nums);
        dbg_BT_node(tree_node);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [3,2,1]\n");
    printf("expected result: output = [3,null,2,null,1]\n");
    {
        vector<int> nums{3,2,1};
        
        Solution solution;
        auto tree_node = solution.constructMaximumBinaryTree(nums);
        dbg_BT_node(tree_node);
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
