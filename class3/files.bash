#!/bin/bash
echo "Directory conatins this many files and dirs:"
pwd
ls | wc | colrm 10
