NAME ?= main

ASM=asar
ASMFLAGS=

VPATH=src

.PHONY: all
all: $(NAME).sfc

$(NAME).sfc: main.asm
	$(ASM) $(ASMFLAGS) $^ $@

# Clean directory
.PHONY: clean
clean:
	rm $(NAME).sfc
