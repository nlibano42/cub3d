/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:26:49 by ruramire          #+#    #+#             */
/*   Updated: 2023/10/24 19:12:55 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../utils/libft/libft.h"

// Keycodes for mlx
# define DESTROY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2
//

// Keycodes for Mac
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define INT_MAX 2147483647

// The above code is defining the size of the window
# define CUB 10
//

typedef struct s_parse
{
	char			**all;
	char			**map;

	char			*ceiling;
	char			*floor;

	char			*west;
	char			*east;
	char			*south;
	char			*north;

	int				w_index;
	int				e_index;
	int				s_index;
	int				n_index;

	int				c_index;
	int				f_index;

	int				map_index;
}					t_parse;

typedef struct s_valid_data
{
	unsigned int	ceiling[3];
	unsigned int	floor[3];
	char			*so;
	char			*no;
	char			*ea;
	char			*we;
	char			**maps;
	int				map_len;
	int				line_len;
	char			player;
}					t_valid_data;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w_win;
	int				h_win;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_mlx;
typedef struct s_key
{
	int				x;
	int				y;
	int				pov;
}					t_key;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_texture;

typedef struct s_norm
{
	double			first_x;
	double			first_y;
	double			step_x;
	double			step_y;
	double			cub_distance;
	double			wall_height;
	int				start;
	int				end;
	unsigned int	color;
	t_texture		*choice_txt;
	double			start_angle;
}	t_norm;

typedef struct s_all
{
	t_parse			parse;
	t_valid_data	valid;
	t_mlx			mlx;
	t_key			key;
	unsigned int	len;
	int				x_p_pos;
	int				y_p_pos;
	double			x_player;
	double			y_player;
	double			direction_ang;
	double			rotation_speed;
	double			horizontal_distance;
	double			verticale_distance;
	double			ver_x;
	double			ver_y;
	double			hor_x;
	double			hor_y;
	double			x_offset;
	t_texture		w_txt;
	t_texture		e_txt;
	t_texture		n_txt;
	t_texture		s_txt;
	t_norm			norm;
}					t_all;

// mlx_utils
void				init_mlx(t_all *data);
int					mlx_close(t_all *data);
int					mlx_key_release(int keycode, t_all *data);
int					mlx_key(int keycode, t_all *data);
int					mlx_keypress(t_all *data);
void				my_mlx_pixel_put(t_all *data, int x, int y, \
					unsigned int color);

// list of functions that are used to move the player around the map.
void				rotate_left_and_right(t_all *data, int direction);
void				move_player(t_all *data, int x_factor, int y_factor);

// parsing
int					parsing(char *av, t_all *data);

// parsing utils
void				init_data(t_all *data);
int					is_valid_filename(char *av);
int					read_file(char *file, t_all *data, int i);

// free
void				free_parsing(t_all *data);
void				free_all(t_all *data);
void				free_rgb(char **rgb);
void				free_textures(t_all *data);
void				free_map(char **arr);

// get textures and colors
int					get_dir_meta(t_all *d, const char *dir, \
					char **dest, int *index);

// get_all
int					load_and_validate_metadata(t_all *data);
void				load_map_data(t_all *data, int i, int len, int temp);

// check
int					check(t_all *data);

// check colors
int					check_ceiling(t_all *data, int j);
int					check_colors(t_all *data);

// check_colors_utils
int					cout_comma(char *str);
int					check_is_rgb(char **rgb);
int					fill_ceiling(char **color, t_all *data);
int					fill_floor(char **color, t_all *data);

// check_textures
int					check_textures(t_all *data);

// check_textures_utils
int					open_file(char *str);
void				init_textures(t_all *data);

// check_map
int					check_is_white_spaces(char *str);
int					check_map(t_all *data);
unsigned int		big_len(t_all *data);
void				init_map(t_all *data);
int					check_characters(t_all *data);
int					first_and_last_char(char **str, int map_len, int line_len);
int					search(char *src, char *str);
int					endmap_index(char **str);
void				add_space(t_all *data);
void				init_angle(t_all *data);
int					check_valid_map(t_all *data);
int					check_player(t_all *data, int i, int j, int player);
int					middle_char(t_all *data, int i, int j, int start);
int					middle_char_helper(t_all *data, int i, int j);
int					zero_checker(t_all *data, int i, int j);
int					space_checker(t_all *data, int i, int j);
int					is_empty(char *str);
int					check_wall(t_all *data, double y, double x);
int					check_wall_y(t_all *data, int x_wall, int y_wall);
int					check_wall_x(t_all *data, int x_wall, int y_wall);

// drawing
int					draw(t_all *data);
void				init_player_position(t_all *data, int x, int y, int *player);
double				normalize_angle(double ang);
double				calculate_distance(t_all *data, double y, double x);
int					is_left(double ang);
int					is_up(double ang);
unsigned int		get_color(t_texture txt, double y, t_all *data, \
					double wall_h);
unsigned int		get_color_value(t_all *data, char *type);

// intersection
void				horizontal_inter_helper(t_all *data, double ang, \
					int *index_x, int *index_y);
void				horizontal_inter_init(t_all *data, double ang);
void				horizontal_inter(t_all *data, double ang);
void				vertical_inter_init(t_all *data, double ang);
void				vertical_inter_helper(t_all *data, \
					double ang, int *index_y, int *index_x);
void				vertical_inter(t_all *data, double ang);

#endif
