#!/bin/bash
N=$1
DIRECTORY=$2

traverse(){
    f=$1
    if [ -d "$f" ]; then
        for q in $f/*; do
            if [ -f "$q" ]; then
                LC_ALL=C grep -o -E '([[:alnum:]]+\.?)+@(([[:alnum:]]+-*)+[[:alnum:]]+)\.([[:alpha:]]+\.?)+' $q >> rpemails.txt
            else
                 traverse "$q"
            fi
        done
    fi
}


for f in $DIRECTORY/*; do
    traverse "$f"
    if [ -f "$f" ]; then
        LC_ALL=C grep -o -E '([[:alnum:]]+\.?)+@(([[:alnum:]]+-*)+[[:alnum:]]+)\.([[:alpha:]]+\.?)+' $f >> rpemails.txt
    fi
done

sort rpemails.txt | uniq -c > finalSort.txt
sort -n -r finalSort.txt > final.txt
cat final.txt >> finalEmails.txt

head -$N finalEmails.txt > topemails.txt

#iterate through the finalEmails.txt

grep -o -E '@(([[:alnum:]]+-*)+[[:alnum:]]+)\.([[:alpha:]]+\.?)+' topemails.txt | sort | uniq > domains.txt

sort rpemails.txt | uniq > rawemails.txt

#grep the emails that have the @domain

while read domain; do
    while read email; do
        if [[ $email == *$domain* ]]; then
            echo "$email" >> emails_top_domains.txt
        fi
    done < rawemails.txt
done < domains.txt

rm finalEmails.txt final.txt finalSort.txt rawemails.txt rpemails.txt domains.txt
    

