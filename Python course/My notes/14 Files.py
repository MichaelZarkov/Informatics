# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# -------------------- Intro -------------------- #

# This file contains only the very basics of input and output to a file.
# Also only text files are discussed here.


# -------------------- Opening and closing a file -------------------- #

# We open a file like this:
my_file = open("<file_path", <mode>)
# By default, if we don't specify the mode, the file is opened for read only and in text mode.
# Most common modes are:
#   'r' - file opened for read only.
#   'w' - opened for write only. If the file exists its content is erased.
#   'a' - for appending to and existing file.
#   'r+' - for both reading to and writing to a file. There are also 'w+' and 'a+'.
#   't' - text mode.
#   'b' - binary mode.

# Closing a file.
# If we just open a file on its own like this:
    my_file = open("file_name.txt")
# it is mandatory to close it like this:
    my_file.close()
# There is a better way to do it and it's with the following construct:
    with open("file_name.txt") as my_file:
        # ... do stuff with the 'my_file'
    # When we exit the indented block, the file is automatically closed.


# -------------------- Reading from a file -------------------- #

# 'file.read()' - if called without an argument, returns the whole contents of the file.
# 'file.read(n)' - reads the first n characters in text mode (in binary maybe it reads the first n bytes?).
file_content = my_file.read()    # Reads the whole file.
file_content = my_file.read(10)  # Reads the first 10 chars.

# 'file.readline()' - reads single line in text mode.
# 'file.readline(n)' - reads up to n characters or up to the first new line character.

# 'file.readlines()' - returns a list of the lines in a file.
# Example:
# If the file is as follows:
#   This is line 1
#   This is line 2
#   This is line 3
# The result will be: ['This is line 1\n', 'This is line 2\n', 'This is line 3']

# We can iterate through the lines of a file with for loop.
with open("my_text_file.txt","r") as file:
    i = 1;
    for line in file:
        print("Line num: ", i, " Line content: ", line)
        i = i + 1


# -------------------- Writing to a file -------------------- #

# We use the 'file.write(<string>)' method to write to a file.
    with open("my_file.txt", 'w') as file:
        file.write("This line will be written.\nThis line will also be written.\nThe last line.")

    # Example:
    # Write a list of strings to a file.
    l = ["string 1\n", "string 2\n", "another string", " and yet another string"]
    with open("output_file.txt", "w") as file:
        for s in l:
            file.write(s)

# 'file.truncate()' - this function truncates a file up to a given point (i.e. deletes the contents after a specified
#                     point). The file has to be opened in the appropriate mode for this function to work. It is useful
#                     if we want to rewrite some of the contents of the file.


# -------------------- The file pointer -------------------- #

# Analogous to C++ there is a file pointer in the file object which keeps track of the position in the file where to
# read or write next. The different opening modes put this pointer at different places by default (beginning or end).
# Also analogous to C++ we can get the location or move this pointer with the following functions.
    # 'file.tell()' - returns the current position in bytes.
    #
    # 'file.seek(<offset>, <from>)' -  changes the position by '<offset>' bytes with respect to '<from>'. From can take
    #                                  the value of 0,1,2 corresponding to the beginning, relative to current position
    #                                  and end.


# -------------------- Examples -------------------- #

# Copy a text file.
    with open("input.txt", 'r') as ifile:
        with open("output.txt", 'w') as ofile:
            for line in ifile:
                ofile.write(line)