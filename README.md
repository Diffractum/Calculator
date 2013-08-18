Bistromathique
==============



Make a Bistromathique with nice rules:

::
	- 25 lines per fonction
	- 5 fonctions per file
	- only malloc, free, read, write and ... nothing else
	- for is banned from the bistro
	- and more things like that

# Bistromathique work like that:

echo "math expr" | ./calc "base" "operator" "size of expr"
::
	ex : echo "50*10+(32-5+(856/50))" | ./calc "0123456789" "()+-*/%" "21"
