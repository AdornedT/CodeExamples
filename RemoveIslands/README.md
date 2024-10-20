# removeIsland Function

## Overview
The `removeIsland` function processes a 2D matrix (grid) that represents a map of land (`1`) and water (`0`). The function identifies and removes isolated land masses (islands) that are completely surrounded by water. Any land connected to the border of the grid remains unaffected, while isolated inner land regions are converted to water.

## Problem Definition
Given a matrix consisting of `1`s and `0`s:
- `1` represents land.
- `0` represents water.

The task is to remove "islands" of land that are entirely surrounded by water. Islands are defined as regions of `1`s that are not connected to any land on the matrix's borders, either horizontally or vertically.

### Example
For the following grid:

```plaintext
[
  [1, 0, 0, 0, 1],
  [0, 1, 1, 0, 0],
  [0, 0, 1, 1, 0],
  [1, 0, 1, 0, 0],
  [1, 1, 0, 0, 1]
]

After applying the removeIsland function, the result should look like this:

[
  [1, 0, 0, 0, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 0],
  [1, 0, 0, 0, 0],
  [1, 1, 0, 0, 1]
]

```

## Requirements
The function should traverse the grid to identify which regions of land should be removed and which should be preserved.
Land connected to the borders of the grid must remain unchanged, as it is not considered isolated.
Only inner islands that are surrounded by water (not connected to borders) should be removed.

### Inputs
A 2D grid (matrix) consisting of 1s and 0s.

### Outputs
A modified 2D grid where all isolated islands have been removed, leaving only land connected to the grid's edges.

### Assumptions
The matrix will have at least one row and one column.
Islands are made up of horizontally or vertically connected land cells. Diagonally connected cells are not considered part of the same island.
Edge Cases
The grid is entirely land or entirely water.
All land is connected to the border.
Islands that consist of a single 1 surrounded by 0s should also be removed.
Usage
This function is useful for simulating geographical changes, particularly in map-based games or environmental simulations where isolated regions of land need to be removed or processed differently.