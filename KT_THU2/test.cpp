#include <iostream>
#include <string.h>
using namespace std;

struct input
{
    char str;
};

struct SNode
{
    input ip;
    SNode *next;
};

struct Stack
{
    SNode *top;
};

SNode *KhoiTaoStact(Stack &s)
{
    s.top = NULL;
}

bool IsEmpty(Stack s)
{
    return s.top == NULL;
}

SNode *createNode(char x)
{
    SNode *p = new SNode();
    if (p == NULL)
    {
        cout << "Not enough memory to allocate !";
        return NULL;
    }
    p->ip.str = x;
    p->next = NULL;
    return p;
}

bool popS(Stack &s, char &x)
{
    if (s.top != NULL)
    {
        SNode *p = s.top;
        x = p->ip.str;
        s.top = s.top->next;
        p->next = NULL;
        delete p;
    }
    return true;
}

void pushS(Stack &s, SNode *p)
{
    if (IsEmpty(s))
        s.top = p;
    else
    {
        p->next = s.top;
        s.top = p;
    }
}

bool Top(Stack &s, int &x)
{
    if (IsEmpty(s))
        return false;
    x = s.top->ip.str;
    return true;
}

void XuatStack(Stack s)
{
    while (!IsEmpty(s))
    {
        char x;
        popS(s, x);
        cout << x << " ";
    }
}

int uT(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '^')
        return 3;
}

void hauTo()
{
    Stack s;
    // input tmp;

    KhoiTaoStact(s);

    // while (tmp.str != '~')
    // {
    //     cin >> tmp.str;
    //     if (tmp.str != '~')
    //     {
    //         SNode *p = createNode(tmp);
    //         pushS(s, p);
    //     }
    // }

    // XuatStack(s);

    int i = 0;
    string infix = "((a+(b*c))-d)";
    string postfix = "";
    int x = Top(s, x);
    int y;

    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
            i++;
        }
        else if (infix[i] == '(')
        {
            pushS(s, createNode(infix[i]));
            i++;
        }

        else if (infix[i] == ')')
        {
            while (x != '(')
            {
                Top(s, x);
                popS(s, y);
                postfix += s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while (!s.isEmpty() && priority(infix[i]) <= priority(s.peek()))
            {
                postfix += s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    cout << "Postfix is : " << postfix;
    return postfix;
}

int main()
{
    hauTo();
    return 0;
}