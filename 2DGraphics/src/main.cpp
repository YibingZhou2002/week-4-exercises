#include "../include/Scene.h"
#include <memory>
#include <iostream>
#include <fstream>

int main() {
    // Create a 600x400 scene with white background
    Scene scene(600, 400, Color(240, 240, 240));
    
    // Add a blue circle with velocity
    auto blueCircle = std::make_unique<Circle>(Point(200, 200), 30, Color(0, 0, 255));
    blueCircle->setVelocity(50, 30);  // 50 pixels per second in x, 30 in y
    scene.addShape(std::move(blueCircle));
    
    // Add a red rectangle with velocity
    auto redRectangle = std::make_unique<Rectangle>(Point(350, 250), 60, 40, Color(255, 0, 0));
    redRectangle->setVelocity(-40, 60);
    scene.addShape(std::move(redRectangle));
    
    // Add a green circle with velocity
    auto greenCircle = std::make_unique<Circle>(Point(300, 150), 20, Color(0, 255, 0));
    greenCircle->setVelocity(70, -50);
    scene.addShape(std::move(greenCircle));
    
    // Animate the scene for 5 seconds at 24 fps
    std::cout << "Generating animation frames..." << std::endl;
    scene.animate(5.0, 24, "frame");
    std::cout << "Generated " << scene.getFrameCount() << " frames" << std::endl;
    
    // Create a script to convert the PPM files to a GIF or MP4 (if ImageMagick is installed)
    std::ofstream scriptFile("create_animation.sh");
    if (scriptFile) {
        scriptFile << "#!/bin/bash\n";
        scriptFile << "# This script converts the generated PPM frames to an animated GIF\n";
        scriptFile << "# Requires ImageMagick to be installed\n\n";
        scriptFile << "convert -delay 4 -loop 0 frame_*.ppm animation.gif\n";
        scriptFile << "echo \"Animation saved as animation.gif\"\n";
        scriptFile.close();
        
        // Make the script executable
        std::system("chmod +x create_animation.sh");
        std::cout << "Created script 'create_animation.sh' to convert frames to GIF" << std::endl;
    }
    
    return 0;
}
