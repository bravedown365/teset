#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "kt.h"
using namespace std;

Node::Node()
{
    info = 0;
    next = NULL;
}

Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Not enough memory to allocate !";
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
}

void deleteNode(Node *&p)
{
    if (p == NULL)
        return;
    p->next = NULL;
    delete p;
}

void showNode(Node *p)
{
    cout << p->info;
}

void init(SList &l)
{
    l.head = NULL;
    l.tail = NULL;
}

bool isEmpty(SList l)
{
    return l.head == NULL;
}

void traverse(SList l)
{
    if (isEmpty(l))
    {
        cout << "List is empty\n";
        return;
    }
    for (Node *p = l.head; p != NULL; p = p->next)
        cout << p->info << '\t';
}

void addHeadSList(SList &l, Node *p)
{
    if (p == NULL)
        return;
    if (isEmpty(l))
        l.head = l.tail = p;
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void addTailSList(SList &l, Node *p)
{
    if (p == NULL)
        return;
    if (isEmpty(l))
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void addAfterNodeSList(SList &l, Node *q, Node *p)
{
    if (p == NULL)
        return;
    else
    {
        if (q == NULL)
        {
            if (l.head == NULL)
                l.head =
                    l.tail = p;
            else
                return;
        }
        else
        {
            if (q == l.tail)

                addTailSList(l, p);
            else
            {
                p->next =
                    q->next;
                q->next = p;
            }
        }
    }
}

Node *searchSList(SList l, int x)
{
    for (Node *q = l.head; q != NULL; q = q->next)
        if (q->info == x)
            return q;
    return NULL;
}

void createSList(SList &l)
{
    int n, x;
    init(l);
    do
    {
        cout << "Cho biết số phần tử của danh sách (n > 0) : ";
        cin >> n;
    } while (n <= 0);
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhập phần tử thứ %d là : " << i;
        cin >> x;
        Node *p = createNode(x);
        addTailSList(l, p);
        addHeadSList(l, p);
    }
}

void createSList(SList &l, int n)
{
    int x;
    Node *q;
    l.head = l.tail = NULL;
    (l);
    for (int i = 1; i <= n; i++)
    {
        cout << "Input the element % d : " << i;
        cin >> x;
        q = createNode(x);
        if (q == NULL)
        {
            printf("Not enough memory to allocate!");
            return;
        }
        if (l.head == NULL)
            l.head = l.tail = q;
        else
        {
            l.tail->next = q;
            l.tail = q;
        }
    }
}

void deleteHeadSList(SList &l)
{
    if (l.head == NULL)
        return;
    else
    {
        Node *p = l.head;
        l.head = p->next;
        p->next = NULL;
        delete p;
    }
}

void deleteTailList(SList &l)
{
    if (l.head == NULL)
        return;
    else
    {
        Node *p = l.tail;
        Node *q = l.head;
        if (p == q)
        {
            l.head = l.tail =
                NULL;
            delete p;
        }
        else
        {
            while (q->next != l.tail)
                q = q->next;
            l.tail = q;
            l.tail->next = NULL;
            delete p;
        }
    }
}

void deleteMidSList(SList &l, Node *q)
{
    if (l.head == NULL || q == NULL || q == l.tail)
        return;
    else
    {
        if (q->next == l.tail)
            deleteTailList(l);
        else
        {
            Node *p = q->next;
            q->next = p->next;
            p->next = NULL;
            delete p;
        }
    }
}

SNode *popS(Stack &s)
{
    SNode *p = NULL;
    if (s.top != NULL)
    {
        p = s.top;
        s.top = s.top->next;
        p->next = NULL;
    }
    return p;
}

void pushS(Stack &s, SNode *p)
{
    if (p != NULL)
        if (s.top == NULL)
            s.top = p;
        else
        {
            p->next = s.top;
            s.top = p;
        }
}