## Discrete Fourier Transform(DFT) and Inverse Discrete Fourier Transform(IDFT)

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
![alt text](https://github.com/ellenfel/DSP-From-Ground-Up/blob/master/images/IDFT.png?raw=true)


With dft algorithm we decompose the periodic-discrete input signal(plotted black) to two output signals(plotted red), being real(left) and imaginary(right). With  idft we took that same output files as inputs and synthesize the input signal from them(plotted blue). 
