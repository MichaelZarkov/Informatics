# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be 
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# Python is an interpreted language. It evaluates a file from top to bottom. When it encounters a problem it throws an error.
    print("Hello, world!")  # This will be printed.
    frint("Hello, world!")  # This will throw and error because "frint" is not defined and execution will be stopped.
    print("Hello, world!")  # This will not execute.
    
# Basic types: int, float, str, bool.
    11             # Integer.
    2.16           # Floating point number.
    "Hello hello"  # String.
    'Hello hello'  # It doesn't matter if we use single or double quotes.
    True           # Boolean
    False          # Boolean
    
    # type(<exp>) - returns the type of the expression.
    type(2)        # Returns "int".
    type(2.0)      # "float"
    type('mystr')  # "str"
    type(True)     # "bool"
    
    # Conversion functions: float(<exp>), int(<exp>), str(<exp>), bool(<exp>).
    type(float(2))  # Returns "float"
    float("2.89")   # Result 2.89
    int("12mmm")    # Throws an error. The string is not a valid representation of a number.
    int(2.99)       # Result 2. Gets rounded to the whole part of the real number.
    bool(0)         # Returns False.
                    # If the expression is a number if it is 0 then it is converted to False. If it is not 0 then
                    # it is converted to True.
    bool("")        # Result False. Only the empty sting is converted to False.
    bool("mystr")   # True
    
# Operators:
    # The usual arithmetic operators: +, -, *, /, //, **. Order of the operation is the usual.
    type(6/4)   # Result "float. This is floating point division.
    type(6//4)  # Result "int". Whole number division.
    5**4        # Result 625. Exponentiation. The result can be float or int.
    
    # Concatenation: +
    "hello " + "world"  # "hello world"
    
    # Comparison: ==
    "hello" == 'hello'  # True
    
# Variables:
    x = 3    # x is of type int and has a value 3
    y = 3.0  # y is of type float and has a value 3.0
    z = x    # z is int and has value 3
    
    # We can delete variables with 'del'.
    var1 = 3
    print(var1)   # No problem.
    del var1
    #print(var1)  # Error: name 'var1' is not defined.