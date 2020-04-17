#!/bin/bash

FILE=$1
if [ -f "$FILE" ]; then
    echo "$FILE exist"
    now=$(date +"%T")
    cp "$FILE" "$(FILE).bak$(now)"
    
fi

