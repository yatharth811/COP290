set terminal png size 1024, 768
set output 'FCLayer.png'
set style fill solid 0.25 border -1
set style boxplot outliers pointtype 7
set xlabel "Dimension of Square Matrices"
set ylabel "Time Taken (in ms)"
set yrange [0: 5000]
set style data boxplot
plot 'FCLayer.txt' using (1):2:(0.5):1 title "FCLayer"