#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>

#include "KT.h"
using namespace std;

Node::Node()
{
    info.giaTien = 0;
    info.namSX = 0;
    info.soTrang = 0.0;
    next = NULL;
}

Node *createNode(SV sv)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Not enough memory to allocate!";
        return NULL;
    }
    p->info.giaTien = sv.giaTien;
    strcpy(p->info.maSach, sv.maSach);
    p->info.namSX = sv.namSX;
    p->info.soTrang = sv.soTrang;
    strcpy(p->info.tenSach, sv.tenSach);

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
    cout << p->info.maSach << "\t"
         << p->info.tenSach << "\t"
         << p->info.soTrang << "\t"
         << p->info.namSX << "\t"
         << p->info.giaTien << "\n";
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

    cout << setw(12) << left << "Mã sách"
         << setw(32) << left << "Tên sách"
         << setw(22) << left << "Số trang"
         << setw(25) << left << "Năm sản xuất"
         << setw(12) << left << "Giá bán" << endl;
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        cout << setw(10) << left << p->info.maSach
             << setw(30) << left << p->info.tenSach
             << setw(20) << left << p->info.soTrang
             << setw(20) << left << p->info.namSX
             << setw(10) << left << p->info.giaTien << endl;
    }
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

void createList(SList &l)
{
    SV tmp;
    init(l);
    string temp = "";
    fstream file;
    file.open("KT.txt");
    while (!file.eof())
    {
        file.getline(tmp.maSach, sizeof(tmp.maSach), '#');
        file.getline(tmp.tenSach, sizeof(tmp.tenSach), '#');
        file >> tmp.soTrang;
        getline(file, temp, '#');
        file >> tmp.giaTien;
        getline(file, temp, '#');
        file >> tmp.namSX;
        getline(file, temp, '\n');

        Node *p = createNode(tmp);
        addTailSList(l, p);
    }
    file.close();
}

void demSach(SList &l)
{
    int count = 0;
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        if (p->info.soTrang > 500 && p->info.namSX < 2018)
            ++count;
    }
    cout << "Số cuốn sách có số trang lớn hơn 500 và sản xuất trước năm 2018 là: " << count << endl;
}

void xoaDau(SList &l)
{
    if (l.head == NULL)
        return;
    else
    {
        Node *p = l.head;
        l.head = l.head->next;
        p->next = NULL;
        delete p;
    }
}

void XoaCuoi(SList &l)
{
    if (l.tail == NULL)
        return;
    else
    {
        Node *p = l.tail;
        Node *q = l.head;
        if (p == q)
        {
            l.head = l.tail = NULL;
            delete p;
        }
        else
        {
            while (q->next != l.tail)
                q = q->next;
            q->next = NULL;
            l.tail = q;
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
            XoaCuoi(l);
        else
        {
            Node *p = q->next;
            q->next = p->next;
            p->next = NULL;
            delete p;
        }
    }
}

void xoaSachGiaX(SList &l)
{
    if (isEmpty(l))
        return;

    Node *g = new Node();
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        if (p->info.giaTien > 100000)
        {
            if (p == l.head)
                xoaDau(l);
            else
            {
                g->next = p->next;
                delete p;
            }
        }
        g = p;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SList l;
    createList(l);
    traverse(l);
    // demSach(l);
    // xoaSachGiaX(l);
    // traverse(l);
}