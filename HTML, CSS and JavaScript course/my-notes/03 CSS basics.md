# CSS Basics

## Illustration of CSS

**CSS** (cascading style sheets) is an extremely powerful tool for styling a 
webpage. The exact same HTML source document can be styled beyond 
recognition just by changing the CSS. We use CSS for the hugely important task - 
creating the user interface and user experience. Yes, we could just use the raw 
HTML for our website but for the average user that would be boring and they'd 
probably leave our site immediately. 

One example of the power of CSS is [CSS Zen Garden][css-zen-garden]. People can 
download the source HTML and provide their own CSS and imagery - so the content 
is the same just the CSS is different. The plethora of different looks are 
available to see and you can also see the CSS behind it.

## CSS Properties and CSS Rules

*You style HTML elements via **CSS properties**. Different HTML elements may have 
different CSS properties you can set. CSS properties can be organized into **CSS 
rules**. A CSS rule groups a set of CSS properties together, and applies all 
properties to the HTML elements matched by the CSS rule.*

### CSS Properties

*A **CSS property** styles an aspect of an HTML element*.  
Properties and their 
values are predefined in the CSS specification so not all HTML elements have the 
same set of properties. Properties are specified with name-value pairs like so 
`property-name: value`. A name-value pair is called a **declaration**. If we 
have more properties one after the other we have to separate them with semicolon. 
For example:
```html
<h1 style="color: crimson; font-size: 26px; text-align: center;">
  Examples of CSS Properties
</h1>
```
Here `color`, `font-size` and `text-align` are properties with respective values 
`crimson`, `26px` and `center`. The properties are applied to the `h1` element. 
As you can see from this example CSS properties can be changed directly in the 
opening tag of and element. However in real world applications we do this basically 
never because reusability of code will be zero and consistency of the style of the 
webpage will be extremely hard to maintain (we have to copy and paste the 
properties for every single `h1` element). We do it this way only when testing. 

### CSS Rules

*A **CSS rule** is a grouping of zero or more CSS properties which are to be applied 
to one or more target HTML elements.*  
A CSS rule consists of a CSS **selector** and a **set of CSS properties**. The CSS 
selector determines what HTML elements to target with the CSS rule. The CSS 
properties specify how to style the targeted HTML elements. Here is a CSS rule 
example:
```css
p {
  color: brown;
  font-size: 16px;
  width: 1000px;
}
```
This rule targets all `p` (paragraph) elements. Here `p` is the selector.

*A collection of these rules is called a **style sheet**.*

One place where we can put rules is in a `<style>` tag inside the `<head>` tag:
```html
<!doctype html>
<html>
  <head>
    <title>My HTML Document</title>
    <style>
      h1 { color: red; }

      p {
        color: brown;
        font-size: 16px;
        width: 1000px;
      }
    </style>
  </head>
  <body>Body ...</body>
</html>
```
However this is still not the best place to put rules because it limits reusability.
Best place to put rules is in external `.css` files and then include them in the 
HTML file in the `<head>` section like so:
```html
<link href="link to the file" rel="stylesheet">
```
`rel="stylesheet"` specifies that the file is CSS file to be used for styling. CSS 
files are just text files with rules one after the other. Just like HTML, CSS files 
are processed from top to bottom.

## Selectors in Rules

*CSS selectors are used to determine which element ar set of elements to apply the 
declarations to.*
Knowing how to craft a selector to target particular elements is useful not only for 
CSS but also for JavaScript because some libraries use the browser selector API to 
attach behavior and data to elements.

### Element Selector

We just specify the name of the element.
```css
/* This selector says that the text in each paragraph element will be colored blue. */
p { color: blue; }
```

### Class Selector

We specify the name of the class with a dot `.` in front of it. Every element that 
has its attribute `class` set to `myBlueClass` (so `class="myBlueClass"`) will have 
blue colored text.
```css
/* Elements from class 'myBlueClass' will have blue text. */
.myBlueClass { color: blue; }  /* We call this class definition. */
```
```html
<!-- The HTML -->
<div class="myBlueClass">
  I WILL be blue. 
  <span>If no other CSS rules are applied I WILL be blue. You can check out "inheritance" in "Conflict Resolution" to find out why.</span>
</div>
<div>I WON't be blue.</div>
```
Note that an element can belong to multiply classes. We just separate the class 
names by a space:
```html
<div class="class-1 class-2">...text...</div>
```
A class selector can have multiple classes. Just separate the class names by a 
dot `.`.
```css
/* Affects elements that belong to both 'class-1' and 'class-2'. */
.class-1.class-2 { color: red; }
```

### ID Selector

We specify the value of the `id` of an element preceded by a hashtag `#`.
```css
#last-paragraph { color: blue }
```
```html
<span id="last-paragraph">I'm the only element affected by the rule</span>
<p>I'm not affected.</p>
```
The ID selector is the least general one because only one element in a document can 
have this particular ID value.

### Universal Selector `*`

Selects every element. We use it if we want every element to have a particular
property. Useful for properties that cannot be inherited.

```css
* { color: blue; }  /* Text everywhere will be blue. */
```

### Grouping Selectors

We can apply the same rule to more than one selector (group of elements) by separating 
the selectors with a comma `,`.
```css
/* I will be applied to every div element and every element with class attribute set to myBlueClass. */
div, .myBlueClass { color: blue; }
```
Check out [03-css-selectors-example.html] for an example.

### Combining Selectors

*Combining selectors allows us to more precisely target elements.*  

#### Element with class selector

Allows us to target particular element from a particular class. We can also say that 
the element has to belong to more than one class.
```css
/* Targets all elements 'p' that belong to the 'small' class. */
p.small { font-size: 10px; }
/* Targets all elements 'p' that belong to both 'big' and 'bold' classes.  */
p.big.bold { font-size: 20px; font-weight: bold; }
```

#### Child Selector (direct child selector)

Allows us to target direct children of an element. You read this selector from 
right to left - for example `div > p` is read *every `p` element that is a direct 
child of a `div` element*.
```css
/* Every 'p' element which is a DIRECT child of a 'div' element will be affected. */
div > p { color: red; }

/* We can have more arrows. */
/* Every 'p' element which is a DIRECT child of 'div' element which is a DIRECT child of another 'div' element will be affected. */
div > div > p { color: red; }

/* We are not limited to only element selectors. We can also use class and ID selectors. */
/* Affects every 'span' element direct child of element from class 'my-class', direct child of element with id="id-1". */
#id-1 > .my-class > span { color: red; }
```

#### Descendant Selector

Targets children of an element at any level. It's also read from right to left.
```css
/* Affects every 'p' element that's a child at any level of an 'article' element. */
article p { color: blue; }

/* We are not limited to element selectors. */
/* Affects every element from 'class-2' which is a child at any level on an element from 'class-1'. */
.class-1 .class-2 { color: red; }

/* Can we have something like this??? */
div div p { color: red; }
```

#### Adjacent Sibling Selector

Targets elements that directly follow a certain element. Also read from right to 
left. Used less often.
```css
/* Targets all 'p' elements that directly follow a div element */
div + p { color: red; }
```
```html
<p>I won't be red.</p>
<div>I won't be red.</div>
<p>I WILL be red.</p>
<p>I won't be red.</p>
```

#### General Sibling Selector

Targets all siblings following an element. Read from right to left. Used less often.
```css
div ~ p { color: red; }
```
```html
<p>I won't be red.</p>
<div>I won't be red.</div>
<p>I WILL be red.</p>
<h2>I won't be red.</h2>
<p>I WILL be red.</p>
```

Check out [04-css-combining-selectors-example.html] for an example.

### Pseudo-class Selectors

A CSS **pseudo-class** is a keyword added to a selector that specifies a special 
state of the selected element(s). For example, the pseudo-class `:hover` can be used 
to select a button when a user's pointer hovers over the button and this selected 
button can then be styled. There are many different pseudo-classes defined in the 
CSS specification. Here are some of the more common ones:

- `:link` - matches links that have not yet been visited.
- `:visited` - matches links that have been visited.
- `:hover` - matches when you hover over the element with your mouse.
- `:active` - matched when the item is clicked on but the mouse button is not 
  yet released.
- `:nth-child()` - matches elements based on the indexes of the elements in the 
  child list of their parents. In other words, the `:nth-child()` selector selects 
  child elements according to their position among all the sibling elements within 
  a parent element.

See examples at [05-css-pseudo-classes].

## Conflict Resolution

The following is an example of conflicting rules:
```css
p { color: red; }
p { color: blue; }
```
CSS has a way to determine which rule takes precedence. This is the job of the 
so called **cascade algorithm** - hence the name **cascading** style sheets. 
I will highlight the main determining factors for which rule gets applied however 
there are some features which I'll skip. Still most of the thing should be correct.

*Here are some basic concepts:*
- *Merge*
- *Inheritance*
- *Specificity*
- *Origin precedence*

### Merge

If two rules target the same element and they don't have a conflict then both get 
applied (they merge). Example:
```html
<style>
  p { color: red; }
  .my-class { background-color: blue; }
</style>
...
<p class="my-class">Red text on blue background.</p>
<!-- The two rules don't conflict so both get applied. -->
```

### Inheritance

All children (at any level) inherit the styles from their parents unless a rule 
specifies otherwise. Inheritance has specificity score of zero - the lowest 
possible - so everything overwrites it. Example:
```html
<style>
  body { color: blue; }
  .my-class { color: red; }
</style>
...
<body>
  This text is blue.
  <p class="my-class">This text is red <span>and this text is also red.</span></p>
  <p>This text is blue <span>as well as this text.</span></p>
</body>
```
Most commonly we specify some properties for `<body>` so that we have a consistency 
of the style in our webpage.

### Specificity

Specificity roughly determines how well the selector matches the tag. If rule A
is more specific than rule B then A gets applied. The specificity score can be 
determined as a vector (a, b, c, d).
We have 4 criteria in order from most to least important:
1. Inline style
2. ID
3. Class, attribute selector and pseudo-class
4. Elements (like `div`) and pseudo-elements

The scoring system is best explained with examples so here we go:
1. `<p style="color: blue;"> ... </p>` - this has a score of (1, 0, 0, 0) and that 
   is basically the highest score so inline styles overwrite (almost) everything.
2. `#id-1 { ... }` - this rule gets a score of (0, 1, 0, 0) so less than the inline 
   style. If we have a conflict the inline style will win.
3. `.class-1.class-2 > .class-3 { ... }` - the score here is (0, 0, 3, 0) because 
   we have 3 classes (can be also attribute selectors or pseudo-classes). So 
   the score is the number of classes. If we had a conflict with ID selector, the ID 
   selector will win (has a 1 in second position).
4. `div p { ... }` - again we count the number of elements and get the score 
   (0, 0, 0, 2).

Some more examples:
1. We have the following two conflicting rules for the `<span>` tag. 
   ```css
   div p > span.my-class { color: red; }
   .my-class .my-class { color: blue; }
   ```
   ```html
   <div>
     <p class="my-class">
       <span class="my-class">This text will be blue.</span>
     </p>
   </div>
   ```
   First rule has specificity score (0, 0, 1, 3).  
   Second rule has specificity score (0, 0, 2, 0).  
   Second rule is with higher specificity score so it gets applied.

Note that there are online specificity calculators and VS Code even tells you 
the specificity when you mouseover a rule.

### Origin Precedence

When we have two conflicting rules with **the same specificity** the rule that comes 
last gets applied. For example:
```html
<style>
  .class-2 > .class-3 { color: red; }
  
  /* ... some more rules ... */
  
  .class-1 .class-3 { color: blue; }
</style>
...
<body class="class-1">
  <div class="class-2">
    <p class="class-3">This text will be blue.</p>
  </div>
</body>
```
The two selector in the rules match the element `p`; they have the same specificity 
so the second one gets applied. If we had the second rule in and external CSS file 
the result would've been the same because the file is declared after the first rule. 

Order also matters inside of rules. For example:
```css
p {
  color: red;
  color: blue;
}
```
The color for a paragraph will be blue. The browser doesn't give an error when we 
do this. Actually if the browser encounters something that it doesn't understand 
it just ignores in. So a common practice is:
```css
p {
  font-family: Arial;
  font-family: /* Insert some obscure font that has limited support in browsers. */
}
```
In the browser supports the fancy font it will use it; if not it will use Arial.

### Order of Application of Rules

Rules are applied in this order:
1. A more specific selector takes precedence over a less specific one.
2. Rules that appear later in the code override earlier rules if both have the 
   same specificity.
3. A css rule with `!important` always takes precedence.

We use `!important` like this:
```css
p {
  color: red !important;
}
```
However just like `goto` in `C` it is really best not use it (use it only in 
very special cases).



[css-zen-garden]: https://csszengarden.com/ "Website showcasing the power of CSS."
[03-css-selectors-example.html]: ../examples/03-css-selectors-example.html
[04-css-combining-selectors-example.html]: ../examples/04-css-combining-selectors-example.html
[05-css-pseudo-classes]: ../examples/05-css-pseudo-classes.html