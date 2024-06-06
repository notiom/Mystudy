#include "sort.h"

using namespace std;

void sortSelect(std::vector<int> &nums)
{
    int n = nums.size();
    for(int i = 0;i < n - 1;i++)
    {
        int min = i;
        for(int j = i + 1;j < n;j++)
        {
            if(nums[j] < nums[min])
            {
                min = j;
            }
        }
        swap(nums[i],nums[min]);
    }
}