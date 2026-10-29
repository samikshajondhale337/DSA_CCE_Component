# Algorithm

1. Start the program.
2. Read the number of locations.
3. Input the cost matrix representing roads between locations.
4. Select the source vertex (warehouse).
5. Initialize all distances to infinity, visited values to false, and parent values to -1.
6. Set the source distance to zero.
7. Select the unvisited vertex with the minimum distance.
8. Update the distances of its neighboring vertices if a shorter path is found.
9. Repeat Steps 7–8 until all reachable vertices are processed.
10. Display the shortest distances from the source.
11. Display the menu with the following options:
    - Change source vertex.
    - Display the shortest path.
    - Update road cost.
    - Display shortest distances.
12. If the source changes, reset the arrays and run Dijkstra’s algorithm again.
13. If a destination is selected, use the parent array to display the complete shortest path.
14. If a road cost is updated, modify the cost matrix and recalculate the shortest distances.
15. Repeat the menu until the user selects Exit.
16. Stop the program.
