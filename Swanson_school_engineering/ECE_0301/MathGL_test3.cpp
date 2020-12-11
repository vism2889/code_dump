/*
 * MathGL_test3.cpp
 */

#include <mgl2/mgl.h>
#include <iostream>

int main() {
	// min time & max time for plot
	double t_min = 0, t_max = 2;
	
	// array length
	int N = (t_max-t_min)*100;
	
	// arrays for t, x(t)
	double t[N], x[N];
	
	// loop to make x(t) = 1
	for (int i=0; i<N; i++)
	{
		t[i] = t_min + i*(t_max-t_min)/N;
		x[i] = 1;
	}
	
	// MathGL objects from the mglData class for plotting
	mglData t_mgl(N), x_mgl(N);
	
	// copy (t, x) to (t_mgl, x_mgl) using public member variable a
	for (int i=0; i<N; i++)
	{
		t_mgl.a[i] = t[i];
		x_mgl.a[i] = x[i];
	}
		
	// Create mglGraph object
	mglGraph gr;
	
	// Set title
	gr.Title("Plot of DC Signal");
	
	// Set axis ranges as (x start, x end, y start, y end)
	gr.SetRanges(t_min, t_max, -1.2, 1.2);
	
	// Set the origin of the graph
	gr.SetOrigin(0, 0);
	
	// Set tick markers as (axis, spacing, num sub-ticks, origin, label)
	gr.SetTicks('x', (t_max-t_min)/5, 0, t_min, "");
	
	// Create axis
	gr.Axis();
	
	// Put a string at (start point, end point, string value)
	gr.Puts(mglPoint(-0.2, -0.1), mglPoint(-0.2, 0.1), "x(t)");
	
	// Same as above, but string is horizontal if no second point
	// is given
	gr.Puts(mglPoint( (t_max + t_min)/2, -0.5), "t");
	
	// Plot the function in x_mgl versus t_mgl.
	gr.Plot(t_mgl, x_mgl);
	
	// Write the plot to eps & png files
	gr.WriteEPS("plot1.eps");
	gr.WritePNG("plot1.png");

	return 0;
}
