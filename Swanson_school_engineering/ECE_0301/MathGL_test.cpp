#include <mgl2/mgl.h>

int main() {
	
	// Create mglGraph object
	mglGraph gr;
	
	// Set title
	gr.Title("Sin Wave");
	
	// Set range as (x start, x end, y start, y end)
	gr.SetRanges(0, 6*M_PI, -1.2, 1.2);
	
	// Set the origin of the graph
	gr.SetOrigin(0, 0);
	
	// Set the tick markers as (axis, spacing, ?, ?, label)
	gr.SetTicks('x', M_PI, 0, 0, "\\pi");
	
	// Create axis
	gr.Axis();
	
	// Put a string at (start point, end point, string value)
	gr.Puts(mglPoint(-1,-0.2), mglPoint(-1,0), "y-axis");
	
	// Same as above, but string is horizontal if no second point
	// is given
	gr.Puts(mglPoint(3*M_PI,-1.2), "x-axis");
	
	// Plot a function written in a string
	gr.FPlot("sin(9*x)");
	
	// Write the plot to a png file
	gr.WriteFrame("sin.png");

	return 0;
}
