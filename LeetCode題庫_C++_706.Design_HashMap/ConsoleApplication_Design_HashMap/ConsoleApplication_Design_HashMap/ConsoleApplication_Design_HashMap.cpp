// ConsoleApplication_Design_HashMap.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    // solution 1 (keven, best, using vector to store the key(index) & value(element value) )
    vector<int> hash_map_vec;
    MyHashMap() {
        hash_map_vec.resize(101, -1);    // because key range is 0 <= key <= 10^6
    }
    
    void put(int key, int value) {
        hash_map_vec[key] = value;
    }
    
    int get(int key) {
        return hash_map_vec[key];
    }
    
    void remove(int key) {
        hash_map_vec[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    std::cout << "Hello LeetCode - Design Hash Map, DataStructure(Linked List, Array, Hash Table)!\n";
    cout << "https://leetcode.com/problems/design-hashmap" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"MyHashMap\", \"put\", \"put\", \"get\", \"get\", \"put\", \"get\", \"remove\", \"get\"], [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]\n");
    printf("expected result: output = [null, null, null, 1, -1, null, 1, null, -1]\n");
    {
        int key = 3;
        int value = 10;
        MyHashMap* obj = new MyHashMap();
        obj->put(key,value);
        
        // // debug printf
        // {
        //     printf("------------------------------- after put >>> ------------------------------------\n");
        //     int index = 0;
        //     while ( index < obj->hash_map_vec.size() )
        //     {
        //         if (obj->hash_map_vec[index] != -1)
        //         {
        //             printf("case 1 -> index:%d, value:%d\n", index, obj->hash_map_vec[index]);
        //         }
        //         else{
        //             printf("case 2 -> index:%d, value:%d\n", index, obj->hash_map_vec[index]);
        //         }
                
                
        //         index++;
        //     }
        // }
        
        int param_2 = obj->get(key);
        // debug printf
        {
            printf("----------------------- after get >>> param_2:%d -----------------------------\n", param_2);
            // int index = 0;
            // while ( index < obj->hash_map_vec.size() )
            // {
            //     if (obj->hash_map_vec[index] != -1)
            //     {
            //         printf("case 1 -> index:%d, value:%d\n", index, obj->hash_map_vec[index]);
            //     }
            //     else{
            //         printf("case 2 -> index:%d, value:%d\n", index, obj->hash_map_vec[index]);
            //     }
            //     index++;
            // }
        }

        obj->remove(key);
        // // debug printf
        // {
        //     printf("--------------------- after remove >>> ---------------------------- \n");
        //     int index = 0;
        //     while ( index < obj->hash_map_vec.size() )
        //     {
        //         if (obj->hash_map_vec[index] != -1)
        //         {
        //             printf("case 1 -> index:%d, value:%d\n", index, obj->hash_map_vec[index]);
        //         }
        //         else{
        //             printf("case 2 -> index:%d, value:%d\n", index, obj->hash_map_vec[index]);
        //         }
        //         index++;
        //     }
        // }
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
