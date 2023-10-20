/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:28:08 by byoshimo          #+#    #+#             */
/*   Updated: 2023/10/03 17:36:55 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_transformation_matrix(t_rt *rt, t_coordinates up)
{
	double			**orientation;
	double			**translation;
	double			**transformation;
	t_coordinates	left;
	t_coordinates	true_up;

	left = calculate_cross_product(rt->camera.vector, up);
	true_up = calculate_cross_product(left, rt->camera.vector);
	orientation = create_identity_matrix(4);
	orientation[0][0] = left.x;
	orientation[0][1] = left.y;
	orientation[0][2] = left.z;
	orientation[1][0] = true_up.x;
	orientation[1][1] = true_up.y;
	orientation[1][2] = true_up.z;
	orientation[2][0] = -rt->camera.vector.x;
	orientation[2][1] = -rt->camera.vector.y;
	orientation[2][2] = -rt->camera.vector.z;
	translation = create_translation_matrix(negate_tuple(rt->camera.point));
	transformation = multiply_matrices(orientation, translation);
	free_matrix(&orientation);
	free_matrix(&translation);
	rt->render.inverse = invert_matrix(transformation);
	free_matrix(&transformation);
}

static void	transform_view(t_rt *rt)
{
	t_coordinates	up;

	up = create_vector(0, 1, 0);
	if (are_equals(calculate_dot_product(rt->camera.vector, up), 1))
		up = create_vector(1, 0, 0);
	if (are_equals(calculate_dot_product(rt->camera.vector, up), -1))
		up = create_vector(-1, 0, 0);
	set_transformation_matrix(rt, up);
}

static void	calculate_pixel_size(t_rt *rt)
{
	double	aspect;
	double	half_view;

	half_view = tan(rt->camera.fov * M_PI / 360);
	aspect = (double)WIDTH / (double)HEIGHT;
	if (aspect >= 1 - EPSILON)
	{
		rt->render.half_width = half_view;
		rt->render.half_height = half_view / aspect;
		rt->render.pixel_size = half_view * 2 / WIDTH;
	}
	else
	{
		rt->render.half_width = half_view * aspect;
		rt->render.half_height = half_view;
		rt->render.pixel_size = half_view * 2 / HEIGHT;
	}
}

static void	draw(t_rt *rt)
{
	int				i;
	int				j;
	t_ray			ray;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray = create_ray(rt, i, j);
			intersections(rt, ray, &rt->intersections);
			rt->hit = get_hit(rt->intersections);
			if (rt->hit)
			{
				rt->hit->ray = ray;
				rt->hit->color = lightning(rt);
				mlx_put_pixel(rt->render.image, i, j, rt->hit->color.red << 24 \
					| rt->hit->color.green << 16 \
					| rt->hit->color.blue << 8 | 255);
			}
			free_intersections(&rt->intersections);
		}
	}
	free_matrix(&rt->render.inverse);
}

void	render(t_rt *rt)
{
	rt->render.mlx = mlx_init(WIDTH, HEIGHT, "miniRT - bilu", true);
	if (!rt->render.mlx)
		print_error(MLX_INIT, rt);
	rt->render.image = mlx_new_image(rt->render.mlx, WIDTH, HEIGHT);
	if (!rt->render.image)
		print_error(MLX_IMAGE, rt);
	transform_view(rt);
	calculate_pixel_size(rt);
	draw(rt);
	if (mlx_image_to_window(rt->render.mlx, rt->render.image, 0, 0) == -1)
		print_error(MLX_IMAGE_TO_WIN, rt);
}
