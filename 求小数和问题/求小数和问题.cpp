// 求小数和问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//小和问题
/*
		在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和，
		求一个数组的小和
		比如[1,3,4,2,5]
		1左边比1小的 没有， 3左边小的 1  ；
		4左边比4小的 1， 3
		2左边比2小的 1，
		5左边比5 小的 1 3 4 2
		和是16
		使用归并排序解决，
		在merge的过程中进行判断相加

*/
/*
	逆序对问题
	在一个数组中，左边的数如果比右边的数大，则这两个数构成一个逆序对，请打印出所有的逆序对

*/

#include <iostream>
#include<vector>
using namespace std;
int result;
vector<vector<int> > nixudui;
// 进行合并操作
//void merge(vector<int>& nums, int L, int mid, int R) {
//	// 先构建一个辅助数组
//	vector<int> helper(R - L + 1, 0);
//	int p1 = L;
//	int p2 = mid + 1;
//	int help_start = 0;
//	while (p1 <= mid && p2 <= R) {
//		result += nums[p1] < nums[p2] ? (R - p2 + 1) * nums[p1] : 0;  // 计算小和
//		if (nums[p1] > nums[p2]) {
//			// 这就构成了逆序对 这样的话 p1后面直到mid的数都与p2 构成了一个逆序对
//			vector<int> mid_result;
//			/*mid_result.push_back(nums[p1]);
//			mid_result.push_back(nums[p2]);
//			nixudui.push_back(mid_result);*/
//			int index = p1;
//			while (index <= mid) {
//				mid_result.push_back(nums[index]);
//				mid_result.push_back(nums[p2]);
//				nixudui.push_back(mid_result);
//				mid_result.clear();
//				index++;
//			}
//		}
//		//cout << result << endl;
//		helper[help_start++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
//	}
//	while (p1 <= mid) {
//		helper[help_start++] = nums[p1++];
//	}
//	while (p2 <= R) {
//		helper[help_start++] = nums[p2++];
//	}
//	// copy到原数组
//	for (int i = 0; i < helper.size(); i++) {
//		nums[L + i] = helper[i];
//	}
//}
//
//// 递归调用的函数 [L.....R] 进行归并排序
//void sortProcess(vector<int>& nums, int L, int R) {
//	if (L == R) return;
//	int mid = L + (R - L) / 2;
//	sortProcess(nums, L, mid);
//	sortProcess(nums, mid + 1, R);
//	merge(nums, L, mid, R);
//}
//
//void mergesort(vector<int>& nums) {
//	sortProcess(nums, 0, nums.size() - 1);
//}
//
//void mergesort2(vector<int>& nums) {
//	sortProcess(nums, 0, nums.size() - 1);
//}
//void sortProcess2(vector<int>& nums, int L, int R) {
//	if (L == R) return;
//	int mid = L + (R - L) / 2;
//	sortProcess(nums, L, mid);
//	sortProcess(nums, mid + 1, R);
//	merge(nums, L, mid, R);
//}
//void merge2(vector<int>& nums, int l, int mid, int r) {
//	vector<int> helper(r - l + 1, 0);
//	int p1 = l;
//	int p2 = mid + 1;
//	int helper_start = 0;
//	while (p1 <= mid && p2 <= r) {
//		helper[helper_start++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
//	}
//	while (p1 <= mid) {
//		helper[helper_start++] = nums[p1++];
//	}
//	while (p2 <= r) {
//		helper[helper_start++] = nums[p2++];
//	}
//	for (int i = 0; i < helper_start; i++) {
//		nums[l + i] = helper[i];
//	}
//
//}

void merge(vector<int>& nums, int L, int mid, int R) {
	vector<int> helper(R - L + 1, 0);
	int p1 = L;
	int p2 = mid+1;
	int helper_start = 0;
	while (p1 <= mid && p2 <= R) {
		// 判断逆序对的个数
		if (nums[p1] > nums[p2]) {
			result += mid - p1 + 1;
		}
		helper[helper_start++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
	}
	while (p1 <= mid) {
		helper[helper_start++] = nums[p1++];
	}
	while (p2 <= R) {
		helper[helper_start++] = nums[p2++];
	}

	for (int i = 0; i < helper.size(); i++) {
		nums[L + i] = helper[i];
	}
}

void sortProcess(vector<int>& nums, int L, int R) {
	if (L == R) return;
	int mid = L + (R - L) / 2;
	sortProcess(nums, L, mid);
	sortProcess(nums, mid + 1, R);
	merge(nums, L, mid, R);
}
void mergesort(vector<int>& nums) {
	// 对nums数组进行归并排序
	sortProcess(nums, 0, nums.size() - 1);
}
int main()
{
	vector<int> nums = {1,3,2,3,1};

	mergesort(nums);
	for (auto item : nums) {
		cout << item << " ";
	}
	//cout << result << endl;
    //std::cout << "Hello World!\n";
	/*for (auto item : nixudui) {
		for (auto i : item) {
			cout << i << " ";
		}
		cout << endl;*/
	cout << endl;
	cout << result << endl;
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
