// Console_Design_Front_Mid_Back_Que.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class FrontMiddleBackQueue {
private:
    vector<int> front_middle_back_vec;

public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        if (front_middle_back_vec.empty()){
            pushBack(val);
            return;
        }
        
        front_middle_back_vec.insert(front_middle_back_vec.begin(), val);
    }
    
    void pushMiddle(int val) {
        if (front_middle_back_vec.size() == 0 || front_middle_back_vec.size() == 1){
            pushFront(val);
            return;
        }
        
        int mid_idx = front_middle_back_vec.size() / 2;
        auto begin_iter = front_middle_back_vec.begin();

        begin_iter += mid_idx;
        front_middle_back_vec.insert(begin_iter, val);
    }
    
    void pushBack(int val) {
        front_middle_back_vec.push_back(val);
    }
    
    int popFront() {
        if (front_middle_back_vec.empty()) return -1;

        int res = front_middle_back_vec[0];
        front_middle_back_vec.erase(front_middle_back_vec.begin());

        return res;
    }
    
    int popMiddle() {
        
        int cur_vec_size = front_middle_back_vec.size();
        int res = 0;

        if (cur_vec_size == 0) return -1;
        if (cur_vec_size == 1) {
            res = front_middle_back_vec[0];
            front_middle_back_vec.erase(front_middle_back_vec.begin());
            return res;
        }
        
        int mid_idx = 0;
        if (cur_vec_size % 2){
            // cur_vec_size is 3 or 5 or ...
            mid_idx = cur_vec_size / 2;
            
        }else{
            // cur_vec_size is 2 or 4 or ...
            mid_idx = cur_vec_size / 2 - 1;
        }
        
        res = front_middle_back_vec[mid_idx];

        auto mid_iter = front_middle_back_vec.begin();
        while (mid_idx > 0)
        {
            mid_iter++;

            mid_idx--;
        }
        
        front_middle_back_vec.erase(mid_iter);

        return res;
    }
    
    int popBack() {
        if (front_middle_back_vec.empty()) return -1;

        int res = front_middle_back_vec[front_middle_back_vec.size() - 1];
        front_middle_back_vec.erase(front_middle_back_vec.begin() + (front_middle_back_vec.size() - 1));

        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main()
{
    std::cout << "Hello LeetCode - Design Front Middle Back Queue, DataStructure(LinkedList, Queue)!\n";
    cout << "https://leetcode.com/problems/design-front-middle-back-queue/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input = [\"FrontMiddleBackQueue\", \"pushFront\", \"pushBack\", \"pushMiddle\", \"pushMiddle\", \"popFront\", \"popMiddle\", \"popMiddle\", \"popBack\", \"popFront\"]\n");
    printf("        [[], [1], [2], [3], [4], [], [], [], [], []]\n");
    printf("expected result: output = [null, null, null, null, null, 1, 3, 4, 2, -1]\n");
    {
        
        FrontMiddleBackQueue *q = new FrontMiddleBackQueue();
        q->pushFront(1);   // [1]
        q->pushBack(2);    // [1, 2]
        q->pushMiddle(3);  // [1, 3, 2]
        q->pushMiddle(4);  // [1, 4, 3, 2]
        
        printf("popFront() START\n");
        int res = q->popFront();     // return 1 -> [4, 3, 2]
        printf(">>> after popFront(), res:%d\n", res);

        printf("popMiddle() START\n");
        res = q->popMiddle();    // return 3 -> [4, 2]
        printf(">>> after popMiddle(), res:%d\n", res);

        printf("popMiddle() START\n");
        res = q->popMiddle();    // return 4 -> [2]
        printf(">>> after popMiddle(), res:%d\n", res);

        printf("popBack() START\n");
        res = q->popBack();      // return 2 -> []
        printf(">>> after popBack(), res:%d\n", res);

        printf("popFront() START\n");
        res = q->popFront();     // return -1 -> [] (The queue is empty)
        printf(">>> after popFront(), res:%d\n", res);

        delete q;
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
