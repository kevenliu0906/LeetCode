// Console_BinaryTree_Right_Side_View.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        // solution 0 (keven, using queue to solve)
        {
            vector<int> res;

            if (root == NULL){
                return res;
            }
            
            queue<TreeNode*> tmp_tn_que;
            queue<TreeNode*> cur_tn_que;
            
            res.push_back(root->val);   // add root-val in first   
            tmp_tn_que.push(root);

            while (tmp_tn_que.size())
            {
                cur_tn_que.swap(tmp_tn_que);
                vector<TreeNode*> tmp_tn_vec;
                while (cur_tn_que.size())
                {
                    auto cur_tn = cur_tn_que.front();
                    if (cur_tn->left){
                        tmp_tn_que.push(cur_tn->left);
                        tmp_tn_vec.push_back(cur_tn->left);
                    }
                    if (cur_tn->right){
                        tmp_tn_que.push(cur_tn->right);
                        tmp_tn_vec.push_back(cur_tn->right);
                    }
                    
                    cur_tn_que.pop();
                }
                int tmp_vec_size = tmp_tn_vec.size();
                // printf("tmp_vec_size:%d\n", tmp_vec_size);
                if (tmp_vec_size){
                    auto last_right_val = tmp_tn_vec[tmp_vec_size-1]->val;
                    // printf("last_right_val:%d\n", last_right_val);
                    res.push_back(last_right_val);
                }
            }

            return res;
        }
    }
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

int main()
{
    std::cout << "Hello LeetCode - BinaryTree Right Side View, Algorithm(BinaryTree)!\n";
    cout << "https://leetcode.com/problems/binary-tree-right-side-view/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,3,null,5,null,4]\n");
    printf("expected result: output = [1,3,4]\n");
    {
        TreeNode *tn5 = new TreeNode(5);
        TreeNode *tn2 = new TreeNode(2, NULL, tn5);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn3 = new TreeNode(3, NULL, tn4);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.rightSideView(root);
        if (res.size() == 0){
            printf("res is NULL!\n");
        }else{
            printf("res is:\n");
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }
        
        delete tn5;
        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,null,3]\n");
    printf("expected result: output = [1,3]\n");
    {
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn1 = new TreeNode(1, NULL, tn3);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.rightSideView(root);
        if (res.size() == 0){
            printf("res is NULL!\n");
        }else{
            printf("res is:\n");
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }
        
        delete tn1;
        delete tn3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [null]\n");
    printf("expected result: output = []\n");
    {
        TreeNode *root = NULL;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.rightSideView(root);
        if (res.size() == 0){
            printf("res is NULL!\n");
        }else{
            printf("res is:\n");
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [1,2]\n");
    printf("expected result: output = [1,2]\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn1 = new TreeNode(1,tn2,NULL);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.rightSideView(root);
        if (res.size() == 0){
            printf("res is NULL!\n");
        }else{
            printf("res is:\n");
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }

        delete tn1;
        delete tn2;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: root = [1,2,3,4]\n");
    printf("expected result: output = [1,3,4]\n");
    {
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn2 = new TreeNode(2,tn4,NULL);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn1 = new TreeNode(1,tn2,tn3);
        TreeNode *root = tn1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.rightSideView(root);
        if (res.size() == 0){
            printf("res is NULL!\n");
        }else{
            printf("res is:\n");
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }

        delete tn1;
        delete tn2;
        delete tn3;
        delete tn4;
        
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
