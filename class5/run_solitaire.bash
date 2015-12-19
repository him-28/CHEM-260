#!/bin/bash
# Script to run a series of solitaire simulations up to a specified
# maximum number of faces (starting at 2) and suits (starting at 2)

# First test that the simulation program is available and 
# the other inputs are in sensible ranges
if [ ! -x Solitaire.py ]; then
    echo "Could not find Solitaire.py with executable permission"
    exit 1
fi
if [ $# -ne 3 ]; then
    echo "Command requires 3 arguments.  Usage: run_solitaire.bash [Max Faces] [Max Suits] [Ntrials]"
    exit 1
fi
intregex='^[0-9]+$'
if ! [[ $1 =~ $intregex ]] || ! [[ $2 =~ $intregex ]] || ! [[ $3 =~ $intregex ]]; then
    echo "One of the arguments in not an integer $1 $2 $3"
    exit 1
fi

if [ $1 -gt 15 ] || [ $2 -gt 8 ]; then   ##### Need to fill in condition if $1 > 15
    echo "Limited to less than 15 faces and 8 suits"
    exit 1
fi
if [ $3 -gt 100000 ]; then   ##### Need to fill in condition that $3 > 100000
    echo "Limited to less than 100000 trials"
    exit 1
fi

echo "F S  %win"
# Loop over faces starting with 2
faces=2
while [ $faces -le "$1" ]  ##### Need to fill in condition that faces <= $1
do
    # Loop over suits starting with 2
    suits=2
    while [ $suits -le "$2" ] ##### Need to fill in condition that suits <= $2
    do
	let ncards=faces*suits
	let odd=ncards%2
	# Only run cases where we have an even number of cards
	if [ $odd -ne 1 ]; then
	    echo -n $faces $suits 
	    Solitaire.py $faces $suits $3 | colrm 1 21
	fi
	let suits++ ##### Need to fill operation that adds 1 to suits
    done
    let faces++ ##### Need to fill in operation that adds 1 to faces
done
