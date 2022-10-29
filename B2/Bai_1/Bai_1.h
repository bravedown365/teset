#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

typedef int Data;

struct Node
{
	Data info;
	Node *next;
	Node();
	Node(Data item, Node *link = NULL);
	void ShowNode();
};

struct List
{
	Node *head;
	Node *tail;
};