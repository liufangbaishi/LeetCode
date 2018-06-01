#include <iostream>
#include <vector>
using namespace std;
//��������������
// ����{ 3,1,-2,6,-3 }����8
int GetMax(int a, int b)
{
	return a > b ? a : b;
}
int GetMaxArray(vector<int> arr)// ��̬�滮��˼��  Max(dp[i]) = getMax(Max(dp[i-1])+arr[i], arr[i])
		          //��ͷ��ʼ�������飬����������Ԫ�� arr[i] ʱ�����������ĺͿ���Ϊ Max(dp[i-1])+arr[i]��
		       	  //Ҳ����Ϊ arr[i]�����Ƚϼ��ɵó��ĸ�����ȡ���ֵ��ʱ�临�Ӷ�Ϊ n
{
	int size = arr.size();
	int sum = arr[0];
	int max = arr[0];
	for (int i = 1; i < size; i++)
	{                                        
		sum = GetMax(sum + arr[i], arr[i]);  
		if (sum > max)
			max = sum;
	}
	return max;
}

int MaxArray(vector<int> arr) //����һ�飬��ǰԪ����ӣ����С��0��������¿�ʼ�ۼӣ�
                              //ͬʱ����֮ǰ�����������
{
	int size = arr.size();
	int max = arr[0];
	int cur = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (cur < 0)
			cur = 0;
		cur = cur + arr[i];
		if (cur > max)
			max = cur;
	}
	return max;
}
int main()
{
	int num = 0;
	cin >> num;
	vector<int> arr;
	arr.resize(num);
	for (size_t i = 0; i < num; i++)
		cin >> arr[i];
	int i = GetMaxArray(arr);
	//int i = MaxArray(arr);
	cout << i << endl;
}