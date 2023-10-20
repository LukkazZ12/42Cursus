######################## COLORS       ###############################
L_RED				=		\033[0;31m
L_REDB				=		\033[1;31m
L_WHITE				=		\033[0;37m
L_WHITEB			=		\033[1;37m
L_YELLOW			=		\033[0;33m
L_YELLOWB			=		\033[1;33m
L_GREEN				=		\033[0;32m
L_GREENB			=		\033[1;32m
######################## CONFIG	TESTS ###############################
HEADERS_TEST		=		-Icriterion-2.4.2/include/criterion
FLAGS 				=		-Wall -Werror -Wextra -g3 -O3 -MMD -MP
MINIRT_LIB			=		-I../minirt/includes
LIBFT_PATH			=		../minirt/libft
LIBFT_LIB			=		../minirt/libft/includes
MLX_PATH			=		../minirt/includes/mlx
MLX_LIB				=		../minirt/includes/mlx
VALGRIND_FLAG		=		valgrind --trace-children=yes --leak-check=full -q
LIB_CRITERION		=		-Lcriterion-2.4.2/lib -lcriterion
DEBUG				=		-g3
FLAG_MLX			=		-lm -ldl -lglfw -pthread
######################## PATHS        ###############################
PATH_OBJ			=		objs/
DIR_OUTS			=		outs/
DIR_FILES			=		fd_test/
OBJS_PROJECT		=		../minirt/objects/
UNIT_PATH			=		./unit_test/
VPATH				=		$(addprefix $(UNIT_PATH),					\
							matrices									\
							parser										\
							ray_casting									\
							tuples)
######################## PROJECT FILES ##############################
SRC_EXCLUDED		=		$(addprefix $(OBJS_PROJECT),				\
							minirt.o									\
							render.o)
SRC_PROJECT			=		$(filter-out $(SRC_EXCLUDED),				\
							$(wildcard $(OBJS_PROJECT)*.o))
######################## TEST SOURCES ###############################
MATRICES			=		are_equals_matrices_test.c					\
							copy_submatrix_test.c						\
							create_identity_matrix_test.c				\
							create_rotation_matrix_test.c				\
							create_scaling_matrix_test.c				\
							create_shearing_matrix_test.c				\
							create_translation_matrix_test.c			\
							calculate_cofactor_matrix_test.c			\
							calculate_determinant_test.c				\
							invert_matrix_test.c						\
							matrix_inverse_identity_test.c				\
							matrix_length_test.c						\
							multiply_matrices_test.c					\
							multiply_matrix_tuple_test.c				\
							transpose_matrix_test.c
PARSER				=		atod_test.c									\
							parser_test.c								\
							validate_amb_light_test.c					\
							validate_angle_test.c						\
							validate_camera_test.c						\
							validate_color_test.c						\
							validate_coordinates_test.c					\
							validate_cylinder_test.c					\
							validate_double_test.c						\
							validate_light_test.c						\
							validate_int_test.c							\
							validate_normalized_vector_test.c			\
							validate_plane_test.c						\
							validate_sphere_test.c
RAY_CASTING			=		calculate_ray_position_test.c				\
							calculate_ray_sphere_intersections_test.c	\
							calculate_sphere_normal_test.c				\
							get_hit_test.c								\
							intersections_test.c						\
							intersections_list_add_test.c				\
							new_intersection_test.c
TUPLES				=		add_tuples_test.c							\
							are_equals_test.c							\
							are_equals_tuples_test.c					\
							divide_tuple_test.c							\
							calculate_cross_product_test.c				\
							calculate_dot_product_test.c				\
							multiply_tuple_test.c						\
							negate_tuple_test.c							\
							normalize_vector_test.c						\
							subtract_tuples_test.c
SRC					=		$(MATRICES)									\
							$(PARSER)									\
							$(RAY_CASTING)								\
							$(TUPLES)
OBJ					=		$(patsubst %.c, $(PATH_OBJ)%.o, $(SRC))
DEP					=		$(patsubst %.c, $(PATH_OBJ)%.d, $(SRC))
EXEC_OUTS			=		$(wildcard $(DIR_OUTS)*)
ONE_TEST			=		$(patsubst %.c, $(PATH_OBJ)%.o, $(TEST_NAME))
######################## RULES        ###############################

all: create_outs_dir make_minirt $(PATH_OBJ) $(OBJ) $(EXEC_OUTS)

$(PATH_OBJ)%.o:	%.c
	@			$(CC)  $(FLAGS) $(MINIRT_LIB) -I$(LIBFT_LIB) -I$(MLX_LIB) $(HEADERS_TEST) -I$(UNIT_PATH) -c $< -o $@
	@			$(CC)  $(FLAGS) $(MINIRT_LIB) $(FLAG_MLX) $(HEADERS_TEST) -L$(LIBFT_PATH) -L$(MLX_PATH) $(LIB_CRITERION) -I$(UNIT_PATH) -g \
				$@ $(SRC_PROJECT) -o $(subst $(PATH_OBJ), $(DIR_OUTS), $(basename $@)) -lm -lft
	@			echo "$(L_GREEN)[$(subst objs/,,$@) compiled]$(L_WHITE)"

run-test: rm-obj create_outs_dir make_minirt $(PATH_OBJ) $(ONE_TEST)
	@			echo $(ONE_TEST%)
	@			echo "$(L_YELLOWB)[Run Test: $(L_WHITEB) $(TEST_NAME) $(L_YELLOWB)]: $(L_WHITE)"
	@			$(VALGRIND_FLAG) $(addprefix ./outs/, $(notdir $(basename $(TEST_NAME))))
	@			@if [ $$? -eq 0 ]; then \
					echo "Comando executado com sucesso"; \
				else \
					echo "Erro ao executar o comando"; \
				fi

rm-obj:
	@			rm -rf objs

$(PATH_OBJ):
	@			mkdir $@

-include $(DEP)

bypass: create_outs_dir $(TESTS)
	@echo
	-@for name in $(TESTS); do \
		echo "$(L_YELLOWB)$${name}: $(L_WHITE)"; \
		./$(DIR_OUTS)/$${name}; echo ; \
	done

make_minirt:
	@			$(MAKE) -s -C ../minirt
	@			echo "$(L_YELLOWB)[Make miniRT Objects]$(L_WHITE)"

create_outs_dir:
	@			mkdir -p $(DIR_OUTS)
	@			mkdir -p $(DIR_FILES)

$(EXEC_OUTS):
	@			echo "$(L_YELLOWB)[Run Test: $(L_WHITEB)$@$(L_YELLOWB)]: $(L_WHITE)" && $(VALGRIND_FLAG) ./$@;

clean:
	@			$(MAKE) -s -C ../minirt $@
	@			rm -rf objs
	@			rm -rf $(DIR_FILES)
	@			echo "$(L_RED)[$(L_YELLOW)Objects Removed! $(L_RED)$(OBJ)]$(L_WHITE)"

fclean: clean
	@			$(MAKE) -s -C ../minirt $@
	@			rm -rf outs fd_test
	@			echo "$(L_RED)[$(L_YELLOW)Removed! $(L_RED)$(EXEC_OUTS)]$(L_WHITE)"

re: fclean all

.PHONY: re fclean clean all $(TESTS) $(EXEC_OUTS)