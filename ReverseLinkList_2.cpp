#include <iostream>
using namespace std;
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right)
    {
        return head;
    }
    if (head->next->next == nullptr)
    {
        ListNode* p = head;
        ListNode* p2 = head->next;
        p2->next = p;
        p->next = nullptr;
        head = p2;
        return head;
    }

    ListNode* p = head;
    ListNode* parent = head;
    int count = 1;
    while (count != left)
    {
        parent = p;
        p = p->next;
        count++;
    }

    ListNode* temp = p;
    ListNode* p2 = p->next;

    if (right - left < 2)
    {
        ListNode* temp2 = p2->next;
        p2->next = p;
        p->next = temp2;
        if (p == head)
        {
            head = p2;
            return head;
        }
        parent->next = p2;

        return head;
    }

    ListNode* p3 = p->next->next;
    count = count + 2;
    while (count < right)
    {
        p2->next = p;
        p = p2;
        p2 = p3;
        p3 = p3->next;
        count++;

    }
    p2->next = p;
    ListNode* temp2 = p3->next;
    p3->next = p2;
    temp->next = temp2;
    if (temp == head)
    {
        head = p3;
        return head;
    }
    parent->next = p3;

    return head;

}
int main()
{
	return 0;
}