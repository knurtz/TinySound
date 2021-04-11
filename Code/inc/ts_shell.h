#ifndef SHELL_COMMANDS_H
#define SHELL_COMMANDS_H

#include "ch.h"
#include "hal.h"
#include <string.h>
#include "shell.h"
#include "chprintf.h"
#include "ff.h"

// FatFS tree command
void cmd_tree(BaseSequentialStream *chp, int argc, char *argv[]);

#endif /* SHELL_COMMANDS_H */
