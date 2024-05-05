# Steiner-Tree Routing Algorithm

Authors: Adithya Pillai Ramesh, Dan Jose Jinoy, Noah James DeGroot## Input


## Problem Description

This programming assignment asks you to implement a Steiner-tree router 
that can connect pins for a single net on a single-layer chip. 
Given a set of pins for a single net, the Steiner-tree router routes all pins within a chip. 
Pins are connected by horizontal lines (H-line) and/or vertical lines (V-line). 
Steiner points are allowed to be used during routing.
The objective of Steiner-tree routing is to minimize the total routing wirelength. 
The total routing wirelength $W$ of a set of $P$ can be computed by the following:

$$
W = \sum_{pi \in P} w(p_i) + d
$$

where $p_i$ denotes an H-line or a V-line in the line segment set $P$ and $w(p_i)$ denotes the real routing wirelength of $p_i$. Here, $d$ denotes the disjoing cost evaluated by the following:

$$
d = 2 \times U \times H
$$

where $U$ is the number of unconnected pins and $H$ is the half perimeter wirelength (HPWL) of the chip boundary.

## Input
The input file starts with the chip boundary, followed by the description of pins. The description of each pin contains the keyword PIN, followed by the name and the coordinate of the pin. 

| Input Format | Example |
| ------------ | ------- |
| Boundary = (llx,lly), (urx,ury)<br> NumPins = number <br> PIN name (x,y) <br> ...| Boundary = (0,0), (100,100) <br> NumPins = 3 <br> PIN p1 (20,30) <br> PIN p2 (50,30) <br> PIN p3 (50,90)|

The sample input for the format defines a net with three pins, `p1`, `p2`, and `p3`.

## Output

| Input Format | Example |
| ------------ | ------- |
| NumRoutedPins = number <br> Wirelength = number <br> H-line (x1,y) (x2,y) <br> V-line (x,y1) (x,y2) <br> ... | NumRoutedPins = 3 <br> WireLength = 90 <Br> V-line (50,30) (50,90) <br> H-line (20,30) (50,30) |


## Compiling the Code

Once you download and unzip the code, it can be compiled in linux using the following syntax:

```bash
g++ -O3 pa3.cpp pa3.h [executable file name]
```

## Program Command 

The program is ran in linux using the following commands:


```bash
[executable file name] [input file name] [output file name]
```

For example:

```bash
~$ ./router input_pa3/case1 output1
```

