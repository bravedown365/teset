#include "Bai_1.h"

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

void Node::ShowNode()
{
    cout << info << " ";
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
    Init(l);

    string str;
    string value;
    int number;

    ifstream data("Bai_1.txt");
    while (getline(data, str))
    {
        istringstream ss(str);
        while (getline(ss, value, ' '))
        {
            istringstream sn(value);
            sn >> number;
            Node *p = CreatNode(number);
            AddTail(l, p);
        }
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

void deleteMidList(List &l, Node *q)
{
    if (l.head == NULL || q == NULL || q == l.tail)
        return;
    else
    {
        Node *p = q->next;
        q->next = p->next;
        p->next = NULL;
        delete p;
    }
}

void xoaGiaTriSau(List &l, int key)
{
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        if (p->info == key)
        {
            if (p->next == l.tail)
            {
                XoaCuoi(l);
            }
            deleteMidList(l, p->next);
            return;
        }
    }
}

void xoaGiaTriX(List &l, int key)
{
    if (l.head->info == key)
        xoaDau(l);
    else if (l.tail->info == key)
        XoaCuoi(l);
    else
    {
        for (Node *p = l.head; p != NULL; p = p->next)
        {
            if (p->info == key)
            {
                deleteMidList(l, p);
                return;
            }
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

void DeleteEven(List &l)
{
    if (l.head == NULL)
        return;
    Node *p = l.head, *q = p;
    while (p != NULL)
    {
        if (p->info % 2 == 0)
        {
            if (p == l.head)
            {
                p = p->next;
                q = p;
                xoaDau(l);
            }
            else
            {
                if (p == l.tail)
                {
                    XoaCuoi(l);
                    break;
                }
                else
                {
                    Node *v = q;
                    p = p->next;
                    deleteMidList(l, v);
                }
            }
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    List l;

    CreateList(l);
    // xoaDau(l);
    // xoaGiaTriSau(l, 3);
    // xoaGiaTriX(l, 3);
    // HuyDS(l);
    // DeleteEven(l);
    ShowList(l);
}