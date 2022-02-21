set terminal png size 1024, 768
set output 'mkl.png'
set style fill solid 0.25 border -1
set style boxplot outliers pointtype 7
set xlabel "Dimension of Square Matrices"
set ylabel "Time Taken (in ms)"
set yrange [0: 300]
set style data boxplot
plot 'mkl_plot.txt' using (1):2:(0.5):1 title "MKL"