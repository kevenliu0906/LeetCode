// Console_N-ary_Tree_Postorder_Traver.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    void postorder_detail(Node* root, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }
        
        for (size_t i = 0; i < root->children.size(); i++)
        {
            postorder_detail(root->children.at(i), res);
        }
        
        res.push_back(root->val);

    }

    vector<int> postorder(Node* root) {
        // solution 1 (keven, using recursive to solve)
        {
            vector<int> res;

            postorder_detail(root, res);
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - N-ary Tree Post-order Traversal, Algorithm and DataStructure(Tree, recursive, stack)!\n";
    cout << "https://leetcode.com/problems/n-ary-tree-postorder-traversal/" << endl << endl;
    // cout << "solution: https://medium.com/@cashbooktw/construct-binary-tree-with-preorder-and-inorder-traversal-c50fb945f00f" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,null,3,2,4,null,5,6]\n");
    printf("expected result: output = [5,6,3,2,4,1]\n");
    {
        vector<Node*> children1;
        vector<Node*> children3;
        
        // for node-3
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        children3.push_back(n5);
        children3.push_back(n6);
        Node *n3 = new Node(3, children3);
        
        // for node-1
        Node *n2 = new Node(2);
        Node *n4 = new Node(4);
        children1.push_back(n3);
        children1.push_back(n2);
        children1.push_back(n4);
        Node *n1 = new Node(1, children1);
        Node *root = n1;

        
        Solution solution;
        auto res = solution.postorder(root);
        if (res.size() == 0)
        {
            printf("post-order for node is NULL\n");
        }else{
            printf("post-order for node is:\n");
            for (size_t i = 0; i < res.size(); i++)
            {
                printf("%d,", res[i]);
            }
            printf("\n");
        }
        
        delete n1;
        delete n2;
        delete n3;
        delete n4;
        delete n5;
        delete n6;
        
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
