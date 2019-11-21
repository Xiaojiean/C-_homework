#include "num.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const char student_id[] = "20170311299";
	auto number = new CNum;

	number->init_num();
	number->print_student_id(student_id, strlen(student_id));
	
	delete number;

	return 0;
}
