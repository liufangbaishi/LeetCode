
// sqrtx   二分查找法  开方根

int sqrt(int x) {
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	int begin = 1;
	int end = x/2;
	while (begin <= end) {
		int mid = begin + ((end - begin) >> 1);
		if ((mid <= x/mid) && ((mid + 1) > x/(mid+1)))  
			                //注意：这里不要写成mid*mid，因为乘积的结果有可能会溢出
			return mid;
		else if (mid < x/mid)
			begin = mid+1;
		else
			end = mid-1;
	}
	return 0;
}
void test()
{
	int ret = sqrt(2147395599);
	cout << ret << endl;
}