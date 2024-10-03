// Conso_Find_LargestVal_EachTreeRow.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que; 
        if (root == NULL)
        {
            return res;
        }
        

        tmp_tn_que.push(root);
        while (tmp_tn_que.size())
        {
            cur_tn_que.swap(tmp_tn_que);
            int cur_row_max_tn_val = 0;
            if (cur_tn_que.size())
            {
                cur_row_max_tn_val = cur_tn_que.front()->val;
            }
            
            while (cur_tn_que.size())
            {
                auto cur_tn = cur_tn_que.front();
                if (cur_tn->left){
                    tmp_tn_que.push(cur_tn->left);
                }
                if (cur_tn->right){
                    tmp_tn_que.push(cur_tn->right);
                }

                cur_row_max_tn_val = max(cur_tn->val, cur_row_max_tn_val);
                
                cur_tn_que.pop();
            }

            res.push_back(cur_row_max_tn_val);
        }
        
        return res;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find LargestValue in Each Tree Row, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/find-largest-value-in-each-tree-row/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [1,3,2,5,3,null,9]\n");
    printf("expected result: output = [1,3,9]\n");
    {
        TreeNode *tn5 = new TreeNode(5, NULL, NULL);
        TreeNode *tn3_1 = new TreeNode(3, NULL, NULL);
        TreeNode *tn9 = new TreeNode(9, NULL, NULL);
        TreeNode *tn3_2 = new TreeNode(3, tn5, tn3_1);
        TreeNode *tn2 = new TreeNode(2, NULL, tn9);
        TreeNode *tn1 = new TreeNode(1, tn3_2, tn2);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.largestValues(roots);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
        
        
        delete tn1;
        delete tn2;
        delete tn3_1;
        delete tn3_2;
        delete tn5;
        delete tn9;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: roots = [1,2,3]\n");
    printf("expected result: output = [1,3]\n");
    {
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.largestValues(roots);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
        
        
        delete tn1;
        delete tn2;
        delete tn3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: roots = []\n");
    printf("expected result: output = []\n");
    {
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *roots = NULL;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.largestValues(roots);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
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
