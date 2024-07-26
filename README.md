# chip8-emulator

This program is made to implement chip8 using C++.
Reference: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM

# 1. What is Chip8?


Chip-8 is a simple, interpreted, programming language which was first used on some do-it-yourself computer systems in the late 1970s and early 1980s.

# 2. Structure of Chip8

## - 2-1. memory
Chip8 is capable of accessing up to 4096 bytes of RAM.

```text
Memory Map:
+---------------+= 0xFFF (4095) End of Chip-8 RAM
|               |
|               |
|               |
|               |
|               |
| 0x200 to 0xFFF|
|     Chip-8    |
| Program / Data|
|     Space     |
|               |
|               |
|               |
+- - - - - - - -+= 0x600 (1536) Start of ETI 660 Chip-8 programs
|               |
|               |
|               |
+---------------+= 0x200 (512) Start of most Chip-8 programs
| 0x000 to 0x1FF|
| Reserved for  |
|  interpreter  |
+---------------+= 0x000 (0) Start of Chip-8 RAM
```

## - 2-2. registers

- 16 general purpose 8-bit registers
- 16-bit register I(stores memory address)
- VF register(used as flag)
- pseudo registers(not accessable from Chip8)
- program counter(used to store the currently executing address)
- stack pointer(used to point to the topmost level)


## - 2-3. keyboard

```text
1	2	3	C
4	5	6	D
7	8	9	E
A	0	B	F
```
Chip8 follows the upper key binding.

## - 2-4. display

```text
(0,0)	(63,0)
(0,31)	(63,31)
```
Original implementation of Chip8 uses 64x32-pixel monochrome display with upper format.

## - 2-5. timers and sound

Chip8 provides 2 timers: delay timer, sound timer

### - delay timer: 
Active whenever the delay timer register(DT) is non-zero. This does nothing more than subtracting 1 from the value of DT at a rate of 60HZ. When DT reaches 0, deactivates.
### - sound timer: 
Active whenever the sound timer(ST) is non-zero. It decrements at a rate of 60HZ, 
however, as long as ST's value is greater than zero, Chip8 buzzer sounds. Same as delay timer, when ST reaches zero, deactivates.