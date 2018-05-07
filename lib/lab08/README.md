# Lab 8: Hashing and Sorting #
This lab focuses on two separate topics, the first being hashing and the second being sorting. Up until now, you have been doing exhaustive searching, where you have had to go to every item in your data structure in order to find something you were looking for. Well there is a better way to do random access. You can instead use a data structure called a hash table, that stores objects in an array, but places them in the array based on the output of a function. 

You will also be implementing two very important sorting functions this week. Bubble sort, insertion sort, and selection sort are not the most efficient sorting algorithm around, with all of those having a running time of n^2. We want something that goes quite a bit faster. Some very smart people decades ago found some great algorithms. You will be implementing two of them; quicksort and merge sort. Both of these will be using your `doubly_linked_list` from lab 6, so make sure that that is fully working.

### Lab Instructions ###

Implement the hash table using the three most common probing techniques: linear, quadratic, double. Use the two provided hashing functions `hash_1` and `hash_2`.

When the hash table gets more than 70% full, you will need to double the size of the hash table to help reduce the number of collisions that could occur. There are three common techniques of probing a hash table.
* *linear*: When a collision is found at `table[n%max_size]`, go to the array location `table[(n+attempt)%max_size]`, where `n` is the output of the `hash_1` function and attempt is the number of collisions encountered so far. Continue moving along the array cell by cell until the desired location is found.
* *quadratic*: When a collision is found at `table[n%max_size]`, go to the array location `table[(n + attempt^2)%max_size]`.
* *double*: When a collision is found at `table[n%max_size]`, go to the array location `table[(n+attempt*m)%max_size]`, where `m` is the output of the `hash_2` function.

Implement both merge sort and quicksort. Verify they sort. We will only provide basic tests. *You* must implement the sorts using their algorithms.

There are thousands of videos on YouTube that cover these topics in much more depth than we will have the opportunity during class. Use them for more help understanding the assignment. If you find one that helped you, post it in the Lab 8 channel on slack to help your fellow classmates out.

### Hash Table Information ###
* Wikipedia article on [Hash Function](https://en.wikipedia.org/wiki/Hash_function)
* Wikipedia article on [Hash Table](https://en.wikipedia.org/wiki/Hash_table)
* Youtube video on [Hash Table](https://www.youtube.com/watch?v=shs0KM3wKv8)

##### Function Explanation #####
* `hash_1(std::string)`: DJB2 String hashing algorithm
* `hash_2(std::string)`: BKDR String hashing algorithm
* `expand()`: Increases the size of the hash table when the hash table gets more than 70% full. New max size comes from PRIMES array.
* `hash_table(char)`: Constructor that takes in the type of probing to be used.
* `~hash_table()`: Deconstructor.
* `insert(std::string, int)`: Take in a key and it's value and insert them into the hash_table. Handle collisions in the way defined by the constructor that created the hash table. If the key already exists in the hash table, return false and do not insert or update the item.
* `get(std::string)`: Get the value associated with that key.
* `remove(std::string)`: Remove the key and value from the hash table
* `in_table(std::string)`: Checks to see if that key is in the hash table
* `update(std::string, int)`: Change the value associated with a key. If the value is not in the hash table, insert it.
* `to_string()`: Convert the hash table to a string for testing. Yay! No operator overloading!


### Quicksort Information ###
* Wikipedia article on [Quicksort](https://en.wikipedia.org/wiki/Quicksort)
* Youtube video on [Quick Sort](https://www.youtube.com/watch?v=SLauY6PpjW4)

### Merge Sort Information ###
* Wikipedia article on [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)
* Youtube explanation of [Merge sort](https://youtu.be/KF2j-9iSf4Q)
* Explanation of a [Hash function](http://www.partow.net/programming/hashfunctions/)