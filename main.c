/*
#include "stackC.h"
#include <string.h>
#include <stdio.h>

inline boolean isOperator(char c) {
	return '0' <= c && c <= '9' ? 0 : 1;
}

inline int compute(int left, int right, char op) {
	switch (op) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	}
	return 0;
}

int main() {
	char str[] = "abc*+d/e-";
	Stack s;
	InitStack(&s);

	for (int i = 0; i < strlen(str); i++) {
		if (isOperator(str[i])) {
			int right = Stack_Back(s);
			Stack_popBack(&s);
			int left = Stack_Back(s);
			Stack_popBack(&s);
			int ans = compute(left, right, str[i]);
			Stack_pushBack(&s, ans);
		}
		else {
			Stack_pushBack(&s, str[i] - '0');
		}
	}
	
	printf("%d", Stack_Back(s));
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char t[100] = { 'A', 'B', 'C', 'D', 'F', 'G', 'I'};

void preOrder(int p) {
	printf_s("%c ", t[p]);

	if(t[(p + 1) * 2 - 1])
		preOrder((p + 1) * 2 - 1);

	if(t[(p + 1) * 2])
		preOrder((p + 1) * 2);
}

void inOrder(int p) {
	if(t[(p + 1) * 2 - 1])
		inOrder((p + 1) * 2 - 1);

	printf_s("%c ", t[p]);

	if (t[(p + 1) * 2])
		inOrder((p + 1) * 2);
}

void postOrder(int p) {
	if (t[(p + 1) * 2 - 1])
		postOrder((p + 1) * 2 - 1);

	if (t[(p + 1) * 2]) {
		postOrder((p + 1) * 2);
	}

	printf_s("%c ", t[p]);
}

int main(int argc, char** argv) {
	t[9] = 'E';
	t[12] = 'H';
	preOrder(0);
	printf_s("\n");
	inOrder(0);
	printf_s("\n");
	postOrder(0);

	return 0;
}
*/