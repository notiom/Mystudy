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
    std::vector<int> res = {64,25,12,22,11};;
    cout << "insert---------------" <<endl;
    printNums(res);
    sortInsert(res);
    printNums(res);
    std::vector<int> nums = {64,25,12,22,11};;
    cout << "select---------------" <<endl;
    printNums(nums);
    sortSelect(nums);
    printNums(nums);
    std::vector<int> nums2 = {64,25,12,22,11};;
    cout << "bubble---------------" <<endl;
    printNums(nums2);
    sortBubble(nums2);
    printNums(nums2);
    std::vector<int> nums3 = {64,25,12,22,11};
    cout << "quick---------------" <<endl;
    printNums(nums3);
    quickSort(nums3,0,nums3.size() - 1);
    printNums(nums3);

}