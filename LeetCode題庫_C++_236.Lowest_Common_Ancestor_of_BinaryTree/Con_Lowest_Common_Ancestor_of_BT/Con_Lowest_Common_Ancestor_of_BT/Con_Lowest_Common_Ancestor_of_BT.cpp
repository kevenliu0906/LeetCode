// Con_Lowest_Common_Ancestor_of_BT.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    TreeNode* BestAnswer_LCA(TreeNode *root, TreeNode *p, TreeNode *q){
        vector<vector<TreeNode*>> all_path;
        vector<TreeNode*> single_path;
        queue<TreeNode*> tmp_tn_que;
        queue<TreeNode*> cur_tn_que;
        vector<TreeNode*> p_tn_vec;
        vector<TreeNode*> q_tn_vec;

        // STEP1: record each path from root to "p-node" and "q-node"
        tmp_tn_que.push(root);
        single_path.push_back(root);
        all_path.push_back(single_path);
        // record the path from root to p-node if exist
        if (root->val == p->val){
            p_tn_vec = single_path;
            // unordered_set<TreeNode*> tmp_tn_set(single_path.begin(), single_path.end());   // this usage will cause data in set is not same as vector
            // p_tn_set.swap(tmp_tn_set);
        }
        // record the path from root to q-node if exist
        else if (root->val == q->val){
            q_tn_vec = single_path;
            // unordered_set<TreeNode*> tmp_tn_set(single_path.begin(), single_path.end());   // this usage will cause data in set is not same as vector
            // q_tn_set.swap(tmp_tn_set);
        }
        
        while (tmp_tn_que.size())
        {
            cur_tn_que.swap(tmp_tn_que);
            while (cur_tn_que.size())
            {
                // single_path = all_path[0];
                // // printf("single_path size:%d\n", single_path.size());
                // // for (size_t i = 0; i < single_path.size(); i++)
                // // {
                // //     printf("%d,", single_path[i]->val);
                // // }
                // // printf("\n");
                
                auto cur_tn = cur_tn_que.front();
                if (cur_tn->left){
                    tmp_tn_que.push(cur_tn->left);
                    single_path = all_path[0];
                    single_path.push_back(cur_tn->left);
                    all_path.push_back(single_path);
                    // record the path from root to p-node if exist
                    if (cur_tn->left->val == p->val){
                        p_tn_vec = single_path;
                        // unordered_set<TreeNode*> tmp_tn_set(single_path.begin(), single_path.end());   // this usage will cause data in set is not same as vector
                        // p_tn_set.swap(tmp_tn_set);
                    }
                    // record the path from root to q-node if exist
                    else if (cur_tn->left->val == q->val){
                        q_tn_vec = single_path;
                        // unordered_set<TreeNode*> tmp_tn_set(single_path.begin(), single_path.end());   // this usage will cause data in set is not same as vector
                        // q_tn_set.swap(tmp_tn_set);
                    }
                }
                if (cur_tn->right){
                    tmp_tn_que.push(cur_tn->right);
                    single_path = all_path[0];
                    single_path.push_back(cur_tn->right);
                    all_path.push_back(single_path);
                    // record the path from root to p-node if exist
                    if (cur_tn->right->val == p->val){
                        p_tn_vec = single_path;
                        // unordered_set<TreeNode*> tmp_tn_set(single_path.begin(), single_path.end());   // this usage will cause data in set is not same as vector
                        // p_tn_set.swap(tmp_tn_set);
                    }
                    // record the path from root to q-node if exist
                    else if (cur_tn->right->val == q->val){
                        q_tn_vec = single_path;
                        // unordered_set<TreeNode*> tmp_tn_set(single_path.begin(), single_path.end());   // this usage will cause data in set is not same as vector
                        // q_tn_set.swap(tmp_tn_set);
                    }
                }
                
                cur_tn_que.pop();
                all_path.erase(all_path.begin());

                if (p_tn_vec.size() && q_tn_vec.size()){
                    break;
                }
            }

            if (p_tn_vec.size() && q_tn_vec.size()){
                break;
            }
        }

        // // debug path from root to all leaves
        // printf("all_path size:%d\n", all_path.size());
        // for (size_t i = 0; i < all_path.size(); i++)
        // {
        //     printf("all_path[%d]:", i);
        //     for (size_t j = 0; j < all_path[i].size(); j++)
        //     {
        //         printf("%d,", all_path[i][j]->val);
        //     }
        //     printf("\n");
        // }

        // // debug path from root to p-node
        // printf("path from root to p-node:\n");
        // printf(">>>>>");
        // for (auto tn = p_tn_vec.begin(); tn != p_tn_vec.end(); tn++)
        // {
        //     printf("%d,", (*tn)->val);
        // }
        // printf("\n");
        
        // // debug path from root to q-node
        // printf("path from root to q-node:\n");
        // printf(">>>>>");
        // for (auto tn = q_tn_vec.begin(); tn != q_tn_vec.end(); tn++)
        // {
        //     printf("%d,", (*tn)->val);
        // }
        // printf("\n");

        TreeNode *lastMatch_tn = NULL;
        bool match = false;
        int moveIdx = 0;
        while (moveIdx < p_tn_vec.size() && moveIdx < q_tn_vec.size()){
            match = false;
            if (p_tn_vec[moveIdx] == q_tn_vec[moveIdx]){
                match = true;
                lastMatch_tn = p_tn_vec[moveIdx];
            }else{
                break;
            }
            
            moveIdx++;
        }
        if (match){
            if (p_tn_vec.size()>q_tn_vec.size()){
                return q;
            }else{
                return p;
            }
            
        }else{
            return lastMatch_tn;
        }
        
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // solution 0 (keven, using queue to solve)
        {
            auto res = BestAnswer_LCA(root, p, q);
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
    std::cout << "Hello LeetCode - Lowest Common Ancestor of Binary Tree, Algorithm(Binary Tree)!\n";
    cout << "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1\n");
    printf("expected result: output = [3]\n");
    {
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn2 = new TreeNode(2, tn7, tn4);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn5 = new TreeNode(5, tn6, tn2);
        TreeNode *tn0 = new TreeNode(0);
        TreeNode *tn8 = new TreeNode(8);
        TreeNode *tn1 = new TreeNode(1, tn0, tn8);
        TreeNode *tn3 = new TreeNode(3, tn5, tn1);
        TreeNode *root = tn3;
        TreeNode *p = tn5;
        TreeNode *q = tn1;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.lowestCommonAncestor(root, p, q);
        dbg_BT_node(res);
        
        
        delete tn3;
        delete tn5;
        delete tn1;
        delete tn6;
        delete tn2;
        delete tn0;
        delete tn8;
        delete tn7;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4\n");
    printf("expected result: output = [5]\n");
    {
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn2 = new TreeNode(2, tn7, tn4);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn5 = new TreeNode(5, tn6, tn2);
        TreeNode *tn0 = new TreeNode(0);
        TreeNode *tn8 = new TreeNode(8);
        TreeNode *tn1 = new TreeNode(1, tn0, tn8);
        TreeNode *tn3 = new TreeNode(3, tn5, tn1);
        TreeNode *root = tn3;
        TreeNode *p = tn5;
        TreeNode *q = tn4;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.lowestCommonAncestor(root, p, q);
        dbg_BT_node(res);
        
        
        delete tn3;
        delete tn5;
        delete tn1;
        delete tn6;
        delete tn2;
        delete tn0;
        delete tn8;
        delete tn7;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 6, q = 0\n");
    printf("expected result: output = [3]\n");
    {
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn4 = new TreeNode(4);
        TreeNode *tn2 = new TreeNode(2, tn7, tn4);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn5 = new TreeNode(5, tn6, tn2);
        TreeNode *tn0 = new TreeNode(0);
        TreeNode *tn8 = new TreeNode(8);
        TreeNode *tn1 = new TreeNode(1, tn0, tn8);
        TreeNode *tn3 = new TreeNode(3, tn5, tn1);
        TreeNode *root = tn3;
        TreeNode *p = tn6;
        TreeNode *q = tn0;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.lowestCommonAncestor(root, p, q);
        dbg_BT_node(res);
        
        
        delete tn3;
        delete tn5;
        delete tn1;
        delete tn6;
        delete tn2;
        delete tn0;
        delete tn8;
        delete tn7;
        delete tn4;
    }
    printf("*****************************************************\n");

    printf("\n\n");
    
    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: root = [1,2], p = 1, q = 2\n");
    printf("expected result: output = [1]\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn1 = new TreeNode(1, tn2, NULL);
        TreeNode *root = tn1;
        TreeNode *p = tn1;
        TreeNode *q = tn2;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.lowestCommonAncestor(root, p, q);
        dbg_BT_node(res);
        
        delete tn1;
        delete tn2;
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
