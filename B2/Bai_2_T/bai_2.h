struct Music
{
    char ten[51], tacGia[41], caSi[41];
    int time;
};

struct Node
{
    Music ms;
    Node *next;
    Node();
};

struct List
{
    Node *head;
    Node *tail;
};