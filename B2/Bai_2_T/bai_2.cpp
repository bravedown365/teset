#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>

#include "bai_2.h"
using namespace std;

Node::Node()
{
    ms.time = 0;
    next = NULL;
}

void Init(List &l)
{
    l.head = l.tail = NULL;
}

Node *CreateNode(Music ms)
{
    Node *p = new Node();
    if (p == NULL)
    {
        cout << "Không đủ bộ nhớ" << endl;
        return NULL;
    }
    strcpy(p->ms.ten, ms.ten);
    strcpy(p->ms.tacGia, ms.tacGia);
    strcpy(p->ms.caSi, ms.caSi);
    p->ms.time = ms.time;

    p->next = NULL;
    return p;
}

bool isEmpty(List l)
{
    return l.head == NULL;
}

void AddHeadList(List &l, Node *p)
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

void AddTailList(List &l, Node *p)
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

void CreateList(List &l)
{
    Init(l);
    Music tmp;
    fstream file;
    string temp = "";
    file.open("bai_2.txt");
    while (!file.eof())
    {
        file.getline(tmp.ten, sizeof(tmp.ten), '#');
        file.getline(tmp.tacGia, sizeof(tmp.tacGia), '#');
        file.getline(tmp.caSi, sizeof(tmp.caSi), '#');
        file >> tmp.time;
        getline(file, temp, '\n');

        Node *p = CreateNode(tmp);
        AddTailList(l, p);
    }
    file.close();
}

void ShowList(List l)
{
    if (isEmpty(l))
    {
        cout << "List is empty";
        return;
    }
    cout << setw(54) << left << "Tên bài hát" << "|"
         << setw(43) << left << "Tác giả" << "|"
         << setw(42) << left << "Ca Sĩ" << "|"
         << setw(14) << left << "Thời lượng" << "|" << endl;
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        cout << setw(51) << left << p->ms.ten << "|"
             << setw(41) << left << p->ms.tacGia << "|"
             << setw(41) << left << p->ms.caSi << "|"
             << setw(10) << left << p->ms.time << "|" << endl;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    List l;
    CreateList(l);
    ShowList(l);

    system("pause");
}