﻿// Console_BinaryTree_Inorder_Traversal.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


//  Definition for a binary tree node.
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
    
    vector<int> res;
    
    vector<int> inorderTraversal(TreeNode* root) {
        // // solution 0 (keven, using recursive to solve)
        // {

        //     if (root == NULL)
        //     {
        //         return res;
        //     }
            
        //     inorderTraversal(root->left);   // 1st. traversal to left-side
        //     res.push_back(root->val);       // 2nd, print root
        //     inorderTraversal(root->right);  // 3rd. traversal to left-side

        //     return res;
        // }

        // solution 1 (keven, using stack to solve)
        {
            stack<TreeNode*> store_tn_stack;
            TreeNode *cur_tn = root;

            while (cur_tn || store_tn_stack.size())
            {
                // STEP1: traverse left-side node
                while (cur_tn)
                {
                    store_tn_stack.push(cur_tn);
                    cur_tn = cur_tn->left;
                }
                
                // STEP2: get last root tn from stored stack
                cur_tn = store_tn_stack.top();
                store_tn_stack.pop();
                res.push_back(cur_tn->val);

                // STEP3: traverse right-side secondly
                cur_tn = cur_tn->right;
            }

            return res;
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - BinaryTree Inorder Traversal, Algorithm and DataStructure(Binary Tree, stack)!\n";
    cout << "https://leetcode.com/problems/binary-tree-inorder-traversal" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,null,2,3]\n");
    printf("expected result: output = [1,3,2]\n");
    {
        TreeNode *TN3 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2 = new TreeNode(2, TN3, NULL);
        TreeNode *TN1 = new TreeNode(1, NULL, TN2);
        TreeNode *root = TN1;
        
        Solution solution;
        auto res = solution.inorderTraversal(root);
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
