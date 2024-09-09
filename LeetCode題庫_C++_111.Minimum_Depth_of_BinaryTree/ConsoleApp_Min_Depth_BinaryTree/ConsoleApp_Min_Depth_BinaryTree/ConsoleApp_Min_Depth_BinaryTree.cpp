// ConsoleApp_Min_Depth_BinaryTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

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
    int minDepth(TreeNode* root) {
        // solution 1 (keven, force directly)
        {
            vector<TreeNode*> tmp_tn_vec;
            int lev_count = 0;
            
            if (root == NULL){
                return 0;
            }

            tmp_tn_vec.push_back(root);
            while (tmp_tn_vec.size())
            {
                lev_count++;
                vector<TreeNode*> cur_tn_vec(tmp_tn_vec);
                tmp_tn_vec.clear();
                int tn_idx = 0;
                while (tn_idx < cur_tn_vec.size())
                {
                    auto cur_tn = cur_tn_vec[tn_idx];

                    if (cur_tn->left == NULL && cur_tn->right == NULL)
                    {
                        // BINGO~~~~
                        return lev_count;
                    }
                    
                    if (cur_tn->left){
                        tmp_tn_vec.push_back(cur_tn->left);
                    }
                    if (cur_tn->right){
                        tmp_tn_vec.push_back(cur_tn->right);
                    }

                    tn_idx++;   
                }   
            }

            return 0;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Minimum Depth of BinaryTree, Algorithm(BinaryTree, Depth-First Search, Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/binary-tree-preorder-traversal" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = 2\n");
    {
        TreeNode *TN15 = new TreeNode(15, NULL, NULL);
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN20 = new TreeNode(20, TN15, TN7);
        TreeNode *TN9 = new TreeNode(9, NULL, NULL);
        TreeNode *TN3 = new TreeNode(3, TN9, TN20);
        TreeNode *root = TN3;
        
        Solution solution;
        auto res = solution.minDepth(root);
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
    printf("input: root = [2,null,3,null,4,null,5,null,6]\n");
    printf("expected result: output = 5\n");
    {
        TreeNode *TN6 = new TreeNode(6, NULL, NULL);
        TreeNode *TN5 = new TreeNode(5, NULL, TN6);
        TreeNode *TN4 = new TreeNode(4, NULL, TN5);
        TreeNode *TN3 = new TreeNode(3, NULL, TN4);
        TreeNode *TN2 = new TreeNode(2, NULL, TN3);
        TreeNode *root = TN2;
        
        Solution solution;
        auto res = solution.minDepth(root);
        printf("res is %d\n", res);
        

        delete TN6;
        delete TN5;
        delete TN4;
        delete TN3;
        delete TN2;
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
