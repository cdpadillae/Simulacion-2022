Bessel_0.pdf: Bessel_0.txt Bessel_plot.gp
	gnuplot Bessel_plot.gp

Bessel_0.txt: Bessel.x
	./$< > $@

%.x: %.cpp
	g++ $< -o $@

clear:
	rm -r *.txt *.x
