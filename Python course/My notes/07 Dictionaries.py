# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# Dictionary (also known as associative array).
# Stores a collection of key-value pairs.
# The keys are used to access the corresponding values.
# The keys have to be unique. We cannot have two of the same key in a dictionary.
# The keys have to be immutable objects like int, float, string, tuple.
# Values don't have to be unique and can be of any type.
# As of Python version 3.7, dictionaries are ordered. In Python 3.6 and earlier, dictionaries are unordered.
# When we say that dictionaries are ordered, it means that the items have a defined order, and that order will not change.
# Unordered means that the items do not have a defined order, you cannot refer to an item by using an index.
# Define a dictionary:
    d1 = { "key1" : 34, "key2" : 42, "key3" : {}, "key4" : (1, 2)}
    d2 = {}  # The empty dictionary.
# We can also use the 'dict()' constructor.
    d3 = dict(name = "Mike", age = 24, height = 179)  # {'name': 'Mike', 'age': 24, 'height': 179}
    dict()  # The empty dictionary.
# Access a value by key.
    d1["key1"]  # 34
    d1["key4"]  # (1, 2)
# Dictionaries are mutable so we can change, delete and add elements.
    d1["key1"] = 88         # Change the value of an element.
    del(d1["key1"])         # Delete an element.
    del(d1["asdf"])         # Error, no such key in the dictionary.
    d1["new_key"] = "fdsa"  # Add new element.
    
# Functions.
    d1.keys()     # Get the keys of a dictionary. Returns an object of type dict_keys.
    d1.values()   # Get the values of a dictionary. Returns an object of type dict_values.
    "key1" in d1  # Check if a key is from the dictionary. Returns True or False.

    len(d)     # How many elements in the dictionary.
    sorted(d)  # Returns a sorted list of the keys.
    
# Note: there is such fancy thing called dictionary comprehension. I should learn it and write it here.
# I think it is similar in idea to Haskell's list comprehension.