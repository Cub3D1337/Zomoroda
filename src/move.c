/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:41:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/07/27 16:18:59 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// void    reset_player(t_cub *cub)
// {
//     t_pointi start_pos;
//     t_pointi end_pos;

//     start_pos.y = (int)cub->p.y - (cub->p.size / 2);
//     end_pos.y = (int)cub->p.y + (cub->p.size / 2);
//     while (start_pos.y < end_pos.y)
//     {
//         end_pos.x = (int)cub->p.x + (cub->p.size / 2);
//         start_pos.x = (int)cub->p.x - (cub->p.size / 2);
//         while (start_pos.x < end_pos.x)
//         {
//             printf("Start Pixel: y: %d    x: %d\n", start_pos.y, start_pos.x);
//             printf("End Pixel: y: %d    x: %d\n", end_pos.y, end_pos.x);
//             put_pixel(cub, start_pos.x, start_pos.y, 0x00ff00);
//             start_pos.x++;
//         }
//         start_pos.y++;
//     }
// }

// void    move(t_cub *cub)
// {
//     if (cub->p.move_up || cub->p.move_down
//         || cub->p.move_left || cub->p.move_right)
//     {
//         // reset_player(cub);
//         if (cub->p.move_up)
//         {
//             cub->p.y -= SPEED;
//         }
//         if (cub->p.move_down)
//         {
//             cub->p.y += SPEED;
//         }
        
//         if (cub->p.move_left)
//         {
//             cub->p.x -= SPEED;
//         }
//         if (cub->p.move_right)
//         {
//             cub->p.x += SPEED;
//         }
//         draw_player(cub);
//         mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
//         printf("Move\n");
//     }
// }


void reset_player(t_cub *cub)
{
    t_pointi start_pos;
    t_pointi end_pos;

    start_pos.y = (int)cub->p.prev_y - (cub->p.size / 2);
    end_pos.y = (int)cub->p.prev_y + (cub->p.size / 2);
    end_pos.x = (int)cub->p.prev_x + (cub->p.size / 2);
    while (start_pos.y < end_pos.y)
    {
        start_pos.x = (int)cub->p.prev_x - (cub->p.size / 2);
        while (start_pos.x < end_pos.x)
        {
            put_pixel(cub, start_pos.x, start_pos.y, 0x000000); // BLACK to erase
            start_pos.x++;
        }
        start_pos.y++;
    }
}


void move(t_cub *cub)
{
    if (cub->p.move_up || cub->p.move_down
        || cub->p.move_left || cub->p.move_right)
    {
        // Save previous position BEFORE moving
        cub->p.prev_x = cub->p.x;
        cub->p.prev_y = cub->p.y;

        // Move
        if (cub->p.move_up)
            cub->p.y -= SPEED;
        if (cub->p.move_down)
            cub->p.y += SPEED;
        if (cub->p.move_left)
            cub->p.x -= SPEED;
        if (cub->p.move_right)
            cub->p.x += SPEED;

        // Reset the square at previous position
        reset_player(cub); // NOW this will use prev_x / prev_y

        // Draw player at new position
        draw_player(cub);

        // Render frame
        mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img_ptr, 0, 0);
    }
}

