// ConsoleApplication_Balance_BinaryTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
 
class Solution {
public:
    int GetNodeDepth(TreeNode* root){
        
        int Node_Dept = 0;
        
        if (root==NULL){
            return Node_Dept;
        }
        
        queue<TreeNode*> tmp_queue;
        tmp_queue.push(root);
        while (tmp_queue.size()){
            queue<TreeNode*> cur_queue;
            cur_queue.swap(tmp_queue);
            while (cur_queue.size()){
                auto cur_node = cur_queue.front();
                if (cur_node->left){
                    tmp_queue.push(cur_node->left);
                }
                if (cur_node->right){
                    tmp_queue.push(cur_node->right);
                }
                
                cur_queue.pop();
            }
            Node_Dept++;
        }
        
        return Node_Dept;
    }
    
    bool isBalanced(TreeNode* root) {
        // solution 1 (keven, using queue and recursive to solve)
        {
            if (root == NULL)
                return true;
                
            // get left-child depth
            auto left_depth = GetNodeDepth(root->left);
            // printf("left_depth:%d\n", left_depth);
            
            // get right-child depth
            auto right_depth = GetNodeDepth(root->right);
            // printf("right_depth:%d\n", right_depth);

            // STEP1: check if current node is balance
            if (abs(left_depth - right_depth) > 1)
                return false;

            // STEP2: check if current_node -> left is balance
            if (!isBalanced(root->left))
                return false;

            // STEP3: check if current_node -> right is balance
            if (!isBalanced(root->right))
                return false;
            
            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Balance Binary Tree, Algorithm(Binary Tree)!\n";
    cout << "https://leetcode.com/problems/balanced-binary-tree" << endl << endl;
    cout << "BinaryTree is balance as : https://ithelp.ithome.com.tw/articles/10213283" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,9,20,null,null,15,7]\n");
    printf("expected result: output = true\n");
    {
        TreeNode *TN15 = new TreeNode(15, NULL, NULL);
        TreeNode *TN7 = new TreeNode(7, NULL, NULL);
        TreeNode *TN20 = new TreeNode(20, TN15, TN7);
        TreeNode *TN9 = new TreeNode(9, NULL, NULL);
        TreeNode *TN3 = new TreeNode(3, TN9, TN20);
        TreeNode *root = TN3;
        
        Solution solution;
        auto res = solution.isBalanced(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);

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
    printf("input: root = [1,2,2,3,3,null,null,4,4]\n");
    printf("expected result: output = false\n");
    {
        TreeNode *TN4_1 = new TreeNode(4, NULL, NULL);
        TreeNode *TN4_2 = new TreeNode(4, NULL, NULL);
        TreeNode *TN3_1 = new TreeNode(3, TN4_1, TN4_2);
        TreeNode *TN3_2 = new TreeNode(3, NULL, NULL);
        TreeNode *TN2_1 = new TreeNode(2, TN3_1, TN3_2);
        TreeNode *TN2_2 = new TreeNode(2, NULL, NULL);
        TreeNode *TN1_1 = new TreeNode(1, TN2_1, TN2_2);
        TreeNode *root = TN1_1;
        
        Solution solution;
        auto res = solution.isBalanced(root);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);

        delete TN1_1;
        delete TN2_1;
        delete TN2_2;
        delete TN3_1;
        delete TN3_2;
        delete TN4_1;
        delete TN4_2;
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
