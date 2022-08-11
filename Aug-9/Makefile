bisection.pdf:datos.txt script_plot.gp
	gnuplot script_plot.gp

datos.txt:bisection.x
	./$< > datos.txt

%.x:%.cpp
	g++ $< -o $@

clear:
	rm -r *.txt *.x
