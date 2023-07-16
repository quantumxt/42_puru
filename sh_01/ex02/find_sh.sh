#!/bin/bash
for i in $(find . -iname '*.sh' -type f)
do
  strip_par=$(basename $i)
  echo ${strip_par%.*}
done
