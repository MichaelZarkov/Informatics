# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# The following is maybe the simplest definition of a class in Python.
class My_class:
    pass
# We use the 'pass' key word when we haven't implemented the class yet but we want the program to compile (a class
# can't have an empty body).


# This is a class with a single static variable (also known as class variable).
class My_class:
    my_static_var = 0
# Maybe should add some details later but for now know that static variables behave somewhat weirdly.


# '__init()__' is the constructor. The instance variables of the class should be declared there.
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
# The 'self' parameter is a reference to the current instance of the class, and is used to access variables that
# belongs to the class. It does not have to be named 'self' , you can call it whatever you like, but it has to be the
# first parameter of any function in the class.


# Of course we can also have methods.
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def say_hello(self):
        print(f"Hello, my name is {self.name}!")
        
    def set_name(self, new_name):
        self.name = new_name
        print(f"New name is {self.name}.")
        
p = Person("John", 24)  # Create instance.
p.set_name("Mike")
p.say_hello()  # Prints 'Hello, my name is Mike!'.
print(p.age)   # We can access the attributes.


# 'dir(<class_name>)' returns a list of the methods of the class.