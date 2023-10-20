/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:20:13 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/09/01 15:14:46 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

static void mlx_scroll_cb(GLFWwindow* window, double xoffset, double yoffset)
{
	const t_mlx* mlx = glfwGetWindowUserPointer(window);
	const mlx_scroll_t scroll_hook = ((mlx_ctx_t*)mlx->context)->scroll_hook;

	scroll_hook.func(xoffset, yoffset, scroll_hook.param);
}

static void mlx_mouse_cb(GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
{
	const t_mlx* mlx = glfwGetWindowUserPointer(window);
	const mlx_mouse_t mouse_hook = ((mlx_ctx_t*)mlx->context)->mouse_hook;

	mouse_hook.func(button, action, mods, mouse_hook.param);
}

static void mlx_cursor_cb(GLFWwindow* window, double xpos, double ypos)
{
	const t_mlx* mlx = glfwGetWindowUserPointer(window);
	const t_mlx_cursor cursor_hook = ((mlx_ctx_t*)mlx->context)->cursor_hook;

	cursor_hook.func(xpos, ypos, cursor_hook.param);
}

//= Public =//

void mlx_scroll_hook(t_mlx* mlx, t_mlx_scrollfunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* const mlxctx = mlx->context;
	mlxctx->scroll_hook.func = func;
	mlxctx->scroll_hook.param = param;
	glfwSetScrollCallback(mlx->window, mlx_scroll_cb);
}

void mlx_mouse_hook(t_mlx* mlx, t_mlx_mousefunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* const mlxctx = mlx->context;
	mlxctx->mouse_hook.func = func;
	mlxctx->mouse_hook.param = param;
	glfwSetMouseButtonCallback(mlx->window, mlx_mouse_cb);
}

void mlx_cursor_hook(t_mlx* mlx, t_mlx_cursorfunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* const mlxctx = mlx->context;
	mlxctx->cursor_hook.func = func;
	mlxctx->cursor_hook.param = param;
	glfwSetCursorPosCallback(mlx->window, mlx_cursor_cb);
}

bool mlx_is_mouse_down(t_mlx* mlx, t_mouse_key key)
{
	MLX_NONNULL(mlx);

	return (glfwGetMouseButton(mlx->window, key) == GLFW_PRESS);
}

void mlx_set_mouse_pos(t_mlx* mlx, int32_t x, int32_t y)
{
	MLX_NONNULL(mlx);

	glfwSetCursorPos(mlx->window, (double)x, (double)y);
}

void mlx_get_mouse_pos(t_mlx* mlx, int32_t* x, int32_t* y)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(x);
	MLX_NONNULL(y);

	double xd, yd;
	glfwGetCursorPos(mlx->window, &xd, &yd);
	*x = (int32_t)xd;
	*y = (int32_t)yd;
}
