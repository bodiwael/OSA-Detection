# OSA-Detection
 <img src="faceDetection.png">

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Overview
OSA-Detection is a project aimed at detecting Obstructive Sleep Apnea (OSA) using various hardware components and machine learning models. The repository includes code and resources for data collection, model training, and real-time detection of OSA events.

## Features
- **Real-time data collection** using sensors connected to Arduino and ESP8266/ESP32 boards.
- **Machine learning models** for OSA detection.
- **Firebase integration** for data storage and retrieval.
- **Mobile application (OSA.apk)** for user interface and monitoring.

## Installation
### Prerequisites
- Arduino IDE
- Python 3.x
- Jupyter Notebook
- Firebase account

### Hardware
- MAX30102 Pulse Oximeter Sensor
- ESP8266/ESP32 microcontroller

### Steps
1. **Clone the repository:**
   ```sh
   git clone https://github.com/bodiwael/OSA-Detection.git
   cd OSA-Detection
   ```

2. **Set up Arduino:**
   - Open the Arduino IDE.
   - Install the required libraries from the `libraries/` directory.
   - Upload the `arduino/` code to your Arduino board.

3. **Set up Firebase:**
   - Follow the steps in `Python-Firebase-Tutorial` to configure Firebase.
   - Update the Firebase configuration in the Python scripts.

4. **Install Python dependencies:**
   ```sh
   pip install -r requirements.txt
   ```

## Usage
1. **Data Collection:**
   - Use the Arduino setup to collect real-time data and upload it to Firebase.

2. **Model Training:**
   - Use the `models-trial.ipynb` Jupyter Notebook to preprocess data and train the machine learning models.

3. **Real-time Detection:**
   - Run the `osa-detection.ipynb` notebook for real-time OSA detection using the trained model.

4. **Mobile Application:**
   - Install `OSA.apk` on your Android device for monitoring and alerts.

## Project Structure
- `arduino/`: Contains Arduino code for data collection.
- `Python-Firebase-Tutorial/`: Tutorial for setting up Firebase with Python.
- `models-trial.ipynb`: Jupyter Notebook for training machine learning models.
- `osa-detection.ipynb`: Jupyter Notebook for real-time OSA detection.
- `OSA.apk`: Android application for user interface.
- `firebase/`: Firebase setup files.
- `data_filtered (1).csv`: Example dataset.
- `faceDetection.png`: Image resource.
- `libraries/`: Contains Arduino libraries required for the project.

## Contributing
Contributions are welcome! Please fork this repository and submit pull requests with detailed descriptions of your changes.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

If you have any questions or need further assistance, please open an issue in this repository. Happy coding!
