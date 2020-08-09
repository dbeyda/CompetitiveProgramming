#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* findCommonNode(Node *a, Node *b)
{
    if (!a || !b) return nullptr;
    while(a && b)
    {
        if (a == b) break;
        a = a->next;
        b = b->next;
    }
    return a;
}

int findSizeAndLastNode(Node *head, Node **last)
{
    if (!head) return 0;
    int len = 0;
    while(head)
    {
        if (!head->next)
            (*last) = head;
        len++;
        head = head->next;
    }
    return len;
}

Node* findIntersection(Node *a, Node *b)
{
    Node *lastA = nullptr;
    Node *lastB = nullptr;
    Node *headA = a;
    Node *headB = b;
    int lena = findSizeAndLastNode(a, &lastA);
    int lenb = findSizeAndLastNode(b, &lastB);
    // last node is not the same
    if (lastA != lastB) return nullptr;

    // padding with zeros to make the lists the same size;
    while (lena < lenb)
    {
        Node newNode = {0, a};
        headA = &newNode;
        lena++;
    }
    while (lena > lenb)
    {
        Node newNode = {0, b};
        headB = &newNode;
        lenb++;
    }

    return findCommonNode(headA, headB);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node a5 = {2, nullptr};
    Node a4 = {5, &a5};
    Node a3 = {3, &a4};
    Node a2 = {71, &a3};
    Node a1 = {54, &a2};
    Node b2 = {52, &a3};
    Node b1 = {33, &b2};

    Node * common = findIntersection(&a1, &b1);
    cout << "Found common node " << common->data << endl;
    return 0;
}
