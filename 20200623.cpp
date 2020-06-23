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
		long left = i, right = i + 1;//默认区间[1,2）
		long num = 0;//表示区间范围

		 // 这个loop用来遍历以start节点开始往下一直到n所有节点
		while (left <= n){//如果范围的左边界小于n
			num += min(n + 1, right) - left;//算出这个区间有多少数
			left *= 10;//*10,代表字典树到了它子节点的第一个位置上
			right *= 10;
		}
		if (num > m){//说明我们要找的节点在这个分支上，继续往下找
			i *= 10;//往子节点找
			m--;
		}
		else{//说明刚才遍历的节点范围找不到m，所以还得扩大范围，往右移动
			m -= num;//m在下一个范围需要的数，需要减去在这个范围需要的数
			i++;//范围有移
		}
	}
	cout << i << endl;
	return 0;
}