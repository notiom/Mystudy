//1.自己的解，使用冒泡排序的思想，如果右侧是0，就和他交换

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        //思路等同于冒泡排序
        for(int i = 0;i < n;i++)
        {   
            if(nums[i] == 0)
            {
                //遍历后面的元素是否为0
                for(int j = i + 1;j < n;j++)
                {
                    if(nums[j] != 0)
                    {
                        //交换位置
                        nums[i] = nums[i] + nums[j];
                        nums[j] = nums[i] - nums[j];
                        nums[i] = nums[i] - nums[j];
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
};

//2.官方题解(双指针，学习快速排序)
// 双指针思想，即一个指针用来记录非零元素，一个指针用来将后面所有的元素赋值给前面。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 第一次遍历的时候，j指针记录非0的个数，只要是非0的统统都赋给nums[j]	
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j += 1;
            }
        }
        // 第二次遍历把末尾的元素都赋为0即可
        while(j < nums.size()){
            nums[j] = 0;
            j += 1;
        }
    }
};
