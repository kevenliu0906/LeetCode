// ConsoleApplication_BinaryTree_Path.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>

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

void dbg_BT_node(TreeNode *root)
{

    // print by BT traversal(level-ordered traversal)
    queue<TreeNode*> nums_queue;

    printf("------- FINAL RESULT(dbg) -------\n");

    if (root == NULL)
    {
        printf("tn is NULL\n");
        return;
    }
    
    nums_queue.push(root);
    while (nums_queue.size())
    {
        auto cur_tn = nums_queue.front();
        nums_queue.pop();
        if (cur_tn == NULL){
            printf("null,");
        }else{
            printf("%d,", cur_tn->val);
            if (cur_tn->left || cur_tn->right)
            {
                nums_queue.push(cur_tn->left);
                nums_queue.push(cur_tn->right);
            }          
        }
    }
    printf("\n---------------------------------\n");
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // solution 1 (keven, force directly)
        {
            vector<string> res;
            queue<TreeNode*> tmp_tn_que;
            queue<TreeNode*> cur_tn_que;
            queue<string> tmp_tnpath_que;
            queue<string> cur_tnpath_que;
            tmp_tn_que.push(root);
            tmp_tnpath_que.push(to_string(root->val));
            while (tmp_tn_que.size())
            {
                cur_tn_que.swap(tmp_tn_que);
                cur_tnpath_que.swap(tmp_tnpath_que);
                while (cur_tn_que.size())
                {
                    auto cur_tn = cur_tn_que.front();
                    auto cur_tnpath = cur_tnpath_que.front();
                    if (cur_tn->left || cur_tn->right)
                    {
                        if (cur_tn->left){
                            tmp_tn_que.push(cur_tn->left);
                            tmp_tnpath_que.push(cur_tnpath + "->" + to_string(cur_tn->left->val));
                        }
                        if (cur_tn->right){
                            tmp_tn_que.push(cur_tn->right);
                            tmp_tnpath_que.push(cur_tnpath + "->" + to_string(cur_tn->right->val));
                        }
                        
                    }else{
                        // printf("cur_tnpath:%s\n", cur_tnpath.c_str());
                        res.push_back(cur_tnpath);
                    }

                    cur_tn_que.pop();
                    cur_tnpath_que.pop();
                }
            }

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - BinaryTree Path, Algorithm(Binary Tree, Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/binary-tree-paths/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,3,null,5]\n");
    printf("expected result: output = [\"1,2,5\", \"1,3\"]\n");
    {
        TreeNode *tn5 = new TreeNode(5);
        TreeNode *tn2 = new TreeNode(2, NULL, tn5);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.binaryTreePaths(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("item[%d]: %s\n", i, res[i].c_str());
        }
        printf("\n");

        delete tn5;
        delete tn2;
        delete tn3;
        delete tn1;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1]\n");
    printf("expected result: output = [\"1\"]\n");
    {
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.binaryTreePaths(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("item[%d]: %s\n", i, res[i].c_str());
        }
        printf("\n");

        delete tn1;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [1,2,3,null,5,4,null]\n");
    printf("expected result: output = [\"1,2,5\", \"1,3,4,6\"]\n");
    {
        TreeNode* tn5 = new TreeNode(5);
        TreeNode* tn2 = new TreeNode(2, NULL, tn5);
        TreeNode* tn6 = new TreeNode(6);
        TreeNode* tn4 = new TreeNode(4, NULL, tn6);
        TreeNode* tn3 = new TreeNode(3, tn4, NULL);
        TreeNode* tn1 = new TreeNode(1, tn2, tn3);
        
        
        TreeNode* root = tn1;

        dbg_BT_node(root);
        Solution solution;
        auto res = solution.binaryTreePaths(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("item[%d]: %s\n", i, res[i].c_str());
        }
        printf("\n");

        delete tn5;
        delete tn2;
        delete tn6;
        delete tn4;
        delete tn3;
        delete tn1;

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
