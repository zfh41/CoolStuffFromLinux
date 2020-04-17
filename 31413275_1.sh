#!/bin/bash


for i in {A..Z}
do
        for z in {A..Z}
        do
                wget https://en.wikipedia.org/wiki/"$i$z" -O "$i$z".html
                lynx -dump –nolist "$i$z".html > "$i$z".txt
                cat "$i$z".txt >> wiki.txt
                rm "$i$z".html
                rm "$i$z".txt
        done
done


awk NF wiki.txt > wikiNF.txt
LC_ALL=C sed '/https:/d' wikiNF.txt > wikiNF1.txt
LC_ALL=C sed '/file:/d' wikiNF1.txt > wikiNF2.txt
LC_ALL=C sed '/http:/d' wikiNF2.txt > wikiNF3.txt


sort wikiNF3.txt | grep -o '[[:alpha:]]*[A-Za-z]' > sortWiki.txt
sort sortWiki.txt > finalSort.txt
LC_ALL=C sed '/^[b-z]$/d' finalSort.txt > singleC.txt
uniq -c singleC.txt > uniqSort.txt
sort -n -r uniqSort.txt > final.txt
head -15 final.txt

rm sortWiki.txt finalSort.txt singleC.txt uniqSort.txt final.txt wiki*.*
