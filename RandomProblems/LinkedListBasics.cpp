#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;
    ListNode()
    {
        value = 0;
        next = nullptr;
    }
    ListNode(int val, ListNode *ptr)
    {
        this->value = val;
        this->next = ptr;
    }
};

ListNode *reverseLinkedListIteratively(ListNode *head)
{
    // Iteratively
    ListNode *prevptr = nullptr;
    ListNode *currptr = head;
    ListNode *nextptr = nullptr;
    while (currptr != nullptr)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

ListNode *reverseLinkedListRecursively(ListNode *prev, ListNode *curr)
{
    if (curr == nullptr)
        return prev;
    ListNode *next = curr->next;
    curr->next = prev;
    reverseLinkedListRecursively(curr, next);
}


ListNode* reverseHead; 
void reverseLinkedListRecursively2(ListNode *prev, ListNode *curr) {
    if(curr != nullptr) {
        reverseLinkedListRecursively2(curr, curr->next);
        curr->next = prev;
        return;

    } else {
        reverseHead = prev;
        return;
    }
}


int main()
{
    ListNode *head = new ListNode();
    ListNode *itr = head;
    vector<int> nums = {1, 2, 3, 4};
    for (int num : nums)
    {
        ListNode *temp = new ListNode(num, nullptr);
        itr->next = temp;
        itr = temp;
    }

    // itr = reverseLinkedListIteratively(head);
    // itr = reverseLinkedListRecursively(nullptr, head);

    reverseLinkedListRecursively2(nullptr, head);
    itr = reverseHead;

    while (itr)
    {
        cout << itr->value << " ";
        itr = itr->next;
    }

    return 0;
}
