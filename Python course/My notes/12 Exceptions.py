# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.


# For more info check our the built-in exceptions: https://docs.python.org/3/library/exceptions.html

# Let's look at the example:
try:
    a = int(input("Enter numerator: "))
    b = int(input("Enter denominator: "))
    res = a / b 
    print(f"The result is: {res}")
except ZeroDivisionError:
    print("The denominator cannot be zero.")
except ValueError:
    print("You must enter a number.")
except:
    print("Unknown error.")   

# 01. In the try block we execute the code which might throw an exception.
# 02. We can test for specific exceptions like 'ZeroDivisionError' or 'ValueError'.
# 03. We can test for more than one exception in given except block like this:
#     'except (<exc_name_1>, <exc_name_2>, ... , <exc_name_n>):'.
# 04. We can catch any exception with just 'except:'
# 05. Optionally we can use 'else' and 'finally'.
#     'else' executes only if there was no exception.
#     'finally' executes regardless of whether there was an exception or not.
# 06. We throw an exception with 'raise Exception("some text for the error")'.

# Example with 'else' and 'finally':
try:
    raise NameError
    print("This will not get printed.")
except NameError:
    print("Caught a NameError!")
except:
    print("Unknown error!")
else:
    print("This will not get printed.")
finally:
    print("This will get printed.")