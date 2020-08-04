// 动态规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<vector>
#include<math.h>
using namespace std;
int max3(const int& a, const int& b, const int& c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b > c) {
			return b;
		}
		else {
			return c;
		}
	}
}

// 1. 实现整数拆分函数
int integerBreak(int n) {
	// 定义一个数组dp ,dp[i] 表示拆分i所得到的最大乘积
	std::vector<int> dp(n + 1, 1);
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		// 对于每个dp[i]的值
		for (int j = 1; j < i; j++) {
			// 把 i 划分成 j 和 i-j 然后和 j * dp[i-j], 比较
			dp[i] = max3(dp[i], j * (i - j), j * dp[i - j]);
		}
	}
	//for (auto item : dp) {
	//	std::cout << "i的整数划分："<<item<< std::endl;
	//}
	return dp[n];
}

// 2. 分割等和子集  给定一个只包含正整数的非空数组。
//是否可以将这个数组分割成两个子集，使得两个子集的元素和相等
// 背包问题的变体 容量为sum/2 的时候，是否可以恰好填满背包
bool canPartition(vector<int>& nums) {
	int n = nums.size();
	int sum = 0;
	for (auto num : nums) {
		sum += num;
	}

	if (sum % 2 != 0) return false;
	sum /= 2;
	vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));
	// base case  当背包容量为0的时候，一定可以填满
	for (int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			// 如果 当前背包容量小于nums[i-1]
			if (j < nums[i - 1]) {
				dp[i][j] = dp[i - 1][j]; // 当前物品不能放入背包
			}
			else {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
			}
		}
	}
	for (auto items : dp) {
		for (auto item : items) {
			cout << item << " ";
		}
		cout << endl;
	}
	return dp[n][sum];


}


int main()
{
	// 1. 整数划分
	//cout << integerBreak(10) << endl;
	// 2. 分割等和子集
	vector<int> num = { 1, 5, 11, 5 };
	cout << canPartition(num) << endl;
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
