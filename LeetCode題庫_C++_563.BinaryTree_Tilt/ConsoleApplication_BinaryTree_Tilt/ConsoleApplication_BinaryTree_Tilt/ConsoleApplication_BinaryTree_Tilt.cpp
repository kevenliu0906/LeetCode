// ConsoleApplication_BinaryTree_Tilt.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
private:
    int res_abs_diff_sum = 0;
    int all_node_sum_from_root_to_leaves(TreeNode *root){
        if (root == NULL)
        {
            return 0;
        }

        int left_sum = all_node_sum_from_root_to_leaves(root->left);
        int right_sum = all_node_sum_from_root_to_leaves(root->right);
        int abs_diff_sum = abs(left_sum - right_sum);
        res_abs_diff_sum += abs_diff_sum;

        // printf("root->val:%d, left_sum:%d, right_sum:%d, abs_diff_sum:%d\n", root->val, left_sum, right_sum, abs_diff_sum);
        
        return (root->val + left_sum + right_sum);
        
    }

public:
    int findTilt(TreeNode* root) {
        // solution 1 (keven, using recursive to solve)
        {
            int left_sum = 0;
            int right_sum = 0;

            auto all_nodes_sum = all_node_sum_from_root_to_leaves(root);
            // printf("****** all_leaves_sum:%d ********\n", all_nodes_sum);
            
            return res_abs_diff_sum;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - BinaryTree Tilt, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/binary-tree-tilt/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [1,2,3]\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.findTilt(roots);
        printf("result:%d\n", result);
        
        delete tn1;
        delete tn2;
        delete tn3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: roots = [4,2,9,3,5,null,7]\n");
    printf("expected result: output = 15\n");
    {
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn5 = new TreeNode(5, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn3, tn5);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn9 = new TreeNode(9, NULL, tn7);
        TreeNode *tn4 = new TreeNode(4, tn2, tn9);
        TreeNode *roots = tn4;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.findTilt(roots);
        printf("result:%d\n", result);
        
        delete tn3;
        delete tn5;
        delete tn2;
        delete tn7;
        delete tn9;
        delete tn4;
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
