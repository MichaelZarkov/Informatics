# HTML Basics

## What Is HTML, CSS and JavaScript

**HTML** stands for **h**yper**t**ext **m**arkup **l**anguage. Hypertext means text 
that contains links to other texts (i.e. cross-referencing between files (not sure
if this is entirely correct)). Markup means *to annotate*. Language means that it
has well defined syntax. HTML is used to define the *structure* of the *content* 
in a webpage and annotate its content (it doesn't have to be a webpage;
that's just the most common use).
The key word here is *structure* - for example a webpage has two headings, five 
paragraphs and a title. It **doesn't** tell us anything about the formatting - 
what's the font, the text color, or left or right alignment.

**CSS** stands for cascading style sheets. It is the language we use to style a 
web page. It describes how HTML elements are to be displayed on screen, paper, or 
in other media (so it deals with the formatting). It can control the layout 
of multiple web pages all at once. For example if we have a heading we'll use CSS 
to define what color and font size it is and a lot more than that.

**JavaScript** provides the functionality of a webpage.

These three technologies work together to provide us with basically all websites on 
the Internet.

### Who's In Charge of HTML

The two main bodies in charge are [W3C (World Wide Web Consortium)][W3C] and 
[WHATWG (Web Hypertext Application Technology Working Group)][WHATWG].
**W3C** deals with the standard of HTML (as of 13.09.2024 it is HTML5), and 
**WHATWG** deals mainly with evolving and testing our new features of HTML.
[This][html5-living-standard] is the living standard of HTML.

**Note:** wherever I say HTML I'm referring to HTML5 standard.

## HTML Tags

Usually HTML **tags** have an **opening** and **closing tag** and they surround 
some content. For example we can have the paragraph tag:
```html
<p>I'm a paragraph.</p>
```
Technically speaking `p` is called an **element** and `<p>` is called a (opening) 
tag (however these terms are often used interchangeably).

All HTML tags have an opening tag but not all have a closing tag. For example
`<br>` (line break) and `<hr>` (horizontal rule) don't have a closing tag. There 
are also self closing tags like `<p/>` which don't contain any content but they 
are rarely used and have additional rules about them.

HTML elements can have **attributes** (name-value pairs). For example:
```html
<p id="someId">...paragraph...</p>
```
In particular **no two elements in the same file** can have the same `id`. 
Attributes can only be specified in the opening tag. We don't always need to 
surround the value of the attribute in quotes but it is best practice to do so. 
There is no difference between single or double quotes (we can even nest one in 
the other).

We cannot have space right after `<`; there must be at least one space 
between the element name and the first attribute; the closing tag cannot have
space between `/` and the element name.
```html
<!-- Correct -->
  <p id="id1"></p>
  <p   id    =    "id2"    ></p   >
<!-- Incorrect -->
  < p></p>
  <p></ p>
  <p>< /p>
```

## Basic HTML Document Structure

The most basic HTML document is the following:
```html
<!doctype html>
<html>
  <head>
    <title>My first HTML document.</title>
  </head>
  <body>
    Hello, World!
  </body>
</html>
```
This is basically the "hello, world" program in HTML. Every HTML document has:  
1. `<!doctype html>` - declaration that tells the browser to render it as HTML. 
   The capitalization of the letters doesn't matter (`<!DOCTYPE HTML>` is also 
   valid); the only thing is that `<!doctype` must not have spaces. We can 
   actually have a webpage without this declaration but then the browser would 
   interpret it in what's called **Quirks Mode** - the browser is ready for 
   non-standard or legacy webpage.
2. Everything else is enclosed between `<html>` and `</html>`.
3. The content in `<head>` is **not** displayed on the webpage, it contains 
   metadata for the main content.
4. `<title>` is **mandatory** and **must not** be empty.
5. `<body>` contains everything to be displayed on the webpage visible by the 
   user and is not actually mandatory for a valid HTML document.

Something already pretty obvious is that to close a tag we have to close all 
the tags inside it first. For example
```html
<p>Some text <span> more text </p> even more text.</span>  <!-- Incorrect -->
```

The browser reads and interprets HTML documents sequentially from top to bottom. 

Another thing to remember is that consecutive white spaces of the usual kinds 
(space, tab, new line) are ignored by the browser. For example the following 
sections of code are displayed exactly the same way:
```html
<div>This is some text.</div>
<div>This is also some text.</div>
```
```html
 <div>  This is 
      some     text.  

    </div><div> This 
                        is also 

some text.

    </div>
```

Result:

> This is some text.  
> This is also some text.


## HTML5 Content Models (should reed a bit more on this)

**Content model** (or **content category**) roughly means *the default behavior 
the browser applies to the elements belonging to that content model and to the 
nesting rules of those elements*. In other words which elements are allowed to be 
nested in which other elements. Prior to HTML5, elements were either 
**block-level** or **inline elements**. HTML5 split these two into seven categories but 
the **block level** and **inline** categories are still relevant. From the new 
categories block-level elements roughly translate to the category **flow content** and 
inline elements translate to **phrasing** content.

**Block-level** elements:
- render on a new line by default (that can be changed with CSS).
- can contain other block-level or inline elements.

**Inline** elements:
- render on the same line by default.
- can contain only other inline elements.

Perhaps the most template example of block-level element is the `div` (stands for 
division) element, and the most generic inline element is the `span` element. 
`div` defines a section in an HTML document; `span` is used to mark up a part of 
the text. You can put `span` inside of `div` but you cannot put `div` inside of 
`span` - `span` is an inline element.

Example:
```html
<!doctype html>
<html>
  <head>
    <title>My first HTML document.</title>
  </head>
  <body>
    <div>Dogs are carnivores.</div>
    <div>Dogs are not herbivores.</div>
    <span>Cats are also carnivores.</span>
    <span>Horses eat grass.</span>
    <div>But do these things even matter in the <span>Grand</span> Universe???</div>
  </body>
</html>
```

Text displayed by the browser:

> Dogs&nbsp;are&nbsp;carnivores.  
> Dogs&nbsp;are&nbsp;not&nbsp;herbivores.  
> Cats&nbsp;are&nbsp;also&nbsp;carnivores.&nbsp;Horses&nbsp;eat&nbsp;grass.  
> But&nbsp;do&nbsp;these&nbsp;things&nbsp;even&nbsp;matter&nbsp;in&nbsp;the&nbsp;Grand&nbsp;Universe???

## HTML Essential Tags

Before we begin looking at particular tags it is important to remember to use 
tags according to their intended purpose. Let's look at an example:
```html
<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title>Heading Elements</title>
</head>
<body>
  <header>
    header element - Some header information goes here. Usually consists of company logo, some tag line, 
    etc. Sometimes, navigation is contained in the header as well.
    <nav>nav (short for navigation) element - Usually contains links to different parts of the web site.</nav>
  </header>
  <h1>Main Heading of the Page (hard not to have it)</h1>
  <section>
    Section 1
    <article>Article 1</article>
    <article>Article 2</article>
    <article>Article 3</article>
  </section>
  <section>
    Section 2
    <article>Article 4</article>
    <article>Article 5</article>
    <article>Article 6</article>
    <div>Regular DIV element</div>
  </section>
  <aside>
    ASIDE - Some information that relates to the main topic, i.e., related posts.
  </aside>

  <footer>
    JHU Copyright 2015
  </footer>
</body>
</html>
```

Notice how easy it is to determine the document structure with just one look. We have 
a header, a title, two sections with three articles each, some side note and a 
footer. We could've used the `<div>` tag in place of almost every other tag and 
the functionality would've been the same but we would've lost the ease of 
understanding of the structure. The elements like `article`, `section`, `footer` 
are called semantic elements. They don't give us any extra formatting functionality 
(with CSS we can style any regular `<div>` tag like them) but they tell us 
something about the meaning of the content in them (e.g. the text in `<h1>` is 
the main heading of the page) (if we don't use them, that's like calling every 
variable in a program var_1, var_2, ... just makes it horrible to read). 
Semantic elements **might** also play a role in 
**SEO (search engine optimization)** so they are important not only for readability.

### `<h1>` to `<h6>`

As in Markdown we have six degrees of headings - `<h1>` the biggest (most important) 
to `<h6>` - the smallest. It is always a good idea to use `<h1>` because it 
represents the main idea/topic of the webpage.

### `<header>`

Contains some header information about the page - usually company logo and navigation 
within the website.

### `<p>`

A paragraph.

### `<section>`

Should check out what exactly it is used for but probably for dividing the page into 
sections :) 

### `<aside>`

Contains content related to the other content in the page but not as directly.

### `<footer>`

Footer information of the page (pretty self explanatory).

### `<a>`

Creates hyperlinks.

### `<img>`

Displays an image.

### Lists 

#### `<ul>` - unordered lists

We create unordered lists with `<ul>` tag. We add elements with `<li>` tag. We 
can nest lists.

#### `<ol>` - ordered lists

We create ordered lists with `<ol>` tag. We add elements with `<li>` tag. We can nest 
lists. Example:
```html
<ol>
  <li>First list item.</li>
  <li>Second list item.</li>
  <li>Third list item.
    <ul>
      <li>Subitem one.</li>
      <li>Subitem two.</li>
      <li>Subitem three.</li>
    </ul>
  <li>Fourth list item.</li>
  <li>Last list item.</li>
</oL>
```

The result is:

1. First list item.
2. Second list item.
3. Third list item.
   - Subitem one.
   - Subitem two.
   - Subitem three.
4. Fourth list item.
5. Last list item.

## HTML Character Entity References

Sometimes we need to use characters which are not present on a standard keyboard or 
we have to use characters like `<`, `>`, `&` which are special characters (these 
three in particular **must always** be escaped).

Another use we have for entity references is when we use smaller character sets.
If you use an HTML entity name or a hexadecimal number, the character will always 
display correctly, independent of what character set (encoding) your page uses! 

List of some of the more important characters to escape:
- `<` - `&lt;` - less than
- `>` - `&gt;` - greater than
- `&` - `&amp;` - ampersand
- **NBSP** - `&nbsp;` - non-breaking space. When a line is too long to show at 
  once on the screen the browser usually breaks it at the white spaces and shows it 
  on several rows. NBSP prevents this line wrapping so for example:
  ```html
  This&nbsp;will&nbsp;show&nbsp;without&nbsp;line&nbsp;wrapping.
  ```
  will always show on one line. Note that NBSP **should not** be used to insert 
  multiple white spaces. We should use a styled `<span>` tag for example.
- © - `&copy;` - copyright symbol (this might not show up properly depending on how 
  you view this file)

## Hyperlinks

The `<a>` HTML element (or anchor element), with its `href` attribute, creates 
a hyperlink to web pages, files, email addresses, locations in the same page, 
or anything else a URL can address.
```html
<a href="https://example.com" title="Link to example website">Link text.</a>
```
Content (the link text) within each `<a>` should indicate the link's destination.
The `title` attribute specifies extra information about an element. The information 
is most often shown as a tooltip text when you mouseover the element (it is also 
used with screen readers for the visually impaired).

`href` works with external links (like "https://example.com") and relative links 
to a different page of the same website. You can also link to a section of the same 
document - just type `#section_id` in place of the link where `section_id` is a 
valid id of an element in the document. You can have a look at [01-links-example] 
document to see examples of links. 

You can also have images as links. Just put `<img>` tag inside of `<a>` tag.

You can specify if you want to open the link in new tab with the `target` attribute 
equal to `_blank` like this:
```html
<a href="https://example.com" target="_blank">link text</a>
```

## Images

The `<img>` tag is used to display an image like this:
```html
<img src="link to an image" width="number" height="number" alt="Some description of the image.">
```
As you can see `<img>` is a self closing tag (doesn't have a closing tag). 
It is also an inline element. Width and height should always be specified whenever 
possible because if the images don't load (their link is broken for example) the 
page won't get messed up visually - the space would still be reserved for the 
image it just won't show. `alt` attribute is similar (but not exactly the same) 
to `title` attribute in the `<a>` tag.

You can see the example file [02-images-example].

[01-links-example]: ../examples/01-links-example.html "Examples for link in a webpage."

[02-images-example]: ../examples/02-images-example.html "Example for images in a webpage."

[html5-living-standard]: https://html.spec.whatwg.org/

[W3C]: https://www.w3.org/ "World Wide Web Consortium"

[WHATWG]: https://whatwg.org/