using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList *previousNode = NULL;
  LinkedList *currentNode = head;
  while (currentNode != NULL ) {
  	LinkedList *nextNode = currentNode->next;
  	currentNode->next = previousNode;
  	previousNode = currentNode;
  	currentNode = nextNode;
  }
  return previousNode;
}
