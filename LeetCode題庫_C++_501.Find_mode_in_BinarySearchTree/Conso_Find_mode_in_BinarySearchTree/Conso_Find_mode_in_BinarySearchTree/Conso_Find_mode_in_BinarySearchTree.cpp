// Conso_Find_mode_in_BinarySearchTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
    vector<int> findMode(TreeNode* root) {
        // solution 1 (keven, force directly)
        {
            int val_count_vec[200001] = {0};   // val range is [-10^5 ~ 10^5], idx: val, element: count
            vector<int> res;
            queue<TreeNode*> tmp_tn_que;
            queue<TreeNode*> cur_tn_que;
            tmp_tn_que.push(root);
            while (tmp_tn_que.size())
            {
                cur_tn_que.swap(tmp_tn_que);
                while (cur_tn_que.size())
                {
                    auto cur_tn = cur_tn_que.front();
                    if (cur_tn->val >= 0){   // positive value
                        val_count_vec[2*cur_tn->val]++;
                    }else{                   // negative value
                        val_count_vec[2*(abs(cur_tn->val)) - 1]++;
                    }
                    
                    
                    if (cur_tn->left){
                        tmp_tn_que.push(cur_tn->left);
                    }
                    if (cur_tn->right){
                        tmp_tn_que.push(cur_tn->right);
                    }
                    
                    cur_tn_que.pop();
                }
            }
            
            // use map to store & sort datas
            multimap<int,int> count_val_multimap;    //key: counts, value:node_val
            for (size_t i = 0; i < 200001; i++)
            {
                if (val_count_vec[i])
                {
                    if (i%2 == 0){  // positive value
                        // printf("val[%d](node:%d) - count:%d\n", i, i/2, val_count_vec[i]);
                        count_val_multimap.insert(pair<int,int>(val_count_vec[i], i/2));
                    }
                    else{           // negative value
                        // printf("val[%d](node:%d) - count:%d\n", i, 0-(i + 1)/2, val_count_vec[i]);
                        count_val_multimap.insert(pair<int,int>(val_count_vec[i], 0-(i + 1)/2));
                    }
                }
            }

            // printf("count_val_multimap size:%d\n", count_val_multimap.size());

            // for (auto iter = count_val_multimap.rbegin(); iter != count_val_multimap.rend(); iter++)
            // {
            //     printf("count:%d, iter->val:%d\n", iter->first, iter->second);
            // }

            int biggest_Freq = count_val_multimap.rbegin()->first;
            for (auto iter = count_val_multimap.rbegin(); iter != count_val_multimap.rend(); iter++){
                if (iter->first == biggest_Freq){
                    res.push_back(iter->second);
                }else{
                    break;
                }
                
            }

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find mode in Binary Search Tree, Algorithm(Binary Tree, Binary Search Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/find-mode-in-binary-search-tree/" << endl << endl;
    // cout << "solution: https://medium.com/@cashbooktw/construct-binary-tree-with-preorder-and-inorder-traversal-c50fb945f00f" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,null,2,2]\n");
    printf("expected result: output = [2]\n");
    {
        TreeNode *tn2_2 = new TreeNode(2);
        TreeNode *tn2_1 = new TreeNode(2, tn2_2, NULL);
        TreeNode *tn1_1 = new TreeNode(1, NULL, tn2_1);
        TreeNode *root = tn1_1;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findMode(root);
        if (res.size() == 0){
            printf("res is NULL\n");
        }else{
            printf("res size is %d!\n", res.size());
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }

        delete tn2_2;
        delete tn2_1;
        delete tn1_1;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [-100000,-100000,100000,2,1,-3,null]\n");
    printf("expected result: output = [-100000]\n");
    {
        TreeNode *tn2_1 = new TreeNode(2);
        TreeNode *tn1_1 = new TreeNode(1);
        TreeNode *tn3_1 = new TreeNode(-3);
        TreeNode *tn100000_1 = new TreeNode(-100000, tn2_1, tn1_1);
        TreeNode *tn100000_2 = new TreeNode(100000, tn3_1, NULL);
        TreeNode *tn5_1 = new TreeNode(-100000, tn100000_1, tn100000_2);
        TreeNode *root = tn5_1;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findMode(root);
        if (res.size() == 0){
            printf("res is NULL\n");
        }else{
            printf("res size is %d!\n", res.size());
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }

        delete tn2_1;
        delete tn1_1;
        delete tn3_1;
        delete tn100000_1;
        delete tn100000_2;
        delete tn5_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [-5,-3,1,2,1,3,null]\n");
    printf("expected result: output = [1]\n");
    {
        TreeNode *tn2_1 = new TreeNode(2);
        TreeNode *tn1_1 = new TreeNode(1);
        TreeNode *tn3_1 = new TreeNode(3);
        TreeNode *tn3_2 = new TreeNode(-3, tn2_1, tn1_1);
        TreeNode *tn1_2 = new TreeNode(1, tn3_1, NULL);
        TreeNode *tn5_1 = new TreeNode(-5, tn3_2, tn1_2);
        TreeNode *root = tn5_1;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findMode(root);
        if (res.size() == 0){
            printf("res is NULL\n");
        }else{
            printf("res size is %d!\n", res.size());
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }

        delete tn2_1;
        delete tn1_1;
        delete tn3_1;
        delete tn3_2;
        delete tn1_2;
        delete tn5_1;
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
