/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:20:19 by jvan-hal          #+#    #+#             */
/*   Updated: 2023/09/01 15:06:38 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

bool mlx_equal_image(void* lstcontent, void* value)
{
	const t_mlx_image* lcontent = lstcontent;
	const t_mlx_image* lvalue = value;

	return (lcontent == lvalue);
}

bool mlx_equal_inst(void* lstcontent, void* value)
{
	const draw_queue_t* lcontent = lstcontent;
	const t_mlx_image* lvalue = value;

	return (lcontent->image == lvalue);
}