// ����ǰ��ż�������λ�ò���
// ���û��Ҫ�����λ�ò��䣬���Բ���ǰ��ָ��ķ�������ǰ�������ż��ͣ�£��Ӻ���ǰ����������ͣ�£�������������
#include <iostream>
#include <vector>
#include "juzhen.h"
using namespace std;
// ����һ���ռ䣬�������飬��һ���ҵ��������ڶ����ҵ�ż��
// Ҳ���Կ��������ռ䣬����һ�飬���ż���ŵ������ĺ���
void reOrderArray(vector<int> &array) 
{
	if (array.empty())
		return;
	int size = array.size();
	vector<int> ret(size);
	int index = 0;
	for (int i = 0; i<size; i++)
	{
		if (array[i] % 2 == 1)
			ret[index++] = array[i];
	}
	for (int i = 0; i<size; i++)
	{
		if (array[i] % 2 == 0)
			ret[index++] = array[i];
	}
	for (int i = 0; i < size; i++)
		array[i] = ret[i];
}


int main()
{
	test();
	/*vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	reOrderArray(v);*/
}