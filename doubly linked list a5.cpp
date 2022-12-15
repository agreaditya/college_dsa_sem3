//Aditya Agre
//SYCOA06
//Doubly linked list

#include <iostream>
using namespace std;
struct node
{				//structure to create a format to save data
  int data;
  node *next;
  node *prev;			//declaring two pointers next and prev to traverse through data
};
class Doublylinkedlist
{
private:
  node * header = NULL;		//making header null

public:
  void InsertatBeginning ();
  void InsertatPosition ();
  void InsertatEnd ();
  void Display ();
  void DeletetheFirst ();
  void DeleteatPosition ();
  void DeletetheLast ();
};
void
Doublylinkedlist::InsertatBeginning ()
{				//function to add element in beginning
  int n;
  node *newnode;
  newnode = new node;
  cout << "ENTER THE DATA" << endl;
  cin >> n;
  newnode->data = n;
  newnode->next = header;
  newnode->prev = NULL;
  if (header != NULL)
    {
      header->prev = newnode;
    }
  header = newnode;
}

void
Doublylinkedlist::InsertatPosition ()
{				//function to add element at position
  int n, position;
  node *newnode;
  newnode = new node;
  cout << "ENTER THE DATA TO BE INSERTED AT POSITION" << endl;
  cin >> n;
  newnode->data = n;
  newnode->next = NULL;
  newnode->prev = NULL;
  if (position < 1)
    {
      cout << "POSITION SHOULD BE GREATER THAN 1" << endl;
    }
  else if (position == 1)
    {
      newnode->next = header;
      header->prev = newnode;
      header = newnode;
    }
  else
    {
      node *temp = header;
      for (int i = 1; i < position - 1; i++)
	{
	  if (temp != NULL)
	    {
	      temp = temp->next;
	    }
	}
    }
  node *temp = header;
  if (temp != NULL)
    {
      newnode->next = temp->next;
      newnode->prev = temp;
      temp->next = newnode;
      if (newnode->next != NULL)
	{
	  newnode->next->prev = newnode;
	}
      else
	{
	  cout << "\nThe previous node is null.";
	}
    }
}

void
Doublylinkedlist::InsertatEnd ()
{				//function to add element at the end
  int n;
  cout << "ENTER THE ELEMENT" << endl;
  cin >> n;
  node *newnode = newnode;
  newnode = new node;
  newnode->data = n;
  newnode->next = NULL;
  newnode->prev = NULL;
  if (header == NULL)
    {
      header = newnode;
    }
  else
    {
      node *temp = header;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = newnode;
      newnode->prev = temp;
    }
}

void
Doublylinkedlist::DeletetheFirst ()
{				//function to delete element at start
  int n, ptr;
  node *newnode = newnode;
  cout << "ENTER THE ELEMENT TO DELETE" << endl;
  cin >> n;
  newnode->data = n;
  if (header == NULL)
    {
      cout << "DELETION NOT POSSIBLE AS NO DATA" << endl;
    }
  else
    {
      newnode = header;
      header = header->next;
      header->prev = NULL;
      delete (newnode);
    }
}

void
Doublylinkedlist::DeleteatPosition ()
{
}

void
Doublylinkedlist::DeletetheLast ()
{				//function to delete last element
  node *ptr;
  if (header == NULL)
    {
      cout << "UNDERFLOW" << endl;
    }
  else if (header->next == NULL)
    {
      header = NULL;
      delete (header);
      cout << "Node Deleted Successfully" << endl;
    }
  else
    {
      ptr = header;
      if (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->prev->next = NULL;
      delete (ptr);
      cout << "Node Deleted Successfully!!" << endl;
    }
}

void
Doublylinkedlist::Display ()
{				//function to display
  node *ptr = header;
  while (ptr != NULL)
    {
      cout << ptr->data << "\t";
      ptr = ptr->next;
    }
  cout << "\n";
}

int
main ()
{
  int opt;
  Doublylinkedlist obj;
  do
    {

      cout << "1.INSERT AT BEGINNING" << endl;
      cout << "2.INSERT AT POSITION" << endl;
      cout << "3.INSERT AT END" << endl;
      cout << "4.DELETE AT BEGINNING" << endl;
      cout << "5.DELETE AT POSITION" << endl;
      cout << "6.DELETE AT END" << endl;
      cout << "7.DISPLAY DATA" << endl;
      cout << "0.EXIT" << endl;

      cin >> opt;
      switch (opt)
	{
	case 1:
	  obj.InsertatBeginning ();
	  break;
	case 2:
	  obj.InsertatPosition ();
	  break;
	case 3:
	  obj.InsertatEnd ();
	  break;
	case 4:
	  obj.DeletetheFirst ();
	  break;
	case 5:
	  obj.DeleteatPosition ();
	  break;
	case 6:
	  obj.DeletetheLast ();
	  break;
	case 7:
	  obj.Display ();
	  break;
	default:
	  cout << "ENTER VALID INPUT" << endl;
	  break;
	}
    }
  while (opt);
  return 0;
}



