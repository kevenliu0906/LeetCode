// ConsoleApplication_Min_Stack.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

// solution 0 (best, reference others, https://hackmd.io/@Zero871015/LeetCode-155)
//             <Sol1.> if the min function is created on getMin() function, 
//                     there will be always loop-check the min-value when calling getMin() --> it will cause much time
//             <Sol2.> because it's not always the min-value is on top when poping         --> it would be better solution
class MinStack {
public:

    vector<int> nums_vec;
    int min_num;

    MinStack() {
        min_num = INT_MAX;
    }
    
    void push(int val) {
        nums_vec.push_back(val);
        min_num = min(val, min_num);
    }
    
    void pop() {
        auto topValue = top();
        if (min_num == topValue)
        {
            // represent the top value is the minimum value
            // so need to obtain the minimum again from nums[0]~nums[topIndex-1]
            min_num = INT_MAX;
            for (size_t i = 0; i < nums_vec.size()-1; i++)
            {
                min_num = min(nums_vec[i], min_num);
            }
        }else{
            ;
        }
        nums_vec.pop_back();
    }
    
    int top() {
        return nums_vec[nums_vec.size()-1];
    }
    
    int getMin() {
        return min_num;
    }
};

// // solution 1 (keven)
// class MinStack {
// public:

//     int totalcount;
//     vector<int> num_order;

//     MinStack() {
//         totalcount = 0;
//     }
    
//     void push(int val) {
//         totalcount++;
//         num_order.push_back(val);
//     }
    
//     void pop() {
//         num_order.pop_back();
//     }
    
//     int top() {
//         return num_order[num_order.size()-1];
//     }
    
//     int getMin() {
//         auto temp_num_vec = num_order;
//         sort(temp_num_vec.begin(), temp_num_vec.end());
//         return temp_num_vec[0]; 
        
//         // will cause error (Time Limit Exceeded)
//         // set<int> num_order_set(num_order.begin(), num_order.end());
//         // return *(num_order_set.begin());
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    std::cout << "Hello LeetCode - Min Stack, DataStructure(Stack)!\n";
    cout << "https://leetcode.com/problems/min-stack/" << endl << endl;
    // cout << "solution: https://hackmd.io/@Zero871015/LeetCode-155" << endl;    

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: Input = [\"MinStack\",\"push\",\"push\",\"push\",\"getMin\",\"pop\",\"top\",\"getMin\"] [[],[-2],[0],[-3],[],[],[],[]]\n");
    printf("expected result: output = [null,null,null,null,-3,null,0,-2]\n");
    {
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        auto result = minStack.getMin(); // return -3
        printf("after getMin:%d\n", result);
        minStack.pop();
        result = minStack.top();    // return 0
        printf("after top:%d\n", result);
        result = minStack.getMin(); // return -2
        printf("after getMin:%d\n", result);
        
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
