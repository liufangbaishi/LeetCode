#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// 手机键盘九键的排列组合，例如给"23", 输出ad,ae,af,bd,be,bf,cd,ce,cf
void getStr(map<int, string> &m, string &str, int index, string &tmp, vector<string>&res)
{
	if (index == str.size()) {
		res.push_back(tmp);
		return;
	}
	int num = str[index] - '0';
	for (int i = 0; i < m[num].size(); i++)
		getStr(m, str, index + 1, tmp + m[num][i], res);
}
vector<string> letterCombinations(string digits)
{
	vector<string> res;
	map<int, string> m;
	string tmp;
	m.insert({ 2, "abc" }), m.insert({ 3, "def" }), m.insert({ 4, "ghi" }), m.insert({ 5, "jkl" }), m.insert({ 6, "mno" }),
		m.insert({ 7, "pqrs" }), m.insert({ 8, "tuv" }), m.insert({ 9, "wxyz" });

	if (digits.empty()) 
		return res;
	getStr(m, digits, 0, tmp, res);
	return res;
}
