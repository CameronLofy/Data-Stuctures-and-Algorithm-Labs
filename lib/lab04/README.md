# Lab 4: Simple Calculator #
**10 points**

**Due 27 February, 2018**

This lab will take all of the work you have previous done and connect it together to make a calculator. You will be using the expresssionStream from Lab 1 to parse an input expression and calculate that expressoin. You will be implementing the Shunting yard algorithm to perform your calculation. This algorithm uses both Last In/First out (Stack) and First In/First Out (queue) to accomplish the calculation. This means that in order to get your calculator working, you need to have lab 2 and lab 3 working properly.

### Lab Instructions
Implement each of the functions to perform the necessary actions outlined in the `.h` files.

As you are writing your functions, read the instructions and think of how you would test that functions while you are writing it. Write your Test first and then implement your functions. Try running your test and then fixing your issues.  

You only need to support integer calculations. If you feel like supporting floating point calculations, you might need to change the way expressionStream works. You will also need to write a new calculate function that returns a float rather than an integer. 

You may need to create auxiliary functions to complete tasks, or to avoid copy and pasting repetitive code. Do not make these class functions. These should only appear in the .cpp file

### Hints ###
- Wikipedia article on [Shunting-yard Algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm)
- Wikipedia article on [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- Wikipedia article on [Fifo](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)_)
- Wikipedia article on [Lifo](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- Some of these functions are basically the same. Don't rewrite or paste code, just call the function with the altered inputs.
- Keep track of your edge cases: empty, 1 item, 2 items
