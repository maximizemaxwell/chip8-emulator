//
// Created by max on 7/26/24.
//
#pragma once
#ifndef CHIP8_H
#define CHIP8_H

#include "chip8const.h"

// basic structure of chip8, defines variables to save values
struct chip8 {
    //MEMORY
    unsigned char memory[CHIP8_MEM_SIZE];
    // 16 UNIVERSAL 8 BIT REGISTERS
    unsigned char V[CHIP8_NUM_GENERAL_REGS];
    // memory address register MAR(16bits)
    unsigned short I;
    // timer (delay timer, 8bits)
    unsigned char DT;
    // timer (sound timer)
    unsigned char ST;
    // program counter
    unsigned short PC;
    // stack pointer
    unsigned char SP;
    // keyboard
    bool keyboard[CHIP8_NUM_KEYS];
    //keyboard mapping
    char* keymap;
    // display 64x32
    bool display_pixels[CHIP8_HEIGHT][CHIP8_WIDTH];
};
#endif //CHIP8_H
