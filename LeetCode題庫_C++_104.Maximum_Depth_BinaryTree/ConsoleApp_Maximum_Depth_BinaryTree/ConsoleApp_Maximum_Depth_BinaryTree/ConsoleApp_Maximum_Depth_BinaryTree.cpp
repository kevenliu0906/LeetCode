// ConsoleApp_Maximum_Depth_BinaryTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

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
    
    int maxDepth(TreeNode* root) {
        // solution 1 (keven, best, using recursive to solve)
        {
            if (root==NULL){
                return 0;
            }

            auto res = 1 + max( maxDepth(root->left), maxDepth(root->right));

            return res;
            
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Maximum Depth of Binary Tree, DataStructure and Algorithm(queue, BinaryTree, DFS, BFS)!\n";
    cout << "https://leetcode.com/problems/n-ary-tree-preorder-traversal/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = 3\n");
    {

        TreeNode *TN15 = new TreeNode(15, NULL, NULL);
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN20 = new TreeNode(20, TN15, TN7);
        TreeNode *TN9 = new TreeNode(9, NULL, NULL);
        TreeNode *TN3 = new TreeNode(3, TN9, TN20);
        TreeNode *root = TN3;
        
        Solution solution;
        auto res = solution.maxDepth(root);
        printf("res is %d\n", res);
        
        delete TN15;
        delete TN7;
        delete TN20;
        delete TN9;
        delete TN3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,null,2]\n");
    printf("expected result: output = 2\n");
    {

        TreeNode *TN2 = new TreeNode(2, NULL, NULL);
        TreeNode *TN1 = new TreeNode(1, NULL, TN2);
        TreeNode *root = TN1;
        
        Solution solution;
        auto res = solution.maxDepth(root);
        printf("res is %d\n", res);
        
        delete TN1;
        delete TN2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1,null,2,null,null,3,4,null,5]\n");
    printf("expected result: output = 4\n");
    {

        TreeNode *TN5 = new TreeNode(5, NULL, NULL);
        TreeNode *TN4 = new TreeNode(4, NULL, TN5);
        TreeNode *TN3 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2 = new TreeNode(2, TN3, TN4);
        TreeNode *TN1 = new TreeNode(1, NULL, TN2);
        TreeNode *root = TN1;
        
        Solution solution;
        auto res = solution.maxDepth(root);
        printf("res is %d\n", res);
        
        delete TN1;
        delete TN2;
        delete TN3;
        delete TN4;
        delete TN5;
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
