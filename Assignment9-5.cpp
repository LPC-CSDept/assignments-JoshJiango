#include<iostream>

using namespace std;

struct Node
{
  int num;
  struct Node* next;
};

const int N=5;
Node *setValue(Node *);
void printValue(Node *);

int main()
{
  Node *head;

  head = nullptr;

  head = setValue(head);
  printValue(head);
}

Node *setValue(Node *head)
{
  for(int i=0; i<N; i++)
  {
    Node *new_node, *ptr, *prev;

    new_node = new Node;
    cout << "Enter your num: ";
    cin >> new_node->num;
    new_node->next = nullptr;

    if(head == nullptr)
    {
      head = new_node;
    }
    else
    {
      prev = nullptr;
      ptr = head;
      while(ptr != nullptr)
      {
        if(new_node->num < ptr->num)
        {
          break;
        }
        else
        {
          prev = ptr;
          ptr = ptr->next;
        }
      }
    
      if(prev == nullptr)
      {
        new_node->next = head;
        head = new_node;
        //head = new_node; // same as the code above line 59-60
        //new_node->next = ptr; // same as the code above line 59-60
      }
      else
      {
        new_node->next = ptr; // prev->next same as ptr 
        prev->next = new_node;
      }
    }
  }
  return head;
}

void printValue(Node *head)
{
  cout << "--------------------\n";
  Node* ptr;
  int i=1;
  ptr = head;
  while(ptr != nullptr)
  {
    cout << i++ <<  " node's value: " << ptr -> num << endl;
    ptr = ptr -> next;
  }
}