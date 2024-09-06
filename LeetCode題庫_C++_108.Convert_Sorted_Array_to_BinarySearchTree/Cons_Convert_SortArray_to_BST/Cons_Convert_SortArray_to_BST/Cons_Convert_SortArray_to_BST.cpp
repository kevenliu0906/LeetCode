// Cons_Convert_SortArray_to_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    // TreeNode* res_BST = NULL;

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // solution 1 (keven, using recursive to solve)
        {
            TreeNode *res = NULL;
            if (nums.size() < 1){
                return res;
            }
            
            if (nums.size() == 1){
                res = new TreeNode(nums[0], NULL, NULL);
                return res;
            }
            

            int left = 0;
            int right = nums.size()-1;
            int mid = left + (right-left)/2;
            // printf("nums[left]:%d, nums[mid]:%d, nums[right]:%d\n", nums[left], nums[mid], nums[right]);
            
            // STEP1: create a node with mid-nums value(for root)
            res = new TreeNode(nums[mid], NULL, NULL);
            // printf("------> new res, val:%d\n", res->val);

            // STEP2: create a node with mid-nums value(for left-side)
            if (left < mid){
                vector<int> nums_left(nums.begin(), nums.begin()+mid);
                res->left = sortedArrayToBST(nums_left);
                // printf("---------> res->left, val:%d\n", res->left->val);
            }

            // STEP3: create a node with mid-nums value(for right-side)
            if (right > mid){
                vector<int> nums_right(nums.begin()+mid+1, nums.end());
                res->right = sortedArrayToBST(nums_right);
                // printf("---------> res->right, val:%d\n", res->right->val);
            }

            return res;
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
    std::cout << "Hello LeetCode - Convert Sorted Array to Binary Search Tree, Algorithm(Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [-10,-3,0,5,9]\n");
    printf("expected result: output = [0,-3,9,-10,null,5] or [0,-10,5,null,-3,null,9]\n");
    {
        vector<int> nums{-10,-3,0,5,9};
        
        Solution solution;
        auto res = solution.sortedArrayToBST(nums);
        dbg_BT_node(res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [1,3]\n");
    printf("expected result: output = [1,null,3] or [3,1]\n");
    {
        vector<int> nums{1,3};
        
        Solution solution;
        auto res = solution.sortedArrayToBST(nums);
        dbg_BT_node(res);
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
