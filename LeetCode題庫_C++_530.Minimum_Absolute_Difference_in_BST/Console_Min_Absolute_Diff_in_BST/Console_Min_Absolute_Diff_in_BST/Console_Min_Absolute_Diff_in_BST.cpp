// Console_Min_Absolute_Diff_in_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<int> inOrder_vec;

    void inOrder_search(TreeNode* root){
        if (root == NULL){
            return;
        }
        
        inOrder_search(root->left);
        // printf("%d,", root->val);
        inOrder_vec.push_back(root->val);
        inOrder_search(root->right);
    }

    int getMinimumDifference(TreeNode* root) {

        // solution 1 (keven, using in-order in BST will cause the list of number is alignment by ascend)
        {
            inOrder_search(root);
            // printf("\n");
            int res_min = 100000;
            for (size_t i = 0; i < inOrder_vec.size() - 1; i++)
            {
                auto cur_diff = abs(inOrder_vec[i] - inOrder_vec[i+1]);
                if (cur_diff < res_min){
                    res_min = cur_diff;
                }
            }
            
            return res_min;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Minimum Absolute Difference in BST, Algorithm(Depth-First Search, Breadth-First Search, Binary Tree)!\n";

    cout << "https://leetcode.com/problems/minimum-absolute-difference-in-bst/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [4,2,6,1,3]\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn2 = new TreeNode(2, tn1, tn3);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn4 = new TreeNode(4, tn2, tn6);
        TreeNode *root = tn4;
        
        Solution solution;
        auto res = solution.getMinimumDifference(root);
        printf("res is %d\n", res);

        delete tn1;
        delete tn3;
        delete tn2;
        delete tn6;
        delete tn4;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,0,48,null,null,12,49]\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *tn12 = new TreeNode(12);
        TreeNode *tn49 = new TreeNode(49);
        TreeNode *tn48 = new TreeNode(48, tn12, tn49);
        TreeNode *tn0 = new TreeNode(0);
        TreeNode *tn1 = new TreeNode(1, tn0, tn48);
        TreeNode *root = tn1;
        
        Solution solution;
        auto res = solution.getMinimumDifference(root);
        printf("res is %d\n", res);

        delete tn1;
        delete tn0;
        delete tn48;
        delete tn49;
        delete tn12;
        
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
