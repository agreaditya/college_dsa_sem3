// Aditya Agre
// SYCOA06
// dsa assignment2 linked list

#include <iostream>
using namespace std;

struct node {
  int data;
  node *next; // this creates a pointer which has a data type of a struct pointer.
  // therefore, node*
};

int read_data() {
  int x;
  cout << "Pls enter data for node as integer" << endl;
  cin >> x;
  return x;
}

// The functions which change the header location
// have been given returntype as node pointer(node*)
node *insertion_in_beg(node *header) {

  node *newnode;
  newnode = new node;
  /*the new keyword creates a new variable and returns its address.
     thats why we are taking newnode as avariable which points to the newnode
     and isnt actually the newnode */
  int val;
  val = read_data();
  newnode->data = val;
  /*newnode is a pointer to structure. to acces its members we use ->
     but if u created a variable newnode where newnode stores the entire struct
     variable itself eg: node x1; x1.data=2; x1.next=NULL; node * header=&x1;

     here u use . operator to access the members */

  if (header == NULL) {
    header = newnode;

    newnode->next = NULL;

    

  } else {
    newnode->next = header;
    header = newnode;
  }
  return header;
}
void insert_at_posn(node *header) {
  node *newnode;
  newnode = new node;
  int val;
  val = read_data();
  newnode->data = val;

  if (header == NULL) {
    header = newnode;

    newnode->next = NULL;

    newnode = new node();

  }

  else {
    cout << "Pls enter value after which the new node should be added" << endl;
    int checkval;
    cin >> checkval;
    node *p;
    node *q;
    p = header;
    q = header->next;

    while (p->data != checkval) {
      p = q;
      q = q->next;
    }
    // if it is supposed to be added at the end
    if (p->next == NULL) {
      p->next = newnode;
      newnode->next = NULL;

    }
    // other conditions
    else {
      p->next = newnode;
      newnode->next = q;
    }
  }
}
void insert_at_end(node *header) {
  node *newnode;
  newnode = new node;
  int val;
  val = read_data();
  newnode->data = val;

  if (header == NULL) {
    header = newnode;

    newnode->next = NULL;

    

  } else {
    node *p;

    p = header;

    while (p->next != NULL) {
      p = p->next;
    }

    p->next = newnode;
    newnode->next = NULL;
  }
}
node *delete_first(node *header) {
  if (header == NULL) {
    cout << "No terms to be deleted." << endl;
  } else if (header->next == NULL) {
    node *temp;
    temp = header;
    header = NULL;
    delete (temp);
  } else {
    node *p;
    p = header;
    header = header->next;
    delete (p);
  }
  return header;
}
void delete_at_loc(node *header) {
  cout << "Pls enter the value you want to delete:" << endl;
  int val;
  cin >> val;
  node *p;
  node *q;
  p = header;
  q = p->next;

  if (p->data == val) {
    delete_first(header);

  } else {

    while (q->data != val) {
      p = p->next;
      q = q->next;
    }
    // if term to be deleted is at the end
    if (q->next == NULL) {
      p->next = NULL;
      delete (q);
    }

    // if term to be deleted is in the middle
    else {
      p->next = q->next;
      delete (q);
    }
  }
}
void delete_last(node *header) {
  node *p;
  node *q;

  p = header;
  q = p->next;
  while (q->next != NULL) {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  delete (q);
}
void display(node *header) {
  node *p;
  p = header;
  int i = 1;

  if (header == NULL) {
    cout << "No nodes in list." << endl;
  }

  else {
    cout << "\nNode number: " << i << "\t" << p->data << "\t" << endl;

    //(To print first term)

    while (p->next != NULL) {
      p = p->next;
      i++;
      // we are first incrementing then printing
      // if we do the opposite, the last term doesnt get printed
      cout << "\nNode number: " << i << "\t" << p->data << "\t"
           << endl;
    }
    cout << "\n";
  }
}

int main() {

  node *header = NULL;

  // menu

  int choice;

  do {
    cout << "To insertion_in_beg press 1\nTo insert_at_posn enter 2\nTo "
            "insert_at_end enter 3\nTo delete_first enter 4\nTo delete_at_loc "
            "enter 5\nTo delete_last enter 6\nTo display enter 7\nTo quit "
            "enter 0  "
         << endl;

    cin >> choice;

    switch (choice) {
    case 1:
      header = insertion_in_beg(header);
      break;

    case 2:
      insert_at_posn(header);
      break;

    case 3:
      insert_at_end(header);
      break;

    case 4:
      header = delete_first(header);
      break;

    case 5:
      delete_at_loc(header);
      break;

    case 6:
      delete_last(header);
      break;

    case 7:
      display(header);
      break;
    }

  } while (choice != 0);
}
