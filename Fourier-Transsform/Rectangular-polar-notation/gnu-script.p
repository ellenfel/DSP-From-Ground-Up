set terminal canvas

set terminal canvas rounded size 1300, 600

set output 'rect-polar_CANVAS-OUTPUT.html'
reset
set size 1,1
set multiplot
set size 0.5,0.5
set origin 0,0.5
plot 'input_rex.dat' with lines lc rgb 'red'

set origin 0.5,0.5
plot 'input_imx.dat' with lines lc rgb 'red'

set origin 0,0
plot 'output_mag.dat' with lines lc rgb 'blue'

set origin 0.5,0
plot 'output_phase.dat' with lines lc rgb 'blue'

