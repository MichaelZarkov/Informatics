f = function(a0,a1,n)
{
  if (n == 0) { return(a0) }
  f(a1, 2*a1+a0, n-1)
}

fsum = function(a0,a1,n)
{
  i = 0
  sum = 0
  while (i <= n)
  {
    sum = sum + f(a0,a1,i)
    i = i + 1
  }
  return(sum)
}

f(1,0,10)
fsum(1,0,10)