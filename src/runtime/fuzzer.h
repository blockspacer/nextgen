/**
 * Copyright (c) 2016, Harrison Bowden, Minneapolis, MN
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

#ifndef NX_FUZZER_H
#define NX_FUZZER_H

#include <stdint.h>
#include "nextgen.h"
#include "depend-inject/depend-inject.h"

struct fuzzer_control
{
    uint32_t stop;
};

struct fuzzer_instance
{
    int32_t (*stop)(void);
    int32_t (*setup)(void);
    int32_t (*start)(void);
};

/**
 *
 */
struct fuzzer_instance *get_fuzzer(struct fuzzer_config *config);

/**
 * @param A memory allocator object.
 * @param A output writter object.
 * @return A syscall fuzzer object.
 */
struct fuzzer_instance *get_syscall_fuzzer(char *);

/**
 *
 */
struct fuzzer_control *init_fuzzer_control(void);

/* */
extern void inject_fuzzer_deps(struct dependency_context *ctx);

extern void inject_syscall_fuzzer_deps(struct dependency_context *ctx);

#endif
