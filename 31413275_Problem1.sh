#!/bin/bash

PASSED=$1

if [ -d "${PASSED}" ] ; then
    echo "$PASSED is a directory";
    echo "The user permissions: "$(ls -ld ${PASSED} | cut -b 2-4);
elif [ -f "${PASSED}" ]; then
    echo "${PASSED} is a file";
    echo "The user permissions: "$(ls -lt ${PASSED} | cut -b 2-4);
    echo "The size of the file: "$(du 31413275_Problem1.sh | cut -b -2);
    if [ $(du 31413275_Problem1.sh | cut -b -2) -le 1048576 ] && [ $(du 31413275_Problem1.sh | cut -b -2) -gt 102400 ]; then
        echo "Medium File";
    elif [ $(du 31413275_Problem1.sh | cut -b -2) -gt 1048576 ]; then
        echo "Large File";
    else
        echo "Small File";
    fi
else
    echo "${PASSED} is not valid";
    exit 1
fi
