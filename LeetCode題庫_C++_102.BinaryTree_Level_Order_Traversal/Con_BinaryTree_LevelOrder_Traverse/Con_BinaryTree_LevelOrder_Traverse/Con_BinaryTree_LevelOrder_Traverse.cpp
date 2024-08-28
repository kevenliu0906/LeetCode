// Con_BinaryTree_LevelOrder_Traverse.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    void levelOrder_detail(TreeNode *root, vector<vector<int>> &res)
    {
        if (root==NULL){
            return;
        }

        queue<TreeNode*> cur_node_queue;
        queue<TreeNode*> tmp_node_queue;
        tmp_node_queue.push(root);
        while (tmp_node_queue.size())
        {
            tmp_node_queue.swap(cur_node_queue);  // swap the node of "tmp_queue" into "cur_queue"
            vector<int> res_sub;
            while (cur_node_queue.size())
            {
                // 
                auto cur = cur_node_queue.front();
                cur_node_queue.pop();

                res_sub.push_back(cur->val);
                
                // store the next left-node and next right-node to tmp_queue for next iteration
                if (cur->left){
                    tmp_node_queue.push(cur->left);
                }
                if (cur->right){
                    tmp_node_queue.push(cur->right);
                }   
            }
            res.push_back(res_sub);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        // solution 1 (keven, using queue to solve)
        {
            vector<vector<int>> res;

            levelOrder_detail(root, res);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Binary Tree Level Order Traversal, Algorithm and DataStructure(Binary Tree, queue)!\n";
    cout << "https://leetcode.com/problems/binary-tree-level-order-traversal/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = [[3],[9,20],[15,7]]\n");
    {
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN15 = new TreeNode(15, NULL, NULL);
        TreeNode *TN20 = new TreeNode(20, TN15, TN7);
        TreeNode *TN9 = new TreeNode(9, NULL, NULL);
        TreeNode *TN3 = new TreeNode(3, TN9, TN20);
        TreeNode *root = TN3;
        
        Solution solution;
        auto res = solution.levelOrder(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            auto res_sub = res[i].size();
            printf("res(%d): ", i);
            for (size_t j = 0; j < res_sub; j++)
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
