  # build an executable named slist from main.c
  # -g adds debugging info
  #  the build target:
slist: main.c 
	gcc main.c -g -o slist

clean:
	rm slist
