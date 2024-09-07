// Consol_BT_Level_Order_Traverse_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // solution 1 (keven, using queue to solve)
        {
            vector<vector<int>> res;

            if (root == NULL){
                return res;
            }

            queue<TreeNode*> tmp_num_que;

            tmp_num_que.push(root);

            while (tmp_num_que.size())
            {
                queue<TreeNode*> cur_num_que;
                vector<int> sub_res;
                cur_num_que.swap(tmp_num_que);
                while (cur_num_que.size())
                {
                    auto cur = cur_num_que.front();
                    if (cur->left){
                        tmp_num_que.push(cur->left);
                    }
                    if (cur->right){
                        tmp_num_que.push(cur->right);
                    }
                    sub_res.push_back(cur->val);
                    cur_num_que.pop();
                }
                res.insert(res.begin(), sub_res);
            }

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Binary Tree Level Order Traversal II, DataStructure and Algorithm(queue, Binary Tree)!\n";
    cout << "https://leetcode.com/problems/binary-tree-level-order-traversal-ii" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = [[15,7],[9,20],[3]]\n");
    {
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN15 = new TreeNode(15, NULL, NULL);
        TreeNode *TN20 = new TreeNode(20, TN15, TN7);
        TreeNode *TN9 = new TreeNode(9, NULL, NULL);
        TreeNode *TN3 = new TreeNode(3, TN9, TN20);
        TreeNode *root = TN3;
        
        Solution solution;
        auto res = solution.levelOrderBottom(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("(%d) - cur num:", i);
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        
        delete TN7;
        delete TN15;
        delete TN20;
        delete TN9;
        delete TN3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1]\n");
    printf("expected result: output = [[1]]\n");
    {
        TreeNode *TN1 = new TreeNode(1, NULL, NULL);
        TreeNode *root = TN1;
        
        Solution solution;
        auto res = solution.levelOrderBottom(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("(%d) - cur num:", i);
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        
        delete TN1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = []\n");
    printf("expected result: output = []\n");
    {
        TreeNode *root = NULL;
        
        Solution solution;
        auto res = solution.levelOrderBottom(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("(%d) - cur num:", i);
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
