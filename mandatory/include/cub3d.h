/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:56:24 by pro               #+#    #+#             */
/*   Updated: 2022/12/22 19:07:43 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// # include <string.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 500
# define GREEN_PIXEL 0xFF00
# define RED 0xFF0000
# define WHITE_PIXEL 0xFFFFFF
# define WALL 0x5454C5
# define SPACE 0x639CD9
# define YELLOW 0xFFFF00
# define DARK_YELLOW 0xd7d708
# define DARK 0x342056
# define GRID_SIZE 32

# define LEFT_ARROW 123
# define RIGHT_ARROW 124

# define ESC 53
# define W_KEY 13
# define D_KEY 2
# define S_KEY 1
# define A_KEY 0

# define MOVE_STEP 4
# define VIEW_ANGLE 1.0472
# define NBR_RAYS WINDOW_WIDTH

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;
}	t_line;

typedef struct s_cub3d
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	char			**maps;
	int				floor[3];
	int				ciel[3];
	int				last_index;
	double			pos_player_x;
	double			pos_player_y;
	char			direction;
	int				height_of_map;
	int				width_of_map;
}	t_cub3d;

// mlx
typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		pos_player_x;
	int		pos_player_y;
	t_cub3d	*cub;
}	t_vars;

typedef struct s_inter {
	double	x_inter;
	double	y_inter;
	double	x_step;
	double	y_step;
}	t_inter;

typedef struct s_mini_map{
	int		top;
	int		right;
	int		left;
	int		bottom;
	char	**mini_map;
	int		i;
	int		j;
	int		k;
	int		l;
}	t_mini_map;

typedef struct s_mini_map_2{
	char	**mini_map;
	int		i;
	int		h;
	int		w;
	int		p1;
	int		p2;
	int		j;
}	t_mini_map_2;
// libft_functions
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_cub3d			*cub;
	t_mini_map		minimap;
	t_mini_map_2	mini;
	t_point			p1;
	t_point			p2;
	double			angle;
	int				key_press;
	int				key_to_move;
	int				key_to_move_left;
	int				key_to_oriented;
	unsigned int	*adr;
	unsigned int	*adr2;
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*we;
	unsigned int	*ea;
	int				x11;
	int				y11;
}	t_data;

typedef struct s_rect
{
	double	x;
	double	y;
	double	width;
	double	height;
	int		color;
}	t_rect;

typedef struct s_ray
{
	double	distance;
	int		hit_horizontale;
	t_point	*hit_point;
	double	ray_angle;
}	t_ray;

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strstr(char *str, char *to_find);
void	free_texture(char **split);
int		ft_strcmp(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
// getnext line
char	*get_next_line(int fd);
// utils
size_t	ft_len_ptr(char **ptr);
int		ft_is_digit(char *str);
// check map 1
int		check_exten(char *filename);
int		check_name_exc(char *filename);
int		read_file(char *file_name, t_cub3d *cubmap);
char	**remove_empty_line(char **map);
void	get_map(int size, int fd, t_cub3d *cubmap);
// check errors
int		check_colors_floor(char *color, t_cub3d *cubmap);
int		check_colors_ciel(char *color, t_cub3d *cubmap);
int		check_floor_ceil(int *number);
int		check_file_texture(t_cub3d *texture);
int		check_colors_floor(char *color, t_cub3d *cubmap);
int		check_colors(char **colors, t_cub3d *cubmap);
int		check_colors(char **colors, t_cub3d *cubmap);
void	add_textur(t_cub3d *cubmap, char *split, char *find);
int		add_textur_color(char **cubmap, int fd, int size, int last_size);
// maps
int		check_maps(t_cub3d *cubmap, char *namefile);
int		check_map_is_valid(t_cub3d *cubmap);
int		check_name_exc_texture(char *filename);
void	setup_player(char c, int pos_x, int pos_y, t_cub3d *cubmap);
//
void	move(t_data *data, int y, int x);
int		ft_esc(t_data *data);
int		ft_event(int keycode, t_data *data);
void	ft_move(t_data *data);
void	ft_oriented(t_data *data);
//
void	ft_end(t_data	data);
void	ft_init(t_data	*data, t_cub3d *cubmap);
void	ft_main(t_data	*data);
//
void	img_pix_put(t_img *img, int x, int y, int color);
void	create_image(t_data *data);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, t_data *data);
int		render(t_data *data);
void	dda(t_data *data, t_point p1, t_point p2);
int		ft_is_wall(char **map, int i, int j);
//utils2
int		ft_is_wall(char **map, int i, int j);
int		ft_handle_move_event(t_data *data, int keycode);
int		ft_handle_move_r_l(t_data *data, int keycode);
int		ft_handle_oriented_event(t_data *data, int keycode);
void	ft_oriented(t_data *data);
void	ft_move(t_data *data);
void	ft_move_left(t_data *data, char **map, double pa);
void	ft_move_right(t_data *data, char **map, double pa);
void	ft_move_down(t_data *data, char **map, double pa);
void	ft_move_up(t_data *data, char **map, double pa);
int		ft_event(int keycode, t_data *data);
// cast rays
void	ft_cast_rays(t_data *data);
double	norm_angle(double ray_angle);
int		ft_is_wall_2(char **map, int i, int j, t_point *p);
void	draw_map(t_data *data);
//rays2
double	norm_angle(double ray_angle);
int		ft_is_looking_down(double angle);
int		ft_is_looking_up(double angle);
int		ft_is_looking_right(double angle);
int		ft_is_looking_left(double angle);

//render 3d
void	ft_render3d(t_data *data, double ray_dist, \
int index_of_ray, t_ray *ray);
//bonus mini map
void	ft_mini_map(t_data *data);
void	get_mini_map(t_data *data, int x, int y, t_mini_map *minimap);
char	**check_m_map(t_data *data, int x, int y);
void	render_mini_map(t_data *data, t_mini_map_2 *mini);
// event
int		ft_handle_oriented_event(t_data *data, int keycode);
int		ft_handle_move_event(t_data *data, int keycode);
// texture
int		ft_is_looking_up(double angle);
int		ft_is_looking_right(double angle);
int		ft_esc(t_data *data);
int		ft_test(int keycode, t_data *data);
int		render_next_frame(t_data *data);
int		ft_mouse(int x, int y, t_data *data);
void	get_texture_adrr(t_data *data, t_cub3d *cubmap);
double	ft_init_direction(char direction);
int		ft_horiz_1(t_data *data, t_inter inter, double ray_angle, t_point *p2);
int		fr_horizontale(t_data *data, double ray_angle, t_point *p2);
int		ft_verti_1(t_data *data, t_inter inter, double ray_angle, t_point *p2);
int		fr_verticale(t_data *data, double ray_angle, t_point *p2);
double	ft_calc_distance(t_point p1, t_point p2);
int		create_trgb(int t, int r, int g, int b);

#endif
