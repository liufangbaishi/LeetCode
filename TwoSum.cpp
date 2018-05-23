#include <iostream>
#include <vector>
#include <unordered_map>
// һ��������������������������֮�͵���ָ�������֣�������������Ӧ����������ڵڶ���������
using namespace std;
#include "MergeArr.hpp"


//��һ�֣�����ѭ����ʱ�临�Ӷ�̫��
void TwoSum(vector<int>& v1, vector<int>& v2, int key)
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v1.size(); j++)
		{
			if (v1[i] + v1[j] == key)
			{
				v2.push_back(i);
				v2.push_back(j);
				return;
			}
		}
	}
}
// �ڶ��֣������ź��������(����)�������һ�����ּ������һ�����ֵ���key�����ҵ����������key����ָ�����һ�����ֵ�
// ָ����ǰ�ƶ������С�ڣ���ָ���һ�����ֵ�ָ������ƶ�
void TwoSum(vector<int>& v1, vector<int>& v2, int key)//��������������
{
	int begin = 0;
	int end = v1.size() - 1;
	while (begin < end)
	{
		if (v1[begin] + v1[end] == key)
		{
			v2.push_back(begin);
			v2.push_back(end);
			return;
		}
		else if (v1[begin] + v1[end] < key)
			begin++;
		else
			end--;
	}
}

// ʹ�ù�ϣ�ȴ���һ��unordered_map��������Ŀ����������v1��������key��ȥv1[0]��
// ����õ��Ľ����map�У���˵�������ҵ�����ĿҪ���������������õ��Ľ������map�У�
// ���ǰ�v1[0]����������һ�����map�С�ѭ����ȥ���Ϳ��Եõ�����ˡ� 
// ��Ϊ�ڹ�ϣ�в��ҵ�Ч����O��1���Ƿǳ��ߵ�
void TwoSum(vector<int>& v1, vector<int>& v2, int key)
{//��ϣ
	unordered_map<int, int> m;
	for (int i = 0; i < v1.size(); i++)
	{
		unordered_map<int, int>::iterator it = m.find(key - v1[i]);
		if (it != m.end())//�ҵ���
		{
			v2.push_back(m[key - v1[i]]);
			v2.push_back(i);
		}
		else//û�ҵ�����
			m.insert({ v1[i], i });
	}
}

void test()
{
	int arr[] = { 2, 7, 11, 15 };
	int key = 9;
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> v1(arr, arr + size);
	vector<int> v2;
	TwoSum(v1, v2, key);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
}

int main()
{
	test();
}

