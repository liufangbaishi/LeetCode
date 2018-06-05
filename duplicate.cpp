#include<iostream>
#include<string>
using namespace std;
// �����е��ظ����֣�����Ϊn������Ϊ0��(n-1){ 2, 3, 1, 0, 2, 5, 3 }������2��3

// ��һ�֣����ⶨ��һ�����飬��ʼ��Ϊ0�������Ԫ�أ���Ӧλ����Ϊ1�����������1����ô���ҵ��ظ�������
bool duplicate(int numbers[], int length, int* duplication) {
	if (NULL == numbers || length <= 1)
	{
		duplication = NULL;
		return false;
	}
	int *index = new int[length]; //���ٳ���Ϊlength�������ʼ��Ϊ0
	for (int i = 0; i < length; i++)
	{
		int tmp = numbers[i];
		if (0 == index[tmp])
			index[tmp] = 1;
		else if (1 == index[tmp])
		{
			*duplication = numbers[i];
			delete[] index;
			index = NULL;
			return true;
		}
	}
	delete[] index;
	index = NULL;
	duplication = NULL;
	return false;
}

// �ڶ��֣�{ 2, 3, 1, 0, 2, 5, 3 }��ѭ��һ�Σ�
// �ӵ�һ������ʼ��2û������Ӧ���ڵ�λ�ã����±�Ϊ2��Ԫ�ػ��� { 1, 3, 2, 0, 2, 5, 3 }
// ��һ������1����Ȼ���������ڵ�λ�ã����±�Ϊ1��Ԫ�ػ��� { 3, 1, 2, 0, 2, 5, 3 }
// ��һ������3����Ȼ���������ڵ�λ�ã����±�Ϊ3��Ԫ�ػ��� { 0, 1, 2, 3, 2, 5, 3 }
// ��ʱ����һ������0�ڸ��ڵ�λ�ã�����ߣ�1,2,3Ҳ���ڸ��ڵ�λ�ã�
// ������±�Ϊ4��Ԫ��Ϊ2����ʱ���±�Ϊ2��Ԫ�غ��±�Ϊ4��Ԫ����ȣ����ԣ����ҵ����ظ�������
// ��Ȼ����ѭ�������ǵڶ���ѭ���һ�����֣����ѭ�����Σ�
// �Ϳ��Ե���Ӧ���ڵ�λ���У����ԣ�ʱ�临�Ӷ�ΪO(N)
class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length <= 1)
			return false;
		for (int i = 0; i<length; i++)
		{
			if (numbers[i] < 0 || numbers[i] > length-1)
				return false;
		}
		for (int i=0; i<length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				// swap(numbers[i], numbers[numbers[i]]);
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}
		}
	}
};
void test()
{
	Solution s;
	int num[] = { 2, 3, 1, 0, 2, 5, 3 };
	int dup = 0;
	s.duplicate(num, 7, &dup);
	cout << dup << endl;
};


