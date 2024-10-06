# The purpose of this file is for quick reference and refresher on basic Python concepts.
# If you try to compile the whole file, there would probably be errors, but the separate code snippets should be
# correct Python code (unless I made a mistake :) ).
# If not specified, it is considered that the references are for Python version 3.

# -------------------- Introduction to Pandas -------------------- #
"""
Pandas is a popular open-source data manipulation and analysis library for the Python programming language. It provides
a powerful and flexible set of tools for working with structured data, making it a fundamental tool for data
scientists, analysts, and engineers. Pandas is designed to handle data in various formats, such as tabular data, time
series data, and more, making it an essential part of the data processing workflow in many industries.

Here are some key features and functionalities of Pandas:
    - Data Structures: Pandas offers two primary data structures - DataFrame and Series. A DataFrame is a
      two-dimensional, size-mutable, and potentially heterogeneous tabular data structure with labelled axes (rows and
      columns). A Series is a one-dimensional labelled array, essentially a single column or row of data.
      
    - Data Import and Export: Pandas makes it easy to read data from various sources, including CSV files, Excel
      spreadsheets, SQL databases, and more. It can also export data to these formats, enabling seamless data exchange.

    - Data Merging and Joining: You can combine multiple DataFrames using methods like merge and join, similar to SQL
      operations, to create more complex datasets from different sources.

    - Efficient Indexing: Pandas provides efficient indexing and selection methods, allowing you to access specific
      rows and columns of data quickly.

    - Custom Data Structures: You can create custom data structures and manipulate data in ways that suit your specific
      needs, extending Pandas' capabilities.
"""


# -------------------- Loading data -------------------- #

# To use Pandas we have to import it. It abbreviated as 'pd' for ease of writing.
import pandas as pd

# 'pd.read_csv('file_name.csv')' - reads a csv (comma separated values) file and returns a DataFrame.
df = pd.read_csv('my_file.csv')  # Example.


# -------------------- Pandas Series -------------------- #

# A Series is a one-dimensional labelled array in Pandas. It can be thought of as a single column of data with labels
# or indices for each element. We can create a Series from various data sources, such as lists, NumPy arrays, or
# dictionaries.
    data1 = [10, 20, 30, 40]
    s1 = pd.Series(data1)  # Creates a Series from a list. Here Pandas automatically assigns labels 0,1,2,3 to the
                           # corresponding elements 10,20,30,40.

    data2 = { 'width' : 10, 'height' : 20, 'length' : 30 }
    s2 = pd.Series(data2)  # Creates a Series from a dictionary. Here we assign the labels 'width', 'height', 'length' to
                           # the elements 10,20,30.
                      
# Accessing elements.
    # Access elements by label.
        s1[0]             # Result is 10. Access the element with label 1.
        s1[3]             # 40
        s2['height']      # Result is 20. Access the element with label 'height'.
        s2['width']       # 10
        
        # We can also use 'loc[<label>]'.
        s1.loc[0]         # 10
        s2.loc['height']  # 20
    
        # Access range of elements by label. Includes the end label.
        s2['width':'height']  # 10,20
    
    # Access element by index.
        s1.iloc[0]  # 10
        s1.iloc[2]  # 30
        s2.iloc[0]  # 10
        s2.iloc[1]  # 20
        
        # Access range of elements by index. Doesn't includes the end index.
        s2.[0:2]  # 10, 20
        
# Series Attributes and Methods.
    # values: Returns the Series data as a NumPy array.
    # index: Returns the index (labels) of the Series.
    # shape: Returns a tuple representing the dimensions of the Series.
    # size: Returns the number of elements in the Series.
    # mean(), sum(), min(), max(): Calculate summary statistics of the data.
    # unique(), nunique(): Get unique values or the number of unique values.
    # sort_values(), sort_index(): Sort the Series by values or index labels.
    # isnull(), notnull(): Check for missing (NaN) or non-missing values.
    # apply(): Apply a custom function to each element of the Series.


# -------------------- Pandas DataFrames -------------------- #

# A DataFrame is a two-dimensional labelled data structure with columns of potentially different data types. Think of
# it as a table where each column represents a variable, and each row represents an observation or data point.
# DataFrames are suitable for a wide range of data, including structured data from CSV files, Excel spreadsheets, SQ
# databases, and more.

# Creating a DataFrame from a dictionary with keys as column labels and values as lists representing the rows.
    data_1 = { 'name'             : ['Alice', 'Bob', 'Mike'],
               'age'              : [34, 23, 19],
               'favourite_colour' : ['red', 'green', 'blue'] }
    df = pd.DataFrame(data_1)  # 'df' stands for DataFrame.
    print(df)
    # The result printed is this:
    #     name  age favourite_colour
    # 0  Alice   34              red
    # 1    Bob   23            green
    # 2   Mike   19             blue

# Accessing elements, columns and rows.

    # 'loc()' and 'iloc()' are the main functions we use to access elements so are the most important to know.

    # 'loc[<row_label>, <column_label>]'
    # This is a label-based data selecting method which means that we have to pass the name of the row or column that
    # we want to select. This method includes the last element of the range passed in it.
    
    # 'iloc[row_index, column_index]'
    # This is an index-based selecting method which means that we have to pass an integer index in the method to select
    # a specific row/column. This method does not include the last element of the range passed in it.
    
    
    # Examples:
    # Access columns.
        df['name']          # Returns the specified column. The result is of type Pandas Series.
        df[['name']]        # Returns the specified columns. The result is of type DataFrame.
        df[['age', 'name']] # Returns the specified columns.
        
        # We can also use 'loc()' and 'iloc()'.
        df.loc[:,'name']           # Returns just the column 'name'.
        df.loc[:,'name':'age']     # Returns the columns from 'name' to 'age' (including 'age').
        df.loc[1:2, 'name':'age']  # Returns rows from 1 to 2 and columns from 'name' to 'age.
        
    # Access rows.
        df.loc[1]       # Access the a row by label.
        df.loc[1:3]     # We can slice by label.
        df.iloc[1]      # Access a row by index (counting starts from 0 as usual).
        df.iloc[1:3]    # We can slice by index.
        df.iloc[1:3:2]  # We can slice with stride length.
        df[1:3]         # Slicing. Access the specified range of rows (I think this is by index?).
        
    # Access a specific element.
        df.loc[1, 'name']
        df.iloc[2, 1]

# Conditional filtering.
    # Example:
        age_above_30 = df[df['age'] > 30]  # Returns only the Row of Alice.
    # Similarly to the R programming language, 'de['age'] > 30' returns a boolean vector (Series). The comparison
    # '> 30' is made for each element of 'df['age']'. Then we pass this boolean vector to 'df' a again, and it returns
    # only the rows with value True.

# Save to a file.
    df.to_csv('my_data_file.csv')

# DataFrame attributes and methods.
    # shape: Returns the dimensions (number of rows and columns) of the DataFrame.
    # info(): Provides a summary of the DataFrame, including data types and non-null counts.
    # describe(): Generates summary statistics for numerical columns.
    # head(), tail(): Displays the first or last n rows of the DataFrame.
    # mean(), sum(), min(), max(): Calculate summary statistics for columns.
    # sort_values(): Sort the DataFrame by one or more columns.
    # groupby(): Group data based on specific columns for aggregation.
    # fillna(), drop(), rename(): Handle missing values, drop columns, or rename columns.
    # apply(): Apply a function to each element, row, or column of the DataFrame.
    # set_index(): Sets the values for the indexes.