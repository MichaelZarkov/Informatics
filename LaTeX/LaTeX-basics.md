# LaTeX

This is a language for writing mathematical expressions in plane text: [LaTeX/Mathematics]


## LaTeX and Markdown

Some MD processors understand LaTeX - for example VS Code and GitHub.  
Surround LaTeX code with `$` to insert inline math expressions.
Use code block with ` ```math ` to interpret it as LaTeX code. For example:

> Source: `$a^2 + b^2 = c^2$`  
> Rendered version: $a^2 + b^2 = c^2$

Rendered version inside ` ```math ` code block (as you can see it is rendered on a new line):
```math
a^2 + b^2 = c^2
```

**Note**: If you view this document in MD viewer which doesn't support LaTeX the "rendered version" 
won't be rendered at all and you'll see its source instead.

## Common Symbols

### Greek Letters

You just type the name of the greek letter after a backslash. If the first letter of the name is upper 
case then the greek letter will also be uppercase. For example:
- $\alpha, \beta, \gamma, \delta, \epsilon, \lambda, \mu, \phi, \varphi, \zeta$  
  `\alpha, \beta, \gamma, \delta, \epsilon, \lambda, \mu, \phi, \varphi, \zeta`
- $\Alpha, \Beta, \Gamma, \Delta, \Epsilon, \Lambda, \Mu, \Phi, \varPhi, \Zeta$  
  `\Alpha, \Beta, \Gamma, \Delta, \Epsilon, \Lambda, \Mu, \Phi, \varPhi, \Zeta`

As you can see **phi** ($\phi, \varphi$) has two variants and we differentiate between them with `var` - this is also true for other letters with variants.

### Other Symbols

Note that you can change how some symbols look by typing `\displaystyle` before the symbol definition.
This is mainly useful for fractions, sums and integrals.

- $\forall$ - `\forall`
- $\exists$ - `\exists`
- $\in$ - `\in`
- $\dots$ - `\dots`
- $x\,y\:z\;u\,\!v$ - `x\,y\:z\;u\,\!v`
  - `\,` - very small space
  - `\:` - small space
  - `\;` - medium space
  - `\!` - negative space - same width as `\,` 
- $\sum$ - `\sum`
- $\lim$ - `\lim`
- $\infty$ - `\infty`
- $\lim\limits_{x \to \infty} e^x = \infty$ - `\lim\limits_{x \to \infty} e^x = \infty`
- $y'(x)$ - `y'(x)`
- $k_1, k_2, k_3,\dots,k_{n+1}$ - `k_1, k_2, k_3,\dots,k_{n+1}` - underscores are for lower indexes.
- $\frac {1} {x}, \frac{1}{x}, \frac 1 x, \frac{n(n+1)^2}{2}, \frac{\frac 1 2 + \frac 1 2}{\frac 1 2}$ - 
  `\frac {1} {x}, \frac{1}{x}, \frac 1 x, \frac{n(n+1)^2}{2}, \frac{\frac 1 2 + \frac 1 2}{\frac 1 2}`
- $\frac {n!} {(n-k)!k!} = \binom n k$ - `\frac {n!} {(n-k)!k!} = \binom n k`
- $\sqrt 3, \sqrt [82] {3}, \sqrt[82]{3}$$ - `\sqrt 3, \sqrt [82] {3}, \sqrt[82]{3}`
- $\sum_{i=1}^{n} n^2, \displaystyle \sum_{i=0}^{n} n^2$ - `\sum_{i=1}^{n} n^2, \displaystyle \sum_{i=0}^{n} n^2`
- $\displaystyle \int e^{-x}dx, \int e^{-x}\:\mathrm{d}x$ -
  `\displaystyle \int e^{-x}dx, \int e^{-x}\:\mathrm{d}x`  
  You can write integrals like the first one: `\int e^{-x}dx`, but the second way is a little nicer 
  to look at. `\mathrm` just makes the letter upright (like so $d, \mathrm d$) and we also insert a 
  small space with `\:` between the integrand $e^{-x}$ and the integration variable $\mathrm{d}x$.
- $\displaystyle \int_a^b e^t\:\mathrm{d}t$ - `\displaystyle \int_a^b e^t\:\mathrm{d}t`
- $( \big ( \Big ( \bigg ( \Bigg ($ - `( \big ( \Big ( \bigg ( \Bigg (` - different sizes of parentheses 
  if the default ones are not adequate.
- $\pm, \mp$ - `\pm, \mp`



[LaTeX/Mathematics]: https://en.wikibooks.org/wiki/LaTeX/Mathematics "Language for writing mathematical expressions in plane text."