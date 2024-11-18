// Console_Product_the_Last_K_Numbers.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
private:
    // vector<int> num_vec;

public:
    vector<int> num_vec;
    vector<int> num_product_vec{1};
    ProductOfNumbers() {
        num_vec.clear();
    }
    
    void add(int num) {
        // solution 0 (kevenm refer others, best performance)
        {
            auto cur_product = num_product_vec.back();
            if (cur_product == 0){
                num_product_vec = {1,num};   // reset to default because the last product is zero
            }else{
                num_product_vec.push_back(cur_product * num);
            }
            return;
        }

        // solution 1 (keven, force directly)
        {
            num_vec.push_back(num);
            return;
        }
    }
    
    int getProduct(int k) {
        // solution 0 (keven, refer others, best performance)
        {
            int cur_pro_size = num_product_vec.size();
            if (cur_pro_size - 1 - k < 0)   return 0;    // cross-over product 0, so return 0
            
            return num_product_vec[cur_pro_size - 1] / num_product_vec[cur_pro_size - 1 - k];
        }

        // solution 1 (keven, force directly)
        {
            int res = 1;
            int idx = 0;
            while(idx<k){
                res *= num_vec[num_vec.size()-1-idx];
                idx++;
            }
            return res;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

void dbg_nums(vector<int> &nums){
    printf("dbg_nums >>>>> \n");
    for (size_t i = 0; i < nums.size(); i++)
    {
        printf("%d,", nums[i]);
    }
    printf("\n");
    
}

int main()
{
    std::cout << "Hello LeetCode - Product of the Last K Numbers!\n";
    cout << "https://leetcode.com/problems/product-of-the-last-k-numbers/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"ProductOfNumbers\",\"add\",\"add\",\"add\",\"add\",\"add\",\"getProduct\",\"getProduct\",\"getProduct\",\"add\",\"getProduct\"]\n");
    printf("       [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]\n");
    printf("expected result: output = [null,null,null,null,null,null,20,40,0,null,32]\n");
    {
        
        ProductOfNumbers *productOfNumbers = new ProductOfNumbers();
        productOfNumbers->add(3);        // [3]
        dbg_nums(productOfNumbers->num_vec);

        productOfNumbers->add(0);        // [3,0]
        dbg_nums(productOfNumbers->num_vec);

        productOfNumbers->add(2);        // [3,0,2]
        dbg_nums(productOfNumbers->num_vec);

        productOfNumbers->add(5);        // [3,0,2,5]
        dbg_nums(productOfNumbers->num_vec);

        productOfNumbers->add(4);        // [3,0,2,5,4]
        dbg_nums(productOfNumbers->num_vec);

        auto res = productOfNumbers->getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
        printf("after get Product(2), res:%d, expect:20\n", res);

        res = productOfNumbers->getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
        printf("after get Product(3), res:%d, expect:40\n", res);

        res = productOfNumbers->getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
        printf("after get Product(4), res:%d, expect:0\n", res);
        
        productOfNumbers->add(8);        // [3,0,2,5,4,8]
        dbg_nums(productOfNumbers->num_vec);
        
        res = productOfNumbers->getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
        printf("after get Product(2), res:%d, expect:32\n", res);
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
