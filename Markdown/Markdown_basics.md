
# Markdown Basics

This document compiles the main features of Markdown. There are a good amount
of explanations so maybe I should make a separate document with only the syntax.

## To Do

1. Add table of contents.
2. Learn how images are centered if possible.

## Useful Links

[GitHub Flavored Markdown (GFM) docs][gfm-docs] - more advanced.  
[Some GitHub MD tutorials][more-GitHub-MD-docs] - more advanced.  
[Basic MD syntax][basic-md-syntax] - the basic stuff.  
[Extended MD syntax][extended-md-syntax] - the basic stuff.

[LaTeX/Mathematics] - language for writing math expressions in plane text.
See section [Mathematical expressions](#mathematical-expressions) for more info.

## *Italics* and **Bold**

To make text *italic* surround it with dashes `_like this_` or with singe asterisks `*like this*`. You can also make ***italic and bold***
text like `***this***`. You can italicize and boldify text anywhere
(titles, lists, links and so on).

## Headers

There are six types of headers in decreasing size:

> # Header one
> ## Header two
> ### Header three
> #### Header four
> ##### Header five
> ###### Header six

You should use headers one and six sparingly. You place the same number of hash marks
as the size of the header you want. For example Header four is written like
this: `#### Header four`. You should put a space after the hashtags like
this `## Header`, instead of `##Header`. You should leave blank lines 
before and after the header.

## Links

There are two types of links: **inline links** and **reference links**. Inline links 
have their link in place, while reference links link to another place in the document.

**Inline links** are written as: `[link text](link address)`.  
For example if we want to create a hyperlink with link text "Google" which links to
https://www.google.com/ we would write: `[Google](https://www.google.com/)`.
Result is [Google](https://www.google.com/). In practice almost always it's better
to to use the next type of link - reference link.

**Reference links** are written as: `[link text][reference text]`.  
Reference links are useful if we want to link to something more than once,
they give us only a single place where we have to change the links.
The "reference text" is the name of the reference. It is case insensitive and we can use
letters, numbers and special symbols. By convention we put the definitions of the references
(the actual links) at the bottom of the document like this: `[reference text]: link address`. 
An example link to [Google] will look like this:

```
[Google][google]  
[google]: https://www.google.com/
```

For conciseness we can omit the reference text like so: `[Google]`, and then the link text
will also be used for the reference text. We can also have links to files. Just put the 
file path in place of the url.  
Example link to [an example file][example-file].

Optionally in both **inline links** and **reference links** we can add titles
by adding text in quotes (single or double) right after the link address like so:  

```
[Google](https://www.google.com/ "Title text...")
```

The title text shows up when you mouseover the link (mouseover this [Google]). 

## Images

Images are defined almost the same way as links:

```
![alt text](link address)
![alt text][reference text]
```

"alt text" is a phrase or sentence which describes the image for the visually 
impaired.  
Here is and example image:  
![This is a drawing of a cute fox.][drawing-of-fox]  
As with links you can optionally add a title to the image. You can also have an image
act as a link (but I see this as a very rare use case).

## Blockquotes

**Blockquotes** are created with `>`.

```
> I will render into a **blockquote**.  
> I'm a blockquote too!
>> I'm a blockquote inside a blockquote!!!
```

> I will render into a **blockquote**.  
> I'm a blockquote too!
>> I'm a blockquote inside a blockquote!!!

They are useful when you want to highlight a part of the text. Markdown elements
can be rendered inside blockquotes. For compatibility you should put blank lines
before and after blockquotes.

## Lists

**Unordered lists** are created like this 
(you can use `-`, `*` or `+`):
```
* eggs
* fruits
  * apples
  * oranges
* milk
```
Rendered version:
* eggs
* fruits
  * apples
  * oranges
* milk

**Ordered** lists are created like this:
```
1. eggs
2. fruits
   1. apples
   2. oranges
3. milk
```
Rendered version:
1. eggs
2. fruits
   1. apples
   2. oranges
3. milk

## Paragraphs

To make a separate paragraph you have to have at least one empty line.

```
This will render
on the same line.

This will render...

...as two paragraphs.
```
> This will render
> on the same line.
>
> This will render...
>
> ...as two paragraphs.

We can also move text to a new line without creating new paragraphs. This is
accomplished by typing two spaces at the end of the line, or if your Markdown
editor supports HTML (like VS Code) you can use the `<br>` tag at the end of
the line. For example:

```
This is the first line.##
This is the second line.##
This is the third line.<br>
This is the final line.
```
The `##` represent the two spaces. The result looks like this:

> This is the first line.  
> This is the second line.  
> This is the third line.<br>
> This is the final line.

Unless it is in a list you shouldn't indent paragraphs with spaces or tabs
because it can lead to formatting errors.

## Horizontal Rules

Horizontal rule is a thematic break between sections of the document.
In Markdown it's usually a horizontal line. We define it with at least three
underscores, asterisks or dashes: `___`, `***`, `---`.

> Section one...
> 
> ***
> 
> Section two...
> 
> ***
> 
> Section three...
 
You should put a blank line before and after the horizontal rule.

## Code

To denote a word or phrase as `code` enclose it with backticks like so 
`` `code` ``.  
To create **code blocks** just indent the text with four spaces. This however is 
usually harder to read when editing the plain text Markdown file so in most
cases you'd prefer using **fenced code blocks** enclosing the text in triple 
backticks (```) or triple tildes (~~~) like so:

    ```
    some code...
    ```

Note the the backtick (or tilde) enclosed code blocks are not from the basic
Markdown syntax but they work on basically all Markdown processors.

We can have **syntax highlighting** (also not supported everywhere but still
widely used) by adding the name of the language after the first backticks:

    ```C++
    int main() {
      std::cout << "Hello, World!" << std::endl;
      return 0;
    }
    ```
If you use MD processor which supports C++ highlighting, then the following 
code block will be colorful.
```C++
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
```

## Escaping Characters

You can escape characters which are used to format Markdown by preceding them with a
backslash `\`.

## HTML

Many MD processors allow you to use HTML tags in your MD documents. This is useful when
you want to change the attributes of an element like text color or width of an image.
To use HTML tags just place them in the MD document:

```
This is the first line.<br>
The <code>&lt;br&gt;</code> tag produces a line break.<br>
The <code>&lt;code&gt;</code> tag makes a code block and so on.
```

> This is the first line.<br>
> The <code>&lt;br&gt;</code> tag produces a line break.<br>
> The <code>&lt;code&gt;</code> tag makes a code block and so on.

Some editors may only support certain tags. With that in mind here are some useful tags in 
alphabetic order which should be supported on most processors (including GitHub):
- `<sub>` - subscript text: <sub>this is a subscript</sub>,  A<sub>1</sub>, A<sub>2</sub>
- `<sup>` - superscript text: <sup>this is superscript</sup>, A<sup>1</sup>, A<sup>2</sup>

## Mathematical expressions

[Mathematical expressions tutorial][MD-math-expressions]




# The End



[basic-md-syntax]: https://www.markdownguide.org/basic-syntax/
[drawing-of-fox]: ./resources/example-fox-drawing.jpeg "This is the best fox drawing."
[example-file]: ./resources/example-file.txt
[extended-md-syntax]: https://www.markdownguide.org/extended-syntax/
[gfm-docs]: https://github.github.com/gfm/ "GitHub Flavored Markdown docs."
[google]: https://www.google.com/ "The best search engine on the planet."
[LaTeX/Mathematics]: https://en.wikibooks.org/wiki/LaTeX/Mathematics "Language for writing mathematical expressions in plane text."
[MD-math-expressions]: https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/writing-mathematical-expressions
[more-GitHub-MD-docs]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/quickstart-for-writing-on-github