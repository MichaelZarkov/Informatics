
library("MASS")
data(cats)
names(cats)
attach(cats)
is.male = Sex == 'M'
mw = Bwt[is.male]
mhw = Hwt[is.male]
plot(mw, mhw)

mhw2.6 = mhw[mw == 2.6]
prop.test(mean(mhw2.6), 5)
