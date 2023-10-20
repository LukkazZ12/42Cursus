/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:04:27 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/03 18:36:59 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

# define USAGE "Wrong number of arguments.\nUsage: ./miniRT scene.rt"
# define FORMAT "Wrong scene format.\nUsage: ./miniRT scene.rt"
# define INV_FILE "Can't open file."
# define INV_READ "Can't read file."
# define NUM_ELEMENTS "Invalid numbers of elements."
# define INV_ELEMENT "Invalid element."
# define MISS_ELEMENT "Some element (ambient light, camera, light) is missing."
# define NUM_AMB_LIGHT "Invalid number of ambient lights."
# define ARG_AMB_LIGHT "Invalid number of arguments on ambient light."
# define D_RATIO_AMB_LIGHT "Invalid ambient light ratio. Ratio is not a double."
# define R_RATIO_AMB_LIGHT "Invalid ambient light ratio. Ratio: 0.0 - 1.0."
# define COLOR_AMB_LIGHT "Invalid ambient light color."
# define NUM_CAM "Invalid number of cameras."
# define ARG_CAM "Invalid number of arguments on camera."
# define POINT_CAM "Invalid camera point."
# define VECTOR_CAM "Invalid camera vector."
# define R_VECTOR_CAM "Invalid camera vector. Vector is not normalized."
# define FOV_CAM "Invalid camera horizontal field of view."
# define ARG_LIGHT "Invalid number of arguments on light."
# define POINT_LIGHT "Invalid light point."
# define D_BRIGHT_LIGHT "Invalid light brightness. Brightness is not a double."
# define R_BRIGHT_LIGHT "Invalid light brightness."
# define COLOR_LIGHT "Invalid light color."
# define ARG_SP "Invalid number of arguments on sphere."
# define CENTER_SP "Invalid sphere center coordinates."
# define D_DIAM_SP "Invalid sphere diameter. Diameter is not a double."
# define R_DIAM_SP "Invalid sphere diameter. Diameter isn't greater than 0."
# define COLOR_SP "Invalid sphere color or checkerboard/texture parameter."
# define ARG_PL "Invalid number of arguments on plane."
# define POINT_PL "Invalid plane point."
# define NORMAL_PL "Invalid plane normal."
# define N_NORMAL_PL "Invalid plane normal. Normal is not normalized."
# define COLOR_PL "Invalid plane color or checkerboard/texture parameter."
# define ARG_CY "Invalid number of arguments on cylinder."
# define CENTER_CY "Invalid cylinder center coordinates."
# define VECTOR_CY "Invalid cylinder vector."
# define N_VECTOR_CY "Invalid cylinder vector. Vector is not normalized."
# define D_DIAM_CY "Invalid cylinder diameter. Diameter is not a double."
# define R_DIAM_CY "Invalid cylinder diameter. Diameter isn't greater than 0."
# define D_HEIGHT_CY "Invalid cylinder height. Height is not a double."
# define R_HEIGHT_CY "Invalid cylinder height. Height isn't greater than 0."
# define COLOR_CY "Invalid cylinder color or checkerboard/texture parameter."
# define ARG_CO "Invalid number of arguments on cone."
# define CENTER_CO "Invalid cone center coordinates."
# define VECTOR_CO "Invalid cone vector."
# define N_VECTOR_CO "Invalid cone vector. Vector is not normalized."
# define D_HEIGHT_CO "Invalid cone height. Height is not a double."
# define R_HEIGHT_CO "Invalid cone height. Height isn't greater than 0."
# define COLOR_CO "Invalid cone color or checkerboard/texture parameter."
# define MLX_INIT "Could not init window."
# define MLX_IMAGE "Could not create image."
# define MLX_IMAGE_TO_WIN "Could not put image to window."

#endif