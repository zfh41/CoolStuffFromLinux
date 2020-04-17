#!/bin/bash

N=$1
DIRECTORY=$2

touch topemails.txt

touch emails_top_domains.txt

touch rpemails.txt
touch yolo.txt
touch hohoo.txt

if [ "$(ls -A $DIRECTORY)" ]; then
    LC_ALL=C grep -roE '[[:alnum:]]+(\.?[[:alnum:]])*@(([[:alnum:]]+-*)+[[:alnum:]]+)\.([[:alpha:]]+\.?)+[[:alnum:]]+' $DIRECTORY/* >> hohoo.txt
fi


LC_ALL=C grep -o -E '[[:alnum:]]+(\.?[[:alnum:]])*@(([[:alnum:]]+-*)+[[:alnum:]]+)\.([[:alpha:]]+\.?)+[[:alnum:]]+' hohoo.txt > rpemails.txt

sort rpemails.txt | uniq -c > finalSort.txt
sort -k1nr -k2 finalSort.txt > final.txt
cat final.txt >> finalEmails.txt

head -$N finalEmails.txt > topemails.txt

#iterate through the finalEmails.txt

grep -o -E '@(([[:alnum:]]+-*)+[[:alnum:]]+)\.([[:alpha:]]+\.?)+' topemails.txt | sort | uniq > domains.txt

sort rpemails.txt | uniq > rawemails.txt

#grep the emails that have the @domain

while read domain; do

    while read email; do

        if [[ $email == *$domain ]]; then

            echo "$email" >> yolo.txt

        fi

    done < rawemails.txt

done < domains.txt

sort yolo.txt > emails_top_domains.txt

rm finalEmails.txt final.txt finalSort.txt rawemails.txt domains.txt yolo.txt hohoo.txt rpemails.txt
