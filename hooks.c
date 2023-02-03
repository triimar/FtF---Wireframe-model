/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:25:15 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/03 20:45:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	esc_close(mlx_key_data_t keydata, void *param)
{
	t_displ	*s_displ;

	s_displ = (t_displ *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(s_displ->window);
		return ;
	}
}
