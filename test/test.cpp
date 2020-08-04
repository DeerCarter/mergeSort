// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


int main()
{
	//int K, N;
	//cin >> K >> N;

	int M, N, T;
	cin >> N >> M >> T;
	int num = M + N;
	vector<vector<int> > moon(N, vector<int>(2, 0));
	vector<vector<int> > dineer(M, vector<int>(2, 0));
   // 用个map 存下标
	unordered_map<int, int> moon_index;
	unordered_map<int, int> dineer_index;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		moon[i][0] = a;
		moon[i][1] = b;
		if (moon_index.count(b)) {
			moon_index[b] = min(moon_index[b], a);
		}
		else {
			moon_index[b] = a;
		}
		
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dineer[i][0] = a;
		dineer[i][1] = b;
		if (dineer_index.count(b)) {
			dineer_index[b] = min(dineer_index[b], a);
		}
		else {
			dineer_index[b] = a;
		}
	}
	int result_beautiful = INT_MAX;
	// 按照 美味值排序；
	int n = moon.size();
	vector<int> moon_b(n+1, 0);
	for (int i = 0; i < n; i++) {
		moon_b[i] = moon[i][1];
	}
	sort(moon_b.begin(), moon_b.end(),greater<int>());
	
	int m = dineer.size();
	vector<int> dineer_b(m+1, 0);
	for (int i = 0; i < m; i++) {
		dineer_b[i] = dineer[i][1];
	}
	sort(dineer_b.begin(), dineer_b.end(), greater<int>());
	
	moon_index[0] = 0;
	dineer_index[0] = 0;
	int i = 0, j = 0;
	//cout << " 午餐 美味值对应的热量" << endl;
	//for (auto item : moon_index) {
	//	cout << item.first << " " << item.second<<" ";
	//}
	//cout << endl;
	//cout << " 晚餐 美味值对应的热量" << endl;
	//for (auto item : dineer_index) {
	//	cout << item.first << " " << item.second<<" ";
	//}
	//cout << endl;

	//// 
	//cout << " 午餐 美味值" << endl;
	//for (auto item : moon_b) {
	//	cout << item <<" ";
	//}
	//cout << endl;
	//cout << " 晚餐 美味值" << endl;
	//for (auto item : dineer_b) {
	//	cout << item << " ";
	//}
	//cout << endl;
	
	if (moon_b[0] + dineer_b[0] < T) {
		return -1;
	}
	for (int i = 0; i < moon_b.size(); i++) {
		for (int j = 0; j < dineer_b.size(); j++) {
			if (moon_b[i] + dineer_b[j] >= T) {
				result_beautiful = min(result_beautiful, moon_index[moon_b[i]] + dineer_index[dineer_b[j]]);
			}
		}
	}
	cout << result_beautiful << endl;


	return 0;
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
