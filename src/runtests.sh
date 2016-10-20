S="./tester"
while read F
do
    S="$S $F"
done <<< "$(ls tests/*)"
S="$S results.txt"

$S

