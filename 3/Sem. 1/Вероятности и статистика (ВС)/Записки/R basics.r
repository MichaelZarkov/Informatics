# Изготвил Майкъл Зарков.
# Max line width for the document: 125 lines.

# Creating vectors.
  c(3,5,3,2)  # Creates the vector 3,5,3,2.
  1:6  # Integer sequence. Result 1,2,3,4,5,6.
  seq(2,3, by=0.5)  # Creates a sequence with given step. Result: 2.0,2.5,3.0.
  rep(1,2,3, times=3)  # Repeat a vector. Result: 1,2,3,1,2,3,1,2,3.
  rep(1,2,3, each=3)  # Repeat each element of vector. Result: 1,1,1,2,2,2,3,3,3.
  
  # Of course we can combine some of the above.
    rep(2:4, times=2, each=2)  # Result: 2 2 3 3 4 4 2 2 3 3 4 4
  
# Selecting vector elements.
  # By position. Note that R starts counting from 1, not from 0.
    v[4]  # The 4th element.
    v[-4]  # All but the 4th element.
    v[c(2,1,6)]  # The elements at 2nd, 1st and 6th position in this order.
    v[5:10]  # Elements 5 to 10 inclusive.
    v[-(2:4)]  # All elements except 2nd, 3rd and 4th.
  
  # By value.
    v[v == 10]  # Elements which are equal to 10.
                # Note: 'v == 10' returns a boolean vector with the same length as 'v'. The positions in the
                # boolean vector that are true are selected from 'v'.
    v[v < 0]  # Elements less than 0.
    x[x %in% c(1, 2, 5)]  # Elements in the set {1,2,5}.
    
# Loading packages (libraries) in the current environment.
  library("<package_name>")  # Load the package (library).
  data(<dataset_name>)  # Load a data set from the package. This creates a variable in the environments with the
                        # name <dataset_name>. We are ready to use the dataset.
  names(<dataset_name>)  # Print the names of the categories in the dataset. This is no necessary, just to see what are
                         # we working with.
  attach(<dataset_name>)  # Gives access to the names of the categories so we can do for example 'sort(<category_name>).'
    # ... do some stuff.
  detach(<dataset_name>)  # Clean up the workspace after use.
  
# Plots.
  barplot(...)
  hist(...)
  boxplot(...)
  plot(...)  # Simple plot.

# Random data and simulations.
  sample(1:6,10)  # Choose from vector of possibilities.
  runif(1,0,2)  # Uniform real numbers in a range.
  rnorm(1,100,16)  # Normal distribution numbers.
  rbinom(1,n,p)  # Binomial distribution.
 
# Confidence intervals.
  prop.test(...)  # Confidence interval.
  chisq.test(v,p=<prob>)  # Compare one distribution to another.
  

