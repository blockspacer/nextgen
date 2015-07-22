

/**
 * Copyright (c) 2015, Harrison Bowden, Secure Labs, Minneapolis, MN
 * 
 * Permission to use, copy, modify, and/or distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright notice 
 * and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **/

#ifndef UTILS_H
#define UTILS_H

#include "private.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdatomic.h>

/* The enum used to tell output how to output the message. */
enum out_type { ERROR, STD };

enum csp { SET, UNSET };

/* This function as the name implies gets the file size. */
private extern int get_file_size(int fd, off_t *size);

/* map_file_in() takes the file descriptor pointed to by fd and mmaps the file to buf
and puts the files size in size.  */
private extern int map_file_in(int fd, char **buf, off_t *size);

/* This function maps a buffer of size to a file path.  */
private extern int map_file_out(char *path, char *buf, off_t *size);

/* This function replaces printf and perror in the code so we can aggregate output to one point. */
private extern void output(enum out_type type, const char *format, ...);

/* Get the core count of the system we are on. This will include virtual cores on hyperthreaded systems. */
private extern int get_core_count(unsigned int *core_count);

private extern int compare_and_swap_loop(atomic_bool target, int value);

#endif