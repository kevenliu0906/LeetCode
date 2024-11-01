// ConsoleApplication_Design_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList {
private:
    vector<int> stock;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index >= stock.size())
        {
            return -1;
        }
        return stock[index];
    }
    
    void addAtHead(int val) {
        stock.insert(stock.begin(), val);
    }
    
    void addAtTail(int val) {
        stock.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > stock.size())
        {
            return;
        }
        
        if (index == stock.size())
        {
            addAtTail(val);
            return;
        }
        
        stock.insert(stock.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if (index >= stock.size()){
            return;
        }
        
        stock.erase(stock.begin() + index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    std::cout << "Hello LeetCode - Design LinkedList - DataStructure(Linked List)!\n";

    
    // Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    int index = 1;
    
    int param_1 = obj->get(index);
    
    int val = 1;
    obj->addAtHead(val);

    val = 3;
    obj->addAtTail(val);

    index = 1;
    val = 2;
    obj->addAtIndex(index,val); // linked list becomes 1->2->3


    index = 1;
    obj->get(index);    // return 2


    index = 1;
    obj->deleteAtIndex(index);   // now linked list is 1->3

    index = 1;
    obj->get(index);     // return 3
     
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
