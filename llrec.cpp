#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void truellpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
Node*& headCopy = head;
truellpivot(head, smaller, larger, pivot);
headCopy = nullptr;
}

void truellpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) 
{
	if (head == nullptr) {
		smaller = nullptr;
		larger = nullptr;
		return;
	}
	else {
		if (head->val <= pivot) {
			smaller = head;
			smaller->val = head->val;
			truellpivot (head->next, smaller->next, larger, pivot);
		}
		else {
			larger = head;
			larger->val = head->val;
			truellpivot (head->next, smaller, larger->next, pivot);
		}
	}
}

