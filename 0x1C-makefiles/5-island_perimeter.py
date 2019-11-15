#!/usr/bin/python3
"""Find the perimeter of an island."""


def island_perimeter(grid):
    """Returns the perimeter of an island"""
    perimeter = 0
    for i, row in enumerate(grid):
        for j, entry in enumerate(row):
            if entry == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if j == len(row) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
