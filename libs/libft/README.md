# Libft

*This project has been created as part of the 42 curriculum by daherman.*

---

## Description

This project aims to recreate a personal C library based on the standard libc.  
It focuses on understanding low-level programming concepts such as:

- Dynamic memory management
- String manipulation
- Character functions
- Linked list implementation

---

## Instructions

### Compilation

To compile the library:

```bash
make
```

This will generate `libft.a`.

---

### Clean object files

```bash
make clean
```

Removes all `.o` files.

---

### Full clean

```bash
make fclean
```

Removes `.o` files and `libft.a`.

---

### Rebuild

```bash
**make** re
```

Cleans everything and recompiles the library.

## Resources

### Documentation and references

The development of this project was based on the following resources:

- Official C library documentation (`man` pages)
- The C Standard Library reference (ISO C standard)
- [cppreference C library](https://en.cppreference.com/w/c?utm_source=chatgpt.com)
- Various programming tutorials focused on:
  - memory allocation (`malloc`, `free`)
  - string manipulation
  - linked list implementation in C

These resources were used to better understand the expected behavior of standard functions and to ensure correct reimplementation.

---

### Use of Artificial Intelligence

Artificial Intelligence tools were used as a **supporting resource** during the development of this project.

Specifically, AI was used for:

- Clarifying concepts related to dynamic memory management
- Understanding edge cases in standard libc functions
- Improving code documentation and README formatting
- Assisting with Markdown syntax and project structuring

AI was **not used to directly generate final implementation code**, but rather as a tool for explanation, learning reinforcement, and text refinement.

All final implementations were written and tested manually.

---

## Functions implemented in libft

### Character checks

```text
ft_isalpha.c
ft_isdigit.c
ft_isalnum.c
ft_isascii.c
ft_isprint.c
```

---

### Strings and memory

```text
ft_strlen.c
ft_memset.c
ft_bzero.c
ft_memcpy.c
ft_memmove.c
ft_strlcat.c
ft_strlcpy.c
ft_toupper.c
ft_tolower.c
ft_strchr.c
ft_strrchr.c
ft_strncmp.c
ft_memcmp.c
ft_strnstr.c
ft_atoi.c
```

---

### Memory allocation

```text
ft_calloc.c
ft_strdup.c
```

---

### String manipulation

```text
ft_substr.c
ft_strjoin.c
ft_strtrim.c
ft_split.c
```

---

### Conversions

```text
ft_itoa.c
```

---

### Functional utilities

```text
ft_strmapi.c
ft_striteri.c
```

---

### File descriptors

```text
ft_putchar_fd.c
ft_putstr_fd.c
ft_putendl_fd.c
ft_putnbr_fd.c
```

---

### Linked list

```text
ft_lstnew.c
ft_lstadd_front.c
ft_lstsize.c
ft_lstlast.c
ft_lstadd_back.c
ft_lstdelone.c
ft_lstclear.c
ft_lstiter.c
ft_lstmap.c
```

---
