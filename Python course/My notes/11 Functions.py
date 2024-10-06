# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.


# -------------------- Functions -------------------- #

# A function is defined as follows:
def function_name(param1, param2, param3):
    """
    This is my first function. It just adds the 3 parameters.
    """
    res = param1 + param2 + param3
    return res
# We have the key word 'def' followed by a function name and list of zero or more parameters.
# We can optionally place documentation of the function in triple quotes before the body of the function.
# In the Python interpreter we can write 'help(function_name)' and get the documentation printed.
# 'return' exits the function and returns the result. If no returns is specified the function returns the object
# 'None'. 'None' is basically like null - indicates a lack of value. This means that every function in Python returns
# a value.

# Calling a function:
function_name(1, 2, 3)

# The same function can be used for different data types (if the operations used are defined on those data types).
# We can use the above function to concatenate strings.
function_name("My ", "first ", "string.") 

# Variables inside the function are not visible from the outside.
x = 4            # Defined in the global scope.
def foo():
    y = 3        # Local scope.
    print(x, y)  # No problem.
foo()
# print(y)  # Error! y is not defined.

# Default argument values.
def foo(p1=3, p2=0):
    if p2 == 0:
        return 'yes'
    elif p1 == 3:
        return 'no'
    else:
        return "don't know" 
        
print(foo())        # 'yes'
print(foo(24))      # 'yes'
print(foo(p2=-1))   # 'no'. We can specify which parameter.
print(foo(-2, -2))  # "don't know"

# The key word 'pass'. In Python a function cannot have an empty body so if we are in the process of writing code we
# can write 'pass' as the function body, so that the program compiles successfully. This compiles and returns None.
def foo(a, b, c):
    pass
print(foo(1, 2, 3))
        

# -------------------- Common built-in functions -------------------- #

# sum(iterable, start=0)
# Returns the sum of the numbers in 'iterable' plus 'start'. 'start' is optional and is 0 if not specified.
# If 'iterable' is empty, then returns 'start'.
sum([1, 2, 3], 4)  # 10

# len()
# Returns the number of elements in a sequence or a collection.
len({'k1' : 1, 'k2' : 2})  # 2


# -------------------- Variadic function -------------------- #

# A variadic function is a function of indefinite arity, i.e., one which accepts a variable number of arguments.
# In a variadic function, extra arguments are collected in a tuple that we write as *<arg_name> in the argument list.
# Appends 'value' to all the given lists.
def append_many(value, *lists):
  for l in lists:
    l.append(value)
list_1 = [1, 2]
list_2 = [3, 4]
append_many(5, list_1, list_2)  # list_1 == [1, 2, 5], list_2 == [3, 4, 5]
# Notes:
#   01. We could have written the variadic argument '*lists' before 'value' like this: 'append_many(*lists, value)' but
#       I thinks it is better not to because to call the function we have to write:
#           'append_many(l1, l2,..., ln, value=<some_value>)'
#       and it becomes less readable.
#   02. I think we cannot have two or more variadic arguments, for example: 'foo(*args1, *args2)'.

# Functions can also accept an arbitrary number of keyword arguments ("variadic kwargs") using a ** instead of a
# single *. 'kwargs' is a dictionary where the keys are the argument names and the values are the arguments passed.
# The next function calculates the lengths of many lists. We pass the lists in as kwargs, then get a dictionary back
# that maps the 'kwargs' names to the lists' lengths.
def list_lengths(**kwargs):
  return {key: len(values)
          for (key, values) in kwargs.items()}  # This is dictionary comprehension (don't worry about the details).
list_lengths(a=[1, 2, 3], b=[4, 5])             # Result: {'a': 3, 'b': 2}

# We can have both *args and **dict_args. The *args in the function parameter list has to be before **dict_args.
def my_sum(a, *nums, **dict_nums):
    """
    This function just sums all its inputs.
    """
    return a + sum(nums) + sum(dict_nums.values())
print(my_sum(1, 2, 3, 4, n=5, m=6))  # 21