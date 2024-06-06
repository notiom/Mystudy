#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;

void printNums(vector<int> &nums)
{
    cout << "[";
    for(auto num : nums)
    {
        cout << num << ",";
    }
    cout << "]" << endl;
}
int main()
{
    std::vector<int> res;
    res.push_back(64);
    res.push_back(25);
    res.push_back(12);
    res.push_back(22);
    res.push_back(11);
    cout << "insert---------------" <<endl;
    printNums(res);
    sortInsert(res);
    printNums(res);
    std::vector<int> nums;
    nums.push_back(64);
    nums.push_back(25);
    nums.push_back(12);
    nums.push_back(22);
    nums.push_back(11);
    cout << "select---------------" <<endl;
    printNums(nums);
    sortSelect(nums);
    printNums(nums);
    std::vector<int> nums2;
    nums2.push_back(64);
    nums2.push_back(25);
    nums2.push_back(12);
    nums2.push_back(22);
    nums2.push_back(11);
    cout << "bubble---------------" <<endl;
    printNums(nums2);
    sortBubble(nums2);
    printNums(nums2);
    std::vector<int> nums3;
    nums3.push_back(64);
    nums3.push_back(25);
    nums3.push_back(12);
    nums3.push_back(22);
    nums3.push_back(11);
    cout << "quick---------------" <<endl;
    printNums(nums3);
    quickSort(nums3,0,nums3.size() - 1);
    printNums(nums3);

}