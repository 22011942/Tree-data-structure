#include <iostream>
using namespace std;

class Tree {
private:
  char data;
  Tree *leftptr, *rightptr;
public:
  Tree(char value, Tree *L, Tree *R);
  ~Tree() {}
  char RootData() {return data;}
  Tree *Left() {return leftptr;}
  Tree *Right() {return rightptr;}

};

struct Node {
  Tree* data;
  Node *next;
};

class Stack {
private:
  Node *listpointer;
public:
  Stack();
  ~Stack();
  void Push(Tree* value);
  void Pop();
  Tree* Top();
  bool isEmpty();
};

void inOrder(Tree *T);


int main() {
  string line;
  char uncheckedValue;
  int indx;
  getline(cin, line);
  Stack s;
  Tree *T1, *T2, *T;
  for (indx = 0; indx < (int) line.length(); indx++) {
    uncheckedValue = line[indx];
    if (uncheckedValue >= '0' && uncheckedValue <= '9' ) {
      s.Push(new Tree(uncheckedValue, NULL, NULL));
    } else if (uncheckedValue >= '*' && uncheckedValue <= '/' ){
      T1 = s.Top();
      s.Pop();
      T2 = s.Top();
      s.Pop();
      s.Push(new Tree(uncheckedValue, T2, T1));
    }
  }
  T = s.Top();
  inOrder(T);
}

Tree::Tree(char value, Tree *L, Tree *R) {
  data = value;
  leftptr = L;
  rightptr = R;
}

void inOrder(Tree *T) {
if (T == NULL) { return; }
  if (T -> Left() != NULL && T -> Right() != NULL) {
    cout << "(";
  }
  inOrder(T -> Left());
  printf("%c", T-> RootData());
  inOrder(T -> Right());
  if (T -> Left() != NULL && T -> Right() != NULL) {
    cout << ")";
  }
}

Stack::Stack() {
  listpointer = NULL;
}

Stack::~Stack() {
}

void Stack::Push(Tree* value) {
  Node *temp;
  temp = new Node;
  temp -> data = value;
  temp -> next = listpointer;
  listpointer = temp;
}

void Stack::Pop() {
  Node *temp;
  temp = listpointer;
  if (listpointer != NULL) {
    listpointer = listpointer -> next;
    delete temp;
  }
}

Tree* Stack::Top() {
  return listpointer -> data;
}

bool Stack::isEmpty() {
  if (listpointer == NULL) {
    return true;
  }
  return false;
}
