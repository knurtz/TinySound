#ifndef SHELL_H
#define SHELL_H

#include "usart.h"

// Check receive buffer for newline, returns 1 if command was found
uint8_t Shell_CheckCommand(void);

void Shell_ExecuteCommand(void);

void Shell_Init(void);

void Shell_ClearInputBuffer(void);

// Works like normal printf, max. length 100 characters
void xprintf(const char *fmt, ...);

#endif /* SHELL_H */
