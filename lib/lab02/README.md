#LAB 02- String Vector

**Any program that do not compile will receive a zero**

**Any program that attempts to use std library Vectors will receive a zero**

For this lab you will be creating a auto-expanding dynamic-array. This array will explicitly hold std library strings.
As with all labs you can create any PRIVATE data members/ methods you want, but the Public interface should remain the same.
While tests will be provided, you will need to add your own test cases to ensure all corner cases are accounted for and avoided.
This class will be used for future labs so it is important that it is tested thouroughly.

**The following provides the expected behavior of the private data members and the public interface/API:**

*private:*
    
**std::string * data** - pointer to the string data

**unsigned length** - Current number of strings stored in array

**unsigned allocated_length** - Current number of strings allocated to be held in the array

*public:*

**stringVector()** - Constructor, should construct an empty object

**virtual ~stringVector()**- Destructor, should deallocate all memory used by object (NO MEMORY LEAKS)

**unsigned size()**-return the number of strings stored in array

**unsigned capacity()** -return number of strings currently allocated to be stored in array

**void reserve()** - Allows user to choose the allocation size, if it is small than current array then data should be truncated to fit

**bool empty()** - returns true IFF the array is empty

**void append(std::string data)** - append data to end of array, if capacity is zero set it to 1, otherwise double array capacity if this is over capacity

**void swap(unsigned pos1, unsigned pos2)** - swap the string in position1 (pos1) of the array with the string in position2, throw an exception if either position is out of bounds

**stringVector &operator = (stringVector &rhs)** - Copies RHS to object calling the function (this should be a hard COPY, creating a separate object with same values)

**std::string& operator\[ \](unsigned position)** -return a reference to the string at this position, throw an exception if out of bounds

**void sort()** - use the bubble sort function discussed in lab to sort the vector like a dictionary (lower letters and less letters first)