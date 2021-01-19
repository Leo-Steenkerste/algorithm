using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

// O(n) time | O(1) space - where n is the number of nodes in the linked list
LinkedList *shiftLinkedList(LinkedList *head, int k) {
  int listLength = 1;
  LinkedList *listTail = head;
  while (listTail->next != NULL) {
  	listTail = listTail->next;
  	listLength++;
  }
  int offset = abs(k) % listLength;
  if (offset == 0) {
  	return head;
  }
  int newTailPosition = k > 0 ? listLength - offset : offset;
  LinkedList *newTail = head;
  for (int i = 1; i < newTailPosition; ++i) {
  	newTail = newTail->next;
  }

  LinkedList *newHead = newTail->next;
  newTail->next = NULL;
  listTail->next = head;
  return newHead;
}
