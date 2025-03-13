#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
  int val;
  ListNode *next;

  ListNode() {}

  ListNode(int val, ListNode *next) {
    this->val = val;
    this->next = next;
  }
};

void printAList(ListNode *itr) {
  while (itr) {
    cout << itr->val;
    if (itr->next)
      cout << " -----> ";
    itr = itr->next;
  }
  cout << endl;
}

void reverseLL(ListNode *head, ListNode *prev, ListNode *&reverseHead) {
  if (!head)
    return;
  if (!head->next)
    reverseHead = head;
  reverseLL(head->next, head, reverseHead);
  head->next = prev;
}

void reverseLLInBetweenTwoNodes(ListNode *start, ListNode *end,
                                ListNode *prev) {
  if (start == end) {
    start->next = prev;
    return;
  }
  reverseLLInBetweenTwoNodes(start->next, end, start);
  start->next = prev;
}

void reverseBetweenValues(ListNode *&head, int left, int right) {
  ListNode *dummy = new ListNode(0, head);
  ListNode *itr = head;
  ListNode *pItr = dummy;
  ListNode *leftPtr = NULL;
  ListNode *rightPtr = NULL;
  while (itr) {
    if (itr->val == left)
      leftPtr = pItr;
    if (itr->val == right)
      rightPtr = pItr;
    if (leftPtr && rightPtr)
      break;
    pItr = itr;
    itr = itr->next;
  }

  ListNode *reverseHead = rightPtr->next;
  ListNode *storingRightEnd = NULL;

  if (rightPtr->next->next)
    storingRightEnd = rightPtr->next->next;
  reverseLLInBetweenTwoNodes(leftPtr->next, rightPtr->next, storingRightEnd);
  leftPtr->next = reverseHead;
  return;
}

int main() {
  ListNode *head = new ListNode(1, NULL);
  ListNode *itr = head;
  for (int i = 2; i < 11; i++) {
    ListNode *temp = new ListNode(i, NULL);
    itr->next = temp;
    itr = itr->next;
  }

  cout << "Printing the original list" << endl;
  printAList(head);
  ListNode *reverseHead = NULL;
  reverseLL(head, NULL, reverseHead);
  cout << "Printing the reversed list" << endl;
  printAList(reverseHead);
  reverseLL(reverseHead, NULL, reverseHead);
  cout << "Printing the reversed reversed list" << endl;
  printAList(reverseHead);
  reverseBetweenValues(reverseHead, 2, 8);
  cout << "Printing the reversed list between 2, 8" << endl;
  printAList(reverseHead);
  return 0;
}
