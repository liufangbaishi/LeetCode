#include <vector>
#include <iostream>
using namespace std;
#include <string>
string multiply(string num1, string num2) {
	string res="";
	int n1 = num1.size(), n2 = num2.size();
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int carry = 0;
	vector<int> v(n1 + n2, 0);
	for (int i = 0; i < n1; ++i) {
		int a = num1[i] - '0';
		for (int j = 0; j < n2; ++j) {
			int b = num2[j] - '0';
			v[i + j] += a*b;
		}
	}
	for (int i = 0; i < n1 + n2; ++i) {
		v[i] += carry;
		carry = v[i] / 10;
		v[i] %= 10;
	}
	int i = n1 + n2 - 1;
	while (v[i] == 0)
		--i;
	if (i < 0)
		return "0";
	while (i >= 0) 
		res.push_back(v[i--] + '0');
	return res;
}
int main()
{
	string a = "88";
	string b = "97";
	string ret = multiply(a, b);
	cout << ret << endl;
	return 0;
}