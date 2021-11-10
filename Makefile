# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 18:43:10 by ashea             #+#    #+#              #
#    Updated: 2020/08/05 18:43:40 by ashea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCE = ft_color_walls \
	ft_create_distance \
	ft_create_info \
	ft_draw_sprite \
	ft_find_player \
	ft_find_sprite \
	ft_key_hook \
	ft_paint_map \
	ft_read_ceilling \
	ft_read_file \
	ft_read_floor \
	ft_read_map \
	ft_read_path \
	ft_save \
	ft_valid \
	ft_cub3 \
	ft_change_position \
	ft_close \
	ft_create_img \
	ft_search_wall \
	ft_color_floor_ceilling \
	ft_change_hook \

SOURCE_BONUS = ft_color_walls_bonus \
	ft_create_distance_bonus \
	ft_create_info_bonus \
	ft_draw_sprite_bonus \
	ft_find_player_bonus \
	ft_find_sprite_bonus \
	ft_key_hook_bonus \
	ft_paint_map_bonus \
	ft_read_ceilling_bonus \
	ft_read_file_bonus \
	ft_read_floor_bonus \
	ft_read_map_bonus \
	ft_read_path_bonus \
	ft_save_bonus \
	ft_valid_bonus \
	ft_cub3_bonus \
	ft_mini_bonus \
	ft_draw_shot_bonus \
	ft_change_position_bonus \
	ft_close_bonus \
	ft_press_key_bonus \
	ft_create_img_bonus \
	ft_create_s_arg_bonus \
	ft_search_wall_bonus \
	ft_color_floor_ceilling_bonus \
	ft_change_hook_bonus \
	ft_draw_gun_knife_bonus \
	ft_draw_hud_bonus \
	ft_bar_bonus \
	ft_drow_treasures_bonus \
	ft_drow_enemy_bonus \
	ft_create_sprite_arguments_bonus \
	ft_hit_death_sprite_bonus \

RULE = $(addsuffix .c, $(addprefix source/, $(SOURCE)))

RULE_BONUS = $(addsuffix .c, $(addprefix source_bonus/, $(SOURCE_BONUS)))

OBJ = $(RULE:.c=.o)

OBJ_BONUS = $(RULE_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra ./library/lib* -I./include

all: $(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ)

bonus:  $(OBJ_BONUS)
	gcc -o $(NAME) $(FLAGS) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	rm -f *.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

run: clean
	./$(NAME) map/map.cub

.PHONY: all bonus clean fclean re run
