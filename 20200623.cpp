#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	long n, m;
	cin >> n >> m;
	long i = 1;
	m--;
	while (m != 0) {
		long left = i, right = i + 1;//Ĭ������[1,2��
		long num = 0;//��ʾ���䷶Χ

		 // ���loop����������start�ڵ㿪ʼ����һֱ��n���нڵ�
		while (left <= n){//�����Χ����߽�С��n
			num += min(n + 1, right) - left;//�����������ж�����
			left *= 10;//*10,�����ֵ����������ӽڵ�ĵ�һ��λ����
			right *= 10;
		}
		if (num > m){//˵������Ҫ�ҵĽڵ��������֧�ϣ�����������
			i *= 10;//���ӽڵ���
			m--;
		}
		else{//˵���ղű����Ľڵ㷶Χ�Ҳ���m�����Ի�������Χ�������ƶ�
			m -= num;//m����һ����Χ��Ҫ��������Ҫ��ȥ�������Χ��Ҫ����
			i++;//��Χ����
		}
	}
	cout << i << endl;
	return 0;
}