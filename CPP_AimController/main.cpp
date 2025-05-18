#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    std::ifstream input("aim_settings.json");
    if (!input.is_open()) {
        std::cerr << "Error: aim_settings.json not found." << std::endl;
        return 1;
    }

    json settings;
    try {
        input >> settings;
        float rotationSpeed = settings["rotationSpeed"];
        std::string targetBone = settings["targetBone"];

        std::cout << "Rotation Speed: " << rotationSpeed << std::endl;
        std::cout << "Target Bone: " << targetBone << std::endl;
    } catch (...) {
        std::cerr << "Error: Invalid JSON format." << std::endl;
        return 1;
    }

    return 0;
}
