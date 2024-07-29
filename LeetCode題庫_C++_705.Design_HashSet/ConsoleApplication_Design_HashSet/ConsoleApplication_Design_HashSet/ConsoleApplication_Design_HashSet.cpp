// ConsoleApplication_Design_HashSet.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
public:

    // solution 1 (keven, best)
    vector<bool> key_num_vec;
    MyHashSet() {
        key_num_vec.resize(1000001, false);  // because key range is 0 <= key <= 10^6
    }

    void add(int key) {
        key_num_vec[key] = true;
    }

    void remove(int key) {
        key_num_vec[key] = false;
    }

    bool contains(int key) {
        return key_num_vec[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    std::cout << "Hello LeetCode - Design Hash Set, DataStructure()!\n";
    cout << "https://leetcode.com/problems/design-hashset/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: input = [\"MyHashSet\",\"add\",\"add\",\"contains\",\"contains\",\"add\",\"contains\",\"remove\",\"contains\"], [[],[1],[2],[1],[3],[2],[2],[2],[2]]\n");
    printf("expected result: output = false\n");
    {
        MyHashSet* obj = new MyHashSet();
        int key = 3;

        obj->add(key);
        obj->remove(key);
        bool param_3 = obj->contains(key);
        printf("contain key\n");
        printf("param_3(%d), true:%d, false:%d\n", param_3, true, false);
        
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
