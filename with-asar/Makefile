# This makefile is largely pointless, but it allows
# for easier manipulation of the build process, so
# it's worth adding in.

# The name of the resulting ROM file. This will be
# overwritten by Nix when 'nix build' is called.
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
