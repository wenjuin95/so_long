// #include "./minilibx-linux/mlx.h"
// #include <X11/X.h>
// #include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include "../libft/libft.h"

#define HEIGHT 1000
#define WIDTH 1000

//learn how to use key for event
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
 * static int is to keep the value of i
 * if the key is ESC, the program is terminated
 * if the key is D, the program prints the number of times (i++;)
 * 
 *  * KEYSYM vs KEYCODE
 * A keycode is a hardware-specific code sent by the keyboard for a key press, 
 * while a keysym is its abstract representation, 
 * often used in software to identify the key regardless of hardware.
*/
int	handle_input(int keysym, t_mlx_data *data)
{
    static int i = 0;
	if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
	i++;
	if (keysym == XK_d)
        printf("The %d key (d) has been pressed %d\n\n", keysym, i);
	if (keysym == XK_w)
        printf("The %d key (w) has been pressed %d\n\n", keysym, i);
	if (keysym == XK_s)
        printf("The %d key (s) has been pressed %d\n\n", keysym, i);
		if (keysym == XK_a)
        printf("The %d key (a) has been pressed %d\n\n", keysym, i);
    
	//printf("Total %d key has been pressed\n\n", i);
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