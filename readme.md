## SimFishy (COMP 11, S14)

Mid-year COMP-11 project dealing with a simulation of a fish tank and its fish(es - I know it's wrong, but it sounds better so whatever). Objects, or fish, are fed into the program (name, size, velocity, ASCII image) and are then simulated by the object holder (tank). Built so that essentially any object of any size made up of any ASCII characters can be simulated. Pretty good framework for basic animation.

#### Object / Fish Input:

To input, just funnel any text file with the following format and it'll simulate the object-container (tank) and object (fish). Initially define size of tank:
```
tank [tank_height] [tank_width]
```
And then feed in any objects (fish) as you'd like:

```
fish [img_height] [img_width] [init_y_pos] [init_x_pos] [vertical_speed] [horizontal_speed] [object_name]
       _.-,
   .--'  '-._
 _/`-  _      '.
'----'._`.----. \
           `   \ \
                ;_\
```
Then just funnel (`<`) the .txt, .dat, etc. into the program.

