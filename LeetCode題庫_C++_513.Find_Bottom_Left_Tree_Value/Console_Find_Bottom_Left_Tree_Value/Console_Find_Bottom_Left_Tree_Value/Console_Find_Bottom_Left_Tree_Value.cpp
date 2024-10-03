// Console_Find_Bottom_Left_Tree_Value.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que;
        tmp_tn_que.push(root);
        int res = 0;

        while (tmp_tn_que.size())
        {
            cur_tn_que.swap(tmp_tn_que);
            bool bottom_left_value = true;
            while (cur_tn_que.size())
            {
                auto cur_tn = cur_tn_que.front();
                if (cur_tn->left){
                    tmp_tn_que.push(cur_tn->left);
                }
                if (cur_tn->right){
                    tmp_tn_que.push(cur_tn->right);
                }

                if (bottom_left_value)
                {
                    bottom_left_value = false;
                    res = cur_tn->val;
                }
                
                cur_tn_que.pop();
            }
        }
        
        return res;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find Bottom Left Tree Value, Algorithm(Depth-First Search) !\n";
    cout << "https://leetcode.com/problems/find-bottom-left-tree-value/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [2,1,3]\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *roots = tn2;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.findBottomLeftValue(roots);
        printf("result:%d\n", result);
        
        delete tn1;
        delete tn2;
        delete tn3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: roots = [1,2,3,4,null,5,6,null,null,7]\n");
    printf("expected result: output = 7\n");
    {
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn5 = new TreeNode(5, tn7, NULL);
        TreeNode *tn6 = new TreeNode(6, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn4, NULL);
        TreeNode *tn3 = new TreeNode(3, tn5, tn6);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.findBottomLeftValue(roots);
        printf("result:%d\n", result);
        
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
        delete tn5;
        delete tn6;
        delete tn7;
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
