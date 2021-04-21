// SPDX-License-Identifier: GPL-2.0 only
/**
 * Copyright (C) 2021 Kaden5480
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * @file    mock.c
 * @author  Kaden5480
 * @version 1.1
 * @date    2021-04-19 (yyyy-mm-dd)
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_help(char *invalid)
{
    if (invalid)
    {
        printf("mock: Unknown option: %s\n\n", invalid);
    }

    printf("C Mock v1.1\n\n");
    printf("Usage:\n");
    printf("  mock <string>...      Print the given strings in mock format\n\n");
    printf("Options:\n");
    printf("  -h --help             Print this help message\n\n");
}


int main(int argc, char **argv)
{
    // argc must be at least 2
    if (argc < 2)
    {
        print_help(0);
        return 1;
    }
    // print help menu if specified by user
    else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
    {
        print_help(0);
        return 0;
    }
    // print help menu and invalid arg
    else if (argv[1][0] == '-')
    {
        print_help(argv[1]);
        return 1;
    }

    char *c;
    char *fmt;
    int counter;

    // loop through all args
    for (int i = 1; i < argc; i++)
    {
        // if last arg, add newline at end, else spaces
        fmt = (i == argc-1) ? "%s\n" : "%s ";

        // get pointer to first char in arg
        c = argv[i];

        // set counter to 0
        counter = 0;

        do
        {
            // exclude any non-letter char
            if (!isalpha(*c))
            {
                continue;
            }

            // convert char either to upper/lower
            if (counter%2 == 0)
            {
                *c = tolower((unsigned char) *c);
            } 
            else
            {
                *c = toupper((unsigned char) *c);
            }

            // increment counter
            counter++;
        }
        while (*c && c++);

        // print the arg after modification
        printf(fmt, argv[i]);
    }

    return 0;
}
