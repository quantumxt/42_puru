#!/bin/bash

# Define colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

OK=0
KO=0


echo -e "
   _  ______  ___  __  ___  _______           __  
  / |/ / __ \/ _ \/  |/  / / ___/ /  ___ ____/ /__
 /    / /_/ / , _/ /|_/ / / /__/ _ \/ -_) __/  '_/
/_/|_/\____/_/|_/_/  /_/  \___/_//_/\__/\__/_/\_\ 
                                                   
"
file_found=$(find . -iname "*.c" -o -iname "*.h")

echo -e "Files: $(echo "$file_found" | wc -l)\n>> Run Check...\n" 

for i in $(echo "$file_found" | sort)
do
  echo -e "\n========== $i ==========\n"
  cat $i
  res=$(norminette $i)
  echo -e "\n>> Result: "
  if echo "$res" | awk '{print $2}' | grep -q  "OK!"; then
    echo -e "${GREEN}$res${NC}"
    OK=$(($OK + 1))
  else
    echo -e "${RED}$res${NC}"
    KO=$(($KO + 1))
  fi 
done

echo -e "\n<< OK: ${GREEN}$OK${NC}\tKO: ${RED}$KO${NC}\n"
