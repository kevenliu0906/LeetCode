// Console_BinarySearchTree_Iterator.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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

// solution 1 (Keven, using in-ordered & queue to solve)
class BSTIterator {
public:
    queue<TreeNode*> Inordered_tn_que;
    void Inorder_TN(TreeNode *root)
    {
        if (root == NULL)
            return;
        
        Inorder_TN(root->left);
        Inordered_tn_que.push(root);
        Inorder_TN(root->right);
    }

    BSTIterator(TreeNode* root) {
        
        queue<TreeNode*> Empty_queue;
        Inordered_tn_que.swap(Empty_queue);  // clear all elements in queue

        Inorder_TN(root);
        // for debug
        // printf("In-ordered TreeNode queue:");
        // while (Inordered_tn_que.size())
        // {
        //     printf("%d,", Inordered_tn_que.front()->val);
        //     Inordered_tn_que.pop();
        // }
        // printf("\n");
    }
    
    int next() {
        
        auto nextValue = Inordered_tn_que.front()->val;
        Inordered_tn_que.pop();
        return nextValue;
        
    }
    
    bool hasNext() {
        
        if (Inordered_tn_que.size() == 0)
            return false;
        
        return true;

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    std::cout << "Hello LeetCode - Binary Search Tree Iterator, Algorithm and DataStructure(Binary Search Tree, stack)!\n";
    cout << "https://leetcode.com/problems/binary-search-tree-iterator/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: input = [\"BSTIterator\", \"next\", \"next\", \"hasNext\", \"next\", \"hasNext\", \"next\", \"hasNext\", \"next\", \"hasNext\"]\n");
    printf("             = [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]\n");                           
    printf("expected result: output = [null, 3, 7, true, 9, true, 15, true, 20, false]\n");
    {
        TreeNode *TN9 = new TreeNode(9,NULL,NULL);
        TreeNode *TN20 = new TreeNode(20,NULL,NULL);
        TreeNode *TN15 = new TreeNode(15,TN9,TN20);
        TreeNode *TN3 = new TreeNode(3,NULL,NULL);
        TreeNode *TN7 = new TreeNode(7,TN3,TN15);
        TreeNode *root = TN7;

        auto _BSTIterator = new BSTIterator(root);
        
        auto res_int = _BSTIterator->next();
        printf("next:%d\n", res_int);
        res_int = _BSTIterator->next();
        printf("next:%d\n", res_int);
        auto res_bool = _BSTIterator->hasNext();
        printf("hasnext:%d\n", res_bool);
        res_int = _BSTIterator->next();
        printf("next:%d\n", res_int);
        res_bool = _BSTIterator->hasNext();
        printf("hasnext:%d\n", res_bool);
        res_int = _BSTIterator->next();
        printf("next:%d\n", res_int);
        res_bool = _BSTIterator->hasNext();
        printf("hasnext:%d\n", res_bool);
        res_int = _BSTIterator->next();
        printf("next:%d\n", res_int);
        res_bool = _BSTIterator->hasNext();
        printf("hasnext:%d\n", res_bool);

        delete _BSTIterator;

        delete TN9;
        delete TN20;
        delete TN15;
        delete TN3;
        delete TN7;
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
