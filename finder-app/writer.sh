#!/bin/bash

writefile=$1
writestr=$2

# check args
if [ -z $writefile ] || [ -z $writestr ]; then
    echo "Error: arguments missing"
    exit 1
fi

# make directory
writedir=$(dirname "$writefile")
mkdir -p "$writedir"

# redirect file
echo "$writestr" > "$writefile"

#check
if [ $? -ne 0 ]; then
    echo "Error: Could not create file"
    exit 1
fi

exit 0 
