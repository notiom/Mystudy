#include<iostream>
#include<vector>
#include<cmath>
#include<list>
using namespace std;

class Solution
{
private:
	vector<int> nums;
	int n;
public:
	Solution(vector<int>& _nums) : nums(_nums) 
	{
		this->n = nums.size();
	}
	// 9 8 7 6 5 4 3 2 1 
	// 插入排序
	void InsertSort()
	{
		PrintResult();
		for (int i = 1; i < n; i++)
		{
			int current_value = nums[i];
			int position = i;
			/// 当当前位置大于0并且前一个元素大于当前本元素
			// 移位
			while (position > 0 && nums[position - 1] > current_value)
			{
				nums[position] = nums[position - 1];
				position--;
			}
			// 遍历完成后插值
			nums[position] = current_value;
		}
		PrintResult();
	}

	// 冒泡排序
	void BubbleSort()
	{
		// 外循环是次数
		PrintResult();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (nums[j] > nums[j + 1])
				{
					// 将最大的元素冒泡上去
					swap(nums[j], nums[j + 1]);
				}
			}
		}
		PrintResult();
	}

	// 选择排序
	void SelectionSort()
	{
		PrintResult();
		for (int i = 0; i < n; i++)
		{
			int min_idx = i;
			for (int j = i + 1; j < n; j++)
			{
				if (nums[min_idx] > nums[j])
				{
					min_idx = j;
				}
			}
			// 找到最小位置的索引
			swap(nums[min_idx], nums[i]);
		}
		PrintResult();
	}
	// 快速排序
	
	void QuickSort()
	{
		PrintResult();
		QuickSortHelper(0, n - 1);
		PrintResult();
	}
	// 折半插入排序

	void BinaryInsertSort()
	{
		PrintResult();
		for (int i = 1; i < n; i++)
		{
			// 查找插入位置,使用二分查找
			if (nums[i] >= nums[i - 1])
			{
				// 不用插
				continue;
			}

			int idx = BinaryFind(0, i - 1, nums[i]);

			int current_value = nums[i];
			for (int j = i; j > idx; j--)
			{
				//向后移位
				nums[j] = nums[j - 1];
			}
			nums[idx] = current_value;
		}
		PrintResult();
	}


	// 希尔排序
	// 平均时间复杂度o(n ^ 1.3)
	void ShellSort()
	{
		PrintResult();
		int gap = n / 2;

		while (gap > 0)
		{
			// 外层循环时组别
			for (int i = gap; i < n; i++)
			{
				int current_value = nums[i];
				int position = i;

				while (position >= gap && nums[position - gap] > current_value)
				{
					nums[position] = nums[position - gap];
					position -= gap;
				}

				nums[position] = current_value;
			}

			// 缩小间隔
			gap /= 2;
		}
		PrintResult();
	}
	// 堆与堆排序
	// 完全二叉树 -> (大根堆)任一节点 >= 其左右孩子
	void HeadSort()
	{
		PrintResult();
		HeadSortHelper(n);
		PrintResult();
	}
	// 归并排序
	// 1.循环方式 自顶向下

	void MergeSort()
	{
		PrintResult();
		// 逐步增加子数组大小
		for (int size = 1; size < n; size *= 2)
		{
			// 对可能的子数组进行合并
			for (int left = 0; left < n - size; left += 2 * size)
			{
				int mid = min(left + size - 1, n - 1);
				int right = min(left + 2 * size - 1, n - 1);
				Merge(left, right, mid);
			}
		}
		PrintResult();
	}
	// 2.递归方式 自底向上

	void InMergeSort()
	{
		PrintResult();
		InMergeSortHelper(0, n - 1);
		PrintResult();
	}

	//基数排序

	void RadixSort()
	{
		PrintResult();
		// 找到数组中的最大值看有多少位
		int maxVal = *max_element(nums.begin(), nums.end());

		int exp = 1; // 从个位开始

		while (maxVal / exp > 0)
		{
			// 位数还没有被排序完
			// 创建10个桶
			vector<list<int>> buckets(10);

			// 将元素根据当前数字依次分配到不同的桶
			for (int num : nums)
			{
				// 取当前轮对应的位数
				int digit = (num / exp) % 10;
				buckets[digit].push_back(num);
			}
			nums.clear();

			for (const auto& bucket : buckets)
			{
				for (int num : bucket)
				{
					nums.push_back(num);
				}
			}

			exp *= 10; // 处理下一位
		}
		PrintResult();
	}
		
private:
	void PrintResult()
	{
		for (const int& num : nums)
		{
			cout << num << " ";
		}
		cout << endl;
	}

	// 快排
	void QuickSortHelper(int start, int end)
	{
		if (start < end)
		{
			int pivot = Partition(start, end);
			QuickSortHelper(start, pivot - 1);
			QuickSortHelper(pivot + 1, end);
		}
	}

	int Partition(int start, int end)
	{
		int height = nums[end];
		int i = start - 1;

		for (int j = start; j < end; j++)
		{
			if (nums[j] < height)
			{
				i++;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[end]);
		return i + 1;
	}

	// 折半插入的二分查找
	int BinaryFind(int start,int end,int target)
	{
		// 1 1 1 2 3 4 5 
		while (start <= end)
		{
			int pivot = (start + end) >> 1;
			if (nums[pivot] <= target)
			{
				// 在右边
				start = pivot + 1;
			}
			else
			{
				// 等于也可以减一,但是我认为不应该改变元素本身的相对位置,所以需要找到最右边的这个元素索引
				end = pivot - 1;
			}
		}
		return start;
	}

	// 堆排辅助函数
	void HeadSortHelper(int n)
	{
		for (int i = n / 2 - 1;i >= 0;i--)
		{
			Heapify(n, i);
		}

		// 将元素逐渐取出并堆化
		// 到最后一个元素时就没必要构建最大堆了
		for (int i = n - 1; i >= 1; i--)
		{
			swap(nums[0], nums[i]); // 将堆顶元素换到堆底
			Heapify(i, 0);
		}
	}

	// 构建堆
	// 该函数只能以当前节点以下的构建堆
	void Heapify(int n, int root)
	{
		int largest = root;
		int left = 2 * root + 1;
		int right = 2 * root + 2;

		if (left < n && nums[left] > nums[largest])
		{
			largest = left;
		}

		if (right < n && nums[right] > nums[largest])
		{
			largest = right;
		}

		// 如果largest不是根节点
		if (largest != root)
		{
			swap(nums[root], nums[largest]);
			Heapify(n, largest);
		}
	}

	// 归并操作
	void Merge(int left,int right,int mid)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;

		// 创建临时数组
		// 1 2 3
		vector<int> leftnums(0, n1);
		leftnums.assign(nums.begin() + left, nums.begin() + mid + 1);
		vector<int> rightnums(0, n2);
		rightnums.assign(nums.begin() + mid + 1, nums.begin() + right + 1);

		// 合并两个数组
		int i = 0, j = 0, k = left;

		while (i < n1 && j < n2)
		{
			if (leftnums[i] <= rightnums[j])
			{
				nums[k++] = leftnums[i++];
			}

			else
			{
				nums[k++] = rightnums[j++];
			}
		}

		// 复制左子树组的元素
		while (i < n1)
		{
			nums[k++] = leftnums[i++];
		}

		while (j < n2)
		{
			nums[k++] = rightnums[j++];
		}
	}

	void InMergeSortHelper(int left,int right)
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			InMergeSortHelper(left, mid);
			InMergeSortHelper(mid + 1, right);
			Merge(left, right, mid);
		}
	}
};

int main()
{
	vector<int> nums = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	Solution* s = new Solution(nums);
	s->RadixSort();
	return 0;
}
