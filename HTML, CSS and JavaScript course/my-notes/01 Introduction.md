# Introduction to The Course

## Course Resources

GitHub repo of the course: https://github.com/jhu-ep-coursera/fullstack-course4  
There are short examples on every topic so it can serve as a fast refresher of 
knowledge.

### Recommended Books

These books are located in the folder `recommended-books`.
   
1. ["HTML and CSS, Design and Build Websites - Jon Duckett (Wiley) (2011)"][Jon-Duckett-HTML-CSS-book]
2. ["JavaScript and JQuery, Interactive Front-End Web Development - Jon Duckett (Wiley) (2014)"][Jon-Duckett-JavaScript-JQuery-book]
3. ["JavaScript, The Definitive Guide, Activate Your Web Pages - David Flanagan (O'Reilly Media) (2011)"][David-Flanagan-definitive-guide-book]

   > "A must-have reference for expert JavaScript programmers...well-organized and detailed." - Brendan Eich, creator of JavaScript, CTO of Mozilla.
   
## Software Used

### Browsersync

[Browsersync] is a module for Node.js. It gives us helpful tools for web development that
can cut out repetitive tasks. We will mainly use it to refresh the webpage automatically 
when we change the files of the website. To do that go to the project directory in 
Command Prompt and type:
```
browser-sync start --server --directory --files "*"
```
This basically tells Browsersync to watch all files in the directory and when changed 
refresh the page in the browser.

**Note:** this command does not work in PowerShell because it is an external command.
Just use Command Prompt.

To stop Browsersync tracking press `Ctrl + C` in Command Prompt or exit Command Prompt.

### GitHub Pages

GitHub allows us to host a website directly from a repository. We can just edit the
site files, push to the repo and the changes are live. When in the repository go to
**Settings**, go to **Pages** and you can see the link for the website (which should 
be in the form `https://username.github.io/repo_name/`).

We will use GitHub Pages to submit assignments. Note that the repo must be public
in order to submit assignments.

### Online Tools

[JSfiddle] - lets you write HTML, CSS or JavaScript code and share it via a link.

[Codepen] - similar to JSfiddle.

[Caniuse] - shows you which HTML features are supported on which browsers.

[Validator] - check if HTML is valid.


[Browsersync]: https://browsersync.io/

[Caniuse]: https://caniuse.com/?search=h1

[codepen]: https://codepen.io/ "Website that lets you write and share HTML, CSS and JavaScript code." 

[David-Flanagan-definitive-guide-book]: ../recommended-books/JavaScript,%20The%20Definitive%20Guide,%20Activate%20Your%20Web%20Pages%20-%20David%20Flanagan%20(O'Reilly%20Media)%20(2011).pdf

[Jon-Duckett-HTML-CSS-book]: ../recommended-books/HTML%20and%20CSS,%20Design%20and%20Build%20Websites%20-%20Jon%20Duckett%20(Wiley)%20(2011).pdf

[Jon-Duckett-JavaScript-JQuery-book]: ../recommended-books/JavaScript%20and%20JQuery,%20Interactive%20Front-End%20Web%20Development%20-%20Jon%20Duckett%20(Wiley)%20(2014).pdf

[jsfiddle]: https://jsfiddle.net/ "Website that lets you write and share HTML, CSS and JavaScript code."

[Validator]: https://validator.w3.org/#validate_by_input+with_options "Check if HTML is valid."