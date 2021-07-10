#Tutorial of writing custom syntax configs
In order to create your own config for syntax highlighting
you gotta follow futher instructions...

Config should be written in YAML. General framework should be like this

```
extension: 
  - "..."
types:
   - name: "..."
     regexp: "..."
     color: "..."
   - ...
```
Extension key should have all the extension what this highlightning will be used for
Each cell of types should contain such keys as (name, regexp and color)
Name key should contain keyword wished to be highlighted.
Regexp key should contain regexp to find such name
Color key should have one of these values written as strings
 - RED
 - GREEN
 - YELLOW
 - BLACK
 - BLUE
 - GREY
 - WHITE