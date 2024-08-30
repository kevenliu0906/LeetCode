// Console_N-ary_Tree_Preorder_Travers.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    void preorder_detail(Node* root, vector<int> &res)
    {
        if (root == NULL){
            return;
        }

        res.push_back(root->val);
        for (auto child : root->children)
        {
            preorder_detail(child, res);
        }
    }
    vector<int> preorder(Node* root) {
        // solution 1 (Keven, using recursive to solve)
        {
            vector<int> res;

            preorder_detail(root, res);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - N-ary Tree Pre-order Traversal, Algorithm and DataStructure(Tree, stack)!\n";
    cout << "https://leetcode.com/problems/n-ary-tree-preorder-traversal/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,null,3,2,4,null,5,6]\n");
    printf("expected result: output = [1,3,5,6,2,4]\n");
    {
        vector<Node*> children1;
        vector<Node*> children2;

        Node *TN5 = new Node(5);
        Node *TN6 = new Node(6);
        children1.push_back(TN5);
        children1.push_back(TN6);
        Node *TN3 = new Node(3, children1);
        Node *TN2 = new Node(2);
        Node *TN4 = new Node(4);
        children2.push_back(TN3);
        children2.push_back(TN2);
        children2.push_back(TN4);
        Node *TN1 = new Node(1, children2);
        Node *root = TN1;
        
        Solution solution;
        auto res = solution.preorder(root);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
        delete TN5;
        delete TN6;
        delete TN3;
        delete TN2;
        delete TN4;
        delete TN1;
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
