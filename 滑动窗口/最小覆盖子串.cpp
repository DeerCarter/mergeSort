#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

/*
	给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
	输入: S = "ADOBECODEBANC", T = "ABC"
	输出: "BANC"

*/


string minWindow(string s, string t) {
	// 使用滑动窗口 + map
	unordered_map<char, int> need, window;
	// 先记录下需要的子串的信息
	for (auto c : t) need[c]++;

	int left = 0, right = 0;
	int valid = 0;  // 验证当前窗口是否满足要求

	// 记录下最小子串的开始索引和len

	int start = 0, len = INT_MAX;
	while (right < s.size()) {
		char c = s[right];
		right++;
		if (need.count(c)) {
			window[c]++;
			if (window[c] == need[c]) {
				valid++;
			}
		}
		// 判断是否需要收缩左边界
		while (valid == need.size()) {
			if (right - left < len) {
				start = left;
				len = right - left;
			}
			char d = s[left];
			left++;
			if (need.count(d)) {
				if (window[d] == need[d]) {
					valid--;
				}
				window[d]--;
			}
		}
	}
	return len == INT_MAX ? "" : s.substr(start, len);
}

int main()
{
	cout << minWindow("ADOBECODEBANC", "ABC") << endl;
	return 0;
}