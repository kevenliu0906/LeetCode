// ConsoleApp_Design_Circular_Deque.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> circular_deque_vec;
    int max_circular_deque_size = 0;

public:
    MyCircularDeque(int k) {
        max_circular_deque_size = k;
    }
    
    bool insertFront(int value) {
        if (circular_deque_vec.size() >= max_circular_deque_size) return false;
        
        circular_deque_vec.insert(circular_deque_vec.begin(), value);
        return true;
    }
    
    bool insertLast(int value) {
        if (circular_deque_vec.size() >= max_circular_deque_size) return false;
        
        circular_deque_vec.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (circular_deque_vec.empty()) return false;
        
        circular_deque_vec.erase(circular_deque_vec.begin());
        return true;
    }
    
    bool deleteLast() {
        if (circular_deque_vec.empty()) return false;
        
        circular_deque_vec.erase(circular_deque_vec.end()-1);
        return true;
    }
    
    int getFront() {
        if (circular_deque_vec.empty()) return -1;
        
        return circular_deque_vec[0];
    }
    
    int getRear() {
        if (circular_deque_vec.empty()) return -1;
        
        return circular_deque_vec[circular_deque_vec.size() - 1];
    }
    
    bool isEmpty() {
        return circular_deque_vec.empty();
    }
    
    bool isFull() {
        if (circular_deque_vec.size() == max_circular_deque_size) return true;
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{
    std::cout << "Hello LeetCode - Design Circular Deque, DataStructure(LinkedList)!\n";
    cout << "https://leetcode.com/problems/design-circular-deque/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"MyCircularDeque\",\"insertLast\",\"insertLast\",\"insertFront\",\"insertFront\",\"getRear\",\"isFull\",\"deleteLast\",\"insertFront\",\"getFront\"]\n");
    printf("       [[3],[1],[2],[3],[4],[],[],[],[4],[]]\n");
    printf("expected result: output = [null, true, true, true, false, 2, true, true, true, 4]\n");
    {
        
        MyCircularDeque *myCircularDeque = new MyCircularDeque(3);

        auto res_fg = myCircularDeque->insertLast(1); // return True
        printf("after insertLast(1), return %d\n", res_fg);

        res_fg = myCircularDeque->insertLast(2); // return True
        printf("after insertLast(2), return %d\n", res_fg);

        res_fg = myCircularDeque->insertFront(3); // return True
        printf("after insertFront(3), return %d\n", res_fg);

        res_fg = myCircularDeque->insertFront(4); // return False, the queue is full
        printf("after insertFront(4), return %d\n", res_fg);

        auto res_int =  myCircularDeque->getRear();     // return 2
        printf("after getRear, return %d\n", res_int);

        res_fg = myCircularDeque->isFull();   // return True
        printf("after isFull, return %d\n", res_fg);

        res_fg = myCircularDeque->deleteLast();  // return True
        printf("after deleteLast, return %d\n", res_fg);

        res_fg = myCircularDeque->insertFront(4); // return True
        printf("after insertFront, return %d\n", res_fg);
        
        res_int = myCircularDeque->getFront();     // return 4
        printf("after getFront, return %d\n", res_int);

        delete myCircularDeque;
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
