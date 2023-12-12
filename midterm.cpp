#include <iostream>
#include <vector>

class Plastic_Window {
private:
    int Glass_count;
    std::string Frame_material;
    int Fastening_elements_count;
    std::string Glass_package_manufacturer;
    std::string Frame_manufacturer;
    std::string Color;
    double Price;

public:
    // Default constructor
    Plastic_Window() : Glass_count(0), Frame_material(""), Fastening_elements_count(0),
        Glass_package_manufacturer(""), Frame_manufacturer(""), Color(""), Price(0.0) {}

    // Parameterized constructor
    Plastic_Window(int glass_count, const std::string& frame_material, int fastening_elements_count,
        const std::string& glass_package_manufacturer, const std::string& frame_manufacturer,
        const std::string& color, double price)
        : Glass_count(glass_count), Frame_material(frame_material), Fastening_elements_count(fastening_elements_count),
        Glass_package_manufacturer(glass_package_manufacturer), Frame_manufacturer(frame_manufacturer),
        Color(color), Price(price) {}

    // Getters
    int getGlassCount() const { return Glass_count; }
    std::string getFrameMaterial() const { return Frame_material; }
    int getFasteningElementsCount() const { return Fastening_elements_count; }
    std::string getGlassPackageManufacturer() const { return Glass_package_manufacturer; }
    std::string getFrameManufacturer() const { return Frame_manufacturer; }
    std::string getColor() const { return Color; }
    double getPrice() const { return Price; }

    // Setters
    void setGlassCount(int count) { Glass_count = count; }
    void setFrameMaterial(const std::string& material) { Frame_material = material; }
    void setFasteningElementsCount(int count) { Fastening_elements_count = count; }
    void setGlassPackageManufacturer(const std::string& manufacturer) { Glass_package_manufacturer = manufacturer; }
    void setFrameManufacturer(const std::string& manufacturer) { Frame_manufacturer = manufacturer; }
    void setColor(const std::string& color) { Color = color; }
    void setPrice(double price) { Price = price; }

    // Rule of three: Destructor, Copy Constructor, Copy Assignment Operator
    ~Plastic_Window() {
        // Add cleanup code if needed
    }

    // Copy Constructor
    Plastic_Window(const Plastic_Window& other) {
        // Implement copy logic here
    }

    // Copy Assignment Operator
    Plastic_Window& operator=(const Plastic_Window& other) {
        if (this != &other) {
            // Implement copy assignment logic here
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Plastic_Window& window);
    friend std::istream& operator>>(std::istream& is, Plastic_Window& window);
};

// Implementation of the output stream operator (for printing)
std::ostream& operator<<(std::ostream& os, const Plastic_Window& window) {
    os << window.getGlassCount() << "\t"
        << window.getFrameMaterial() << "\t"
        << window.getFasteningElementsCount() << "\t"
        << window.getGlassPackageManufacturer() << "\t"
        << window.getFrameManufacturer() << "\t"
        << window.getColor() << "\t"
        << window.getPrice();
    return os;
}

// Implementation of the input stream operator (for reading)
std::istream& operator>>(std::istream& is, Plastic_Window& window) {
    int glassCount, fasteningCount;
    double price;
    std::string frameMaterial, glassPackageManuf, frameManuf, color;

    // Prompt user for input
    std::cout << "Enter Glass Count: ";
    is >> glassCount;
    window.setGlassCount(glassCount);

    // Repeat the above for other members

    return is;
}

int main() {
    // Prompt the user to input 3 windows in a vector
    std::vector<Plastic_Window> windows;
    for (int i = 0; i < 3; ++i) {
        Plastic_Window window;
        std::cin >> window;
        windows.push_back(window);
    }

    // Print the obtained data in table format
    std::cout << "Glass\tMaterial\tFastening\tGlass Package\tFrame\tColor\tPrice\n";
    for (const auto& window : windows) {
        std::cout << window << "\n";
    }

    // Calculate and print the order price
    double total_price = 0.0;
    for (const auto& window : windows) {
        total_price += window.getPrice();
    }
    std::cout << "\nTotal Order Price: " << total_price << "\n";

    return 0;
}
