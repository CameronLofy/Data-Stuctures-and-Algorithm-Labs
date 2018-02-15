# Lab 3: Last In/First Out, First In/Last Out # 
**10 points**

**Due 20 February, 2018**

For this lab, you will be implementing both a *Last In/First Out* and *First In/First Out* data structures. These data structures store data in a way that allows you to only see one value from the structure. You can't see any other value in the structure unless it is the top value.
These structures are important because they allow us to add or remove data members to the structure in an O(1) complexity.

### Lab Instructions
Implement each of the functions to perform the necessary actions outlined in the `.h` files.

As you are writing your functions, read the instructions and think of how you would test that functions while you are writing it. Write your Test first and then implement your functions. Try running your test and then fixing your issues.  

`lifo_storage` and `fifo_storage` will both be statically sized, meaning that you don't need to worry about dynamically growing the stringVector. Treat it just like an array.
#### Fifo ####
**fifo()**: Default constructor. Set index properly and reserve 100 spaces in fifo_storage

**explicit fifo(std::string input_string)**: Constructor that does the same thing as the default constructor, but adds a single item to the Fifo

**fifo(const fifo &original)**: Copy constructor

**virtual ~fifo()**: Destructor

**fifo &operator=(const fifo &right)**: Assignment operator

**bool is_empty() const**: Return true if the fifo is empty and false if it is not

**unsigned size() const**: Return the size of the fifo

**std::string top() const**: Return the front string of the fifo.

**void enqueue(std::string input)**: Add input string to the back of the fifo

**void dequeue()**: Remove the front string from the fifo
#### Lifo ####
**lifo()**: Default constructor. Set index properly and reserve 100 spaces in fifo_storage

**explicit lifo(std::string input_string)**: Constructor that does the same thing as the default constructor, but adds a single item to the Fifo

**lifo(const lifo &original)**: Copy constructor

**virtual ~lifo()**: Destructor

**lifo &operator=(const lifo &right)**: Assignment operator

**bool is_empty() const**: Return true if the lifo is empty and false if it is not

**unsigned size() const**: Return the size of the lifo

**std::string top() const**: Return the top of the lifo.

**void push(std::string input)**: Add input string to the top of the string

**void pop()**: Remove the top string from the lifo


### Hints ###
- Wikipedia article on [Fifo](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)_)
- Wikipedia article on [Lifo](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- Some of these functions are basically the same. Don't rewrite or paste code, just call the function with the altered inputs.
- Keep track of your edge cases: empty, 1 item, 2 items
