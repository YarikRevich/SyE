#Tutorial of writing custom theme configs
In order to create your own config for theme colors
you gotta follow futher instructions...

Config should be written in YAML. General framework should be like this

```
insert:
  - "..."
  - "..."
command:
  - "..."
  - "..."
effects:
  - "..."
```
The first color of each theme elements(except of "effects", it has only background color) is a font color, but the
second one is for backgound. Both of them should have only these values
 - RED(red)
 - GREEN(green)
 - YELLOW(yellow)
 - BLACK(black)
 - BLUE(blue)
 - GREY(grey)
 - WHITE(white)