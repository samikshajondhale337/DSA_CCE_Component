# Algorithm

Start the program.

Read the number of locations and roads.

Create a weighted graph using an adjacency list.

Read the source, destination, and travel cost of each road.

Select the warehouse as the source location.

Initialize the source distance to 0 and all other distances to infinity.

Insert the source into the priority queue.

Remove the location with the minimum distance from the priority queue.

Check its neighboring locations and update distances if a shorter route is found.

Store the previous location in the parent array.

Repeat Steps 8–10 until the priority queue is empty.

Display the minimum travel cost to each reachable location.

Read the selected delivery destination.

Reconstruct and display the shortest route using the parent array.

Stop.
