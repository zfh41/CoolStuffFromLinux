
#!/bin/bash

DIRECTORY=$1

if [ $# -eq 0 ];
then
    for f in $PWD/*; do
        if [ -f "$f" ] && [ ! -s "$f" ]; then
            traverse "${f}" | rm -r "$f";
        fi
    done
else
    for f in $DIRECTORY/*; do
        if [ -f "$f" ] && [ ! -s "$f" ]; then
            traverse "${f}" | rm -r "$f";
        fi
    done
fi
