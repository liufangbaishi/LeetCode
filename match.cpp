
// 正则表达式匹配
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == NULL || pattern == NULL)
			return false;
		return matchCore(str, pattern);
	}
	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			else      //  *匹配前面的字符1次    *匹配前面的字符n次     *匹配前面的字符0次
				return matchCore(str, pattern + 2);// 忽略一个*
		}
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);
		return false;
	}
};