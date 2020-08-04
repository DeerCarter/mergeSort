#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

/*
	����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���
	����: S = "ADOBECODEBANC", T = "ABC"
	���: "BANC"

*/


string minWindow(string s, string t) {
	// ʹ�û������� + map
	unordered_map<char, int> need, window;
	// �ȼ�¼����Ҫ���Ӵ�����Ϣ
	for (auto c : t) need[c]++;

	int left = 0, right = 0;
	int valid = 0;  // ��֤��ǰ�����Ƿ�����Ҫ��

	// ��¼����С�Ӵ��Ŀ�ʼ������len

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
		// �ж��Ƿ���Ҫ������߽�
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