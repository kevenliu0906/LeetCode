// Console_Implement_Queue_by_Stacks.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>

using namespace std;

// solution 1 (keven, best, using two stack to simult queue)

class MyQueue {
public:
    stack<int> store_num_stack;
    stack<int> simult_queue_num_stack;
    MyQueue() {
        
    }
    
    void push(int x) {
        store_num_stack.push(x);
    }
    
    int pop() {
        auto pop_value = peek();
        
        // reset the element
        simult_queue_num_stack.pop();
        stack<int> tmp_clear;
        store_num_stack.swap(tmp_clear);    // clear all element of num_stack
        tmp_clear = simult_queue_num_stack;

        while (tmp_clear.size())
        {
            // restore num_stack from simult queue_num stack
            store_num_stack.push(tmp_clear.top());
            tmp_clear.pop();
        }

        return pop_value;
    }
    
    int peek() {
        // pre-process
        stack<int> tmp;
        simult_queue_num_stack.swap(tmp);   // clear all element of simult_queue stack
        tmp = store_num_stack;
        
        while (tmp.size())
        {
            // restore simult queue_num stack from num_stack
            simult_queue_num_stack.push(tmp.top());
            tmp.pop();
        }
        //

        auto peek_value = simult_queue_num_stack.top();
        return peek_value;
    }
    
    bool empty() {
        bool empty_fg = store_num_stack.size()? false:true;
        return empty_fg;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
    std::cout << "Hello LeetCode - Implement Queue by Stacks, DataStructure(stack, queue)!\n";
    cout << "https://leetcode.com/problems/implement-queue-using-stacks" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"MyQueue\", \"push\", \"push\", \"peek\", \"pop\", \"empty\"], [[], [1], [2], [], [], []]\n");
    printf("expected result: output = [null, null, null, 1, 1, false]\n");
    {
        int x = 1;
        MyQueue* obj = new MyQueue();
        obj->push(x);
        x = 2;
        obj->push(x);

        auto peek = obj->peek();
        printf("peek:%d\n", peek);
        auto pop = obj->pop();
        printf("pop:%d\n", pop);
        auto empty = obj->empty();
        if (empty){
            printf("my queue is empty!\n");
        }else{
            printf("my queue is NOT empty!\n");
        }
        
        delete obj;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: [\"MyQueue\",\"push\",\"pop\",\"empty\"], [[], [1], [], []]\n");
    printf("expected result: output = [null, null, 1, true]\n");
    {
        int x = 1;
        MyQueue* obj = new MyQueue();
        obj->push(x);

        auto pop = obj->pop();
        printf("pop:%d\n", pop);
        auto empty = obj->empty();
        if (empty){
            printf("my queue is empty!\n");
        }else{
            printf("my queue is NOT empty!\n");
        }
        
        delete obj;
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
