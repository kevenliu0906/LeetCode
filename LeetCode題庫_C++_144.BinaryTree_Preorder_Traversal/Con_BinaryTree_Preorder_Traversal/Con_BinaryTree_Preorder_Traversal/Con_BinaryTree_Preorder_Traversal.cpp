// Con_BinaryTree_Preorder_Traversal.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
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
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        // solution 1 (keven, using stack to solve, best)
        {
            vector<int> res;
            stack<TreeNode*> right_node_stack;

            if (root == NULL){
                return res;
            }
            
            while (root != NULL)
            {
                res.push_back(root->val);

                if (root->right){
                    right_node_stack.push(root->right);
                }

                root = root->left;
                if (root == NULL)
                {
                    if (right_node_stack.size())
                    {
                        root = right_node_stack.top();
                        right_node_stack.pop();
                    }
                }
            }

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Algorithm and DataStructure(Binary Tree, stack)!\n";
    cout << "https://leetcode.com/problems/binary-tree-preorder-traversal" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,null,2,3]\n");
    printf("expected result: output = [1,2,3]\n");
    {
        TreeNode *TN3 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2 = new TreeNode(2, TN3, NULL);
        TreeNode *TN1 = new TreeNode(1, NULL, TN2);
        TreeNode *root = TN1;
        
        Solution solution;
        auto res = solution.preorderTraversal(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
        
        delete TN1;
        delete TN2;
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
