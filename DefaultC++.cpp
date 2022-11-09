#define ACM
#define SRC

#ifdef ACM

#ifdef  __cplusplus
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#ifdef STL
#include <queue>
#include <vector>
#include <deque>
#include <map>
#endif // !STL

#else // #ifndef __cplusplus
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#endif // ! __cplusplus

#ifdef SRC
#pragma warning(disable:4996)
FILE* stream;
void read() {freopen_s(&stream, "testdata.in", "r", stdin);}
void write() {freopen_s(&stream, "testdata.out", "w", stdout);}
#endif // !SRC

#endif // !ACM

bool dct[26][101];
string wrd;

struct memory {
	string _wrd;
}m[101];

bool cmp(int _x, int _y) {
	string wrd1 = m[_x]._wrd;
	string wrd2 = m[_y]._wrd;
	for (int i = 0; i < min(wrd1.length(), wrd2.length()); i++) {
		if (wrd1[i] < wrd2[i]) return 1;
		if (wrd1[i] > wrd2[i]) return 0;
	}
	return 1;
}

int main() {
	read();
	int cnt = 0;
	while (cin >> wrd) {
		if (wrd == "XXXXXX") break;
		++cnt;
		m[cnt]._wrd = wrd;
		for (int i = 0; i < wrd.length(); i++) dct[wrd[i] - 'a'][cnt] = 1;
	}
	int ans_cnt, ans[101];
	bool ok;
	while (cin >> wrd) {
		if (wrd == "XXXXXX") break;
		ans_cnt = 0;
		for (int i = 1; i <= cnt; i++) {
			if (m[i]._wrd.length() != wrd.length()) continue;
			ok = 1;
			for (int j = 0; j < wrd.length(); j++) {
				if (dct[wrd[j] - 'a'][i] == 0) {
					ok = 0;
					break;
				}
			}
			if (ok) ans[++ans_cnt] = i;
		}
		if (ans_cnt) {
			sort(ans + 1, ans + 1 + ans_cnt, cmp);
			for (int i = 1; i <= ans_cnt; i++) cout << m[ans[i]]._wrd << endl;
		}
		else cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}