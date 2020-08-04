// 栈实现队列和队列实现栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#include<queue>
using namespace std;

/*  用两个栈实现队列  实现先入先出*/
class Myqueue {
private:
	stack<int> data;  // 数据栈
	stack<int> pop_stack; //  pop 栈
public:
	void push(int num) {
		//push 的时候正常push进入data栈中
		data.push(num);
	}
	int pop() {
		
		// pop 的时候 ，要判断 pop栈是否为空
		if (pop_stack.empty()) {
			//
			if (data.empty()) {
				cout << " 此时队列为空" << endl;
				return 0;
			}
			while (!data.empty()) {
				pop_stack.push(data.top());
				data.pop();
			}
		}
		int res = pop_stack.top();
		pop_stack.pop();
		return res;
	}
};

// 用队列实现栈
class MyStack {
private:
	queue<int> data_queue;
	queue<int> temp_queue;
public:
	void push(int i) {
		data_queue.push(i);
	}
	int pop() {
		// 
		while (data_queue.size() > 1) {
			temp_queue.push(data_queue.front());
			data_queue.pop();
		}
		int res = data_queue.front();
		data_queue.pop();
		swap(data_queue, temp_queue);
		return res;
	}
};

int main()
{
	Myqueue q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	q1.push(7);
	q1.push(8);
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;

	MyStack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	s1.push(30);
	s1.push(40);
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
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
