# Background of Elements

## Commonly Used Elements

- `background` - with this property we can specify the properties below all at once.
  For example:
  ```css
  div {
    background-color: red;
    background-image: url("../images/happy-face-fox.jpg");
    background-position: center center;
    background-repeat: no-repeat;
  }
  /* Is the same as */
  div {
    background: red url("../images/happy-face-fox.jpg") center center no-repeat;
  }
  ```
  Note that `background` overwrites all these sub-properties if defined after them.
- `background-color` - solid color for the background of the element.
- `background-image` - image as background. We specify the image like so:
  ```css
  div { background-image: url("myImage.png"); }
  ```
  - The quotes are not mandatory but it's good practice to put them.
  - If we use relative URL it has to be relative to the file the CSS rule is in.
  - When both `background-color` and `background-image` are set the image is in 
    front of the background color.
- `background-position` - specify the position of the image in the box. We give it 
  two values - horizontal and vertical (for example `background-position: center 
  center;` puts the image at the center).
- `background-repeat` - if the image is too small to cover the whole element box 
  we can choose to repeat it. By default repeat is on.

