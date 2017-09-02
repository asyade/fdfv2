#include "fdf.h"

int    fdf_skblank(char **str)
{
    char    *begin;

    begin = *str;
    while (**str && ft_isblank(**str))
        *str += 1;
    return (begin != *str);
}

int    fdf_isnumbegin(char c)
{
    return(c == '-' || c == '+' || ft_isdigit(c));
}

int    fdf_sknum(char **str)
{
    if (!fdf_isnumbegin(**str))
        return (0);
    if (!ft_isdigit(**str))
        *str += 1;
    if (!ft_isdigit(**str))
        return (0);
    while (ft_isdigit(**str))
        *str += 1;
    return (1);
}