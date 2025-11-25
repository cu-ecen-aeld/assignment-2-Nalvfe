#!/bin/bash

filesdir=$1
searchstr=$2

#check arguments
if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
    echo "Error: Missing arguments"
    exit 1
fi

#check directories
if [ ! -d "$filesdir" ]; then
    echo "Error: Directory does not exist"
    exit 1
fi

# files (x)
file_count=$(find "$filesdir" -type f 2>/dev/null | wc -l)

# match lines (y)
match_count=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

# output
echo "The number of files are $file_count and the number of matching lines are $match_count"

 
 
