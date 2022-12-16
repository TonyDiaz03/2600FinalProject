#!/bin/bash

# Loop indefinitely
while true; do
    # Prompt user for input
    read -p "Enter row and column: " row col

    # Check for specific input
    if [ "$row" == "q" ] || [ "$col" == "q" ]; then
        # Quit game if "q" is entered
        break
    elif [ "$row" == "1" ] && [ "$col" == "1" ]; then
        # Make move at row 1, column 1
        makeMove 1 1
    elif [ "$row" == "1" ] && [ "$col" == "2" ]; then
        # Make move at row 1, column 2
        makeMove 1 2
    elif [ "$row" == "1" ] && [ "$col" == "3" ]; then
        # Make move at row 1, column 3
        makeMove 1 3
    else
        # Invalid input
        echo "Invalid input. Try again."
    fi
done

