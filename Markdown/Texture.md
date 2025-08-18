 PLAYER (pos, angle)  --->  cast ray(angle_i)
                                   |
                                   v
                             DDA algorithm
                                   |
                         result: side, map_pos, hit_point, dist
                                   |
                                   v
                       Perpendicular distance correction
                                   |
                                   v
                      projection_plane → line_height (screen)
                                   |
                                   v
               compute wallX (fractional hit position on wall)
                                   |
                                   v
                      texture_x = int(wallX * tex.width)
                                   |
                                   v
       step = tex.height / line_height   // how much to advance in texture per screen px
                                   |
                                   v
       tex_pos = (start_y - screen_mid + line_height/2) * step   // initial sample y
                                   |
                                   v
   for screen y in [start_y .. end_y]:
       texture_y = int(tex_pos)
       color = tex[texture_y][texture_x]
       put_pixel(screen x, y, color)
       tex_pos += step
