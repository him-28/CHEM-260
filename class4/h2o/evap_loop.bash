#!/bin/bash
for i in h2o???.gro; do
count_evap $i >> evap.txt
done
