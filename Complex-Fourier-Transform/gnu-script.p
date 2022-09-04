set terminal canvas

set terminal canvas rounded size 1300, 600

set output 'complex-dft-OUTPUT.html'
reset
set size 1,1
set multiplot
set size 0.5,0.5
set origin 0,0.5
plot 'input_rex.dat' with lines

set origin 0.5,0.5
plot 'input_imx.dat' with lines

set origin 0,0
plot 'output_rex.dat' with lines lc rgb 'blue'

set origin 0.5,0
plot 'output_imx.dat' with lines lc rgb 'blue'

