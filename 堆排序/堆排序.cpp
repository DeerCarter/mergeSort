// 堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
// 堆 一个完全二叉树，最大堆表示父节点大于子节点
// 在一个数组上进行原地堆排序
// 以0开始作为根节点
// 那么第i个节点的左子树的下标是 2*i+1，右子树的下标是 2*i+2, 父亲节点的下标是 i-1/2;
// 第一个非叶子节点的下标是 （count-1）/2
// 

// 先写向下调整的函数 shiftdown(vector<int>& nums, int k,int n);
//  k 表示对下标为k 的元素 执行向下调整的操作
// n 是未排序的数组的长度

void shiftdown(vector<int>& nums, int k, int n) {
	// 有左子树
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		if (j + 1 < n && nums[j + 1] > nums[j]) {
			// 有右子树 并且右子树大于左子树
			j+=1;
		}
		if (nums[k] > nums[j]) {
			break;
		}
		else {
			swap(nums[k], nums[j]);
		}
		k = j;
	}
}
// 进行向下交换 n是堆中数据的个数，k是要进行交换的下标
void shiftdown(vector<int>& nums, int k, int n) {
	//有左子树
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		if (j + 1 < n && nums[j + 1] > nums[j]) {
			// 有右子树并且右子树大于左子树
			j = j + 1;
		}
		if (nums[k] > nums[j]) break;
		swap(nums[k], nums[j]);
		k = j;
	}
}
// 
int main()
{
	vector<int> nums = {15,17,19,13,22,16,28,30,41,62};
	// 给定一个数组之后， 先要原地构建一个最大堆，就是从第一个非叶子节点开始 执行shiftdown操作
	int n = nums.size();
	for (int i = (n - 1) / 2; i >= 0; i--) {
		// 从第一个非叶子节点开始
		shiftdown(nums, i, n);
	}
	for (auto item : nums) {
		cout << item << " ";
	}
	cout << endl;
	// 初始的最大堆已经构建完成
	for (int i = n - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		shiftdown(nums, 0, i);
	}
	for (auto item : nums) {
		cout << item << " ";
	}
	cout << endl;
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
