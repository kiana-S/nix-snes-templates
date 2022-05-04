includeonce
lorom

org $00FFE0

; Native mode
dw $FFFF
dw $FFFF
dw $FFFF
dw $FFFF
dw $FFFF
dw VBlank
dw $FFFF
dw $FFFF

; Emulation mode
dw $FFFF
dw $FFFF
dw $FFFF
dw $FFFF
dw $FFFF
dw $FFFF
dw Reset
dw $FFFF


;; Address synonyms for hardware registers


; PPU registers
INIDISP = $2100       ; Control screen brightness and F-blank
OBJSEL = $2101        ; Object properties
OAMADDL = $2102       ; OAM address (low byte)
OAMADDH = $2103       ; ^ (high byte)
OAMDATAW = $2104      ; OAM data write
BGMODE = $2105        ; Background mode
MOSAIC = $2106        ; Mosaic effect switch
BG1SC = $2107         ; Background 1 tilemap
BG2SC = $2108         ; Background 2 tilemap
BG3SC = $2109         ; Background 3 tilemap
BG4SC = $210A         ; Background 4 tilemap
BG12NBA = $210B       ; Backgrounds 1 & 2 graphics
BG34NBA = $210C       ; Backgrounds 3 & 4 graphics
BG1HOFS = $210D       ; Background 1 horizontal scroll
BG1VOFS = $210E       ; ^ vertical scroll
BG2HOFS = $210F       ; Background 2 horizontal scroll
BG2VOFS = $2110       ; ^ vertical scroll
BG3HOFS = $2111       ; Background 3 horizontal scroll
BG3VOFS = $2112       ; ^ vertical scroll
BG4HOFS = $2113       ; Background 4 horizontal scroll
BG4VOFS = $2114       ; ^ vertical scroll
VMAINC = $2115        ; VRAM register settings
VMADDL = $2116        ; VRAM address (low byte)
VMADDH = $2117        ; ^ (high byte)
VMDATALW = $2118      ; VRAM data write (low byte)
VMDATAHW = $2119      ; ^ (high byte)
M7SEL = $211A         ; Mode 7 properties
M7A = $211B           ; Mode 7 matrix A-coordinate
M7B = $211C           ; ^ - B-coordinate
M7C = $211D           ; ^ - C-coordinate
M7D = $211E           ; ^ - D-coordinate
M7X = $211F           ; Mode 7 transform center X-coordinate
M7Y = $2120           ; ^ Y-coordinate
CGADD = $2121         ; CGRAM address
CGDATAW = $2122       ; CGRAM data write
W12SEL = $2123        ; Window enable switches for BG1&2
W34SEL = $2124        ; ^ for BG3&4
WOBJSEL = $2125       ; ^ for objects
WH0 = $2126           ; Window 1 left bound
WH1 = $2127           ; ^ right bound
WH2 = $2128           ; Window 2 left bound
WH3 = $2129           ; ^ right bound
WBGLOG = $212A        ; Window intersection logic (for bgs)
WOBJLOG = $212B       ; ^ (for objects)
TM = $212C            ; Display on main screen
TS = $212D            ; ^ on sub screen
TMW = $212E           ; Enable windowing on main screen
TSW = $212F           ; ^ on sub screen
CGSWSEL = $2130       ; Apply window switch
CGADSUB = $2131       ; Color math method
COLDATA = $2132       ; Subscreen fixed color
INISET = $2133        ; Misc. display settings
MPYL = $2134          ; PPU multiplication result (low byte)
MPYM = $2135          ; ^ (middle byte)
MPYH = $2136          ; ^ (high byte)
SLHV = $2137          ; Scan position CPU latch
OAMDATAR = $2138      ; OAM data read
VMDATALR = $2139      ; VRAM data read (low byte)
VMDATAHR = $213A      ; ^ (high byte)
CGDATAR = $213B       ; CGRAM data read
OPHCT = $213C         ; Horizontal scan position (must be latched)
OPVCT = $213D         ; Scanline (must be latched)
STAT77 = $213E        ; PPU flags, read only
STAT78 = $213F        ; ^
APUIO0 = $2140        ; APU I/O port 1
APUIO1 = $2141        ; ^ port 2
APUIO2 = $2142        ; ^ port 3
APUIO3 = $2143        ; ^ port 4

; WRAM registers
WMDATA = $2180        ; WRAM data access
WMADDL = $2181        ; WRAM address (low byte)
WMADDM = $2182        ; ^ (middle byte)
WMADDH = $2183        ; ^ (high byte)

; Joypad registers
JOYPAD1 = $4016
JOYPAD2 = $4017

; CPU registers
NMITIMEN = $4200      ; Switch for NMI (V-blank)
WRIO = $4201          ; Write to I/O ports of joypads
WRMPYA = $4202        ; Multiplication routine input
WRMPYB = $4203        ; ^
WRDIVL = $4204        ; Division routine input (low byte)
WRDIVH = $4205        ; ^ (high byte)
WRDIVB = $4206        ; Division routine input 2
HTIMEL = $4207        ; Horizontal IRQ timer (low byte)
HTIMEH = $4208        ; ^ (high byte)
VTIMEL = $4209        ; Vertical IRQ timer (low byte)
VTIMEH = $420A        ; ^ (high byte)
MDMAEN = $420B        ; DMA enable flags
HDMAEN = $420C        ; HDMA enable flags
MEMSEL = $420D        ; FastROM switch
RDNMI = $4210         ; NMI flag (should be read at V-blank)
TIMEUP = $4211        ; IRQ flag (should be read at IRQ)
HVBJOY = $4212        ; Blanking flags
RDIO = $4213          ; Read from I/O ports of joypads
RDDIVL = $4214        ; Division result (low byte)
RDDIVH = $4215        ; ^ (high byte)
RDMPYL = $4216        ; Multiplication result (low byte)
RDMPYH = $4217        ; ^ (high byte)
STDCNTRL1L = $4218    ; Auto-joypad-read 1 (low byte)
STDCNTRL1H = $4219    ; ^ (high byte)
STDCNTRL2L = $421A    ; Auto-joypad-read 2 (low byte)
STDCNTRL2H = $421B    ; ^ (high byte)
STDCNTRL3L = $421C    ; Auto-joypad-read 3 (low byte)
STDCNTRL3H = $421D    ; ^ (high byte)
STDCNTRL4L = $421E    ; Auto-joypad-read 4 (low byte)
STDCNTRL4H = $421F    ; ^ (high byte)

; DMA registers
macro dma(c)
DMA<c>PARAM = $43<c>0     ; DMA transfer parameters
DMA<c>ADDB = $43<c>1      ; DMA B-bus address ($21XX)
DMA<c>ADDAL = $43<c>2     ; DMA A-bus address (low byte)
DMA<c>ADDAM = $43<c>3     ; ^ (middle byte)
DMA<c>ADDAH = $43<c>4     ; ^ (high byte)
DMA<c>AMTL = $43<c>5      ; Number of bytes to transfer (low byte)
DMA<c>AMTH = $43<c>6      ; ^ (high byte)
DMA<c>INDH = $43<c>7      ; Indirect HDMA transfer address
DMA<c>ADDA2L = $43<c>8    ; Automatically generated
DMA<c>ADDA2M = $43<c>9    ; ^
DMA<c>LINES = $43<c>A     ; ^
endmacro

; For each DMA channel
%dma(0)
%dma(1)
%dma(2)
%dma(3)
%dma(4)
%dma(5)
%dma(6)
%dma(7)
