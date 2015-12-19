#!/bin/bash
if [ $1 –le 100 ] || [ $2 –ge 1000 ]; then
echo "Range given ($1 to $2) not in (100 to 1000)"
exit 1
fi
