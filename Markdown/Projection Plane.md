# ✅ What projection_plane actually is
```C
double projection_plane = (cub->half_width.0) / tan(FOV / 2.0);
```

This is precomputed to represent the distance between the player (camera) and the projection plane (screen), assuming a symmetric Field of View (FOV).

    Think of it like this:
    In a real 3D camera, how far is the screen from your eye so that objects look proportionally correct?

This distance is used to scale world objects (like walls) so that their height looks right on screen, based on distance.

# ✅ What does it do in projection?
```C
line_height = (BLOCK_SIZE / result.dist) * projection_plane;
```

Here's what's happening:

    `BLOCK_SIZE / result.dist`: gives a raw unscaled height — e.g., how big the wall "should" look at this distance.

    * projection_plane: scales it to screen space, based on current screen width and FOV.

Example:

Suppose:
```C
    BLOCK_SIZE = 64 (each wall block is 64 units high)

    result.dist = 128 (you’re 2 blocks away from wall)

    projection_plane = 320 (from WIDTH=640 and FOV=60°)
```
Then:
```C
line_height = (64 / 128) * 320 = 0.5 * 320 = 160 pixels
```

So the wall will be drawn 160 pixels high in screen space — looks smaller the farther it is.
# ✅ Summary of your statement

    "the projection_plane is the factor that tells me how objects in this window width and with this FOV can appear and how their dimensions are projected or scaled"

✅ 100% correct.
# ✅ Do I need to use it everywhere?

You should use it any time you're converting real-world units (BLOCK_SIZE) into screen-space pixels based on distance and FOV — especially for vertical projections.

That includes:

-    Wall heights

-    Sprite scaling

-    (optionally) floor/ceiling projection tricks

# ✅ Optimization tip

You're right again: you don’t need to recompute it every frame or every ray.

Just compute once in your init_cub():
```C
cub->proj_plane = (cub->half_width.0) / tan(FOV / 2.0);
```

Then use cub->proj_plane everywhere.
