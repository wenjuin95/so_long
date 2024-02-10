#include <time.h>
#include <stdio.h>

// Initialize lastTime to current time and frames to 0
static clock_t lastTime = 0;
static int frames = 0;

void calculateFPS()
{
    // Increment the frame count
    frames++;

    // Get the current time
    clock_t currentTime = clock();

    // Calculate the difference in time since the last FPS calculation
    clock_t delta = currentTime - lastTime;

    // If a second or more has passed since the last FPS calculation
    if (delta >= CLOCKS_PER_SEC)
    {
        // Calculate the FPS as the number of frames divided by the time in seconds
        double fps = (double)frames / ((double)delta / CLOCKS_PER_SEC);

        // Reset the frame count and lastTime to current time
        frames = 0;
        lastTime = currentTime;

        // Print the FPS
        printf("FPS: %.2f\n", fps);
    }
}

int main()
{
	// Loop forever
	while (1)
	{
		// Calculate the FPS
		calculateFPS();
	}

	return 0;
}