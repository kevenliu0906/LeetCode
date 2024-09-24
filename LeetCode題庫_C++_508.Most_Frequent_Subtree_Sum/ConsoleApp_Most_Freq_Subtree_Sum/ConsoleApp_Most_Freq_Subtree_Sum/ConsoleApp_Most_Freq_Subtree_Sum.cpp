// ConsoleApp_Most_Freq_Subtree_Sum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

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
    unordered_multimap<int, int> sum_counts_unorderedmultimap;
    multimap<int, int> counts_sum_multimap;
    int sum_node(TreeNode *root){
        if (root == NULL)
        {
            return 0;
        }
        
        int left_sum = 0;
        int right_sum = 0;
        if (root->left){
            left_sum = sum_node(root->left);
            // printf("sum_node >>> left->val:%d, left_sum:%d\n", root->left->val, left_sum);
        }
        if (root->right){
            right_sum = sum_node(root->right);
            // printf("sum_node >>> right->val:%d, right_sum:%d\n", root->right->val, right_sum);
        }

        auto res = root->val + left_sum + right_sum;
        // printf("sum_node >>> root->val:%d, res:%d\n", root->val, res);

        // record the sum for subtree of current_node 
        if (sum_counts_unorderedmultimap.count(res) == 0){
            sum_counts_unorderedmultimap.insert(pair<int, int>(res, 1));
            counts_sum_multimap.insert(pair<int, int>(1, res));
        }
        else{
            // the sum of subtree is exist, so update the counts
            auto found_iter = sum_counts_unorderedmultimap.find(res);
            auto counts = found_iter->second;
            counts++;
            sum_counts_unorderedmultimap.erase(found_iter);
            sum_counts_unorderedmultimap.insert(pair<int, int>(res, counts));
            counts_sum_multimap.insert(pair<int, int>(counts, res));
        }
        
        return res;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // solution 1 (keven, force directly)
        {
            vector<int> res;

            int aa = sum_node(root);
            // debug the record of sum subtree
            int max_freq = counts_sum_multimap.rbegin()->first;
            int max_sum = counts_sum_multimap.rbegin()->second;

            // printf("max_freq:%d, max_sum:%d\n", max_freq, max_sum);

            for (auto iter = counts_sum_multimap.rbegin(); iter != counts_sum_multimap.rend(); iter++)
            {
                if (iter->first == counts_sum_multimap.rbegin()->first)
                {
                    res.push_back(iter->second);
                }
            }
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Most Frequent Subtree Sum - Algorithm and DataStructure(HASH TABLE, Binary Tree, Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/most-frequent-subtree-sum/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [5,2,-3]\n");
    printf("expected result: output = [2,-3,4]\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn3 = new TreeNode(-3);
        TreeNode *tn5 = new TreeNode(5, tn2, tn3);
        TreeNode *root = tn5;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findFrequentTreeSum(root);
        for (size_t i = 0; i < res.size(); i++){
            printf("%d,", res[i]);
        }
        printf("\n");
        
        
        delete tn2;
        delete tn3;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: root = [5,2,-3,1,6,7,3]\n");
    printf("expected result: output = [7]\n");
    {
        TreeNode *tn1 = new TreeNode(1);
        TreeNode *tn6 = new TreeNode(6);
        TreeNode *tn7 = new TreeNode(7);
        TreeNode *tn3 = new TreeNode(3);
        TreeNode *tn2 = new TreeNode(2, tn1, tn6);
        TreeNode *tn3_1 = new TreeNode(-3, tn7, tn3);
        TreeNode *tn5 = new TreeNode(5, tn2, tn3_1);
        TreeNode *root = tn5;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findFrequentTreeSum(root);
        for (size_t i = 0; i < res.size(); i++){
            printf("%d,", res[i]);
        }
        printf("\n");
        
        delete tn1;
        delete tn6;
        delete tn7;
        delete tn3;
        delete tn2;
        delete tn3_1;
        delete tn5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: root = [5,2,-5]\n");
    printf("expected result: output = [2]\n");
    {
        TreeNode *tn2 = new TreeNode(2);
        TreeNode *tn5_1 = new TreeNode(-5);
        TreeNode *tn5 = new TreeNode(5, tn2, tn5_1);
        TreeNode *root = tn5;
        
        Solution solution;
        dbg_BT_node(root);
        auto res = solution.findFrequentTreeSum(root);
        for (size_t i = 0; i < res.size(); i++){
            printf("%d,", res[i]);
        }
        printf("\n");
        
        
        delete tn2;
        delete tn5_1;
        delete tn5;
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
