#!/bin/bash

if [ -x "./lem_in" ]; then
    if [ -f "$1" ]; then
        echo "Running lem_in with input from $1..."
        time ./lem_in < "$1"
    else
        echo "Error: file not found"
    fi
else
    echo "Error: lem_in executable not found"
fi
