/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:27:46 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/05 17:27:49 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     is_it_valid(t_flags *f)
{
    if (f->plus)
        f->space = 0;
    if (f->minus)
        f->zero = 0;
}
