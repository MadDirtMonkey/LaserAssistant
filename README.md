# LaserAssistant

![Work in Progress](https://img.shields.io/badge/-Work%20In%20Progress-orange)

LaserAssistant is an ESP32-based CO2 laser cutter assistant that monitors and controls various parameters of the laser cutter to ensure optimal performance and safety. It provides real-time monitoring, temperature control, data visualization, safety interlocks, and support for additional features such as motorized Z adjustable cutting beds and laser autofocus.

## Goals

1. Monitor coolant temperature and flow
2. Display various data on a screen
3. Interlocks to prevent damage to the laser if coolant temperature or flow is outside of safe parameters
4. Control active cooling to maintain a target temperature, without dropping below the dew point
5. Support for a coolant heater + pump to prevent freezing in cold temperatures
6. Support motorised Z adjustable cutting beds
7. Support autofocus
8. Updatable OTA

## Feature wishlist

- **Coolant Monitoring**: LaserAssistant monitors the coolant temperature and flow rate to ensure efficient cooling of the laser. It provides real-time updates on the status of the coolant system.

- **Interlocks and Safety**: LaserAssistant implements interlocks to prevent damage to the laser system. If the coolant temperature or flow rate falls outside of safe parameters, the interlocks trigger to protect the laser tube from potential damage.

- **Temperature Control**: The system actively controls the cooling process to maintain a target temperature. It ensures that the coolant does not drop below the dew point, preventing condensation and potential damage to the laser tube.

- **Data Visualization**: The project includes a built-in screen to display various data such as coolant temperature, flow rate, dew point, and other relevant information. The display provides an intuitive interface for easy monitoring.

- **Motorized Z Adjustable Cutting Beds**: The project provides support for motorized Z adjustable cutting beds, allowing precise control of the laser focus depth for different materials and cutting requirements.

- **Autofocus Support**: LaserAssistant includes support for autofocus functionality, enabling automatic adjustment of the laser focus based on the material being cut. This feature simplifies the cutting process and improves accuracy.

- **OTA Updates**: The system supports Over-The-Air (OTA) updates, allowing you to easily update the firmware and add new features to the LaserAssistant without the need for physical reprogramming.

## Getting Started

To get started with LaserAssistant, follow these steps:

1. Clone the repository: `git clone https://github.com/maddirtmonkey/LaserAssistant.git`
2. Install the necessary dependencies (provide a list of required libraries, frameworks, or tools).
3. Configure the system according to your laser cutter's specifications by modifying the relevant parameters in the configuration file (if applicable).
4. Connect your ESP32 board to the sensors, ensuring proper wiring and connections.
5. Compile and upload the firmware to the ESP32 board.
6. Power on the LaserAssistant and start monitoring and controlling your CO2 laser cutter!

## Contributing

Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue in the GitHub repository. If you would like to contribute code, feel free to open a pull request with your changes.

When contributing, please adhere to the existing code style and follow the project's coding guidelines.

## License

This project is licensed under the [GPLv3 License](LICENSE.md).

## Acknowledgments

- [Library/Framework/Tool Name] - Used [Library/Framework/Tool Name] for [specific functionality/reason].
- [Author(s)] - The original creator(s) or contributor(s) of [Library/Framework/Tool Name].
