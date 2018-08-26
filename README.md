# spell_check
A rudimentary spell checking program.

You can use this program by either passing it a file as an argument, or with no arguments and use the stdin stream for input.

**Examples**

Use file as input source

```shell
      ./spell_check filename
```


Use stdin as input source, to terminate when finished enter the EOF character (ctrl+d)

```shell
      ./spell_check
      A rndom sentnce
      Another random sentcne
      
      rndom
      sentcne
```
With suggestions

```shell
      ./spell_check
      This is a rudmentry speel checking progam !!

      progam: Did you mean ? program

      rudmentry: Did you mean ? rudimentary

      speel: Did you mean ? Spiegel spell spiel
```
