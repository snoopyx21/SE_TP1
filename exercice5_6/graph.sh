#!/bin/bash

# we need a file with raw data to graph
if [ "$#" -ne "2" ]
then
    echo "Usage: ./$0 raw-data-file" 1>&2
    exit 1
fi

# the first arg is the filename
f=$1


img=res_$2.png

gnuplot << EOF
set grid
set xlabel "Taille buffer"
set ylabel "Vitesse  (secondes)"
set title "Comparaison temps selon taille de buffer entre fct bibli et prim sys "

plot \
    "${f}" using 1:2 with linespoints lt 1 title "Primitive Système",\
    "${f}" using 1:3 with linespoints lt 2 title "Getchar"
set terminal png
set output "${img}"
replot
EOF
