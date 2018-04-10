# Lab 7: Binary Search Trees #
For this lab, you will be implementing a Binary Search Tree to store integers and do various operations on the tree.

A tree is a data structure very similar to a doubly linked list, but instead of linking back and forth, the node pointers point to nodes one layer deeper. The way data is input into the tree also sorts the data by design. 

### Lab Instructions ###
You will be writing all of the code for the implementation of a tree. You can use any helper functions you would like, but all of the functions that are provided to you need to do the functions that are commented above them. 

Every function than can be implemented with recursion, needs to be implemented with it. Check out the example recursive function `print_gtl()` for an idea of how to accomplish this. Take note of the auxilary functions 

The following functions need to be implemented recursively

- `tree(const tree& copy)`

- `~tree()`

- `void insert(int value)`

- `bool in_tree(int key)` 

- `int get_frequency(int key)`

- `int level(int key)`

- `void path_to(int key)`

- `unsigned depth()`

- `std::string to_string()`

- `void print()`

- `tree& operator=(const tree &rhs)`

- `friend std::ostream& operator<<(std::ostream& stream, tree& RHS)`

- `tree operator+(const tree &rhs) const`

- `std::vector<int> values_above(int key)`


### Hints ###
- `left` children of a parent are **ALWAYS** less than the parent 
- `right` children of a a parent are **ALWAYS** greater than the parent
- You cannot access the parent from a child. It is a one way connection.
- If you are trying to insert a value into a node that already exists, you need to increment the frequency of that value when you find it.
- You will be writing a lot of auxiliary functions.
- Wikipedia article on [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- Article talking about several different [balancing techniques](https://web.eecs.umich.edu/~qstout/pap/CACM86.pdf)
