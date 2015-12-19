#!/bin/bash
echo "The difusion constant in file  $1 is:"
grep 1e  $1 | colrm 1 13 | colrm 9 
