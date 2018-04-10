# Lab 6: Linked List #
**10 points**

**Due 13 March, 2018**

This assignment you will be implementing a fancy linked list, called a doubly linked list. The only difference between this linked list, and the linked list that you created last lab is that the nodes have pointers to both *next* and *prev*. This means that you can now traverse the list in either direction.

### Lab Instructions
Implement each of the functions to perform the necessary actions outlined in the `.h` files or here.

You will implementing some supplementary functions for this class that will help you manipulate this linked list in interesting ways.

Implement the linked list and test the functionality of it using tests. Remember, you need to implement all of the functions supported by the class, including the `sort` function.

As you are writing your functions, read the instructions and think of how you would test that functions while you are writing it. Write your Test first and then implement your functions. Try running your test and then fixing your issues.  

`doubly_linked_list::sort()` will sort the items in a linked list using insertion sort. Refer to the wikipedia article on insertion sort for more information on how this sorting algorithm works. Remember, you will be implementing this in a linked list and not an array. Get creative, because the Wikipedia article talks specifically about performing this sort on an array. You will need to understand how to translate this algorithm to use a linked list instead.

You may need to create auxiliary functions to complete tasks, or to avoid copy and pasting repetitive code. Do not make these class functions. These should only appear in the .cpp file

Don't move **data** in the node from *private* to *public*. We placed this here deliberately. For all of the functions and classes, don't change anything.

### Lab Functions that you haven't seen before
`void swap(unsigned position_1, unsigned position_2)`: Swap the node located at position 1 with the node located at position 2.
 
`void swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start, unsigned location_2_end)`: Swap the subset of nodes starting at position_1_start and ending at position_1_end with the nodes starting at position_2_start to position_2_end. These locations are **inclusive.**

`doubly_linked_list doubly_linked_list::split(unsigned position)`: Split the doubly linked list at position, with position being the priority_head of the second linked list. Truncate the original linked list and return the split off linked list.

`void doubly_linked_list::insert(int input, unsigned int location = 0)`: This inserts a node *at* the location provided. Note that if you don't give it a location to insert the node, it will insert it at the beginning of the linked_list.

`doubly_linked_list operator+(const doubly_linked_list &rhs) const`: Append the right doubly linked list to the right doubly linked list and return that new doubly linked list object.

`doubly_linked_list& operator=(const doubly_linked_list &rhs)`: Copy the right doubly linked list into left doubly linked list

`doubly_linked_list& operator+=(const doubly_linked_list &rhs)`: Append an entire doubly linked list to the end of an existing doubly linked list

`bool operator==(const doubly_linked_list &rhs)`: Checks to see if two doubly linked lists have the same values in the same positions. 

Ask questions on slack about functions that you don't understand. For the most part, this lab is a rehash of your previous labs but with a new data structure.

### Hints ###
- Wikipedia article on [Linked list](https://en.wikipedia.org/wiki/Linked_list)
- Wikipedia article on [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
- Some of these functions are basically the same. Don't rewrite or paste code, just call the function with the altered inputs.
- Keep track of your edge cases: empty, 1 item, 2+ items
- You need to update 3 nodes every time you insert or remove: the previous node, the selected node, and the next node.