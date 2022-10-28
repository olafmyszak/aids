#include <iostream>

struct Node
{
  unsigned short data;
  struct Node* next;
  struct Node* prev;
};

void insertEnd(struct Node** start, short value)
{
  if(*start == nullptr)
  {
	struct Node *new_node = new Node;
	new_node->data = value;
	new_node->next = new_node->prev = new_node;
	*start = new_node;
	return;
  }

  Node *last = (*start)->prev;

  struct Node* new_node = new Node;
  new_node->data = value;

  new_node->next = *start;
  (*start)->prev = new_node;

  new_node->prev = last;
  last->next = new_node;
}

void insertBegin(struct Node** start, short value)
{
  struct Node* last = (*start)->prev;

  struct Node* new_node = new Node;
  new_node->data = value;

  new_node->next = *start;
  new_node->prev = last;

  last->next = (*start)->prev = new_node;

  *start = new_node;
}

void insertBetween(struct Node** start, short insertedValue, short insertedAfterThisValue)
{
  struct Node *new_node = new Node;
  new_node->data = insertedValue;

  struct Node *temp = new Node;

  while(temp->data != insertedAfterThisValue)
  {
	temp = temp->next;
  }

  struct Node *next = temp->next;

}

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
