CC = gcc
DIR = build
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, $(DIR)/%.o, $(notdir $(SOURCES)))
OUTPUT = output.exe

$(OUTPUT): $(OBJECTS)
	$(CC) $^ -o $@ -g

$(DIR)/%.o: %.c
	$(CC) -c $^ -o $@ -g

clean:
	rm -f $(DIR)/* $(OUTPUT)