# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# Tuples can contain objects of different types including other tuples. Tuples are created with (a1, a2,..., an).
    t1 = (1, 2, 3, "my tuple", (), (4, 5, 6))
    t2 = ()    # The empty tuple.
    t3 = (5,)  # A tuple with one element.
    i = (5)    # An integer.
# As with lists we can use the constructor tuple(iterable) to create a tuple from an iterable object.
    tuple([1, 2, 3])  # Creates the tuple (1, 2, 3) from the list [1, 2, 3].
    tuple("tp")       # Creates the tuple ("t", "p").
# Tuples can be indexed just like strings.
    t1[1]   # 2
    t1[-2]  # ()
# Tuples can be sliced (with or without a stride) just like strings. The result is a tuple.
    t1[3:5]  # ('my tuple', ())
    t1[::3]  # (1, 'my tuple')
# We can also index the nested tuples.
    t = ([1, 2, (3, 4)], 5)
    t[0][2][1]  # 4
    
# Similarly to strings, tuples are immutable. We cannot change or delete individual elements.
    t[0] = "change"    # Throws an error.
    del(t[0])          # Throws an error.
    t = ("change", 5)  # We have to reassign the whole tuple to change it.
    
# Functions and operations
    # Concatenation.
        t1 = (1, 2)
        t2 = (3, 4)
        t1 + t2      # (1, 2, 3, 4)
    
    len(t)      # Length.
    sorted(t)   # Returns a sorted list of elements of the iterable object. Elements have to be comparable.
                # Doesn't change the original object t.
    