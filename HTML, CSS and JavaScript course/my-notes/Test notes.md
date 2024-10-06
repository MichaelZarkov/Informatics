# Test Notes

This document contains the questions from the tests from the course.

## HTML Questions

1. The core purpose of HTML is to:  
   - [ ] Display web page content to the user.
   - [x] Communicate the structure of the content.
   - [ ] Tell the browser how to position and align content in the browser window.
   - [ ] Tell the browser what should happen once the page is loaded.
2. W3C (World Wide Web Consortium) is the only organization that dictates what 
   and how browsers should implement HTML5:
   - [ ] True
   - [x] False (WHATWG also plays a big role)
3. WHATWG does NOT version HTML. For them, it's NOT HTML5. It's just HTML:
   - [x] True (Yes, they don't put a version on it)
   - [ ] False
4. All HTML tags must:
   - [x] have an opening tag.
   - [ ] have a closing tag.
   - [ ] have at least 1 attribute.
   - [ ] be lower case.
   - [ ] have an 'id' attribute.
5. Identify correct HTML5 page declaration(s):
   - [x] `<!doctype html>`
   - [x] `<!DocType HTml>`
   - [x] `<!doctype    HTML   >`
   - [ ] `<! doctype html>` (error: space after `!`)
6. Without applying any additional styles, the following code snippet will 
   show up in the browser as how many lines of text? (Assume the browser 
   is stretched wide enough not to cause any single line to wrap).
   ```html
   <div>Dear all,
   <span>I took this really cool course
   </span></div>
   <span>on Coursera.org. I think it's
   my favorite course I've EVER taken!
   Here is the URL for it:
   </span>
   <a href="...">HTML, CSS and JS for Web Developers</a>
   <div>
   Does anyone know how I can give this course 6
   out of 5 stars?
   </div>
   <div>
   Thank you,
   -Yaakov.... I mean a random student! Definitely not Yaakov.
   </div>
   ```
   - [x] 4 lines
7. Semantic HTML tags:
   - [x] May halp the SEO (search engine optimization) of the page.
   - [x] Help computers better understand the structure of the page.
   - [x] Help humans better understand the structure of the page.
   - [ ] Are required to be used in HTML5.
8. One purpose of HTML Character Entity References is
   - [x] To allow the browser to display certain characters it would otherwise 
         interpret as part of HTML code and not something to display to the user.
   - [ ] HTML Character Entity References were useful before HTML5 was introduced. 
         After HTML5, they are no longer needed.
   - [ ] Identify character sets that the browser can support.
9. Using only HTML, how would you make sure that 3 words in an HTML document 
   ALWAYS appear together on 1 line, even if the text word-wraps because the browser 
   window is too narrow for that text line?
   - [ ] Impossible to accomplish with HTML alone!
   - [ ] Place `&nowrap;` entity reference before the 1st word and after the 3rd word.
   - [x] Place `&nbsp;` entity reference after the 1st word and after the 2nd word 
         (with no spaces in between words and entity references).
   - [ ] Place `&nbsp;` entity reference before the 1st word and after the 3rd word.
10. How can you force the browser to open a link in a new window or tab?
    - [ ] Send some special meta tags as part of the page.
    - [ ] Instruct the user to right-click on the link and choose "Open in a New Tab".
    - [x] Include `target='_blank'` attribute as part of the `<a>` tag.
    - [ ] Include `target="new"` attribute as part of the `<a>` tag.
11. The following code rendering in the middle section of the page allows someone 
    to directly link to that middle section of the page, not just the beginning of 
    the page:
    ```html
    <div id="superInterestingContentHere">Bla Bla</div>
    ```
    - [x] True (we can use the `id` to link to this section of the page)
    - [ ] False
12. Even though the width and height attributes of the `<img>` tag are not 
    required, it's always a good idea to use them.
    - [x] True
    - [ ] False

## CSS Questions

1. A style sheet is a collection of CSS rules.
   - [x] True
   - [ ] False
2. Identify the valid CSS rules:
   - [x] 1 
   ```css    
   p {
      height: 23px;
      font-size: 12px;
   }
   ```
   - [x] 2
   ```css
   p { height: 23px; font-size: 12 px; }
   ```
3. A CSS rule can be applied to **only** one selector at a time.
   - [ ] True
   - [x] False (we can have multiple selectors for a given rule)
4. A CSS rule has to be defines separately for each selector.
   - [ ] True
   - [x] False (we can have multiple selectors for a given rule)
5. Given the following HTML code:
   ```html
   <div>
      <p>I am feeling blue</p>
   </div>
   <section>
      <p>I just want to be left alone!</p>
   </section>
   ```
   Which of the following CSS rules turns the text of the first `<p>` tag blue, but 
   NOT the second `<p>` tag?
   - [x] `div > p { color: blue; }`
   - [ ] `div.p { color: blue; }`
   - [x] `div p { color: blue; }`
   - [ ] `p { color: blue; }`
6. Given the following HTML code:
   ```html
   <div>
      <div>
         <div class="makeMeBlue">
            <p>I am feeling blue</p>
         </div>
      </div>
      <section class="makeMeBlue">
         <p>I just want to be left alone!</p>
      </section>
   </div>
   ```
   Which of the following CSS rules turns the text of the first `<p>` tag blue, but 
   NOT the second `<p>` tag? 
   - [ ] `.makeMeBlue > p { color: blue; }`
   - [x] `div.makeMeBlue p { color: blue; }`
   - [x] `div > div > p { color: blue; }`
   - [ ] `div p { color: blue; }`
7. By default, a block-level element tries to take up as much horizontal space 
   as its containing element will allow.
   - [x] True
   - [ ] False
8. Given the following HTML code:
   ```html
   <body>
     <div>Hello</div>
     <span>World!</span>
   </body>
   ```
   and the following CSS code:
   ```css
   div, span { background-color: blue; }
   ```
   Which of the statements are true?
   - [x] The background color behind the words 'Hello' and 'World' is blue.
   - [ ] Both backgrounds will span the entire width of the browser window.
   - [x] The div element's background will span the entire width of the browser.
   - [ ] The span element's background will span the entire width of the browser.
   - [x] The text "World!" will appear on a separate line, below the text "Hello".
9. Given the following HTML code:
   ```html
   <a>
     <div>Div 1</div>
     <div>Div 2</div>
     <div>Div 3</div>
     <div>Div 4</div>
     <div>Div 5</div>
     <div>Div 6</div>
   </a>
   ```
   Which CSS rule below will set the font size of 'Div 5' text to 24px when the 
   user hovers the mouse over **ANY area inside the 'a' element?**
   - [ ] `a:hover:nth-child(5) { font-size: 24px; }`
   - [x] `a:hover div:nth-child(5) { font-size: 24px; }`
10. It's a good idea to place all of your CSS styles into a separate file, external 
    to the HTML page, because you can share the same styles across multiple HTML 
    pages that way.
    - [x] True
    - [ ] False
11. Given the following HTML code:
    ```html
    <style>
      body { color: blue }
    </style>
    ...
    <body>
      <div>
        <section id="mySection">
          I am having a color identity crisis!
        </section>
      </div>
    </body>
    ```
    What color will the words "I am having a color identity crisis!" be?
    - [x] Blue.
    - [ ] Whatever the default color the browser assigns to it since we didn't 
          specify the color of the `<section>` tag.
12. Given the following HTML code:
    ```html
    <style> 
      #mySection { color: green; }
      .myColor { color: blue; }
    </style>
    ...
    <body>
      <div>
        <section id="mySection" class="myColor">
          I am having a color identity crisis again! Help!
        </section>
      </div>
    </body>
    ```
    What color will the words "I am having a color identity crisis again! 
    Help!" be?
    - [ ] Blue.
    - [x] Green.
13. Pixels are absolute units of measurements (as opposed to relative).
    - [x] True
    - [ ] False
14. Given the following HTML code:
    ```html
    <head>
      <style>
        body { font-size: 30px; }
      </style>
    </head>
    <body>
      <div style="font-size: 3em;">How big am I?</div>
    </body>
    ```
    What is the pixel size of the text "How big am I?", assuming the user did 
    NOT increase zoom in the browser window?
    - [x] 90px
    - [ ] 10px
    - [ ] 1/3 of a pixel
15. Assuming no other styles exist, how many pixels wide will the `div` tag be 
    with the following styles:
    ```css
    div {
      padding: 10px 10px 10px 10px;
      margin: 10px 10px 10px 10px;
      width: 100px;
      border: 10px solid black;
    }
    ```
    - [x] 140px (10+10+100+10+10=140; margins are not counted as part of the box)
    - [ ] 200px
    - [ ] 100px
    - [ ] 160px
16. Assuming no other styles exist, how many pixels wide will the 'div' tag be 
    with with following styles:
    ```css
    div {
      padding: 10px 10px 10px 10px;
      margin: 10px 10px 10px 10px;
      width: 100px;
      border: 10px solid black;
      box-sizing: border-box;
    }
    ```
    - [x] 100px (`box-sizing` is set to `border-box`)
    - [ ] 140px
    - [ ] 160px
17. Given the following HTML code:
    ```html
    <div style="background-color: blue; background: url('myPicture.jpg');"> ... </div>
    ```
    What will you see inside the div element?
    - [ ] Image on blue background.
    - [ ] Blue background with no image.
    - [ ] Blue background will be covering the image.
    - [x] Only the image. (`background` property is defined after `background-color` 
          so it overwrites it with only the image)
18. Floating elements takes them out of the regular document flow.
    - [x] True
    - [ ] False
19. The following code:
    ```css
    section { clear: right; }
    ```
    says that none of the section elements should allow anything to float to the 
    right of them.
    - [x] True
    - [ ] False
20. Setting `position: relative;` on an element takes it out of the regular 
    document flow.
    - [ ] True
    - [x] False (doesn't disrupt the document flow)
21. By default all HTML elements have their position set to static.
    - [ ] True
    - [x] False (the `html` element is not static by default)