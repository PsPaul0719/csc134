/*
CSC134
spencep
11/24/25
M6BONUS
*/



#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    // Image dimensions
    const int width = 800;
    const int height = 800;
    const int maxColor = 255;
    
    // Create output file stream
    std::ofstream imageFile("concentric_rings.ppm");
    
    if (!imageFile.is_open()) {
        std::cerr << "Error: Could not create file!" << std::endl;
        return 1;
    }
    
    // Write PPM header (P3 format - ASCII)
    imageFile << "P3\n";
    imageFile << width << " " << height << "\n";
    imageFile << maxColor << "\n";
    
    // Calculate center of image
    double centerX = width / 2.0;
    double centerY = height / 2.0;
    
    // Maximum distance from center to corner
    double maxDistance = std::sqrt(centerX * centerX + centerY * centerY);
    
    // Generate pixel data using nested loops
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate distance from current pixel to center
            double dx = x - centerX;
            double dy = y - centerY;
            double distance = std::sqrt(dx * dx + dy * dy);
            
            // Normalize distance to range [0, 1]
            double normalizedDist = distance / maxDistance;
            
            // Fade from green (center) to red (outside)
            // Green: RGB(0, 255, 0) -> Red: RGB(255, 0, 0)
            int red = static_cast<int>(normalizedDist * 255);
            int green = static_cast<int>((1.0 - normalizedDist) * 255);
            int blue = 0;
            
            // Write RGB values
            imageFile << red << " " << green << " " << blue << " ";
        }
        imageFile << "\n";
    }
    
    imageFile.close();
    std::cout << "Image 'concentric_rings.ppm' created successfully!" << std::endl;
    std::cout << "Dimensions: " << width << "x" << height << " pixels" << std::endl;
    
    return 0;
}