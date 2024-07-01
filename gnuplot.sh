set term pngcairo size 4000,2400
set output sprintf("output.png")

set key font ",25" box lt -1 lw 2 height 1 opaque
set grid lw 1 lt -1 dashtype 5
set xtics nomirror font ",20"
set ytics nomirror font ",20"
set tmargin 7
set bmargin 8
set lmargin 15

set xlabel "X-Axis" font ",28" offset 0,-2
set ylabel "Y-Axis" font ",28" offset -1,0
plot "data" u 1:2 pt 5 ps 3 title "Linear Relation", "data" u 1:3 w l lt 6 lw 5title "Non-Linaear Relation"

