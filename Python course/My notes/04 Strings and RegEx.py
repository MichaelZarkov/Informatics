# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be 
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# It doesn't matter if you use single or double quotes for strings:
    "This is a string"
    'This is also a string'

# String indexing:
    # Indexing starts from 0. We can also index a string starting from the back with negative numbers. The result is a
    # string.
        myStr = "Magic"  # Create a variable.
        myStr[0]         # Returns 'M'
        myStr[3]         # Returns 'i'
        myStr[-1]        # Returns 'c'
        myStr[-5]        # Returns 'M'
        myStr[-6]        # Out of range exception.
        myStr[5]         # Out of range exception.
    # Slicing. With slicing we can obtain a range of elements. The first number tells us the start and the second tells
    # us one position after the end. The result is a string.
        myStr = "Magic"
        myStr[0:3]   # Gives us 'Mag'.
        myStr[0:-1]  # Gives us the string without the last element - 'Magi'.
        myStr[3:3]   # '' - the empty string.
        myStr[1:0]   # '' - the empty string.
        myStr[:2]    # 'Ma'
        myStr[3:]    # 'ic'
    # Stride. We can select only the characters with indexes that are divisible by 2, 3, 4 ... We can also combine it
    # with slicing.
        myStr = "Magic"
        myStr[::2]    # 'Mgc' - get the characters with indexes divisible by 2.
        myStr[::3]    # 'Mi'
        myStr[2:5:2]  # 'gc'
        myStr[0::2]   # Same as 'myStr[::2]'.
        myStr[1::82]  # 'a'. Note that first the slicing is applied and then the stride. If it was the other way around
                      # we would expect the result '' - the empty string.
        
# Concatenation:
    s = "Hello, " + "world."  # "Hello, world."
    3 * s                     # "Hello, world.Hello, world.Hello, world"
    s * 3                     # Same as 3 * s.
    s = s + ".."              # "Hello, world..."

# Strings are immutable. We can not change or delete individual characters.
    myStr = "Magic"
    myStr[0] = "G"           # Throws an error.
    myStr = myStr + " Mike"  # We can reassign the whole string. Result "Magic Mike".
    
# Escape sequences. With backslash '\' we can insert tabs new lines and so on. If we prefix a string with 'r' it is 
# considered a raw string.
    "Magic \n Mike"   # Insert a new line.
    "Magic \\ Mike"   # Inset a backslash.
    r"Magic \n Mike"  # '\n' is considered literally as backslash and the letter 'n' and not as a new line.
    
# String functions:
    s = "Magic Michael"
    s.upper()            # Result: "MAGIC MICHAEL"
    s.replace('a', 'i')  # Result: "Migic Michiel". s.replace(<to_be_replaced>, <replace_with>)
    s.find("i")          # Result: 3. Returns the start index of the first occurrence of the given string. If not found
                         # returns -1.
    s.split()            # Result: ["Magic", "Michael"]. Splits the string at the specified separator. Returns a list
                         # of strings.
    len(s)               # Result: 13. len(obj) - returns the number of elements in the object.
    sorted(s)            # Result: [' ', 'M', 'M', 'a', 'a', 'c', 'c', 'e', 'g', 'h', 'i', 'i', 'l'].
                         # sorted(iterable) - returns a sorted list of elements of the iterable object.
    
# Regular expressions. The built-in RegEx module "re" provides several functions for working with regular expressions,
# including search, split, findall, and sub.
# Note: I think it's better to write patterns as raw strings. I haven't looked this up so it may be wrong.
    import re  # Import the module if you wish to work with regular expressions.
    
    # Some special sequences. This is NOT an exhaustive list.
    # \d  Matches any digit character (0-9)	                                      "123" matches "\d\d\d"
    # \D  Matches any non-digit character	                                      "hello" matches "\D\D\D\D\D"
    # \w  Matches any word character (a-z, A-Z, 0-9, and _)	                      "hello_world" matches "\w\w\w\w\w\w\w\w\w\w\w"
    # \W  Matches any non-word character	                                      "@#$%" matches "\W\W\W\W"
    # \s  Matches any whitespace character (space, tab, newline, etc.)	          "hello world" matches "\w\w\w\w\w\s\w\w\w\w\w"
    # \S  Matches any non-whitespace character	                                  "hello_world" matches "\S\S\S\S\S\S\S\S\S"
    # \b  Matches the boundary between a word character and a non-word character  "cat" matches "\bcat\b" in "The cat sat on the mat"
    # \B  Matches any position that is not a word boundary	                      "cat" matches "\Bcat\B" in "category" but not in "The cat sat on the mat"

    # Functions (not an exhaustive list):
    # Note that some of these functions return objects an not basic data types like lists, strings, ints ...
        # re.search(pattern, string) - finds the first occurrence of pattern. Returns an object.
        re.search(r"Mi", "Mike is not Mine")  # Matches "Mi" from "Mike".
        # re.findall(pattern, string) - finds all occurrences of the pattern. Returns a list.
        re.findall(r"Mi", "Mike is not Mine")
        # re.split(pattern, string) - does the same as the string function split(), but pattern can be a RegEx.
        text = "Mike\nLucy\n\nAmber"
        re.split(r"\n+", text)  # Splits the text at the new lines.
        # re.sub(pattern, repl, string, count=0, flags=0) - return the string obtained by replacing the leftmost
        # non-overlapping occurrences of pattern in string by the replacement repl.
        re.sub(r"mm", "kk", "mmm")  # "kkm"