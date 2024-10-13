# LaTeX

This a language for writing mathematical expressions in plane text.

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

- $\forall$ - `\forall`
- $\exists$ - `\exists`
- $\in$ - `\in`
- $\sum$ - `\sum`
- $\lim$ - `\lim`
- $\lim\limits_{x \to \infty} e^x = \infty$ - `\lim\limits_{x \to \infty} e^x = \infty`
- $y'(x)$ - `y'(x)`
- $k_1, k_2, k_3,...,k_{n+1}$ - `k_1, k_2, k_3,...,k_{n+1}` - underscores are for lower indexes.
