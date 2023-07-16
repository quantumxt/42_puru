#!/bin/bash
echo -e "BSQ Test Script\n"
echo -e "Build BSQ..."
make re
test_files=$(find . -iname "test*" | sort)
for i in $test_files
do
    echo -e "\n=============================\nTest map -> $i\n============================="
    if ! ./bsq "$i"; then
        echo "bsq failed on $i"
    fi
done
