# Car Video Game Simulation

[This project has been implemented in both Java and CPP separately]

This simple game consists of a rectangular room in which different kinds of toy cars are moving
around. All cars have some common properties:

1. You can set their position and initial direction of motion.
2. You can query them for their current position
3. You can ask them to move k steps in their current direction.

Different companies manufacture cars to these specifications, but each interprets and
implements the 3rd property differently. On being asked to move k steps (in instruction 3), they
all start moving in their current direction as far as they can without hitting a wall. However, on
hitting a wall, their behaviour is different. The cars, named Lemon, PingPong and Spinner, act
as follows:

1. Lemon: If it hits a wall of the room, it stops and does not move any further for the rest of
the game
2. PingPong: If it hits a wall, it reverses direction, that is, it turns back and completes the
remaining steps in this reversed direction
3. Spinner: If it hits a wall, it turns right and continues moving along the wall (i.e. with the
wall on its left) for the remaining steps.

We say a car “hits” a wall when it cannot move forward in its current direction.

For simplicity, we will consider that the game is run on a rectangular grid, and any position can
be specified as a pair (x,y) both of which are positive integers, and indices increase to the right
(x) and downwards (y). All positions of cars and walls as well as movements, are integer values.
We will assume that the grid is defined with (0,0) as the top left corner, (Thus, no negative
values for grid coordinates).

The room is defined by the coordinates of the top-left and bottom-right corners. The walls are
one unit beyond these points in all directions. Assume that the room width and height are
greater than 1. More than one car can occupy a grid cell at a time.

The 3 cars are modelled as 3 different classes, each implementing the expected behaviour of
that type of car.

The class Game has the following capabilities:
- You can set the bounds of the room by specifying its top-left and bottom-right
coordinates.
- you can add a car to the game, giving the initial position (grid coordinates) and
orientation (left, right, up, down) of the car.
- you can ask the game to advance all its cars by a specified number of steps. The game
in turn asks each car to move in their current direction by the specified number of steps

The main method does the following:
- Creates an instance of Game
- Reads the input to get the coordinates of the horizontal and vertical bounds of the room
(4 integers: left, right, top, bottom limits of the room)
- Reads the number of cars (integer on the next line)
- Reads the input to determine the type, initial position and initial direction of each car.
Each line of input has the name (a string - one of Lemon, PingPong, Spinner), the initial
position (x,y), and one of left, right, up, down
- Creates a car of the appropriate type and adds it to the Game object, specifying its initial
position and direction
- Reads two integers K and N. Asks the game object to move its cars by K steps, and
repeats this N times.
- Prints out the final position of each car in the order in which they were created. 


Sample input  
5 20 10 30  
4  
Lemon 12 20 right  
PingPong 8 15 right  
Spinner 15 25 right  
PingPong 10 30 left  
5 3  
   
Expected output  
20 20  
17 15  
15 30    
15 30  
