// Console_BT_Zigzag_BFS.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    void BFS(vector<vector<int>> &res, TreeNode *root){
        
        if (root == NULL) return;
        
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que;
        int cur_loop_count = 0;

        tmp_tn_que.push(root);
        while (tmp_tn_que.size())
        {
            cur_loop_count++;
            cur_tn_que.swap(tmp_tn_que);
            vector<int> cur_tn_vec;
            stack<int> cur_tn_vec_stack;
            
            while (cur_tn_que.size())
            {
                auto cur_tn = cur_tn_que.front();
                cur_tn_vec.push_back(cur_tn->val);

                if (cur_tn->left){
                    tmp_tn_que.push(cur_tn->left);
                }
                if (cur_tn->right){
                    tmp_tn_que.push(cur_tn->right);
                }

                cur_tn_que.pop();
            }
            
            if (cur_tn_vec.size()){
                if (cur_loop_count % 2){
                    // odd loop, ex. loop = 1, 3, 5, .etc.
                    res.push_back(cur_tn_vec);
                }else{
                    // even loop, ex. loop = 1, 3, 5, .etc.
                    vector<int> reverse(cur_tn_vec.rbegin(), cur_tn_vec.rend());
                    res.push_back(reverse);
                }
            }
        }
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // solution 1 (keven, using BFS to solve)
        {
            vector<vector<int>> res;
            BFS(res, root);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - BinaryTree Zigzag Level Order Traversal!\n";
    cout << "https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root1 = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = [[3],[20,9],[15,7]]\n");
    {
        
        TreeNode *tn15 = new TreeNode(15, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn20 = new TreeNode(20, tn15, tn7);
        TreeNode *tn9 = new TreeNode(9, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn9, tn20);
        TreeNode *root = tn3;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.zigzagLevelOrder(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        
        
        if (tn15)
            delete tn15;
        if (tn7)
            delete tn7;
        if (tn20)
            delete tn20;
        if (tn9)
            delete tn9;
        if (tn3)
            delete tn3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root1 = [1]\n");
    printf("expected result: output = [[1]]\n");
    {
        
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.zigzagLevelOrder(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        
        
        if (tn1)
            delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root1 = []\n");
    printf("expected result: output = []\n");
    {
        TreeNode *root = NULL;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.zigzagLevelOrder(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
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
