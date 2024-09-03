// Console_Flat_Nested_List_Iterator.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const /*{ return true; }*/ ;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const /*{ return 1; }*/ ;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    /*{
        vector<NestedInteger> res;
        return res;
    }*/;
};

// solution 0 (reference others, using queue to solve)
class NestedIterator {
public:

    queue<int> nestedlist_queue;

    void Flattern_NestedList(vector<NestedInteger> &nestedList)
    {
        for (size_t i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                auto cur_int = nestedList[i].getInteger();
                nestedlist_queue.push(cur_int);
            }else{
                auto cur_nestedlist = nestedList[i].getList();
                Flattern_NestedList(cur_nestedlist);
            }
            
        }

        return;
        
    }

    // Initializes the iterator with the nested list nestedList
    NestedIterator(vector<NestedInteger> &nestedList) {

        Flattern_NestedList(nestedList);

    }
    
    // Returns the next integer in the nested list.
    int next() {
        auto res = nestedlist_queue.front();
        nestedlist_queue.pop();
        return res;
    }
    
    // Returns true if there are still some integers in the nested list and false otherwise.
    bool hasNext() {
        auto res = nestedlist_queue.size();
        if (res > 0)
            return true;
        
        return false;
    }
};

 
// // solution 1 (keven, bad performance)
// class NestedIterator {
// public:

//     vector<int> nestedList_new;

//     // Initializes the iterator with the nested list nestedList
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         //
//         while (nestedList.size() > 0)
//         {
//             static int loop = 0;
//             loop++;
//             auto cur_nestedInteger = nestedList[0];
//             nestedList.erase(nestedList.begin());
            
//             if (cur_nestedInteger.isInteger())
//             {
//                 auto cur_int = cur_nestedInteger.getInteger();
//                 nestedList_new.push_back(cur_int);
//             }else{
//                 auto cur_nestedlist = cur_nestedInteger.getList();
                
//                 int insertPos = 0;
//                 for (size_t i = 0; i < cur_nestedlist.size(); i++)
//                 {                   
//                     auto insert_iter = nestedList.begin();
//                     int tmp_pos = insertPos;
//                     while (tmp_pos > 0)
//                     {
//                         insert_iter++;
//                         tmp_pos--;
//                     }
//                     nestedList.insert(insert_iter, cur_nestedlist[i]);
//                     insertPos++;
//                 }
//             }
//         }
//     }
    
//     // Returns the next integer in the nested list.
//     int next() {
//         auto res = nestedList_new[0];
//         nestedList_new.erase(nestedList_new.begin());
//         return res;
//     }
    
//     // Returns true if there are still some integers in the nested list and false otherwise.
//     bool hasNext() {
//         if (nestedList_new.size() > 0)
//             return true;

//         return false;
//     }
// };

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    std::cout << "Hello LeetCode - Flattern Nested List Iterator, DataStructure(stack, tree, queue)!\n";
    cout << "https://leetcode.com/problems/flatten-nested-list-iterator/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nestedList  = [[1,1],2,[1,1]]\n");
    printf("expected result: output = [1,1,2,1,1]\n");
    {
        // vector<vector<int>> aa{{1,2,3},{1},{3,4,5,6}};
        // vector<NestedInteger> nestedList{{1,1},2,{1,1}};

        // vector<Node*> children1;
        // vector<Node*> children2;

        // Node *TN5 = new Node(5);
        // Node *TN6 = new Node(6);
        // children1.push_back(TN5);
        // children1.push_back(TN6);
        // Node *TN3 = new Node(3, children1);
        // Node *TN2 = new Node(2);
        // Node *TN4 = new Node(4);
        // children2.push_back(TN3);
        // children2.push_back(TN2);
        // children2.push_back(TN4);
        // Node *TN1 = new Node(1, children2);
        // Node *root = TN1;
        
        // Solution solution;
        // auto res = solution.preorder(root);
        // printf("res size is %d\n", res.size());
        // for (size_t i = 0; i < res.size(); i++)
        // {
        //     printf("%d,", res[i]);
        // }
        // printf("\n");
        
        // delete TN5;
        // delete TN6;
        // delete TN3;
        // delete TN2;
        // delete TN4;
        // delete TN1;
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
