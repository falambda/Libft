*This project has been created as part of the 42 curriculum by fwahab-d.*

# Libft

## Description

Libft is the first project of the 42 common core. The goal is to build, from scratch, a static C library (`libft.a`) that reimplements a set of standard libc functions and adds some extra utility functions, so it can be reused in all future 42 projects.

The library is written in C, follows the 42 Norm, and is compiled with `-Wall -Wextra -Werror`.

It is organised in three parts, documented below.

### Part 1 - libc functions

Self-contained reimplementations of standard functions, with the same prototypes and behaviour as the originals (prefixed with `ft_`). None of them depends on any external function, not even on other `ft_` functions.

#### Character checks and conversion

| Function | Prototype | Parameters | Returns | Description |
|----------|-----------|------------|---------|-------------|
| `ft_isalpha` | `int ft_isalpha(int c)` | `c`: character to test | Non-zero if `c` is a letter, `0` otherwise | Checks for an alphabetic character (`A-Z`, `a-z`). |
| `ft_isdigit` | `int ft_isdigit(int c)` | `c`: character to test | Non-zero if `c` is a digit, `0` otherwise | Checks for a decimal digit (`0-9`). |
| `ft_isalnum` | `int ft_isalnum(int c)` | `c`: character to test | Non-zero if `c` is a letter or a digit, `0` otherwise | Checks for an alphanumeric character. |
| `ft_isascii` | `int ft_isascii(int c)` | `c`: character to test | Non-zero if `c` is in the ASCII range, `0` otherwise | Checks that `c` fits in the 7-bit ASCII table (`0-127`). |
| `ft_isprint` | `int ft_isprint(int c)` | `c`: character to test | Non-zero if `c` is printable, `0` otherwise | Checks for a printable character, space included (`32-126`). |
| `ft_toupper` | `int ft_toupper(int c)` | `c`: character to convert | The uppercase letter, or `c` unchanged | Converts a lowercase letter to uppercase. |
| `ft_tolower` | `int ft_tolower(int c)` | `c`: character to convert | The lowercase letter, or `c` unchanged | Converts an uppercase letter to lowercase. |

#### Strings

| Function | Prototype | Parameters | Returns | Description |
|----------|-----------|------------|---------|-------------|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | `s`: string | Length of `s` | Counts the characters before the terminating `'\0'`. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | `dst`: destination buffer; `src`: source string; `size`: size of `dst` | Length of `src` | Copies up to `size - 1` characters of `src` into `dst` and always null-terminates it (if `size > 0`). |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | `dst`: destination string; `src`: string to append; `size`: total size of `dst` | Initial length of `dst` (capped at `size`) plus length of `src` | Appends `src` to the end of `dst` without exceeding `size` bytes, and null-terminates the result. The return value lets the caller detect truncation. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | `s`: string to search; `c`: character to find | Pointer to the first occurrence, or `NULL` | Locates the first occurrence of `c` in `s`. The terminating `'\0'` is considered part of the string. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | `s`: string to search; `c`: character to find | Pointer to the last occurrence, or `NULL` | Locates the last occurrence of `c` in `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | `s1`, `s2`: strings to compare; `n`: maximum number of characters | `0` if equal; otherwise the difference between the first differing characters, read as `unsigned char` | Compares at most `n` characters of two strings. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | `big`: string to search in; `little`: substring to find; `len`: maximum characters to search | Pointer to the start of the match; `big` if `little` is empty; `NULL` if not found | Locates `little` in `big`, looking at no more than `len` characters. |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | `nptr`: string to convert | The converted integer | Skips leading whitespace, reads an optional `+` or `-` sign, then converts the following digits to an `int`. |
| `ft_strdup` | `char *ft_strdup(const char *s)` | `s`: string to duplicate | Pointer to the new string, or `NULL` if the allocation fails | Returns a copy of `s` stored in newly allocated memory (`malloc`). |

#### Memory

| Function | Prototype | Parameters | Returns | Description |
|----------|-----------|------------|---------|-------------|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | `s`: memory area; `c`: byte value; `n`: number of bytes | `s` | Fills the first `n` bytes of `s` with the byte `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | `s`: memory area; `n`: number of bytes | Nothing | Sets the first `n` bytes of `s` to zero. |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | `dst`: destination; `src`: source; `n`: number of bytes | `dst` | Copies `n` bytes from `src` to `dst`. The areas must not overlap. |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | `dst`: destination; `src`: source; `len`: number of bytes | `dst` | Copies `len` bytes from `src` to `dst`. Works correctly even if the areas overlap. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | `s`: memory area; `c`: byte to find; `n`: number of bytes to scan | Pointer to the matching byte, or `NULL` | Scans the first `n` bytes of `s` looking for the first occurrence of `c`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | `s1`, `s2`: memory areas; `n`: number of bytes | `0` if equal; otherwise the difference between the first differing bytes, read as `unsigned char` | Compares the first `n` bytes of two memory areas. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | `nmemb`: number of elements; `size`: size of each element | Pointer to the allocated memory, or `NULL` if the allocation fails | Allocates memory for `nmemb` elements of `size` bytes each and sets all of it to zero. |

### Part 2 - Additional functions

Functions that are not in the libc, or that are part of it in a different form. They may use `malloc`, `free`, `write` and the functions of Part 1.

| Function | Prototype | Parameters | Returns | Description |
|----------|-----------|------------|---------|-------------|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | `s`: source string; `start`: index where the substring begins; `len`: maximum length of the substring | The new substring, or `NULL` if the allocation fails | Allocates and returns a substring of `s` starting at index `start`, with at most `len` characters. If `start` is beyond the end of `s`, returns an empty string. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | `s1`: prefix string; `s2`: suffix string | The new concatenated string, or `NULL` if the allocation fails | Allocates and returns a new string that is the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | `s1`: string to trim; `set`: characters to remove | The trimmed string, or `NULL` if the allocation fails | Allocates and returns a copy of `s1` with every character belonging to `set` removed from the beginning and from the end. |
| `ft_split` | `char **ft_split(char const *s, char c)` | `s`: string to split; `c`: delimiter character | `NULL`-terminated array of new strings, or `NULL` if any allocation fails | Splits `s` into words using `c` as delimiter. Consecutive delimiters do not produce empty strings. If an allocation fails, everything already allocated is freed. |
| `ft_itoa` | `char *ft_itoa(int n)` | `n`: integer to convert | The string representing `n`, or `NULL` if the allocation fails | Allocates and returns the decimal string of an integer. Handles negative numbers and `INT_MIN`. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | `s`: source string; `f`: function applied to each character, receiving its index and the character | The new string resulting from the successive applications of `f`, or `NULL` if the allocation fails | Applies `f` to every character of `s` and builds a new string with the results. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | `s`: string to iterate; `f`: function applied to each character, receiving its index and a pointer to the character | Nothing | Applies `f` to every character of `s`, giving it the chance to modify the string in place. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | `c`: character to write; `fd`: file descriptor | Nothing | Writes the character `c` to the given file descriptor. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | `s`: string to write; `fd`: file descriptor | Nothing | Writes the string `s` to the given file descriptor. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | `s`: string to write; `fd`: file descriptor | Nothing | Writes the string `s` followed by a newline to the given file descriptor. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | `n`: integer to write; `fd`: file descriptor | Nothing | Writes the integer `n` in decimal to the given file descriptor. Handles `INT_MIN`. |

### Part 3 - Linked list functions

Functions to manipulate singly linked lists built with the following structure:

```c
typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;
```

`content` stores the data of the node, and `next` points to the following node (or is `NULL` for the last one).

| Function | Prototype | Parameters | Returns | Description |
|----------|-----------|------------|---------|-------------|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | `content`: data to store in the node | The new node, or `NULL` if the allocation fails | Allocates a new node, sets its `content` and sets `next` to `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | `lst`: address of the pointer to the first node; `new`: node to add | Nothing | Adds `new` at the beginning of the list. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | `lst`: beginning of the list | Number of nodes | Counts the nodes of the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | `lst`: beginning of the list | The last node | Returns the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | `lst`: address of the pointer to the first node; `new`: node to add | Nothing | Adds `new` at the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | `lst`: node to free; `del`: function that frees the content | Nothing | Frees the content of the node with `del`, then frees the node itself. It does not free `next`. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | `lst`: address of the pointer to a node; `del`: function that frees the content | Nothing | Deletes and frees the given node and every node after it, then sets the list pointer to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | `lst`: beginning of the list; `f`: function applied to each content | Nothing | Iterates the list and applies `f` to the content of each node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | `lst`: beginning of the list; `f`: function applied to each content; `del`: function that frees a content if needed | The new list, or `NULL` if an allocation fails | Iterates the list, applies `f` to each content and builds a new list with the results. If an allocation fails, the new list is cleared with `del`. |

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

AI was used as a support tool for explaining theory concepts (e.g. linked lists, memory management, and the rationale behind the `strlcat` interface).
