//二进制中1的个数
int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);//n-1和n相比，n的最后1位1变为0，之后的数0变为1,1变为0，相与之后，相当于将n的最后一位1给去掉
	}
}
int main()
{
	NumberOf1(5);
	return 0;
}