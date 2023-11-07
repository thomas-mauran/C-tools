BUILD_FOLD=build

COMPILER=gcc

# FOLDERS
HEX_TOOL=hextool

all: hextool


install: hextool
	sudo cp $(BUILD_FOLD)/$(HEX_TOOL) /usr/local/bin

hextool: mkdir
	$(COMPILER) $(HEX_TOOL)/main.c -g -o $(BUILD_FOLD)/$(HEX_TOOL) -lm
	
mkdir:
	mkdir -p build