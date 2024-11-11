// ConsoleApp_Design_Curcular_Queue.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> circular_que_vec;
    int max_circular_que_size = 0;
public:
    MyCircularQueue(int k) {
        max_circular_que_size = k;
    }
    
    bool enQueue(int value) {
        if (circular_que_vec.size() >= max_circular_que_size) return false;

        circular_que_vec.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if (circular_que_vec.empty()) return false;
        
        circular_que_vec.erase(circular_que_vec.begin());
        return true;
    }
    
    int Front() {
        if (circular_que_vec.empty()) return -1;
        
        return circular_que_vec[0];
    }
    
    int Rear() {
        if (circular_que_vec.empty()) return -1;
        
        return circular_que_vec[circular_que_vec.size()-1];
    }
    
    bool isEmpty() {
        if (circular_que_vec.size()) return false;
        
        return true;
    }
    
    bool isFull() {
        if (circular_que_vec.size() == max_circular_que_size) return true;
        
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    std::cout << "Hello LeetCode - Design Curcular Queue, DataStructure(LinkedList)!\n";
    cout << "https://leetcode.com/problems/design-circular-queue/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"MyCircularQueue\",\"enQueue\",\"enQueue\",\"enQueue\",\"enQueue\",\"Rear\",\"isFull\",\"deQueue\",\"enQueue\",\"Rear\"]\n");
    printf("       [[3], [1], [2], [3], [4], [], [], [], [4], []]\n");
    printf("expected result: output = [null, true, true, true, false, 3, true, true, true, 4]\n");
    {
        
        MyCircularQueue *myCircularQueue = new MyCircularQueue(3);

        auto res_fg = myCircularQueue->enQueue(1); // return True
        printf("after enQueue(1), return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(2); // return True
        printf("after enQueue(2), return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(3); // return True
        printf("after enQueue(3), return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(4); // return False
        printf("after enQueue(4), return %d\n", res_fg);

        auto res_int =  myCircularQueue->Rear();     // return 3
        printf("after rear, return %d\n", res_int);

        res_fg = myCircularQueue->isFull();   // return True
        printf("after isFull, return %d\n", res_fg);

        res_fg = myCircularQueue->deQueue();  // return True
        printf("after deQueue, return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(4); // return True
        printf("after enQueue, return %d\n", res_fg);
        
        res_int = myCircularQueue->Rear();     // return 4
        printf("after rear, return %d\n", res_int);

        delete myCircularQueue;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: [\"MyCircularQueue\",\"enQueue\",\"enQueue\",\"enQueue\",\"enQueue\",\"deQueue\",\"deQueue\",\"isEmpty\",\"isEmpty\",\"Rear\",\"Rear\",\"deQueue\"]\n");
    printf("       [[8],[3],[9],[5],[0],[],[],[],[],[],[],[]]\n");
    printf("expected result: output = [null,true,true,true,true,true,true,false,false,0,0,true]\n");
    {
        
        MyCircularQueue *myCircularQueue = new MyCircularQueue(8);

        auto res_fg = myCircularQueue->enQueue(3); // return True
        printf("after enQueue(3), return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(9); // return True
        printf("after enQueue(9), return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(5); // return True
        printf("after enQueue(5), return %d\n", res_fg);

        res_fg = myCircularQueue->enQueue(0); // return False
        printf("after enQueue(0), return %d\n", res_fg);

        res_fg = myCircularQueue->deQueue();  // return True
        printf("after deQueue, return %d\n", res_fg);

        res_fg = myCircularQueue->deQueue();  // return True
        printf("after deQueue, return %d\n", res_fg);

        res_fg = myCircularQueue->isEmpty();  // return false
        printf("after isEmpty, return %d\n", res_fg);

        res_fg = myCircularQueue->isEmpty();  // return false
        printf("after isEmpty, return %d\n", res_fg);

        auto res_int =  myCircularQueue->Rear();     // return 0
        printf("after rear, return %d\n", res_int);

        res_int =  myCircularQueue->Rear();     // return 0
        printf("after rear, return %d\n", res_int);

        res_fg = myCircularQueue->deQueue();  // return True
        printf("after deQueue, return %d\n", res_fg);

        delete myCircularQueue;
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
