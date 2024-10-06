# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# -------------------- For loops -------------------- #

# We use for loops to iterate trough a predetermined range or through an iterable object like a list, set, dictionary.
l = [0, 1, 2]
for i in l:
    print(i+1)
# This prints: 1 2 3


# The variable following the 'for' is actually a reference to the actual list element so we can operate on it directly.
l = [[1], [2], [3]]  # Elements have to be mutable objects so we can change them.
for i in l:
    i += [0]  # i is a reference to the actual element of l, so we change it.
    print(i)  # We can see the element has changed.
print(l)      # l has changed and this prints [[1,0], [2,0], [3,0]].


# We can do stupid stuff like:
# WARNING!!!
# Infinite loop because we are adding new elements to the list as the loop runs.
# If you run it, press Ctrl + C to terminate.
l = [1, 2, 3]
for i in l:
    l.append(0)  # Adding a new element.
    print(i)
    
    
# Example with a dictionary:
d = { "k1" : 3, "k2" : 5, "k3" : 8 }
# We loop through the keys.
for k in d:
    print(f"Key = {k} | Value = {d[k]}")
    
    
# range() function gives ... a range :) that we can iterate through. Note that in Python 2.x, range() returns a list
# but in Python 3 it returns a range object.
range(9)      # Gives us the range [0, 8] (not including 9)
range(3, 7)   # [3, 6]
range(-2, 5)  # [-2, 4]
# We can index a list like this:
l = [3, 5, 8]
for i in range(0, len(l)):
    print(f"Index = {i} | Elem = {l[i]}")  # Prints indexes and corresponding elements.
    
    
# enumerate() function allows us to get the index and the element. For example:
l = [3, 5, 8]
for i, elem in enumerate(l):               # 'elem' is a reference to the list element.
    print(f"Index = {i} | Elem = {elem}")  # Prints indexes and corresponding elements.
    
    
# -------------------- While loops -------------------- #

# We use while loops to run code while a condition is satisfied.
dates = [1988, 1974, 1990, 2001, 1955]
i = 0
while dates[i] < 2000:
    print(dates[i])
    i += 1
# Prints 1988 1974 1990


# -------------------- Break and continue -------------------- #

# Break and continue work as in C++.


# -------------------- Variables -------------------- #

# Note that variables inside loops and if statements are also visible from the "outside".
if True:
    s = 8
print(s)  # Prints 8

while True:
    k = 5
    break
print(k)  # Prints 5