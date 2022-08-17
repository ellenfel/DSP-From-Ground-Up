## Convolution
### output.html file

if graph does not appear chances are gnuplot didn't add the following lines to the end of the 'output.html' file so add them after the lines of:

```
ctx.closePath();
ctx.stroke();
```

coppy-paste this part:
```
// plot boundaries and axis scaling information for mousing 
gnuplot.plot_term_xmax = 1300;
gnuplot.plot_term_ymax = 600;
gnuplot.plot_xmin = 52.0;
gnuplot.plot_xmax = 1275.9;
gnuplot.plot_ybot = 580.0;
gnuplot.plot_ytop = 10.1;
gnuplot.plot_width = 1223.9;
gnuplot.plot_height = 569.9;
gnuplot.plot_axis_xmin = 0;
gnuplot.plot_axis_xmax = 350;
gnuplot.plot_axis_ymin = -1.5;
gnuplot.plot_axis_ymax = 1.5;
gnuplot.plot_axis_x2min = "none"
gnuplot.plot_axis_y2min = "none"
gnuplot.plot_logaxis_x = 0;
gnuplot.plot_logaxis_y = 0;
gnuplot.plot_timeaxis_x = "";
gnuplot.plot_timeaxis_y = "";
gnuplot.plot_axis_width = gnuplot.plot_axis_xmax - gnuplot.plot_axis_xmin;
gnuplot.plot_axis_height = gnuplot.plot_axis_ymax - gnuplot.plot_axis_ymin;
}
</script>
<link type="text/css" href="/usr/local/share/gnuplot/5.4/js/gnuplot_mouse.css" rel="stylesheet">
</head>
<body onload="gnuplot_canvas(); gnuplot.init();" oncontextmenu="return false;">

<div class="gnuplot">
<canvas id="Tile" width="32" height="32" hidden></canvas>
<table class="plot">
<tr><td>
    <canvas id="gnuplot_canvas" width="1300" height="600" tabindex="0">
	Sorry, your browser seems not to support the HTML 5 canvas element
    </canvas>
</td></tr>
</table>
</div>

</body>
</html>
```

canvas output:
![alt text](https://github.com/ellenfel/DSP-From-Ground-Up/blob/master/Convolution/canvas-output.png?raw=true)


So we've designed a low pass filter.
It's taken a input signal(input_signal.dat).
and convolved with this impulse response signal(impulse_response.dat) and get the output signal as a result.
Like we designed,  impulse response signal has a cut-off frequency of 6 kHz.
So in effect it's a low pass filter.
What we have represented as an output signal is just has 1 kHZ and this 1 kHz signal was hidden
within the input signal that is a 15 kHz signal.
But by using our convolution algorithm we've been able to successfully filter out the high frequency
components.

### GNU Plot
```
gnuplot> set terminal canvas
gnuplot> set output 'output.html'
gnuplot> set terminal canvas rounded size 1300,600
gnuplot> reset
gnuplot> set size 1,1
gnuplot> set multiplot
multiplot> set size 0.5,0.5
multiplot> set origin 0,0.5
multiplot> plot 'input_signal.dat' with lines lc rgb 'black'
multiplot> set origin 0.5,0.5
multiplot> plot 'impulse_response.dat' with lines lc rgb 'red'
multiplot> set origin 0,0
multiplot> plot 'output_signal.dat' with lines lc rgb 'blue'
```

## Running-Sum Algorithm

![alt text](https://github.com/ellenfel/DSP-From-Ground-Up/blob/master/Convolution/RunningSum-CanvasOutput.png?raw=true)

So this is the resort produced by the running-sum algorithm and from here we can tell that the
Running-sum algorithm can be used as a smoothing filter
It works a bit like the moving-average filter.  Which can be used to smooth out a signal without indicating the cutoff frequency.
By using a simple running sum algorithm, You can take out the noise and do things like peak detection.
Imagine we are writing an algorithm to detect the peaks in the given input signal signal.
It's going to be rather difficult to detect a peak in the signal course you've caught so much noise and there multiple local peaks in each cycle. So the algoritm wowuld work faster if the signal goes through running-sum algorithm before processing

### output file and gnuplot
Almost exact same steps apply in this algorithm as well. just add the lines that given for convolution to end of your html file
for producing the graph you wont need the lines of
```
multiplot> set origin 0.5,0.5
multiplot> plot 'impulse_response.dat' with lines lc rgb 'red'
```
other than that its exactly same. Just maybe set the output file name, something other than `output.html` so it wouldn't overwrite in to convulion graph 
