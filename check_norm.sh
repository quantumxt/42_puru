#!/bin/bash

VERSION='0.2.0'

# Define colors
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

OK=0
KO=0
SHOW_SRC=false

help_menu ()
{
    echo "Usage: ./check_norm.sh [OPTION]"
    echo "Norminette checker, counts number of OK & KO."
    echo ""
    echo "OPTIONS"
    echo -e "  -h\t\tShow the help menu."
    echo -e "  -s\t\tPrint the content (source code) of each file checked."
}

print_header ()
{
echo -e "
${BLUE}
   _  ______  ___  __  ___  _______           __  
  / |/ / __ \/ _ \/  |/  / / ___/ /  ___ ____/ /__
 /    / /_/ / , _/ /|_/ / / /__/ _ \/ -_) __/  '_/
/_/|_/\____/_/|_/_/  /_/  \___/_//_/\__/\__/_/\_\ 
                                                   
Version ${VERSION}
${NC}
"
}

print_header

# Get options
while getopts "hs" flag; do
 case $flag in
   h) # Handle the -h flag
   help_menu
   exit 0
   ;;
   s)
   SHOW_SRC=true
   ;;
   c) # Handle the -c flag, requires arg
   COMPILATION_CORE=$OPTARG
   ;;
   \?)
   # Handle invalid options
   echo "Invalid option, ignoring..."
   exit 0
   ;;
 esac
done


file_found=$(find . -iname "*.c" -o -iname "*.h")

echo -e "Files: $(echo "$file_found" | wc -l)\n>> Run Check...\n" 

for i in $(echo "$file_found" | sort)
do
  if [ "$SHOW_SRC" == true ] ; then
  	echo -e "\n========== $i ==========\n"
  	cat $i
  fi
  res=$(norminette $i)

  if echo "$res" | awk '{print $2}' | grep -q  "OK!"; then
    echo -e "${GREEN}<< $res${NC}"
    OK=$(($OK + 1))
  else
    echo -e "${RED}<< $res${NC}"
    KO=$(($KO + 1))
  fi 
done

echo -e "\n<< OK: ${GREEN}$OK${NC}\tKO: ${RED}$KO${NC}\n"
