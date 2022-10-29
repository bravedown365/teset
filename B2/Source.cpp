#include "LinkedList.h"

Node::Node()
{
    info = 0;
    next = NULL;
};

Node::Node(Data item, Node *link)
{
    info = item;
    next = link;
}

void Init(List &l)
{
    l.head = l.tail = NULL;
}

Node *CreatNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Khong du bo nho" << endl;
        system("pause");
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
}

void AddHead(List &l, Node *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void AddTail(List &l, Node *p)
{
    if (l.tail == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateList(List &l)
{
    int n, x;
    Init(l);
    do
    {
        cout << "Nhap so phan tu cua DS: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap phan tu thu " << i << " la: ";
        cin >> x;
        Node *p = CreatNode(x);
        AddTail(l, p);
    }
}

void ShowList(List l)
{
    cout << "\nDu lieu DS la: " << endl;
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        cout << p->info << "\t";
    }
}

void xoaDau(List &l)
{
    if (l.head == NULL)
        return;
    Node *p = new Node;
    p = l.head;
    l.head = l.head->next;
    p->next = NULL;
    delete p;
}

void XoaCuoi(List &l)
{
    if (l.tail == NULL)
        return;
    for (Node *k = l.head; k != NULL; k = k->next)
    {
        if (k->next == l.tail)
        {
            delete l.tail;
            k->next = NULL;
            l.tail = k;
        }
    }
}

void XoaNutQ(List &l, int key)
{
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        if (p != NULL && p->next != NULL && p->info == key)
        {
            p->next = p->next->next;
            return;
        }
    }
}

void XoaNutValueX(List &l, int key)
{
    if (l.head->info == key)
        xoaDau(l);
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        if (p != NULL && p->next != NULL && p->next->info == key)
        {
            p->next = p->next->next;
            return;
        }
    }
}

void HuyDS(List &l)
{
    for (Node *k = l.head; k != NULL; k = k->next)
    {
        Node *p = l.head;
        l.head = p->next;
        delete p;
    }
    l.tail = NULL;
}

void HoanVi(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void SapXep(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->info > j->info)
            {
                HoanVi(i->info, j->info);
            }
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    List l;

    CreateList(l);
    ShowList(l);

    // xoaDau(l);
    // XoaCuoi(l);
    // XoaNutQ(l, 2);
    // XoaNutValueX(l, 1);
    // HuyDS(l);

    // SapXep(l);
    // ShowList(l);
}