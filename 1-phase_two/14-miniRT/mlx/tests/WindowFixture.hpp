// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by Jelle van Kraaij.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

# pragma once

# include <gtest/gtest.h>
# include <MLX42/MLX42.h>

class Window : public ::testing::Test
{
protected:
	t_mlx* mlx = nullptr;

	static constexpr const char* name = "MLX42";
	static const int32_t height = 400;
	static const int32_t width = 400;

	inline void SetUp() override
	{
		// reset error code as it is shared between tests
		g_mlx_errno = MLX_SUCCESS;
		mlx_set_setting(MLX_HEADLESS, true);
		ASSERT_EQ(g_mlx_errno, MLX_SUCCESS);
		mlx = mlx_init(width, height, name, false);
		ASSERT_NE(mlx, nullptr);
		ASSERT_EQ(g_mlx_errno, MLX_SUCCESS);
	}

	inline void TearDown() override
	{
		ASSERT_NE(mlx, nullptr);
		mlx_terminate(mlx);
		ASSERT_EQ(g_mlx_errno, MLX_SUCCESS);
	}
};
