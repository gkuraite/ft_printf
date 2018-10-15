# ft_printf

#### Final Score 102/100

## Challenge

Recode libc's ```printf``` function. 

At 42, Students must write all their own functions from scratch. <br />
Normal library functions such as ```realloc```, ```strjoin```, ```strdup```, etc., are strictly forbidden.<br />

```ft_printf``` must achieve the following requirements:

  - Manage the following conversions: ```s```, ```S```, ```p```, ```d```, ```D```, ```i```, ```o```, ```O```, ```u```, ```U```, ```x```, ```X```, ```c``` & ```C``` 
  - Manage ```%%```
  - Manage the flags ```#```, ```0```, ```-```, + ```&``` space
  - Manage the minimum field-width
  - Manage the precision
  - Manage the flags ```hh```, ```h```, ```l```, ```ll```, ```j```, & ```z```.

```ft_printf``` must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf). It must not have any leaks. Errors must be handled carefully. <br />
In no way can it quit in an unexpected manner (segmentation fault, bus error, double free, etc).

```ft_printf``` must be formatted and behave in the same way as libc's ```printf```:

```c
  ft_printf("%d is the answer to %s, %s, and %s.", 42, "life", "the universe", "everything");
  printf("%d is the answer to %s, %s, and %s.", 42, "life", "the universe", "everything");
```
Should output:

```
  42 is the answer to life, the universe, and everything.
  42 is the answer to life, the universe, and everything.
```

## Usage

Run ```make```. This will compile **libftprintf.a**. To use, include ```ft_printf.h``` and use just like ```printf```:
```c
#include <ft_printf.h>

int     main(void)
{
  ft_printf("%s\n", "Hello World");
  return(0);
}
```
Then compile with a program:
```
$> gcc -Wall -Werror -Wextra main.c libftprintf.a -I includes 
```
