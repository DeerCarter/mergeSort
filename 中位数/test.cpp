#include<iostream>
#include<stack>
#include <string>
#include<vector>
#include<queue>
using namespace std;

// ����һ���沨�����ʽ �����  ����  ["4", "13", "5", "/", "+"]  ��� 6

// ��һ���ַ���ת��Ϊint
int changeToInt(string s) {
	int result = 0;
	int length = s.size();
	int i =0;
	while (i < length) {
		int number = s[i++] - '0';
		result = result * 10 + number;
	}
	return result;
}

int evalRPN(vector<string>& tokens) {
	// �������һ��string����
	// ���ж��ǲ��ǲ����� 
	stack<int> result;
	int n = tokens.size();
	for (int i = 0; i < n; i++) {
		string s = tokens[i];
		if (s== "/" || s == "+" || s == "*" || s == "-") {
			int number1 = result.top();
			result.pop();
			int number2 = result.top();
			result.pop();
			int temp = 0;
			if (s == "/") {
				temp = number2 / number1;
			}
			else if (s == "+") {
				temp = number1 + number2;
			}
			else if (s == "*") {
				temp = number1 * number2;
			}else if (s == "-") {
				temp = number2 - number1;
			}
			result.push(temp);
		}
		else {
			// ���ǲ����� ��������
			int length = s.size();
			if (s[0] == '-') {
				// �Ǹ���
				s = s.substr(1, length - 1);
				int number = changeToInt(s);
				result.push(0-number);
			}
			else {
				// ������
				int number = changeToInt(s);
				result.push(number);
			}
		}
	}
	return result.top();
}

int solve(int n, vector<int>& a) {
	// write code here
	// �����е�ż�� ���մӴ�С��˳���������ÿ����������
	// ��һ�����ѣ�
	priority_queue<int> big;
	//int n = a.size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			big.push(a[i]);
		}
	}
	cout << endl;
	if (big.empty())  return 0;
	// �����ż���Ѳ�Ϊ�յ�ʱ��
	while (!big.empty()) {
		int max_ou = big.top();
		
		big.pop();
		// �Ѷ�һ����ż���� ��������2 ���ǲ���ż��
		if (max_ou % 2 == 0 && (max_ou/2) % 2==0) {
			big.push(max_ou / 2);
		}
		count++;
		while (!big.empty() && big.top() == max_ou) {
			big.pop();
			if (max_ou % 2 == 0 && (max_ou / 2) % 2 == 0) {
				big.push(max_ou / 2);
			}
		}
	}
	return count;
}

int solve2 (int n, vector<int>& array) {
	// write code here
	// ������ Ȼ������ķ����м� 
	sort(array.begin(), array.end());
	vector<int> temp(n, 0);
	int mid = n / 2;
	int left_start = n - 2;
	for (int i = mid - 1; i >= 0; i--) {
		temp[i] = array[left_start];
		left_start -= 2;
	}
	int right_start = n - 1;
	for (int i = mid; i < n; i++) {
		temp[i] = array[right_start];
		right_start -= 2;
	}
	// 
	for (auto item : temp) {
		cout << item << " ";
	}
	cout << endl;
	int res = 0;
	for (int i = 0; i < n-1; i++) {
		if (abs(temp[i + 1] - temp[i]) > res) {
			res = abs(temp[i + 1] - temp[i]);
		}
	}
	return res;
}

// ����׺���ʽ ת�����沨�����ʽ
int main()
{
	//vector<int> nums = {2,1,1,3,2};
	//cout << solve2(5, nums) << endl;

	vector<string>  tokens{ "3","-4","+" };
	cout << evalRPN(tokens) << endl;
	return 0;
}