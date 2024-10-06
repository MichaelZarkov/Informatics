# Styling Text

## Font Size

We have two ways of measuring font size - **absolute** and **relative**.

### Absolute Font Size

The pixel measurement `px` is considered absolute font size. There is some 
relative component to it because of the resolution and DPI of screens but it's 
still considered absolute. We define it like this:
```css
body { font-size: 20px; }
p { font-size: 16px; }
```
Usually browsers have default font size of 16px.

### Relative Font Size

**Percentages** and **"ems"** are relative font sizes. We define them like so:
```css
body { font-size: 150%; }
p { font-size: 2em; }
div { font-size: 0.5em; }
```
Relative font sizes have cumulative effect. The above `body` rule says that 
*whatever the size of the text in the body at the moment increase it to 150%*.
The `p` rule says *whatever the size of the text in a paragraph increase it 
two times*. So if we have a paragraph `p` in body its text will increase three 
times (1.5 * 2 = 3). Here's an example:
```html
<body style="font-size: 20px;">Text 20px.
  <div style="font-size: 2em;">Text 40px.
    <div style="font-size: 2em;">Text 80px.
      <div style="font-size: 0.5em;">Text 40px.</div>
    </div>
  </div>
</body> 
```
Of course you can use percents and the result will be the same.

## Common CSS Properties for Styling Text

Here is an example of common text styling properties:
```css
.myClass {
  font-family: Arial, Helvetica, sans-serif;
  color: #0000ff;
  font-style: italic;
  font-weight: bold;
  font-size: 24px;
  text-transform: uppercase;
  text-align: right;  
}
```
- `font-family` - the font of the text. We usually specify a couple of fonts 
  (called **fallback fonts**) separated with a comma in case the browser doesn't 
  support the font. The browser sees the first font (in this case `Arial`), if 
  it has it installed it uses it, if it doesn't uses the next font (`Helvetica`) 
  and so on.
- `color` - color of the text. It is best to specify it with a hexadecimal number 
  as shown. First two digits are for the red channel; second two for the green; 
  last two for the blue. The text in the example is pure blue.
- `font-style` - whether the text is italic or normal.
- `font-weight` - boldness of the text; can be specified as a number.
- `font-size` - self explanatory. Can be relative or absolute.
- `text-transform` - transformations of text like uppercase, lowercase, 
  capitalize.
- `text-align` - center, left, right, justify.