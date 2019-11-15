#!/usr/bin/python3
"""Find the perimeter of an island."""


def island_perimeter(grid):
    """Returns the perimeter of an island"""
    perimeter = 0
    for i, row in enumerate(grid):
        for j, entry in enumerate(row):
            if entry == 1:
                perimeter += count_neighbor_zeros(grid, i, j)
    return perimeter


def count_neighbor_zeros(grid, i, j):
    """Returns number of zeros surrounding a grid index."""
    return 4 - sum([grid[i+1][j], grid[i-1][j], grid[i][j+1], grid[i][j-1]])
