/// Aditya Agre
// DSA Assignment 1
// Roll no. A06
// Storing employee data in hash table
// Collision:Linear probing
// Searching data in hash table

#include <iomanip>
#include <iostream>
using namespace std;

class Employee {

private:
  long int empid;        // variables made private because
  string e_name, e_city; // only mem func are accessing them

public:
  Employee() { // default constructor
    empid = -1;
  }

  // Declaring member functions
  bool check();
  void storedata(long int emp_id);
  void showdata();
  bool find_store(long int new_hashkey, long int emp_id, int N);
  void search(long int new_hashkey, long int emp_id, int N,
              Employee Hash_table[], long int orig_hashkey);
};

// member functions:

// print data of given object
// this is a member function which displays data of associated //object
void Employee::showdata() {
  cout << "Name of employee is:      ";
  cout << e_name << endl;
  cout << "Employee id is:           ";
  cout << empid << endl;
  cout << "City:                     ";
  cout << e_city << endl;
}

// store data into given object
// this is used after determining the location to be saved at
// takes input from user and saves data into corresponding object //variables
void Employee::storedata(long int emp_id) {
  cout << "Enter name:     \t";
  string name, city;
  cin >> name;
  cout << "Enter city:     \t";
  cin >> city;

  empid = emp_id;
  e_name = name;
  e_city = city;
}

// check if given object is free
bool Employee::check() {
  if (empid == -1) {
    return true;
  } else {
    return false;
  }
}

// check if given object is free, and store data, else, check next
// this uses both the check and storedata func above
// uses recursion in case of collision
bool Employee::find_store(long int new_hashkey, long int emp_id, int N) {
  bool repeat;
  if (check()) {
    storedata(emp_id);
    repeat = false;
  } else {
    cout << "Collision\n";
    // new_hashkey=(new_hashkey+1)%N;  ///***

    // find_store(new_hashkey, emp_id, N);
    repeat = true;
  }
  return repeat;
}

// Search for given id in hash table
// start w hash key locatioon
// Collision: go to next loc(update new_hashkey)
// also, checking if record exists(therefore, passing orig hashkey //too)
// passing entire hash table bcoz we are using recursion
//(search calls itself on the next object)
// this cant be done w just a member func as it works w only one //object at
// once
void Employee::search(long int new_hashkey, long int emp_id, int N,
                      Employee Hash_table[], long int orig_hashkey) {

  if (empid == emp_id) {
    cout << "\nPosition in table:        ";
    cout << new_hashkey << endl;
    cout << "Employee id is:           ";
    cout << empid << endl;
    showdata();

  } else {

    // here, we dont do do new_hashkey+1
    // instead we do (new_hashkey+1)%N because it also covers the
    // case when we have to go from last key to first

    int check_index;
    if (orig_hashkey == 0) {
      check_index = N - 1;
    } else {
      check_index = (orig_hashkey + N - 1) % N;
    }

    if (new_hashkey != check_index) {
      new_hashkey = ((new_hashkey + 1) % N);

      Hash_table[new_hashkey].search(new_hashkey, emp_id, N, Hash_table,
                                     orig_hashkey);

    } else {
      cout << "\n**Record doesnt exist**\n";
    }
  }
}

// NON MEMBER FUNCTIONS:

// func to return hash key by inputting employee id and size
long int hash_func(long int emp_id, int N) {
  long int hash_key_orig;
  hash_key_orig = (emp_id) % N;
  return hash_key_orig;
}

// func to read employee id and return it
long int read_empid() {
  long int empid;
  cout << "\nEnter employee id ";
  cin >> empid;
  return empid;
}

int main() {
  int N;
  // N is number of employees.
  cout << "Enter number of employees:\t";
  cin >> N;

  // creating array of objects of class employee
  Employee Hash_table[N];

  // taking inputs for n users
  int i;
  long int emp_id, hash_key;
  for (i = 0; i < N; i++) {
    emp_id = read_empid();
    hash_key = hash_func(emp_id, N);
    // we now have the hash key for the given key

    bool repeat;
    repeat = Hash_table[hash_key].find_store(hash_key, emp_id, N);

    while (repeat) {
      hash_key = hash_func(hash_key + 1, N);
      repeat = Hash_table[hash_key].find_store(hash_key, emp_id, N);
    }
  }
  cout << "\nPrinting hash tables:";
  for (i = 0; i < N; i++) {

    cout << "\nPostion in table:         ";
    cout << i << endl;
    Hash_table[i].showdata();
  }

  long int id;
  bool keep_going = true;
  while (keep_going == 1) {
    cout << "\nSearch:\nPls enter the employee id you are looking for\n";
    cin >> id;
    hash_key = hash_func(id, N);

    Hash_table[hash_key].search(hash_key, id, N, Hash_table, hash_key);
    cout << "\nDo you want to search for more employees?\nTo search for more, "
            "enter 1\nTo quit, enter 0\n";
    cin >> keep_going;
  }
}
