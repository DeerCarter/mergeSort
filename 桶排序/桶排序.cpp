// 桶排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
		给定一个数组，求如果排序之后，相邻两数的最大差值
		要求时间复杂度O(n)， 且不能用非基于比较的排序
*/
/*
		解题思路：
				借助桶排序的思想，有n个数，找出min和max，创建n+1个桶，看每个数在那个桶中，
				然后对于每一个非空桶，计算他的min与上一个非空桶的max的最大插值
*/
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums{22,3,5,66,8,10,38,27,16};
	int max = INT_MIN;
	int min = INT_MAX;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		if (nums[i] < min) {
			min = nums[i];
		}
	}

	// 找到max和min
	// 创建三个数组
	vector<int> hasNums(n + 1, 0);
	vector<int> MAXS(n + 1, 0);
	vector<int> MINS(n + 1, 0);
	// 遍历一遍判断元素应该在那个桶中  每个桶只保存最大值和最小值
	for (int i = 0; i < n; i++) {
		int index = (int)(nums[i] - min) * (n) / (max - min);
		if (hasNums[index] == 0) {
			MAXS[index] = nums[i];
			MINS[index] = nums[i];
			hasNums[index] = true;
		}
		else if (hasNums[index] ==1) {
			MAXS[index] = MAXS[index] > nums[i] ? MAXS[index] : nums[i];
			MINS[index] = MINS[index] < nums[i] ? MINS[index] : nums[i];
		}
	}
	for (auto item : MAXS) {
		cout << item << " ";
	}
	cout << endl;
	for (auto item : MINS) {
		cout << item << " ";
	}
	cout << endl;

	// 遍历桶 找到非空桶和上一个非空桶的最大差值
	int lastMax = MAXS[0];
	int res = 0;
	for (int i = 0; i < n+1; i++) {
		if (hasNums[i]) {
			res = res > MINS[i] - lastMax ? res : MINS[i] - lastMax;
			lastMax = MAXS[i];
		}
	}
	cout << res <<endl;
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
