#!/bin/bash

# Loop indefinitely
while true; do
    # Choose next move randomly
    row=$((RANDOM % 3 + 1))
    col=$((RANDOM % 3 + 1))

    # Make move
    makeMove $row $col
done

