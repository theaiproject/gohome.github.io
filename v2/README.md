For Go Home v2.0 I want to redo v1.0 with user input driven navigation. What's the best way to do this?
I can start with a map

x x x x |   | x | x | x | x | x | x |   | x x x x
x x x x |                               | x x x x
x x x x |   | x | x | x | x | x | x |   | x x x x
x x x x     | x | x | x | x | x | x |     x x x x
--------                |                --------
|           | x | x | x | x | x | x |            |
|           | x | x | x | x | x | x |            |
|                     | x |                      |
|                                                |
--------------------         ---------------------
                |               |
                |               |
                |               |
                |               |
                -----------------

A map would be well represented by a matrix, but I'll need to represent objects in the environment somehow instead of just having an empty grid.
We can start with an empty map with walls that the player cannot move to, represented by 0.
We are going to need a legend, actually.
Invalid space: 0
Valid space: 1

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 1 0
0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0
0 1 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 1 0
0 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 0
0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 0
0 1 1 1 1 1 1 1 1 1 1 1 0 0 0 1 1 1 1 1 1 1 1 1 1 1 0
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

This is all well and good, but there are problems here.
1. It's barely readable
2. We need interaction (objects?)

Let's rebuild the map except human readable

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0         0     0     0   0     0     0         0
0   0 0   0 0   0 0   0   0   0 0   0 0 ^ ^ v v 0
0   0 0   0                           0 ^ ^ v v 0
0                                               0
0 0 0 0 0 0           0 0 0           0 0 0 0 0 0
0 0 0                 0 0 0                 0 0 0
0   0                                       0   0
0       0   0 0   0 0       0 0   0 0   0       0
0 0 0   0     0     0       0     0     0   0 0 0
0   0   0 0 0 0 0 0 0       0 0 0 0 0 0 0   0   0
0       0     0     0       0     0     0       0
0 0 0   0   0 0   0 0 0 0 0 0 0   0 0   0   0 0 0
0                     0   0                     0
0                     0 0 0                     0
0                                               0
0 0 0 0 0 0 0 0 0 0 0       0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0           0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0           0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0           0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Now that's better. I'd like to print a variant of this for the player so they can tell where they are.
The matrix shouldn't contain so many spaces though I should figure. I also need to add interactable objects
List of interactables
1. Generic wall - "I can't go there."
2. Empty space - move player to new location and print map again
3. Elevator - "press elevator button?"
4. Receptionist's desk - "It's the receptionist's desk"
5. Generic cubicle - "Computer, papers, phone, and...is that drool?"
6. Table - "Meetings are hosted here"
7. Stairs - "Go up/down the stairs?"
8. Zombie first time - "Agh, it's a zombie!"
9. Zombie second time - "You die."
10. Orange juice - "You pick up the orange juice."
11. Zombie with orange juice in inventory - "The zombie drinks your orange juice and feels a lot better." (pacified)
12. Window - "As much as I like to lick the window glass while on shift, now isn't the time."

Interactables should be interacted with when the player moves to them. Phases should exist
1. Move phase
2. Interaction resolution phase
    1. figure out what the object is
    2. print out its text
    3. apply resolution
        1. fail state
        2. win state
        3. add zombie movement phase
        4. pacify zombie
Zombie movement should be a phase that only moves the zombie if the zombie has been interacted with

How will these interactables be represented in the matrix?
There are fewer than 256 interactables, so a char matrix should be used.
0 = Wall
1 = Valid space
2 = Window
3 = Cubicle
4 = Table
5 = Receptionist's desk
6 = Stairs
7 = Elevator
8 = Orange juice
9 = Zombie 1st interaction
10 = Zombie 2nd interaction
11 = Zombie with orange juice in inventory

Each object should be represented as a structure with fields:
    ID: the number it refers to
    Description: the object's description to print
    Resolution: what happens when the object is interacted with

The zombie should just be a single object. The resolution should determine how many times they have been interacted with.
How should the resolution be handled programmatically? I need to think on this when I'm not sleepy