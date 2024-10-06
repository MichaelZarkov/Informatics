# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# Comparison operators: ==, !=, <, >, <=, >=. Can be used to compare strings and numbers. Strings are compared
# lexicographically.

# Logical operators: and, or, not.

# If statement. The indentation is mandatory:
age = 18
if age >= 21:
    print("You can drink.")
else:                          # The else statement is optional.
    print("You can't drink.")
print("You can play.")         # Outside the if statement.

# Else if:
if age >= 21:
    print("You can drink and you can vote.")
elif age >= 18:
    print("You can only vote.")
else:
    print("You can't drink or vote.")
    
# Example:
myString = ""    
if not myString:    # The empty string is converted to False.
    print("You gave me an empty string.")
    
# Example:
age = 37
if 30 <= age and age < 40:
    print("You are in your thirties.")
    
# Note that variables inside if statements are also visible from the outside.
if True:
    s = 8
print(s)  # Prints 8