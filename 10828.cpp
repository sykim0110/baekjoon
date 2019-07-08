#include <iostream>
#include <string>

using namespace std;

class Node {
public:
  int data;
  Node* next;
public:
  Node();
  Node(int data);
};

class Stack {
public:
  Node* head;
  int length;

public:
  Stack();
  void push(int data);
  int pop();
  int size();
  int empty();
  int top();
};

Node::Node() {
  next = NULL;
}

Node::Node(int data) {
  next = NULL;
  this->data = data;
}

Stack::Stack() {
  this->head = NULL;
  this->length = 0;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  newNode->next = this->head;
  this->head = newNode;
  (this->length)++;
}

int Stack::pop() {
  if(this->length == 0) {
    return -1;
  }
  else {
    int data = this->head->data;
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    (this->length)--;

    return data;
  }
}

int Stack::size() {
  return this->length;
}

int Stack::empty() {
  if(this->length == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int Stack::top() {
  if(this->length == 0) {
    return -1;
  }
  else {
    return this->head->data;
  }
}

int main() {
  string opcode;
  int numOpcode;
  int data;
  Stack s;
  //opcode가 몇 개인지 입력받음
  
  cin >> numOpcode;
  for(int i = 0; i < numOpcode ; ++i) {
    cin >> opcode;
    if(opcode == "push"){
      cin >> data;
      s.push(data);
    }
    else if(opcode == "pop") {
      cout << s.pop() << endl;
    }
    else if(opcode == "size"){
      cout << s.size() << endl;
    }
    else if(opcode == "empty") {
      cout << s.empty() << endl;
    }
    else if(opcode == "top") {
      cout << s.top() << endl;
    }
    else {
      cout << "INVALID" << endl;
    }
  }

  return 0;
}
