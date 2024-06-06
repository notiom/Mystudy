#include "sort.h"

using namespace std;

int partition(std::vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];  // 选择最右边的元素作为枢轴
    int i = low - 1;        // 较小元素的索引

    for (int j = low; j < high; j++) 
    {
        // 如果当前元素小于或等于枢轴
        if (arr[j] <= pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);  // 交换 arr[i] 和 arr[j]
        }
    }
    std::swap(arr[i + 1], arr[high]);  // 交换 arr[i+1] 和 arr[high] (或 pivot)
    return i + 1; //返回枢轴的位置
}

// 快速排序的主函数
void quickSort(std::vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);  // 获取分区索引

        // 分别对分区进行排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}