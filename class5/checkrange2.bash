#!/bin/bash
if [ $1 -ge 100 ] && [ $2 -le 1000 ]; then
echo "Arguments give reasonable range"
else
echo "Range given ($1 to $2) not in (100 to 1000)"
exit 1
fi
