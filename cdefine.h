#pragma once

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef enum {
	INFEASIBLE = -1,
	ERROR = 0,
	OK = 1
}Status;

typedef int ElemType;
typedef _Bool boolean;