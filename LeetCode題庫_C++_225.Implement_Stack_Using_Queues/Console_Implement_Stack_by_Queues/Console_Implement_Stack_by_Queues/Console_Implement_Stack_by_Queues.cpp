// Console_Implement_Stack_by_Queues.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    
    queue<int> num_queue;

    MyStack() {
        
    }
    
    void push(int x) {
        num_queue.push(x);
    }
    
    int pop() {
        
        int value = top();
        // need use tmp queue to do "top-value erase"
        queue<int> ignore_last_queue;

        while (num_queue.size() > 1)
        {
            // store all elements from num_queue without the last-one
            ignore_last_queue.push(num_queue.front());

            num_queue.pop();
        }

        // pop the last-one element in the front, so the origin num_queue is empty
        num_queue.pop();
        
        // swap the element from tmp queue
        num_queue.swap(ignore_last_queue);

        return value;
    }
    
    int top() {
        return num_queue.back();
    }
    
    bool empty() {
        return num_queue.empty();
    }
};

int main()
{
    std::cout << "Hello LeetCode - Implement Stack using Queues, DataStructure(stack, queue)!\n";
    cout << "https://leetcode.com/problems/implement-stack-using-queues/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"MyStack\", \"push\", \"push\", \"top\", \"pop\", \"empty\"], [[], [1], [2], [], [], []]\n");
    printf("expected result: output = [null, null, null, 2, 2, false]\n");
    printf("Explanation: MyStack myStack = new MyStack(); myStack.push(1); myStack.push(2); myStack.top(); // return 2 myStack.pop(); // return 2 myStack.empty(); // return False\n");
    {
        MyStack myStack;

        myStack.push(1);
        myStack.push(2);
        auto top_value = myStack.top();
        printf("top_value:%d\n", top_value);

        auto pop_value = myStack.pop();
        printf("pop_value:%d\n", pop_value);

        auto empty_fg = myStack.empty();
        printf("empty_fg:%d, true(%d), false(%d)\n", empty_fg, true, false);
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
