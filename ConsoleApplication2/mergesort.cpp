#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums, int L, int mid, int R) {
	// 注意辅助数组的下标从0开始
	vector<int> helper(R - L + 1, 0);
	int p1 = L;
	int p2 = mid + 1;
	int help_start = 0;
	while (p1 <= mid && p2 <= R) {
		helper[help_start++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
	}
	while(p2 <= R) {
		helper[help_start++] = nums[p2++];
	}
	while (p1 <= mid) {
		helper[help_start++] = nums[p1++];
	}
	// 这里注意辅助数组和原数组下标的转换
	for (int i = 0; i < helper.size(); i++) {
		nums[i+L] = helper[i];
	}
}

void sortProcess(vector<int>& nums, int L, int R) {
	if (L == R) {
		return;
	}
	int mid = L + (R - L) /2;
	sortProcess(nums, L, mid);
	sortProcess(nums, mid + 1, R);
	merge(nums, L, mid, R);
}

void mergesort(vector<int>& nums) {
	sortProcess(nums, 0, nums.size() - 1);
}


int main()
{
	vector<int> nums = {4,6,5,2,3,8};
	for (auto item : nums) {
		cout << item << endl;
	}
	mergesort(nums);
	for (auto item : nums) {
		cout << item << endl;
	}
	return 0;
}