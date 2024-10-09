// Console_Construct_String_From_BT.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
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
private:
    string res = "";
    void DFS(TreeNode *root){
        if (root == NULL)
        {           
            return;
        }
        
        // char buf_val[5] = {'\0'};
        // sprintf_s(buf_val, "%d", root->val);
        // itoa(root->val, buf_val, 10);
        auto cur_val = to_string(root->val);
        res.append(cur_val);
        // printf("DFS >>> val:%d, res:%s\n", root->val, res.c_str());

        if (root->left || root->right)
        {
            res.append("(");
            DFS(root->left);
            res.append(")");

            res.append("(");
            DFS(root->right);
            res.append(")");
        }

        // omit all the empty parenthesis pairs
        if (res.size() >= 2)
        {
            if ( res[res.size() - 2] == '(' && res[res.size() - 1] == ')' )
            {
                // the last 2 char is (), so erase them
                res.erase(res.size()-2, 2);
            }
        }
    }

public:
    string tree2str(TreeNode* root) {
        // solution 1 (keven, using DFS to solve)
        {
            DFS(root);
            return res;    
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Construct String From BinaryTree, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/construct-string-from-binary-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [1,2,3,4]\n");
    printf("expected result: output = \"1(2(4))(3)\" \n");
    {
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, tn4, NULL);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.tree2str(roots);
        printf("result(%d):%s\n", result.size(), result.c_str());
        
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: roots = [1,2,3,null,4]\n");
    printf("expected result: output = \"1(2()(4))(3)\" \n");
    {
        TreeNode *tn4 = new TreeNode(4, NULL, NULL);
        TreeNode *tn2 = new TreeNode(2, NULL, tn4);
        TreeNode *tn3 = new TreeNode(3, NULL, NULL);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.tree2str(roots);
        printf("result(%d):%s\n", result.size(), result.c_str());
        
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: roots = [1]\n");
    printf("expected result: output = \"1\" \n");
    {
        TreeNode *tn1 = new TreeNode(1, NULL, NULL);
        TreeNode *roots = tn1;
        
        Solution solution;
        dbg_BT_node(roots);
        auto result = solution.tree2str(roots);
        printf("result(%d):%s\n", result.size(), result.c_str());
        
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
