
og = c(31,50,17,2)
#t = table(rbinom(100,3,1/3))
t = c(33,45,19,3)/100
chisq.test(og,p=t)