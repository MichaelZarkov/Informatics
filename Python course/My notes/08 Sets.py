# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# Sets are unordered collections of unique elements. Elements can be of any type.
    s1 = {"mike", 1, 3, "mike", 3, 4}  # Assigns the set {1, 3, 4, 'mike'} to s1. Notice the secondary occurrences of
                                       # elements were automatically removed.
    set([1, 1, 3, 3])      # {1, 3}. set(iterable) - makes a set from an iterable object.
    s1.add("new_element")  # Add an element.
    s1.add("new_element")  # If we do it twice, noting more happens.
    s1.remove("mike")      # Remove an element.
    "mike" in s1           # Check if an element is in a set.
    
# Union, intersection, difference, symmetric difference, issubset, issuperset.
    s1 = {1, 2, 3, 4}; s2 = {3, 4, 5}; s3 = {1, 2}
    s1.union(s2)                 # {1, 2, 3, 4, 5}
    s1.intersection(s2)          # {3, 4}
    s1.difference(s2)            # {1, 2}
    s1.symmetric_difference(s2)  # {1, 2, 5}
    s3.issubset(s1)              # True
    s1.issuperset(s1)            # True
    s1.issuperset(s2)            # False