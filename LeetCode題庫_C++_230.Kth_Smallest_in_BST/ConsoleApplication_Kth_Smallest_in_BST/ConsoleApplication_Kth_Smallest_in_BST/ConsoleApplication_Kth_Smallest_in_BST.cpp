// ConsoleApplication_Kth_Smallest_in_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<int> tn_val_vec;
    int tn_val_vec_count = 0;
    
    void Pre_ordered(TreeNode *root, int &targetIdx){
        if (root == NULL){
            return ;
        }
        
        // int tn_val_vec_size = tn_val_vec.size();
        printf("cur_root->val:%d, tn_val_vec_count:%d, targetIdx:%d\n", root->val, tn_val_vec_count, targetIdx);
        if (tn_val_vec_count >= targetIdx){
            // BINGO~~~ do not need to move on the next iteration
            return ;
        }
        
        Pre_ordered(root->left, targetIdx);
        
        tn_val_vec.push_back(root->val);
        tn_val_vec_count++;

        Pre_ordered(root->right, targetIdx);
    }

    int kthSmallest(TreeNode* root, int k) {
        // solution 1 (keven, using In-order traversal(recursive) for BST to solve it)
        {
            tn_val_vec.clear();
            Pre_ordered(root, k);
            auto res = tn_val_vec[k-1];
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
    std::cout << "Hello LeetCode - Kth Smallest in BST, Algorithm(Binary Search Tree, Depth-First Search, Binary Tree)!\n";
    cout << "https://leetcode.com/problems/kth-smallest-element-in-a-bst/" << endl << endl;
    
    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,1,4,null,2], k = 1\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn1 = new TreeNode(1, NULL, tn2);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn3 = new TreeNode(3, tn1, tn4);
        TreeNode *root = tn3;
        int k = 1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.kthSmallest(root, k);
        dbg_BT_node(root);
        printf("res is %d\n", res);
        
        printf("tn_val_vec is:\n");
        for (size_t i = 0; i < solution.tn_val_vec.size(); i++)
        {
            printf("%d,", solution.tn_val_vec[i]);
        }
        printf("\n");
        
        
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [5,3,6,2,4,null,null,1], k = 3\n");
    printf("expected result: output = 3\n");
    {
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn2 = new TreeNode(2, tn1, NULL);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn3 = new TreeNode(3, tn2, tn4);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn5 = new TreeNode(5, tn3, tn6);
        TreeNode *root = tn5;
        int k = 3;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.kthSmallest(root, k);
        dbg_BT_node(root);
        printf("res is %d\n", res);
        
        printf("tn_val_vec is:\n");
        for (size_t i = 0; i < solution.tn_val_vec.size(); i++)
        {
            printf("%d,", solution.tn_val_vec[i]);
        }
        printf("\n");
        
        
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
        delete tn5;
        delete tn6;
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
