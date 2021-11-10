/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:42:52 by ashea             #+#    #+#             */
/*   Updated: 2020/08/14 00:29:06 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../include/mlx.h"
# include "../include/libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define R_KEY 15
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define DOWN_KEY 125
# define SPACE_KEY 49
# define SHIFT_KEY 257
# define TAB_KEY 48

typedef struct		s_sprite
{
	int				x;
	int				y;
	float			dist;
}					t_sprite;

typedef struct		s_sprite_arg
{
	int				flag_sprite;
	int				flag_achtung;
	int				life;
	int				patron;
	unsigned int	time;
}					t_sprite_arg;

typedef struct		s_sprites
{
	t_sprite		*sprites;
	int				count;
}					t_sprites;

typedef struct		s_img_win
{
	void			*ptr;
	unsigned int	*addr;
}					t_img_win;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_player
{
	int				x;
	int				y;
	float			look;
}					t_player;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_map
{
	int				x;
	int				y;
	char			**content;
}					t_map;

typedef struct		s_path
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_path;

typedef struct		s_data
{
	t_resolution	resolution;
	int				floor_color;
	int				ceilling_color;
	t_map			map;
	t_player		player;
	t_sprites		s;
	t_path			path;
}					t_data;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_img
{
	void			*ptr;
	int				width;
	int				height;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_info
{
	t_mlx			mlx;
	t_data			data;
	t_img			img_no;
	t_img			img_so;
	t_img			img_we;
	t_img			img_ea;
	t_img			img_s;
	t_img			img_s2;
	t_img			img_s3;
	t_img			img_win;
	t_img			img_gun;
	t_img			img_gun2;
	t_img			img_gun3;
	t_img			img_gun4;
	t_img			img_gun5;
	t_img			img_knife;
	t_img			img_knife2;
	t_img			img_knife3;
	t_img			img_knife4;
	t_img			img_knife5;
	int				time_gun;
	t_mouse			mouse;
	t_img			img_aim;
	int				flag_button;
	int				flag_mini;
	t_sprite_arg	**s_arg;
	int				count_patron;
	char			*patron;
	t_img			img_patron;
	t_img			img_life;
	int				count_life;
	char			*life;
	t_img			img_game_over;
	t_img			img_win_over;
	int				look_up;
	t_img			img_treasure;
	t_img			img_treasure2;
	int				flag_squat;
	t_img			img_no_d;
	t_img			img_so_d;
	t_img			img_we_d;
	t_img			img_ea_d;
	t_img			img_no2;
	t_img			img_so2;
	t_img			img_we2;
	t_img			img_ea2;
	t_img			img_no3;
	t_img			img_so3;
	t_img			img_we3;
	t_img			img_ea3;
	int				count_sprites;
	int				flag_lvl;
	int				flag_right;
	int				flag_right_mouse;
	int				flag_left;
	int				flag_left_mouse;
	int				flag_w;
	int				flag_s;
	int				flag_a;
	int				flag_d;
	int				flag_up;
	int				flag_down;
	int				flag_up_mouse;
	int				flag_down_mouse;
	t_img			img_floor;
	t_img			img_sky;
	int				flag_win_over;
	int				flag_game_over;
	t_img			img_instruction;
	int				flag_instruction;
}					t_info;

typedef struct		s_distance
{
	float			distance;
	int				h;
	float			hit;
	float			angle;
	int				vertical;
	int				x;
	int				y;
	int				flag_door;
	float			distance_d;
	float			hit_d;
	int				x_d;
	int				y_d;
}					t_distance;

typedef struct		s_ray
{
	float			x;
	float			y;
	float			delta_x;
	float			delta_y;
	float			angle;
	int				flag_vert;
}					t_ray;

typedef struct		s_sprite_arguments
{
	float			sprite_dir;
	int				sprite_screen_size;
	int				h_offset;
	int				v_offset;
}					t_sprite_arguments;

void				ft_create_bm_file(int size, int size_x, int size_y, int fd);
void				ft_save_screen(t_info *info);
void				ft_find_player(t_info *info);
t_player			ft_return_player(int x, int y, char content, int *count);
void				ft_find_sprite(t_info *info);
void				ft_return_sprite(t_info *info);
void				ft_sort_sprite(t_info *info);
void				ft_read_map(t_info *info, char *line, int *valid, int ft);
t_map				ft_create_map(t_info *info, int x, int y, char *world_map);
int					ft_valid_line(t_info *info, char *line, int len);
int					ft_valid_line_dop(t_info *info, char *line);
int					ft_valid_map(t_info *info);
unsigned int		ft_create_color(t_color color);
void				ft_read_floor(t_info *info, char *line,
		char **information, int *valid);
void				ft_read_floor_dop(t_info *info, char **information);
void				ft_read_ceilling(t_info *info, char *line,
		char **information, int *valid);
void				ft_read_ceilling_dop(t_info *info, char **information);
void				ft_read_path_no(t_info *info,
		char **information, int *valid);
void				ft_read_path_so(t_info *info,
		char **information, int *valid);
void				ft_read_path_we(t_info *info,
		char **information, int *valid);
void				ft_read_path_ea(t_info *info,
		char **information, int *valid);
void				ft_read_path_s(t_info *info,
		char **information, int *valid);
void				ft_read_file(t_info *info, int ft);
void				ft_read_file_arguments(t_info *info,
		char *line, int *valid);
void				ft_read_resolution(t_info *info,
		char *line, char **information, int *valid);
int					ft_key_hook(int keycode, t_info *info);
void				ft_change_position(t_info *info,
		int change_x, int change_y);
void				ft_stop_all(const char *error_str, t_info *info);
int					ft_close(t_info *info);
void				ft_create_info(t_info *info);
int					ft_paint_map(t_info *info);
void				ft_paint_map_dop(t_info *info, int *limit,
		t_distance distance, int i);
t_distance			ft_create_distance(t_info *info, int i);
t_distance			ft_vertical_tracing(t_info *info, float angle);
t_distance			ft_horizontal_tracing(t_info *info, float angle);
t_distance			ft_search_wall(t_info *info, t_ray *ray);
int					ft_look_up(float f);
int					ft_look_right(float f);
int					ft_color_walls(t_info *info, int y, t_distance *distance);
void				ft_draw_sprite(t_info *info, t_distance *dist);
void				ft_draw_sprite_dop(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int count);
void				ft_draw_sprite_dop_dop(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i);
int					ft_close_x(t_info *info);
void				ft_create_map_pixel_mini(t_info *info);
void				ft_patron_bar(t_info *info);
void				ft_life_bar(t_info *info);
void				ft_draw(t_info *info);
void				ft_play_sound(void);
int					ft_key_hook_r(int keycode, t_info *info);
int					ft_draw_shot(int button, int x, int y, t_info *info);
int					ft_draw_shot_hit(int button, int x, int y, t_info *info);
int					ft_valid_column(t_info *info);
void				ft_open_door(t_info *info, int y, int x);
void				ft_close_door(t_info *info, int y, int x);
void				ft_press_space(t_info *info, int press);
void				ft_press_tab(t_info *info);
void				ft_press_shift(t_info *info);
void				ft_key(t_info *info, int keycode, int press);
t_img				ft_create_img_win(t_info *info);
t_img				ft_create_img(t_info *info, char *path,
		int size_x, int size_y);
t_img				ft_create_img_scale(t_info *info, t_img img,
		int size_x, int size_y);
void				ft_create_info_texture(t_info *info);
void				ft_create_info_sprite(t_info *info);
void				ft_create_info_hud(t_info *info);
void				ft_create_info_flag(t_info *info);
void				ft_create_s_arg(t_info *info);
void				ft_search_wall_dop(t_info *info, t_ray *ray,
		t_distance *dist);
void				ft_search_wall_door(t_info *info, t_ray *ray,
		t_distance *dist);
int					ft_color_walls_we(t_info *info, int pos,
		t_distance *distance);
int					ft_color_walls_ea(t_info *info, int pos,
		t_distance *distance);
int					ft_color_walls_no(t_info *info, int pos,
		t_distance *distance);
int					ft_color_walls_so(t_info *info, int pos,
		t_distance *distance);
void				ft_map_pixel_mini_dist(t_info *info,
		int k_x, int k_y, float *f);
void				ft_create_map_pixel_mini_dop(t_info *info, int *i);
void				ft_create_map_pixel_mini(t_info *info);
int					ft_if_end_of_map(t_info *info, int k_x, int k_y, float *f);
int					ft_if_walls(t_info *info, int k_x, int k_y, float *f);
void				ft_mouse_hook(t_info *info);
void				ft_change_position_hook(t_info *info);
void				ft_change_look_vertical_hook(t_info *info);
void				ft_change_look_horizontal_hook(t_info *info);
void				ft_draw_gun(t_info *info);
void				ft_draw_knife(t_info *info);
void				ft_draw_wall_sprite(t_info *info);
void				ft_draw_hud(t_info *info);
void				ft_game_over(t_info *info);
void				ft_win_over(t_info *info);
int					ft_paint_map(t_info *info);
int					ft_color_floor(t_info *info, t_distance *distance, int y);
int					ft_color_ceilling(t_info *info,
		t_distance *distance, int i, int j);
void				ft_paint_map_dop(t_info *info, int *limit,
		t_distance distance, int i);
void				ft_color_floor_dop(t_distance *distance,
		float *floorxwall, float *floorywall);
int					ft_color_floor(t_info *info, t_distance *distance, int y);
int					ft_color_ceilling(t_info *info,
		t_distance *distance, int i, int j);
void				ft_life_bar(t_info *info);
void				ft_patron_bar(t_info *info);
void				ft_drow_treasures(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i);
int					ft_if_long_away(t_info *info, int *i, int flag_sprite);
void				ft_сollecting_treasures(t_info *info, int *i);
void				ft_drow_enemy(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i);
int					ft_if_closer_walls(t_info *info, t_distance *dist,
		t_sprite_arguments *arg, int *i);
void				ft_achtung_sprite(t_info *info, int *i);
void				ft_shot_sprite(t_info *info, int *i);
void				ft_create_sprite_arguments(t_info *info,
		t_sprite_arguments *arg, int count);
int					ft_hit_or_shot(t_info *info,
		t_sprite_arguments *arg, int count);
int					ft_if_hit(t_info *info, int x, int y, int count);
int					ft_if_head_shot(t_info *info,
		t_sprite_arguments *arg);
int					ft_if_hit_shot_knife(t_info *info,
		t_sprite_arguments *arg);
int					ft_death_sprite(t_info *info,
		int flag_head_shot, int x, int y);
void				ft_hit_sprite(t_info *info, int x, int y);
#endif
