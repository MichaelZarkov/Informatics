library("MASS")  # Load the package.
data("Aids2")    # Load the data.
names(Aids2)     # Print the names of the categories to see what are we working with.
attach(Aids2)    # Give us access to the names of the categories.

# From which states are the 6 oldest people.
ages.of.the.six.oldest = rev(sort(age))[1:6]
state[age %in% ages.of.the.six.oldest]

# How many people participated in the study more than a year.
days = (death - diag)
length(days[days > 365])

# Plot of the transmission of the disease and the age of the people.
plot.age.and.trans = function()
{
  mean.ages = c()
  i = 1
  for (category in unique(T.categ))
  {
    mean.ages[i] = mean(age[T.categ == category])
    i = i + 1;
  }
  barplot(mean.ages, names=unique(T.categ))
}

plot.age.and.trans()

# Task 3.
# Check the mean age of the people that got the disease from
# heterosexual act.
mean(age[T.categ == "hs"])
