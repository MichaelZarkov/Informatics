# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# Lists can contain objects of different types including other lists. Lists are created with [].
    l1 = ["My summer car", 1990, 2.4, [3, 5]]
    l2 = []  # The empty list.
# We can also use the constructor list(iterable) to create a list from an iterable like a set, dictionary, string etc.
    list((3, 4, 5))  # [3, 4, 5] - make a list from a tuple.
# Lists can be indexed just like strings.
    l1[0]   # "My summer car"
    l1[-2]  # 2.4
    l2[0]   # Out of range error.
# Lists can be sliced (with or without a stride) just like strings. The result is a list of elements.
    l1[2:4]  # [2.4, [3, 5]]
    l1[::2]  # ["My summer car", 2.4]
# We can also index the sublists.
    l1[3][1]  # 5
    
# Lists are mutable. We can change their elements, add elements and remove elements.
    l1[0] = "Car"  # Change the element at index. Change "My summer car" to "Car".
    del(l[0])      # Delete the element at index.
    [1, 2] + [3, 4]  # [1, 2, 3, 4]. Concatenation.
    
    # extend(iterable) - adds the specified list of elements (or any iterable object) to the end of the current list.
    # Argument has to be iterable.
    l2.extend([3, 2, "sss"])  # l2 becomes [3, 2, "sss"].
    l = []
    l.extend("a string")      # 'l' becomes ['a', ' ', 's', 't', 'r', 'i', 'n', 'g'] (strings are iterable).
    
    # append(object) - adds a single object to the end of the list.
    l = []
    l.append([3, 2, 1])  # 'l' becomes [[3, 2, 1]] (a single element was added).
    
    len(l)     # Length.
    sorted(l)  # Returns a sorted list of elements of the iterable object. Elements have to be comparable.
               # Doesn't change the original list l.
    l.sort()   # Sorts the list l in-place. l is now a sorted list.
    
# Copy a list. If we do a simple assignment l1 = l2, both variables will be pointing to the same list in memory.
# To actually clone the list we use:
    l1 = l2[:]
    
    
    