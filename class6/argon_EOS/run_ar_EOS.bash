#!/bin/bash
temps=(200 300) #Set temperatures to run
presses=(10 25 50) #Set pressure to run
gromacsrc=/usr/local/gromacs-4.5.5/bin/GMXRC.bash

if [ -f $gromacsrc ]; then
    source $gromacsrc
else
    echo "Could not find gromacs resource file"
fi
if ! type grompp &> /dev/null; then #Test if we find gromacs
    echo "Could not find gromacs software"
    exit 1
fi

#Test if we have the necessary ar files
if [ ! -f ar.top ] || [ ! -f ar.gro ] || [ ! -f ar.template.mdp ]; then
    echo "Missing critical ar file"
    exit 1
fi

if [ -f EOS_data.txt ]; then rm EOS_data.txt; fi 

echo " T   P   Dens"
for temp in ${temps[@]}; do  # Loop over temperatures
    for press in ${presses[@]}; do  # Loop over pressures

# Create ar.mdp file
	cat ar.template.mdp | sed s/@TEMP/$temp/ > ar.temp.mdp
	cat ar.temp.mdp | sed s/@PRESS/$press/ > ar.mdp

# Create ar.tpr
	if [ -f ar.tpr ]; then rm ar.tpr; fi  # Remove ar.tpr if it exists
	grompp -f ar.mdp -c ar.gro -p ar.top -o ar.tpr &> grompp.log  

	if [ ! -f ar.tpr ]; then  # Test if ar.tpr created
	    echo "Trouble, grompp did not create ar.tpr"
	    exit 1
	fi

# Remove ar.edr if it exists
	if [ -f ar.edr ]; then rm ar.edr; fi   

	mdrun -deffnm ar &> mdrun.log # Run MD

	if [ ! -f ar.edr ]; then  # Test if ar.xtc created
	    echo "Trouble, mdrun did not create ar.edr"
	    exit 1
	fi

    # Calculate density
	g_energy -f ar.edr &> g_energy.log << EOF
14
EOF

    # Extract density constant from output & print with temperature
	echo -n $temp $press " "
	grep "^Density" g_energy.log | colrm 1 27 | colrm 10
	echo -n $temp $press " "  >> EOS_data.txt
	grep "^Density" g_energy.log | colrm 1 27 | colrm 10 >> EOS_data.txt
    done
done

# Calculate compressibility factor using R script
if [ ! -f calc_Z.R ]; then
    echo "Trouble, I could not find calc_Z.R"
    exit 1
fi

# Use R in batch mode
Rscript calc_Z.R

echo
echo "Final Results Table"
# Echo results to screen
cat Z_data.out
rm \#*
