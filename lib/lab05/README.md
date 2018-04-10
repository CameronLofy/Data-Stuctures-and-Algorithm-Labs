# Lab 5: Linked List #
**10 points**

**Due 6 March, 2018**

This lab is a continuation of your previous 4 labs, but in this lab we will be swapping out the `stringVector` you wrote with a linked list. A linked list is a data structure that connects nodes together in a line, and the only way to  get to a particular node it to traverse down the line until you find it. Linked lists are useful because they allow us to insert or delete at certain places in O(1) time. 

Your First In/First Out(Queue) and Last In/First Out(Queue) can easily be rewritten to use a linked list. This form of stacks and queues is actually the more traditional way of implementing those data structures because linked list both allow for constant time access of the first element and removal of items, and that that you can have an infinite amount of items in the stack or queue. 
### Lab Instructions
Implement each of the functions to perform the necessary actions outlined in the `.h` files or here.

Implement the linked list and test the functionality of it using tests. Remember, you need to implement all of the functions supported by the class, including the `sort` function.

As you are writing your functions, read the instructions and think of how you would test that functions while you are writing it. Write your Test first and then implement your functions. Try running your test and then fixing your issues.  

`linked_list::sort()` will sort the items in a linked list using selection sort. Refer to the wikipedia article on selection sort for more information on how this sorting algorithm works. Remember, you wlll be implemnting this in a linked list and not an array. Get creative, because the wikipedia article talks specifically about performing this sort on an array. You will need to understand how to translate this algorithm to use a linked list instead.

For the calculator, you only need to support integer calculations. You need to support the operators `+ - * / ( ) ^ %`. **NOTE:** You are adding two new operations in this lab. The actual calculator will be almost exactly the same as your previous calculator. Just copy the contents of the `.h` and `.cpp` and change the namespace and the data structures used to hold the stacks and queues. You may need to change some of the way you accomplish some of the functions as well.

If you feel like supporting floating point calculations, you might need to change the way expressionStream works. You will also need to write a new calculate function that returns a float rather than an integer. 

You may need to create auxiliary functions to complete tasks, or to avoid copy and pasting repetitive code. Do not make these class functions. These should only appear in the .cpp file


### Lab Functions that you haven't seen before

`linked_list::insert(input, location = 0)`: create a node from the input string and put it into the linked list at the given location

`linked_list::append(input)`: create a new node and put it at the end/priority_tail of the linked list

`linked_list::remove(location = 0)`: Remove the node at the given location 

`linked_list::sort()`: Perform selection sort on the linked list

`linked_list::listSize()`: Note that you do **not** have a size variable in your linked list. You *MUST* count the nodes.

Ask questions on slack about functions that you don't understand. For the most part, this lab is a rehash of your previous labs but with a new data structure.

### Hints ###
- Wikipedia article on [Linked list](https://en.wikipedia.org/wiki/Linked_list)
- Wikipedia article on [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
- Wikipedia article on [Shunting-yard Algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm)
- Wikipedia article on [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- Wikipedia article on [Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)_)
- Wikipedia article on [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- Some of these functions are basically the same. Don't rewrite or paste code, just call the function with the altered inputs.
- Keep track of your edge cases: empty, 1 item, 2 item2
