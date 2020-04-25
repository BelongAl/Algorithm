#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	int ishw[len][len];
	int cnt[len];
	for (int i = 0; i < len; i++) {
		cnt[i] = 0;
		for (int j = 0; j < len; j++) {
			ishw[i][j] = i == j ? 1 : 0;
		}
	}
	for (int i = 1; i < len; i++) {
		cnt[i] = cnt[i - 1] + 1;
		for (int j = i; j >= 0; j--) {
			if (s[i] == s[j] && (i - j < 2 || ishw[j + 1][i - 1])) {
				ishw[j][i] = 1;
				cnt[i] = min(j == 0 ? 0 : cnt[j - 1] + 1, cnt[i]);
			}
		}
	}
	cout << cnt[len - 1] << endl;
	return 0;
}

·¢±íÓÚ 2020 - 04 - 20 18:26 : 31