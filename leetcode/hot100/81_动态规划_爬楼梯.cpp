// 1.我自己的解
// 通过递归调用，会超出时间限制 
class Solution 
{
public:
    int climbStairs(int n) 
    {
        // 第一思路:通过递归计算爬到n阶的方法
        // 只需要计算爬到n - 1阶的方法和n - 2阶的方法
        // 然后将两者相加得到n阶的方法
        if (n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// 结论：超时
// 总结：因为在每次递归的时候都重复的计算以前已经计算过的结果

//2. 我自己的改进版本
// 从前往后计算，将前面每次计算后的结果都保存下来，之后可以直接相加

class Solution 
{
public:
    int climbStairs(int n) 
    {
        // 第二思路:通过两个变量保存之前计算的值
        if(n <= 2) return n;
        int left = 1, right = 2; //保存了第0个位置和第1个位置的值
        for(int i = 3;i < n;i++)
        {
            if(i%2 != 0)
            {
                // 此时应该只更新奇数个位置
                left = left + right;
            }
            else
            {
                // 此时更新偶数个位置
                right = left + right;
            }
        }
        return left + right;
    }
};
// 结论:通过 时间复杂度o(n) 空间复杂度o(1).
// 需要区别当前遍历的位置是奇数还是偶数，因为每次只更新一个位置即可

// 3.官方题解改进动态规划.
// 取消了if判断是奇数还是偶数，每次都更新左边的块
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};
// 结论:通过

//4.递推公式
// x^2 = x + 1
// 任何线性关系式都可以通过递推公式求解
// f(n)=c1 * x1^n + c2 * x2^n
// f(1) = 1, f(2) = 2

​class Solution 
{
public:
    int climbStairs(int n) 
    {
        double sqrt5 = sqrt(5);
        // 注意该数可以取到n = 0，所以默认索引是0开始
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }
};
// 时间复杂度 和空间复杂度都为o(1)

// 5.矩阵快速幂
typedef vector<vector<double>> Matrix;

// 矩阵乘法
Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// 计算对角矩阵 D 的 n 次方
Matrix diagonalPower(Matrix &D, int n) {
    Matrix res(2, vector<double>(2, 0));
    for (int i = 0; i < 2; ++i) {
        res[i][i] = pow(D[i][i], n);
    }
    return res;
}

class Solution {
public:
    int climbStairs(int n) {
        // 定义矩阵 P
        Matrix P = {
            { (1 + sqrt(5)) / 2, (1 - sqrt(5)) / 2 },
            { 1, 1 }
        };

        // 定义对角矩阵 D
        Matrix D = {
            { (1 + sqrt(5)) / 2, 0 },
            { 0, (1 - sqrt(5)) / 2 }
        };

        // 计算 P 的逆矩阵 P^-1
        Matrix P_inv = {
            { 1 / sqrt(5), -(1 - sqrt(5)) / (2 * sqrt(5)) },
            { -1 / sqrt(5), (1 + sqrt(5)) / (2 * sqrt(5)) }
        };

        // 计算对角矩阵 D 的 n 次方
        Matrix D_power = diagonalPower(D, n);

        // 计算结果矩阵 A^n = P * D^n * P^-1
        Matrix temp = multiply(P, D_power);
        Matrix result = multiply(temp, P_inv);

        // 返回结果矩阵中的第一个元素作为结果
        return (int)round(result[0][0]);
    }
};
// 了解方法即可，不是一种好方法
