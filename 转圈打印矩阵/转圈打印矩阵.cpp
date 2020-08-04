// 打印矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
	1. 转圈打印矩阵，


*/

#include <iostream>
#include <vector>
using namespace std;
// 给出左上和右下  打印出来
void lefttorightprint(vector<vector<int>> nums,int left_x, int left_y, int right_x, int right_y) {
	int j = left_y;
	while (j <= right_y) {
		cout << nums[left_x][j++] << " ";
	}
	int i = left_x + 1;
	while (i <= right_x) {
		cout << nums[i++][right_y] << " ";
	}
	j = right_y-1;
	while (j >= left_y) {
		cout << nums[right_x][j--] << " ";
	}
	i = right_x-1;
	while (i > left_x) {
		cout << nums[i--][left_y] << " ";
	}

}

// 转圈打印矩阵  要找到矩阵的左上角和右下角
void zhuanquanprint(const vector<vector<int>>& nums) {
	// 先找到左上角和右下角的坐标
	int left_x = 0;
	int left_y = 0;
	int right_x = nums.size() - 1;
	int right_y = nums[0].size() - 1;
	while (left_x <= right_x && left_y <= right_y) {
		lefttorightprint(nums, left_x, left_y, right_x, right_y);
		left_x++;
		left_y++;
		right_x--;
		right_y--;
	}
	
}

int main()
{
	vector<vector<int>> nums{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {130,140,150,160} };
	zhuanquanprint(nums);
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
