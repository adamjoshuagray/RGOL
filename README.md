# RGOL
Conway's Game of Life with Randomization

A good outline of the "traditional" Conway's Game of life can be found on [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).
 
What this code seeks to do is to add some randomness to process. So the usual rules are:

- Any live cell with fewer than two live neighbours dies.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies.
- Any dead cell with exactly three live neighbours becomes a live cell.

but what if we changed this to include the phrase "with a 99% probability" at the end of each line?

We could be even more general, by considering a model where given the current state of the square and
number of live neighbours it has, we become alive or dead (or stay) with some differing probabilities. 
This is exactly the model that we have implemented here.

An interesting extension to this would be to have varying probabilities, depending where on the grid
the square was. This might be like simulating different environmental conditions.

These models are interesting in two senses (that I can think of at the moment anyway):

- The long run evolution of the model: Does any interesting complexity naturally arises with 
 sufficiently long runtimes?
 
- The average evolution of the board given an initial condition.




 
 
