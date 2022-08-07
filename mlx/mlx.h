/*
	mlx.h for MinilibX

	Made by Charlie Root
	Login	<ol@staff.42.fr>

	Started on  Mon Jul 31 16:37:50 2000 Charlie Root
	Last update Tue Oct 01 16:23:28 2014 Olivier Crouzet
*/

#ifndef MLX_H
# define MLX_H


// Basic actions
void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
// origin for x & y is top left corner of the window, y down is positive, color is 0x00RRGGBB
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
void	*mlx_new_image(void *mlx_ptr,int width,int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
							int *size_line, int *endian);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
								int x, int y);
unsigned	mlx_get_color_value(void *mlx_ptr, int color);


// Hooks
int		mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop (void *mlx_ptr);


// IDK what this garbage is
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
						char *string);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
							int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
								int *width, int *height);
void	*mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int		mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);


// Mouse functions
int		mlx_mouse_hide();
int		mlx_mouse_show();
int		mlx_mouse_move(void *win_ptr, int x, int y);
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);


// Somethings something
int		mlx_do_key_autorepeatoff(void *mlx_ptr);
int		mlx_do_key_autorepeaton(void *mlx_ptr);
int		mlx_do_sync(void *mlx_ptr);

#endif /* MLX_H */
