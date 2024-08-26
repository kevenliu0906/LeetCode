// Conso_Flat_BinaryTree_to_LinkList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
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
    void flatten(TreeNode* root) {
        // solution 1 (keven, using stack to solve it)
        {
            stack<TreeNode*> Right_node_stack;
            TreeNode* res_root = NULL;
            TreeNode* res_now = NULL;
            while (root)
            {
                // STEP1. set current_tree_node for right now process tree-node
                auto current_Tree_Node = root;

                // STEP2. storage the right_tree_node into stack for future process
                if (current_Tree_Node->right)
                {
                    Right_node_stack.push(current_Tree_Node->right);
                }
                
                // STEP3. Move root to the next tree_node
                root = current_Tree_Node->left;

                if (root == NULL)
                {
                    if (Right_node_stack.size())
                    {
                        root = Right_node_stack.top();
                        Right_node_stack.pop();
                    }
                }
                
                // STEP4. Linked tree_node to each other
                current_Tree_Node->left = NULL;
                current_Tree_Node->right = NULL;
                if (res_now == NULL)
                {
                    res_root = current_Tree_Node;
                }
                else
                {
                    res_now->right = current_Tree_Node;
                }
                res_now = current_Tree_Node;
            }

            root = res_root;
            
            return;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Flattern BinaryTree to LinkedList, DataStructure(stack, linked list, binary tree)!\n";
    cout << "https://leetcode.com/problems/flatten-binary-tree-to-linked-list/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,5,3,4,null,6]\n");
    printf("expected result: output = [1,null,2,null,3,null,4,null,5,null,6]\n");
    {
        TreeNode *TN6 = new TreeNode(6, NULL, NULL);
        TreeNode *TN4 = new TreeNode(4, NULL, NULL);
        TreeNode *TN3 = new TreeNode(3, NULL, NULL);
        TreeNode *TN5 = new TreeNode(5, NULL, TN6);
        TreeNode *TN2 = new TreeNode(2, TN3, TN4);
        TreeNode *TN1 = new TreeNode(1, TN2, TN5);
        TreeNode *root = TN1;
        
        Solution solution;
        solution.flatten(root);
        
        delete TN1;
        delete TN2;
        delete TN3;
        delete TN4;
        delete TN5;
        delete TN6;
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
