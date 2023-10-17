TCH = gcc 
SRC = $(wildcard *.c)
OBJ =  $(SRC:.c=.o)

project_nam = app.


all: $(project_nam)exe

%.o: %.c
	$(TCH) -c $< -o $@

$(project_nam)exe: $(OBJ)
	$(TCH) $(OBJ) -o $@
	
clean:
	rm *.o *.exe