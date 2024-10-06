# CSS Layout

## The CSS Box Model

*In CSS and HTML every element is considered a box.* The **box model** refers 
to the different components of these boxes, the ways the boxes affect the layout 
and the way widths and heights are calculated.

From inside to outside a box's components are:
- content - where text and images appear.
- padding - clear area between the content and border of a box. Transparent by 
  default - meaning that if some other box is behind it it will show through.
- border - the border of the box.
- margin - clear area outside the border. Transparent by default.

![CSS box components.][box-components]

Google Chrome comes with developer tools installed so you can inspect an element 
from a webpage and see its dimensions.

## Often Used Properties

The following are not complete descriptions of the said properties but the 
main use cases.

- `box-sizing` - the most important one to understand. By default it is set to 
  `content-box` - this means when we set the `width` or `height` of the box we 
  actually set the dimension of the **content** part of the box so the padding 
  and border dimensions are counted separately. For example if we have:
  ```css
  #myId {
    border: 5px;
    padding: 10px;
    box-sizing: content-box;
    width: 200px;
  }
  ```
  then the width of the border plus the padding plus the content will be 
  5+10+200+10+5=230px. This is hard to keep track of so if we instead set the 
  `box-sizing` to `border-box` like so:
  ```css
  #myId {
    border: 5px;
    padding: 10px;
    box-sizing: border-box;
    width: 200px;
  }
  ```
  then the whole width of border, padding and content will be exactly 200px. 
  `border-box` is the preferred way of setting the dimensions and all modern 
  frameworks use this method as their sizing model.
- `background-color` - background color for the padding and the content.
- `border` - width and color of the border.
- `height` - height of the box; behaves differently when `box-sizing` is set to 
  `content-box` or `border-box`. Note that if we restrict the height so that the 
  content doesn't fit then the content will overflow out of the box. One way to 
  deal with this is the property `overflow`.
- `margin` - dimensions of the margin.
- `overflow` - gives us options when the content is too big to fit in a box. By 
  default it is `visible`. We can choose `hidden` content gets clipped to the 
  available space; `auto` - puts scrollbar if necessary; `scroll` - always put 
  scrollbar.
- `padding` - dimensions of the padding.
- `width` - width of the box.
  - Behaves differently when `box-sizing` is set to 
    `content-box` or `border-box`.
  - Can be statically set with `px` (pixels) or dynamically set with `%`. For 
    example if we set width of an element to 50% this means it will use up 50%
    of the width of the **containing element**.

## Where to Define Certain Properties

It is useful for all our element to have the same baseline properties which 
later can be changed or added onto. We usually use the **universal selector** to 
accomplish this:
```css
* {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}
```
The `box-sizing` property is not inherited so this is the best way to put it. 
Browsers usually have default `margin` and `padding` so it's also a good idea 
to reset them to 0.

## Margins

We have two types of margins - **cumulative** and **non-cumulative**. 
- Left and right margins are usually cumulative. If we have two boxes next to 
  one another the left box with margin 30px, the right with margin 20px, then 
  the total margin will be the sum of the two, so 50px.
- Top and bottom margins are usually non-cumulative and the total margin is just 
  the bigger of the two margins. If we have to boxes - one above the other - the 
  top one has margin 30px, the bottom one has margin 20px, then the total margin 
  will be 30px.
- When an element is inside another element and the inner element is not floating 
  then the inner element's top and bottom margin collapses. It will look something 
  like this:
  ![margin-collapse]


## FLoating Elements

*We can take elements out of the regular document flow by floating them. We can 
also tell an element to resume the regular document flow.*

We can float elements to the left or right in their containing element with `float`:
```css
p { float: left; }
div { float: right; }
```
They are taken out the regular document flow and don't interact with it. Instead 
they interact with other floated element.

We can resume regular document flow with the `clear` property. It  specifies what 
should happen with the element that is next to a floating element.
```css
/* Resume document flow after left floating element. */
p { clear: left; }  
/* Resume document flow after right floating element. */
p { clear: right; }
/* Resume in both cases. */
p { clear: both; }
```

You can check out [floating-boxes] for an example.  
You can check out [two-column-layout] for a useful example of floating elements.

## Other Element Positioning

**Static positioning** is synonymous to regular document flow. The default 
for all elements except the `html` element is static positioning. If we try to 
apply positioning offsets to static element nothing will happen. We set it with 
`position: static;`.

**Relative positioning** - here the element is **NOT** taken out of the 
document flow as far as the other elements are concerned but we can *display* it 
in a different place. We use `position: relative;` and to move it we use the 
properties `top`, `bottom`, `left`, `right` - the movement is relative to its 
original position in the document.

**Absolute positioning** - the element is **taken out** of the normal document flow 
and all offsets (top, bottom, left, right) **are relative to the position of the 
nearest ancestor which has positioning set on it other than static**.

**Fixed positioning** - elements is positioned relative to the viewport, which means 
it always stays in the same place even if the page is scrolled. The top, right, 
bottom, and left properties are used to position the element.

There are good examples in the [GitHub repo of the curse][course-repo].

[box-components]: ../images/css-box-components.jpg
[course-repo]: https://github.com/jhu-ep-coursera/fullstack-course4/tree/master/examples/Lecture22
[floating-boxes]: ../examples/07-floating-boxes.html
[margin-collapse]: ../images/margin-collapse.png
[two-column-layout]: ../examples/06-two-column-layout.html