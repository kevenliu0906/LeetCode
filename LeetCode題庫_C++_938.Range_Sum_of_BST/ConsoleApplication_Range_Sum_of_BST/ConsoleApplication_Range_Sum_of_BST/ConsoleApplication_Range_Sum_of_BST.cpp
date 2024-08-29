// ConsoleApplication_Range_Sum_of_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
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
    void In_Order_Traversal(TreeNode* root, vector<int> &num_vec)
    {
        if (root == NULL)
            return;

        In_Order_Traversal(root->left, num_vec);
        num_vec.push_back(root->val);
        In_Order_Traversal(root->right, num_vec);        
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        // solution 1 (keven, using in-ordered traversal for BST to solve)
        {
            vector<int> in_order_nums;
            int res = 0;
            
            In_Order_Traversal(root, in_order_nums);
            
            // printf("BST in-order:\n");
            for (size_t i = 0; i < in_order_nums.size(); i++)
            {
                // printf("%d,", in_order_nums[i]);
                if (in_order_nums[i]<low)
                    continue;
                if (in_order_nums[i]>high)
                {
                    break;
                }
                res+=in_order_nums[i];
            }
            // printf("\n");
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Range Sum of BST, Algorithm(Binary Search Tree, Binary Tree)!\n";
    cout << "https://leetcode.com/problems/range-sum-of-bst/" << endl << endl;
    // cout << "solution: https://medium.com/@cashbooktw/construct-binary-tree-with-preorder-and-inorder-traversal-c50fb945f00f" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [10,5,15,3,7,null,18], low=7, high=15\n");
    printf("expected result: output = 32\n");
    {
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn7 = new TreeNode(7, NULL, NULL);
        TreeNode *tn5 = new TreeNode(5, tn3, tn7);
        TreeNode *tn18 = new TreeNode(18, NULL, NULL);
        TreeNode *tn15 = new TreeNode(15, NULL, tn18);
        TreeNode *tn10 = new TreeNode(10, tn5, tn15);
        TreeNode *root = tn10;
        int low = 7;
        int high = 15;

        Solution solution;
        auto res = solution.rangeSumBST(root, low, high);
        printf("rangeSumBST is %d\n", res);
        
        delete tn3;
        delete tn7;
        delete tn5;
        delete tn18;
        delete tn15;
        delete tn10;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [10,5,15,3,7,13,18,1,null,6], low=6, high=10\n");
    printf("expected result: output = 23\n");
    {
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *tn6 = new TreeNode(6, NULL, NULL);
        TreeNode *tn3 = new TreeNode(3, tn1, NULL);
        TreeNode *tn7 = new TreeNode(7, tn6, NULL);
        TreeNode *tn5 = new TreeNode(5, tn3, tn7);
        TreeNode *tn18 = new TreeNode(18, NULL, NULL);
        TreeNode *tn13 = new TreeNode(13, NULL, NULL);
        TreeNode *tn15 = new TreeNode(15, tn13, tn18);
        TreeNode *tn10 = new TreeNode(10, tn5, tn15);
        TreeNode *root = tn10;
        int low = 6;
        int high = 10;

        Solution solution;
        auto res = solution.rangeSumBST(root, low, high);
        printf("rangeSumBST is %d\n", res);
        
        delete tn1;
        delete tn6;
        delete tn3;
        delete tn7;
        delete tn5;
        delete tn18;
        delete tn13;
        delete tn15;
        delete tn10;
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
