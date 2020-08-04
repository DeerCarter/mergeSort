// BFS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
	LC : 752 转盘锁
	
*/

#include <iostream>
#include <string>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;

//  字符串s 在j 的位置 向上转动一位  返回转动后的结果
string plusone(string s, int j) {
	// 
	string s1 = s;
	if (s1[j] == '9') {
		s1[j] = '0';
	}
	else {
		s1[j] += 1;
	}
	return s1;
}
// 字符串s 在j 的位置 向下转动一位
string minusone(string s, int j) {
	string s1 = s;
	if (s1[j] == '0') {
		s1[j] = '9';
	}
	else {
		s1[j] -= 1;
	}
	return s1;
}
// BFS的框架
void bfs(string target) {

	queue<string> q;  // 先创建一个队列 
	q.push("0000");      // push进去初始值  然后开始循环
	while (!q.empty()) {
		int sz = q.size();
		// 将当前队列中的所有节点向周围扩散
		for (int i = 0; i < sz; i++) {
			string cur = q.front();
			q.pop();
			// 判断是否到达终点
			cout << cur << endl;

			for (int j = 0; i < 4; j++) {
				string up = plusone(cur, j);
				string down = minusone(cur, j);
				q.push(up);
				q.push(down);
			}
		}
		// 在这里增加步数
	}
	return;
}

// 上述的代码   会走回头路， 没有终止条件  没有对死亡密码的处理
int openLock(string target, vector<string> deadends) {
	// 记录下需要跳过的死亡密码
	unordered_set<string> set;
	for (string item : deadends) {
		set.insert(item);
	}
	// 记录下已经穷举过的密码，防止走回头路
	unordered_set<string> visited;
	queue<string> q;
	// 从起点开始广度优先搜索
	int step = 0;
	q.push("0000");
	visited.insert("0000");
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			string cur = q.front();
			//cout << "当前的step是： "<< step <<":  "<< cur << endl;
			q.pop();
			// 如果是死亡密码 跳过
			if (set.count(cur)) {
				continue;
			}
			if (cur == target) {
				return step;
			}

			for (int j = 0; j < 4; j++)
			{
				string up = plusone(cur, j);
				string down = minusone(cur, j);
				if (!visited.count(up)) {
					q.push(up);
					visited.insert(up);
				}
				if (!visited.count(down)) {
					q.push(down);
					visited.insert(down);
				}
			}
		}
		step++;
	}
	// 穷举完都没有找到目标密码，就是找不到了 返回-1
	return -1;
}

// 双向BFS优化
/* 
	传统的BFS是从起点开始向四周扩散，遇到终点时停止，
	双向BFS是从起点和终点同时开始扩散，当两边有交集的时候停止
	局限就是：必须知道终点在哪里

*/
int main()
{
	vector<string> deadens = {"8887","8889","8878","8898" ,"8788","8988" ,"7888","9888" };
	string target = "8888";
	cout << openLock(target, deadens) << endl;
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
