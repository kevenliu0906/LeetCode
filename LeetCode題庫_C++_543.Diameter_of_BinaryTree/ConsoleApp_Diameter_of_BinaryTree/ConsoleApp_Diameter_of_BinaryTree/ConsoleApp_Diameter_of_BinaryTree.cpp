// ConsoleApp_Diameter_of_BinaryTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    
    int length_from_root_to_leave(TreeNode* root){
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que;
        int level_count = 0;
        tmp_tn_que.push(root);
        while (tmp_tn_que.size())
        {
            cur_tn_que.swap(tmp_tn_que);
            if (cur_tn_que.size())
            {
                level_count++;
            }
            while (cur_tn_que.size()){
                auto cur_tn = cur_tn_que.front();
                
                // printf("cur_tn->val:%d\n", cur_tn->val);
                if (cur_tn->left || cur_tn->right){
                    if (cur_tn->left){
                        // printf("cur_tn->left->val:%d\n", cur_tn->left->val);
                        tmp_tn_que.push(cur_tn->left);
                    }
                    if (cur_tn->right){
                        // printf("cur_tn->right->val:%d\n", cur_tn->right->val);
                        tmp_tn_que.push(cur_tn->right);
                    }
                }
                cur_tn_que.pop();
            }
        }
        
        return (level_count - 1);   // -1 because does NOT include root
    }

    int max_length_from_root(TreeNode *root){
        int left_length = 0;
        int right_length = 0;
        printf("max_length_from_root >> root->val:%d\n", root->val);
        if (root->left){
            left_length = length_from_root_to_leave(root->left);    // pass
            left_length = left_length + 1;  // 1 means from root->left
        }
        if (root->right){
            right_length = length_from_root_to_leave(root->right);  // pass
            right_length = right_length + 1;  // 1 means from root->right
        }
        printf("\n");
        return (left_length + right_length);
    }

    void in_ordered_path(TreeNode *root, vector<TreeNode*> &path){
        if (root == NULL){
            return;
        }
        
        in_ordered_path(root->left, path);
        path.push_back(root);
        in_ordered_path(root->right, path);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // solution 1 (keven, reference others)
        // https://medium.com/@ChYuan/leetcode-no-543-diameter-of-binary-tree-%E5%BF%83%E5%BE%97-easy-f6e313e4f8d1
        {
            // according to find the max-length from root to figure out the diameter path
            max_nodes_len = 0;
            max_len_to_leaves(root);

            return max_nodes_len;
        }

        // solution 0 (reference others)
        // https://zxi.mytechroad.com/blog/tree/leetcode-543-diameter-of-binary-tree/
        {
            _res = 0;
            LP(root);
            return _res;
        }

        // solution 2 (keven, force directly, time limit exceed)
        {
            vector<TreeNode*> path_in_order;
            int res_max = 0;

            in_ordered_path(root, path_in_order);
            // printf("path(in-order) >>>> \n");
            for (size_t i = 0; i < path_in_order.size(); i++){
                // printf("%d,", path_in_order[i]->val);
                auto cur_length = max_length_from_root(path_in_order[i]);
                if (cur_length > res_max)
                {
                    res_max = cur_length;
                }
            }
            return res_max;
        }
    }
private:
    // solution 1 used
    int max_nodes_len = 0;
    int max_len_to_leaves(TreeNode *root){
        if (root == NULL){
            return -1;
        }
        
        int left_len = max_len_to_leaves(root->left) + 1;    // max left path from cur_root to leaves
        int right_len = max_len_to_leaves(root->right) + 1;  // max right path from cur_root to leaves
        int cur_max_nodes_len = left_len + right_len;
        
        max_nodes_len = max(cur_max_nodes_len, max_nodes_len);
        
        if (left_len > right_len)
        {
            return left_len;
        }
        else
        {
            return right_len;
        }
        
    }

    // solution 0 used
    int _res;
    int LP(TreeNode *root){
        if (!root){
            return -1;
        }
        int left_len = LP(root->left) + 1;
        int right_len = LP(root->right) + 1;
        _res = max(_res, left_len+right_len);

        return max(left_len, right_len);
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
    std::cout << "Hello LeetCode - Diameter of Binary Tree, Algorithm(Binary Tree, Depth-First Search)!\n";

    cout << "https://leetcode.com/problems/diameter-of-binary-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,2,3,4,5]\n");
    printf("expected result: output = 3\n");
    {
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn5 = new TreeNode(5);
        TreeNode *tn2 = new TreeNode(2, tn4, tn5);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.diameterOfBinaryTree(root);
        printf("res is %d\n", res);
        
        delete tn4;
        delete tn5;
        delete tn2;
        delete tn3;
        delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,2]\n");
    printf("expected result: output = 1\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn1 = new TreeNode(1, tn2, NULL);
        TreeNode *root = tn1;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.diameterOfBinaryTree(root);
        printf("res is %d\n", res);
        
        delete tn2;
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
