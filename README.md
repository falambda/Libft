*This project has been created as part of the 42 curriculum by <fwahab-d>.*

# Libft

## Description

Libft is the first project of the 42 common core. The goal is to build, from scratch, a static C library (`libft.a`) that reimplements a set of standard libc functions and adds some extra utility functions, so it can be reused in all future 42 projects.

The library is written in C, follows the 42 Norm, and is compiled with `-Wall -Wextra -Werror`.

It is organised in three parts:

**Part 1 - libc functions.** Self-contained reimplementations of standard functions, with the same prototypes and behaviour as the originals (prefixed with `ft_`):

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`

**Part 2 - additional functions.** Functions that are not in the libc, or that are part of it in a different form:

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Part 3 - linked list functions.** Functions to manipulate lists built with the following structure:

```c
typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;
```

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

### Compilation

Clone the repository and run `make` at its root to build the library:

```bash
make
```

This produces `libft.a` using `ar rcs`.

Other Makefile rules:

| Rule         | Description                                        |
|--------------|----------------------------------------------------|
| `make`       | Builds `libft.a`                                   |
| `make clean` | Removes the object files                           |
| `make fclean`| Removes the object files and `libft.a`             |
| `make re`    | Rebuilds the library from scratch                  |

### Usage

Include the header in your source files:

```c
#include "libft.h"
```

Then compile your program linking against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Resources

- `man` pages of the reimplemented functions (`man 3 strlen`, `man 3 strlcpy`, etc.)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language), Kernighan & Ritchie
- [GNU Make documentation](https://www.gnu.org/software/make/manual/make.html)
- [Norm - 42 Docs](https://github.com/42School/norminette)
- Peer-learning with other 42 students and the 42 evaluation process

### Use of AI

AI was used as a support tool for explaining theory concepts (e.g. linked lists, memory management, and the rationale behind of the strlcat interface).
