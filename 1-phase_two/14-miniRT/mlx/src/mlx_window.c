/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:14:59 by W2wizard          #+#    #+#             */
/*   Updated: 2023/09/01 18:39:30 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

/**
 * Recalculate the view projection matrix, used by images for screen pos
 * Reference: https://bit.ly/3KuHOu1 (Matrix View Projection)
 */
void mlx_update_matrix(const t_mlx* mlx)
{
	const mlx_ctx_t* mlxctx = mlx->context;
	const float depth = mlxctx->zdepth;

	/**
	 * In case the setting to stretch the image is set, we maintain the width and height but not
	 * the depth.
	 */
	const float width = mlx_settings[MLX_STRETCH_IMAGE] ? mlxctx->initialWidth : mlx->width;
	const float height = mlx_settings[MLX_STRETCH_IMAGE] ? mlxctx->initialHeight : mlx->height;

	const float matrix[16] = {
		2.f / width, 0, 0, 0,
		0, 2.f / -(height), 0, 0,
		0, 0, -2.f / (depth - -depth), 0,
		-1, -(height / -height),
		-((depth + -depth) / (depth - -depth)), 1
	};

	glUniformMatrix4fv(glGetUniformLocation(mlxctx->shaderprogram, "ProjMatrix"), 1, GL_FALSE, matrix);
}

static void mlx_resize_callback(GLFWwindow* window, int32_t width, int32_t height)
{
	const t_mlx* mlx = glfwGetWindowUserPointer(window);
	const mlx_ctx_t* mlxctx = mlx->context;

	if (mlxctx->resize_hook.func)
		mlxctx->resize_hook.func(width, height, mlxctx->resize_hook.param);
}

static void mlx_close_callback(GLFWwindow* window)
{
	const t_mlx* mlx = glfwGetWindowUserPointer(window);
	const mlx_close_t close_hook = ((mlx_ctx_t*)mlx->context)->close_hook;

	close_hook.func(close_hook.param);
}

//= Public =//

void mlx_close_hook(t_mlx* mlx, t_mlx_closefunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* mlxctx = mlx->context;
	mlxctx->close_hook.func = func;
	mlxctx->close_hook.param = param;
	glfwSetWindowCloseCallback(mlx->window, mlx_close_callback);
}

void mlx_resize_hook(t_mlx* mlx, t_mlx_resizefunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* mlxctx = mlx->context;
	mlxctx->resize_hook.func = func;
	mlxctx->resize_hook.param = param;
	glfwSetWindowSizeCallback(mlx->window, mlx_resize_callback);
}

void mlx_set_icon(t_mlx* mlx, t_mlx_texture* image)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(image);

	const GLFWimage icon = {
		.width = image->width,
		.height = image->height,
		.pixels = image->pixels
	};

	glfwSetWindowIcon(mlx->window, 1, &icon);
}

void mlx_set_window_pos(t_mlx* mlx, int32_t xpos, int32_t ypos)
{
	MLX_NONNULL(mlx);

	glfwSetWindowPos(mlx->window, xpos, ypos);
}

void mlx_get_window_pos(t_mlx* mlx, int32_t* xpos, int32_t* ypos)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(xpos);
	MLX_NONNULL(ypos);

	glfwGetWindowPos(mlx->window, xpos, ypos);
}

void mlx_set_window_size(t_mlx* mlx, int32_t new_width, int32_t new_height)
{
	MLX_NONNULL(mlx);

	mlx->width = new_width;
	mlx->height = new_height;
	glfwSetWindowSize(mlx->window, new_width, new_height);
}

void mlx_set_window_limit(t_mlx* mlx, int32_t min[2], int32_t max[2])
{
	MLX_NONNULL(mlx);

	glfwSetWindowSizeLimits(mlx->window, min[0], min[1], max[0], max[1]);
}

void mlx_set_window_title(t_mlx* mlx, const char* title)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(title);

	glfwSetWindowTitle(mlx->window, title);
}
