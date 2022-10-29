#include <iostream>
#include <windows.h>
using namespace std;

typedef int Data;

struct Node
{
	Data info;
	Node *next;
	Node();
	Node(Data item, Node *link = NULL);
};

struct List
{
	Node *head;
	Node *tail;
};