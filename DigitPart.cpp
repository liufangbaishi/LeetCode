#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		string out;
		string res;
		int maxlen = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (!isdigit(s[i]))
				continue;

			while (isdigit(s[i]))
			{
				out += s[i];
				i++;
			}
			if (out.size() > maxlen)
			{
				res.clear();
				maxlen = out.size();
				res = out;
			}
			else if (out.size() == maxlen)
				res += out;
			out.clear();
		}
		cout << res << "," << maxlen << endl;
	}
	return 0;
}