# Cheapest Flights Within K Stops


## Algorithm: Modified Bellman-Ford

The solution utilizes a variation of the **Bellman-Ford algorithm**. Standard Bellman-Ford finds the shortest path in a graph with up to $V-1$ edges (where $V$ is the number of vertices). Since we are restricted to at most $k$ stops, we can traverse at most $k+1$ edges. Therefore, we limit our algorithm to exactly $k+1$ iterations.

### Step-by-Step Explanation:

1.  **Initialization:** * Create an array `dist` of size $n$ (number of cities) initialized to a large value (like `1e9` or infinity) to represent the minimum cost to reach each city.
    * Set the distance to the source city to zero: `dist[src] = 0`.
2.  **Iteration ($k+1$ times):** * Loop $k+1$ times. Each iteration represents taking one more flight (edge) in the journey.
    * Create a temporary array `temp` and copy the current state of `dist` into it. *Why?* This prevents cascading updates within the same iteration. If we update city $B$ from city $A$, we shouldn't use city $B$'s new distance to update city $C$ in the *same* step, as that would represent taking two flights instead of one.
    * Iterate through all the given `flights`. For each flight `[u, v, w]` (from `u` to `v` with cost `w`):
        * If the source city `u` is reachable (`dist[u] != 1e9`), check if taking this flight offers a cheaper route to city `v`.
        * Update the temporary distance: `temp[v] = min(temp[v], dist[u] + w)`.
    * After checking all flights, update the main `dist` array: `dist = temp`.
3.  **Result:** * After $k+1$ iterations, check `dist[dst]`. 
    * If it is still `1e9`, the destination is unreachable within $k$ stops, so return `-1`. 
    * Otherwise, return `dist[dst]`.



## Complexity Analysis

Let $N$ be the number of cities and $E$ be the number of flights (edges). Let $K$ be the maximum number of allowed stops.

### Time Complexity: $O((K + 1) \cdot E)$
* We run an outer loop exactly $K+1$ times.
* Inside the outer loop, we iterate through every single flight in the `flights` array, which takes $O(E)$ time.
* Therefore, the total time complexity is proportional to the number of allowed edges multiplied by the total number of flights.

### Space Complexity: $O(N)$
* We allocate an array `dist` of size $N$ to track the minimum costs to each city.
* During each iteration, we create a `temp` array, also of size $N$. 
* Because the arrays scale linearly with the number of cities, the overall space complexity is $O(N)$.