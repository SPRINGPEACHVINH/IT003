
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reverseLinkedList(SinglyLinkedList *llist)
{
    SinglyLinkedListNode *pre = nullptr;
    SinglyLinkedListNode *next = nullptr;
    SinglyLinkedListNode *current = llist->head;
    while (current != nullptr)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    llist->tail - llist->head;
    llist->head = pre;
}
void insert_node(SinglyLinkedList *llist, int x)
{
    SinglyLinkedListNode *a = new SinglyLinkedListNode(x);
    if (llist->head == nullptr)
    {
        llist->head = a;
    }
    else
    {
        llist->tail->next = a;
    }
    llist->tail = a;
}
void printLinkedList(SinglyLinkedList *a)
{
    SinglyLinkedListNode *p = a->head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();
    int llist_count;

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }

    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
