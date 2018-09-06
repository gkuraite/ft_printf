/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:03:41 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/05 14:03:44 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void      error_message(int error_num)
{
    error_num == 1 ? write(1, "\n\t***Warning: undefined behaviour***\t\n", 38) : 0;
    //error_num == 1 ? ft_putstr("\n\t***Warning: undefined behaviour***\t\n") : 0;
}

void        printf_errors(int error_num)
{
    if (error_num > 0)
        error_message(error_num);
}
