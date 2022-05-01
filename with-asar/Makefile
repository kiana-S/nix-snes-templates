# This makefile is largely pointless, but it allows
# for easier manipulation of the build process, so
# it's worth adding in.

ASM=asar
ASMFLAGS=
VPATH=src

.PHONY: all
all: main.sfc

main.sfc: main.asm
	$(ASM) $(ASMFLAGS) $^ $@

# Clean directory
.PHONY: clean
clean:
	rm main.sfc
