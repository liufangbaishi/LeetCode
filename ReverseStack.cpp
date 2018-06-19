#include <iostream>
#include <vector>
using namespace std;
//用递归函数和栈操作逆序,栈和栈的大小
class ReverseStack {
public:
	vector<int> reverseStackRecursively(vector<int> stack, int top) {
		vector<int> ret;
		ret.resize(top);
		int i = 0;
		Reverse(ret, stack, top, i);
		return ret;
	}
	void Reverse(vector<int> &dst, vector<int> src, int &top, int &index){
		if (top > 0)
		{
			int data = src[top - 1];
			top--;
			dst[index++] = data;
			Reverse(dst, src, top, index);
		}
	}
};
void test()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	vector<int> v(arr, arr + 5);
	ReverseStack res;
	res.reverseStackRecursively(v, 5);
}