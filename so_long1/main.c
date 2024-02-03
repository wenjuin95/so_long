#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 1000
#define WIDTH 1000

// int main()
// {
// 	//learn how to open window with c
// 	void	*mlx;
// 	void	*mlx_win;
// 	//initialize the pointer
// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 	{
// 		free(mlx);
// 		reutrn (1);
// 	}
// 	//create a window
// 	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hello world");
// 	if (mlx_win == NULL)
// 	{
// 		free(mlx_win);
// 		reutrn (1);
// 	}
// 	// maintain a loop to ensure  window will still be displayed on the screen.
// 	mlx_loop(mlx);
// }


// int main()
// {
//	//this to learn how to put image
// 	void *mlx;
// 	void *win;
// 	void *img;
// 	void *path;
// 	int img_height;
// 	int img_width;
//	//get the path
// 	path = "./asset/enermy.xpm";
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, width, height, "Hello World!");
// 	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, win, img, 500, 500);
// 	mlx_loop(mlx);
// 	return 0;
// }


// int main()
// {
// 	//this to learn how to draw
// 	void	*mlx;
// 	void	*mlx_win;	
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hello world");
// 	//this nested loop for a line 
// 	//red
// 	for (int h = 0; h < 100; h++)
// 	{
// 		for (int v=0; v < 100; v++)
// 		mlx_pixel_put(mlx, mlx_win, 500+h, 500+v, 0xFF0000);
// 	}
// 	for (int h = 0; h < 100; h++)
// 	{
// 		for (int v=0; v < 100; v++)
// 		mlx_pixel_put(mlx, mlx_win, 500+h, 600+v, 0x00FF00);
// 	}	
// 	mlx_loop(mlx);
// }


#include <X11/X.h>

/*
 * MLX_STRUCT
 * I stock all the data into a struct
 * because the handler function takes 
 * (void *)pointer_to_data
 * I need therefore this gimmick to 
 * pass more elements in one-go
*/
typedef struct s_mlx_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}               t_mlx_data;

/*
 * HANDLER FUNCTION 
 * Every time a key is pressed this function is called
 *
 * KEYSYM vs KEYCODE
 * A keycode is a hardware-specific code sent by the keyboard for a key press, 
 * while a keysym is its abstract representation, 
 * often used in software to identify the key regardless of hardware.
 * 🚨 MinilibX mac uses keycodes 🚨
*/
int	handle_input(int keycode, t_mlx_data *data)
{
    //Check the #defines
    //find / -name keysym.h 2>/dev/null
    //find / -name keysymdef.h 2>/dev/null
    if (keycode == 65307)
    {
        printf("The %d key (ESC) has been pressed\n\n", keycode);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keycode);
    return (0);
}


int	main(void)
{
    t_mlx_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 
                                WIDTH, 
                                HEIGHT,
                                "My first window!");
    if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }

    /*
     * HOOKS
     *  "Hooking into events" (react to events)
     * When i press a key, handle_input() is triggered
     * 💡 Every event is linked to its own prototype handler 💡
    */
    mlx_key_hook(data.win_ptr, 
                handle_input, 
                &data);

    // Leave the control to the EVENT LOOP
    mlx_loop(data.mlx_ptr);
}