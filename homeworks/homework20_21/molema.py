atomicMass = {"H" : 1.008, "O" : 15.999, "C" : 12.011, "N" : 14.007}
molecule = "H2O"
mass = atomicMass["H"] * 2 + atomicMass["O"]
print("\nMolecule: " + molecule + " - Mass: " + str(mass))
