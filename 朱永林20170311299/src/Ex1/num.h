#ifndef NUM_H
#define NUM_H
#include <iostream>
using namespace std;

class CNum {
	int num_[10][11]{};
public:
	CNum() = default;
	~CNum() = default;
	void init_num();
	inline bool print_num(int index);
	bool print_student_id(const char* id, int len);
};

inline bool CNum::print_num(const int index)
{
	for (size_t i = 0; i < 11; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			if ((num_[index][i] >> (6 - j)) % 2)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return true;
}

#endif //NUM_H
