/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:14:43 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/29 18:08:42 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_ptrptr(char ***ptrptr)
{
	int	i;

	i = 0;
	while (*ptrptr && (*ptrptr)[i])
	{
		free((*ptrptr)[i]);
		i++;
	}
	free(*ptrptr);
	*ptrptr = NULL;
}

void	free_matrix(double ***matrix)
{
	int	i;

	i = 0;
	while (*matrix && (*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

static void	free_sphere_plane_matrices(t_rt *rt)
{
	int	i;

	if (rt->spheres)
	{
		i = -1;
		while (++i < rt->num_sp)
		{
			free_matrix(&rt->spheres[i].inverse);
			free_matrix(&rt->spheres[i].transpose);
		}
	}
	if (rt->planes)
	{
		i = -1;
		while (++i < rt->num_pl)
		{
			free_matrix(&rt->planes[i].inverse);
			free_matrix(&rt->planes[i].transpose);
		}
	}
}

static void	free_cylinder_matrices(t_rt *rt)
{
	int	i;

	if (rt->cylinders)
	{
		i = -1;
		while (++i < rt->num_cy)
		{
			free_matrix(&rt->cylinders[i].inverse);
			free_matrix(&rt->cylinders[i].transpose);
		}
	}
}

void	free_rt(t_rt *rt)
{
	free_ptrptr(&rt->elements);
	free_ptrptr(&rt->element);
	free_ptrptr(&rt->color);
	free_ptrptr(&rt->coordinates);
	free(rt->lights);
	free_sphere_plane_matrices(rt);
	free(rt->spheres);
	free(rt->planes);
	free_cylinder_matrices(rt);
	free(rt->cylinders);
	if (rt->render.mlx)
	{
		mlx_close_window(rt->render.mlx);
		if (rt->render.image)
			mlx_delete_image(rt->render.mlx, rt->render.image);
		mlx_terminate(rt->render.mlx);
	}
	free(rt);
	exit(0);
}
