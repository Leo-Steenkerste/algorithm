using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head);

// O(n) time | O(1) space - where n is the number of the nodes in the Linked list 
bool linkedListPalindrome(LinkedList *head) {
  LinkedList *slowNode = head;
  LinkedList *fastNode = head;
  while (fastNode != NULL && fastNode->next != NULL) {
  	slowNode = slowNode->next;
  	fastNode = fastNode->next->next;
  }

  LinkedList *reversedSecondHalfNode = reverseLinkedList(slowNode);
  LinkedList *firstHalfNode = head;

  while (reversedSecondHalfNode != NULL) {
  	if (reversedSecondHalfNode->value != firstHalfNode->value) {
  		return false;
  	}
  	reversedSecondHalfNode = reversedSecondHalfNode->next;
  	firstHalfNode = firstHalfNode->next;
  }
  return true;
}

LinkedList *reverseLinkedList(LinkedList *head) {
	LinkedList *previousNode = NULL;
	LinkedList *currentNode = head;
	while (currentNode != NULL) {
		LinkedList *nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	return previousNode;
}