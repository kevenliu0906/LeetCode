// ConsoleApplication_Path_Sum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_map>
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
    bool cur_node_sum(TreeNode* root, int& target_sum){
        unordered_map<TreeNode*, int> tn_tillcursum_map;
        queue<TreeNode*> cur_tn_que;
        queue<TreeNode*> tmp_tn_que;
        
        if (root->val == target_sum){
            if (root->left == NULL && root->right == NULL){
                return true;
            }
        }
        
        tmp_tn_que.push(root);
        tn_tillcursum_map.insert(pair<TreeNode*,int>(root,root->val));
        while (tmp_tn_que.size()){
            cur_tn_que.swap(tmp_tn_que);
            while (cur_tn_que.size()){
                auto cur_tn = cur_tn_que.front();
                auto cur_tn_sum_val = tn_tillcursum_map.find(cur_tn)->second;
                // printf("cur_tn_sum_val:%d\n", cur_tn_sum_val);
                auto sum = 0;
                if (cur_tn->left){
                    sum = cur_tn_sum_val + cur_tn->left->val;
                    // printf("cur_tn->left->val:%d, sum:%d, target_sum:%d\n", cur_tn->left->val, sum, target_sum);
                    if ((sum == target_sum) && (cur_tn->left->left == NULL && cur_tn->left->right == NULL)){  // need check if current node is LEAF(is a node with no children)
                        // printf("BINGO~~ FOUND IT, cur_tn_sum_val:%d, cur_tn->left->val:%d\n", cur_tn_sum_val, cur_tn->left->val);
                        return true;
                    }
                    else{
                        // need check in the next round because total-sum in current root is smaller than target
                        tmp_tn_que.push(cur_tn->left);
                        // printf("push queue, cur_tn->left:0x%x\n", cur_tn->left);
                        // record sum of path in current root
                        if (tn_tillcursum_map.find(cur_tn->left) == tn_tillcursum_map.end()){
                            // printf("map insert data: cur_tn->left->val:%d, sum:%d\n", cur_tn->left->val, sum);
                            tn_tillcursum_map.insert(pair<TreeNode*,int>(cur_tn->left,sum));
                        }
                    }
                }
                if (cur_tn->right){
                    sum = cur_tn_sum_val + cur_tn->right->val;
                    // printf("cur_tn->right->val:%d, sum:%d, target_sum:%d\n", cur_tn->right->val, sum, target_sum);
                    if ((sum == target_sum) && (cur_tn->right->left == NULL && cur_tn->right->right == NULL)){  // need check if current node is LEAF(is a node with no children)
                        // printf("BINGO~~ FOUND IT, cur_tn_sum_val:%d, cur_tn->right->val:%d\n", cur_tn_sum_val, cur_tn->right->val);
                        return true;
                    }
                    else{
                        // need check in the next round because total-sum in current root is smaller than target
                        tmp_tn_que.push(cur_tn->right);
                        // printf("push queue, cur_tn->right:0x%x\n", cur_tn->right);
                        // record sum of path in current root
                        if (tn_tillcursum_map.find(cur_tn->right) == tn_tillcursum_map.end()){
                            // printf("map insert data: cur_tn->right->val:%d, sum:%d\n", cur_tn->right->val, sum);
                            tn_tillcursum_map.insert(pair<TreeNode*,int>(cur_tn->right,sum));
                        }
                    }
                }
                
                cur_tn_que.pop();
            }
        }
        // printf("there is no sum of path is EQUAL to target num!\n");
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // solution 1 (keven, using HASH TABLE & queue to solve)
        {
            if (root == NULL){
                return false;
            }
            
            
            if(cur_node_sum(root, targetSum))
                return true;

            return false;
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
    std::cout << "Hello LeetCode - Path Sum, Algorithm(Tree, Binary Tree, Depth-First Search, Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/path-sum/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22\n");
    printf("expected result: output = true\n");
    {
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn11 = new TreeNode(11, tn7, tn2);
        TreeNode *tn4_1 = new TreeNode(4, tn11, NULL);

        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn4_2= new TreeNode(4, NULL, tn1);
        TreeNode *tn13 = new TreeNode(13);
        TreeNode *tn8 = new TreeNode(8,tn13,tn4_2);

        TreeNode *tn5 = new TreeNode(5,tn4_1,tn8);
        
        TreeNode *root = tn5;
        int targetSum = 22;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.hasPathSum(root, targetSum);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        
        delete tn7;
        delete tn2;
        delete tn11;
        delete tn4_1;
        delete tn1;
        delete tn4_2;
        delete tn13;
        delete tn8;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [1,2,3], targetSum = 5\n");
    printf("expected result: output = false\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn1 = new TreeNode(1, tn2, tn3);
        TreeNode *root = tn1;
        int targetSum = 5;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.hasPathSum(root, targetSum);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
        delete tn2;
        delete tn3;
        delete tn1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [], targetSum = 0\n");
    printf("expected result: output = false\n");
    {
        TreeNode *root = NULL;
        int targetSum = 0;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.hasPathSum(root, targetSum);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [1], targetSum = 1\n");
    printf("expected result: output = true\n");
    {
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *root = tn1;
        int targetSum = 1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.hasPathSum(root, targetSum);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);

        delete tn1;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: root = [1,-2,-3,1,3,-2,null,-1], targetSum = -1\n");
    printf("expected result: output = true\n");
    {
        TreeNode *tn_n1 = new TreeNode(-1);
        TreeNode *tn_1_1 = new TreeNode(1, tn_n1, NULL);
        TreeNode *tn_3 = new TreeNode(3);
        TreeNode *tn_n2_1 = new TreeNode(-2);
        TreeNode *tn_n2_2 = new TreeNode(-2, tn_1_1, tn_3);
        TreeNode *tn_n3 = new TreeNode(-3, tn_n2_1, NULL);
        TreeNode *tn_1_2 = new TreeNode(1, tn_n2_2, tn_n3);
        TreeNode *root = tn_1_2;
        int targetSum = -1;
        
        dbg_BT_node(root);
        Solution solution;
        auto res = solution.hasPathSum(root, targetSum);
        printf("res is %d, true(%d), false(%d)\n", res, true, false);

        delete tn_n1;
        delete tn_1_1;
        delete tn_3;
        delete tn_n2_1;
        delete tn_n2_2;
        delete tn_n3;
        delete tn_1_2;
        
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
