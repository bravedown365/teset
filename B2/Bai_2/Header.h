#include <iostream>

using namespace std;

typedef struct Song
{
	char name[51],
		author[41],
		singer[41];
	unsigned int time;
} Data;

struct Node
{
	Data info;
	Node *next;
	Node();
	Node(Data item, Node *link = NULL);
	void showNode();
};

struct SList
{
	Node *head;
	Node *tail;
};