# Lab 9: Huffman Coding #
This lab covers huffman coding and how to use it. For this assignment you will be creating a compression tool that takes in a text file and compresses losslessly. In order for this algorithm to work, you will need to use a special tree called a huffman tree. The creation of this tree requires the use of a priority queue as well as several other data structures.

### Lab Instructions ###
You will need to implement several classes to get this to work. The first thing you should work on is `node.h`. Inside of there you will find a constructor that isn't implemented. 
Implement that and verify it works using the tests provided.

Next you will need to implement the functions found in `huffman_tree.cpp`. The first function you should work on is `insert(char input)`. This function takes a character from the text file and inserts it into a priority queue based on the frequency of that character. Every time you insert something into the queue, you **must** update the queue so that that the items are in order. The lowest frequency item needs to be located at `head` and the highest frequency located at `tail`. The queue only cares about frequency.

Once you have parsed through the input string and created a priority queue based on the frequency, you need to implement the `remove()` function. This function takes a node off of the head and returns it to the caller. Fairly simple to accomplish. Refer to `pop()` and `top()` from previous labs;

Now that you can remove a node from the priority queue, we need to start building the tree. This is done *using* the priorty queue. Take the two lowest frequency nodes, using `remove()` and combined them using that `node` constructor you wrote. Now put that new node back into the queue using the `insert(node*)` function. You  will need to implement this function. It works exaclty like the other insert function, but with a node rather than a character. Remember, every node is a tree with depth 0. Think of your priority queue as a queue of trees.

You will do this process of removing two nodes, creating a new node with them as the children, putting that node back into the tree until there is only one node left. When that happens, your tree is almost done being constructructed. Remove that last node and set it to root. You now have a huffman tree.

With this huffman tree, you will need to generate a dictionary for each of the character values. Implement all of the functions found in `huffman_dictionoary` and verify that they work with the tests. You are now almost ready to start compressing text files. Go through the `huffman.cpp` file and write all of the small pieces of code required to get the algorithm to work. And you should be good to go. 
### Hints ###
* You cannot access the parent from a child. It is a one way connection.
* If you are trying to insert a value into a node that already exists, you need to increment the frequency of that value when you find it.
* [Explanation of Huffman Coding and Lossless Text Compression](https://www.youtube.com/watch?v=JsTptu56GM8)
* [Huffman Coding Wikipedia Page](https://en.wikipedia.org/wiki/Huffman_coding)
* [Youtube search for huffman coding](https://www.youtube.com/results?search_query=huffman+coding)