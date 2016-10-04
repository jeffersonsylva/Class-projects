#include <iostream>
#include <string> // need string for stoi.

using namespace std;

struct node {
  int key;
  node* next;

  node(int key_, node* next_) : key(key_), next(next_) {}

  ~node() {
    cout << "deleting node with key = " << key << endl;
    if(next) {
      delete next;    
    }
  }
};

// delete the second node.
void delete_second_node(node* cur_node) {
  if(!cur_node || !cur_node->next) return;

  // does the second cur_node have a neighbour?
  if(cur_node->next->next) {
    // this is all that is needed to capture the second cur_node's
    // neighbour as a pointer.  cur_node->next->next is the value
    // *(cur_node->next).next, which is a pointer to a cur_node,
    // contrary to what I said in the tutorial. I should have used the
    // definition of -> operator, ie. a->b desugars to (*a).b, a
    // pointer indirection followed by a member access on the
    // indirected-to object.
    node* temp = cur_node->next->next;
    cur_node->next->next = 0;
    delete cur_node->next;
    cur_node->next = temp;
  } else { // the second cur_node has no neighbour.
    delete cur_node->next; // delete the object at address cur_node->next.
    cur_node->next = 0; // now set cur_node's next pointer to 0.
  }
}

node* add_node_to_head(node* cur_node, int key)
{
  node* new_node = new node(key, cur_node);
  return new_node;
}

void print_list_contents(node* cur_node)
{
  for(; cur_node; cur_node = cur_node->next)
    cout << cur_node->key << " ";

  cout << endl;
}

void add_node_to_tail(node*& cur_node, int key)
{
  if(!cur_node) {
    cur_node = new node(key, 0);
    return;
  }

  // navigate to the tail.
  node *tail;
  // we can write the usual while loop setup a bit
  // more compactly using the fact that a for
  // loop (really, any c++ loop) may have an empty body.
  for(tail = cur_node; tail->next; tail = tail->next) ;;  
  tail->next = new node(key, 0);  
}

int count(node* cur_node)
{
  if(!cur_node) return 0;

  int c;
  for(c = 1; cur_node->next; c++, cur_node = cur_node->next) ;;

  return c;  
}

int main(int argc, char* argv[])
{
  // add_node_to_tail depends on the initial pointer being null.
  // if it is not null, expect weirdness to ensue.
  node* my_list = 0;
  
  // argv[0] == "linked_list", since that will be the program name;
  // if I run "linked_list 1 2 3 4 5", I will create a linked list containing
  // nodes with keys valued from 1 to 5, in ascending order. argc = 6,
  // in that case, since we have "linked_list" as the leading argument
  // followed by 5 key values.
  for(int i = 1; i < argc; i++) {
    cout << "argv[i] = " << argv[i] << endl;
    // stoi is a super convenient function that converts integral values
    // in strings to their proper integer representation. I've often
    // seen students roll their own version of stoi, but there's no need
    // to.
    add_node_to_tail(my_list, stoi(argv[i])); 
  }

  // do we have at least two nodes?
  if(argc >= 3) {
    delete_second_node(my_list);
    delete_second_node(my_list);
    print_list_contents(my_list);
  
    cout << "length of the list is : " << count(my_list) << endl;
  }

  delete my_list;
}
