includeonce

macro init()
  sei         ; Disabled interrupts
  clc         ; clear carry to switch to native mode
  xce         ; Xchange carry & emulation bit. native mode
  rep #$18    ; Binary mode (decimal mode off)
  ldx #$1FFF  ; set stack to $1FFF
  txs

  jsr Init
endmacro

org $008000
Init:
  ;; Set defaults for registers

  sep #$30      ; X,Y,A are 8 bit numbers
  lda #$8F
  sta INIDISP   ; screen off, full brightness
  stz OBJSEL    ; Objects are 8x8 or 16x16,
                ; use first 2 pages of VRAM
  stz OAMADDL   ; OAM address $0000
  stz OAMADDH
  stz BGMODE    ; Background mode 0
  stz MOSAIC
  stz BG1SC     ; All backgrounds use tilemap $0000,
  stz BG2SC     ; 1 page in size (32x32)
  stz BG3SC
  stz BG4SC
  stz BG12NBA   ; All backgrounds use character data $0000
  stz BG34NBA
  lda #$FF
  sta BG1VOFS   ; Vertical scroll position $07FF
  sta BG2VOFS
  sta BG3VOFS
  sta BG4VOFS
  lda #$07
  sta BG1VOFS
  sta BG2VOFS
  sta BG3VOFS
  sta BG4VOFS
  stz BG1HOFS   ; Horizontal scroll position $0000
  stz BG1HOFS
  stz BG2HOFS
  stz BG2HOFS
  stz BG3HOFS
  stz BG3HOFS
  stz BG4HOFS
  stz BG4HOFS
  lda #$80
  sta VMAINC    ; Increment after high byte by 1, no remapping
  stz VMADDL    ; VRAM address $0000
  stz VMADDH
  stz M7SEL
  lda #$01
  stz M7A       ; Default to identity matrix
  sta M7A       ; [$0001  $0000]
  stz M7B       ; [$0000  $0001]
  stz M7B
  stz M7C
  stz M7C
  stz M7D
  sta M7D
  stz M7X
  stz M7X
  stz M7Y
  stz M7Y
  stz CGADD     ; CGRAM address $00
  stz W12SEL    ; Disable all layers
  stz W34SEL
  stz WOBJSEL
  stz WH0       ; Disable all windows
  stz WH1
  stz WH2
  stz WH3
  stz WBGLOG    ; Intersection mode OR
  stz WOBJLOG
  stz TM        ; Disable all layers on main screen
  stz TS        ; Disable all layers on sub screen
  stz TMW
  stz TSW
  lda #$30
  sta CGSWSEL   ; Enable main screen, disable sub screen
  stz CGADSUB   ; Disable color math
  lda #$E0
  sta COLDATA   ; Fixed subscreen color black
  stz INISET    ; Disable interlacing, overscan,
                ; pseudo-512 mode
  stz NMITIMEN  ; Disable NMIs (V-blank), IRQ timers,
                ; and auto-joypad-read
  lda #$FF
  sta WRIO      ; Pull all I/O ports low
  stz WRMPYA
  stz WRMPYB
  stz WRDIVL
  stz WRDIVH
  stz WRDIVB
  stz HTIMEL
  stz HTIMEH
  stz VTIMEL
  stz VTIMEH
  stz MDMAEN    ; Disable all DMA & HDMA
  stz HDMAEN
  stz MEMSEL    ; SlowROM default
  cli
  rts
