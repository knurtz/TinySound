#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h> //for va_list var arg functions

char rec_buffer[20];

// check receive buffer for newline, indicating the end of a command
uint8_t Shell_CheckCommand(void)
{
  char* newline_pos = strchr(rec_buffer, '\n');
  if (newline_pos)
  {
    HAL_UART_Transmit(&huart1, (uint8_t*)rec_buffer, strlen(rec_buffer), -1);
    *newline_pos = '\0';
    Shell_ExecuteCommand();
    Shell_Init();
    return 1;
  }
  return 0;
}

void Shell_ExecuteCommand(void)
{
  if (!strcmp(rec_buffer, "help"))
  {
    xprintf("List of commands:\n files - Show files on SD card\n help - List all commands.\n");
  }
  else if (!strcmp(rec_buffer, "files"))
  {
    xprintf("Not implemented yet.\n");
  }
  else xprintf("Unknown command.\n");
}

void Shell_Init(void)
{
  xprintf("\nTinySound> ");
  Shell_ClearInputBuffer();
}

void Shell_ClearInputBuffer(void)
{
  memset(rec_buffer, 0, sizeof(rec_buffer));
  HAL_UART_AbortReceive(&huart1);
  HAL_UART_Receive_DMA(&huart1, (uint8_t*)rec_buffer, sizeof(rec_buffer));
}

// Works like normal printf, max. length 100 characters
void xprintf(const char *fmt, ...)
{
  static char buffer[101];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  int len = strlen(buffer);
  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, len, -1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  // Check for a complete command one last time
  if (!Shell_CheckCommand()) xprintf("Buffer overflow\n");
  Shell_Init();
}