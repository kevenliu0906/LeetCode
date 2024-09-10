// Console_Convert_SortList_to_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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

    TreeNode* createNode(vector<int>& ListNode_vec){

        TreeNode* new_node = NULL;
        if (ListNode_vec.size() == 0){
            return new_node;
        }
        
        int left_idx = 0;
        int right_idx = ListNode_vec.size() - 1;
        int mid_idx = left_idx + (right_idx - left_idx)/2;

        // root
        new_node = new TreeNode(ListNode_vec[mid_idx]);
        // printf("new_node->val:%d\n", new_node->val);

        if (left_idx == right_idx){
            return new_node;
        }
        
        
        // left-side, [vec[begin], vec[mid])
        if (left_idx < mid_idx)
        {
            vector<int> left_vec(ListNode_vec.begin(), ListNode_vec.begin() + mid_idx);
            auto left_node_ptr = createNode(left_vec);
            // if(left_node_ptr)
            //     printf("left_node_ptr->val:%d\n", left_node_ptr->val);
            new_node->left = left_node_ptr;
        }
        
        if (right_idx > mid_idx)
        {
            // right-side, (vec[mid], vec[end])
            vector<int> right_vec(ListNode_vec.begin() + mid_idx + 1, ListNode_vec.end());
            auto right_node_ptr = createNode(right_vec);
            // if(right_node_ptr)
            //     printf("right_node_ptr->val:%d\n", right_node_ptr->val);
            new_node->right = right_node_ptr;
        }

        return new_node;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // transfer node from LiskList to array
        ListNode *tmp_head = head;
        vector<int> ListNode_vec;
        while (tmp_head)
        {
            ListNode_vec.push_back(tmp_head->val);
            tmp_head = tmp_head->next;
        }
        // printf("ListNode_vec:\n");
        // for (size_t i = 0; i < ListNode_vec.size(); i++)
        // {
        //     printf("%d,", ListNode_vec[i]);
        // }
        // printf("\n");

        // 
        TreeNode *root = createNode(ListNode_vec);
        

        return root;
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
    std::cout << "Hello LeetCode - Convert Sorted List to Binary Search Tree, DataStructure and Algorithm(LinkedList, Divide and Conquer, Binary Search, Tree)!\n";
    cout << "https://leetcode.com/problems/binary-tree-preorder-traversal" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [-10,-3,0,5,9]\n");
    printf("expected result: output = [0,-3,9,-10,null,5]\n");
    {
        ListNode *LN9 = new ListNode(9);
        ListNode *LN5 = new ListNode(5, LN9);
        ListNode *LN0 = new ListNode(0, LN5);
        ListNode *LN3 = new ListNode(-3, LN0);
        ListNode *LN10 = new ListNode(-10, LN3);
        ListNode *head = LN10;
        
        Solution solution;
        auto res = solution.sortedListToBST(head);
        dbg_BT_node(res);
        
        
        delete LN9;
        delete LN5;
        delete LN0;
        delete LN3;
        delete LN10;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = []\n");
    printf("expected result: output = []\n");
    {
        ListNode *head = NULL;
        
        Solution solution;
        auto res = solution.sortedListToBST(head);
        dbg_BT_node(res);

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
