from typing import List, Set, Tuple

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Directions in the order of North, East, South, West
        direction_vectors = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        # Initial position and direction (0 -> North, 1 -> East, 2 -> South, 3 -> West)
        x, y = 0, 0
        direction = 0
        
        # Convert obstacles to a set of tuples for O(1) lookup
        obstacle_set: Set[Tuple[int, int]] = set(map(tuple, obstacles))
        
        # Variable to store the maximum distance squared
        max_distance_squared = 0
        
        for command in commands:
            if command == -2:
                # Turn left (counterclockwise)
                direction = (direction - 1) % 4
            elif command == -1:
                # Turn right (clockwise)
                direction = (direction + 1) % 4
            else:
                # Move forward command units
                for _ in range(command):
                    # Calculate the next position
                    next_x = x + direction_vectors[direction][0]
                    next_y = y + direction_vectors[direction][1]
                    
                    # Check if the next position is an obstacle
                    if (next_x, next_y) not in obstacle_set:
                        # Update the position
                        x, y = next_x, next_y
                        # Update the maximum distance squared
                        max_distance_squared = max(max_distance_squared, x * x + y * y)
                    else:
                        # Stop moving if an obstacle is encountered
                        break
        
        return max_distance_squared
