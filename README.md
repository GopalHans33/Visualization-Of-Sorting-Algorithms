# Sorting Visualization

This project is a sorting algorithm visualizer built using SFML (Simple and Fast Multimedia Library). It allows you to generate a random array and visualize the sorting process using various sorting algorithms.

## Features

- Visualize sorting algorithms in real-time
- Choose from multiple sorting algorithms
- Adjustable sorting speed
- Interactive user interface

## Requirements

- SFML library
- C++ compiler

## Installation

1. Install the SFML library:
    - For Windows: Download the SFML library from the [SFML website](https://www.sfml-dev.org/download.php) and follow the installation instructions.
    - For Linux: Install SFML using your package manager. For example, on Ubuntu, you can run:
      ```bash
      sudo apt-get install libsfml-dev
      ```

2. Clone this repository:
    ```bash
    git clone  https://github.com/GopalHans33/Visualization-Of-Sorting-Algorithms.git
    cd Visualization-Of-Sorting-Algorithms
    ```

3. Compile the code:
    ```bash
    g++ -o Visualization-Of-Sorting-Algorithms source.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```

## Usage

1. Run the executable:
    ```bash
    ./Visualization-Of-Sorting-Algorithms
    ```

2. Follow the prompts to:
    - Enter the size of the array.
    - Enter the sorting speed (seconds per step).
    - Choose a sorting algorithm from the menu.

3. The window will display the array and visualize the sorting process.

4. After sorting, you can choose another algorithm to sort the same array again or exit the program.

## Supported Sorting Algorithms

- Merge Sort
- Quick Sort
- Bubble Sort
- Insertion Sort
- Selection Sort

## Code Structure

- `source.cpp`: Contains the main function and all the sorting algorithms.
- `generateRandomArray`: Generates a random array of specified size.
- `drawBars`: Draws the bars representing the array in the SFML window.
- `mergeSort`, `quickSort`, `bubbleSort`, `insertionSort`, `selectionSort`: Functions implementing the respective sorting algorithms with visualization.

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to create a pull request or open an issue.

## License

This project is licensed under the MIT License.

## Acknowledgments

- [SFML Library](https://www.sfml-dev.org/) for providing the multimedia library used for visualization.
- [Sorting Algorithm Visualizations](https://visualgo.net/en/sorting) for inspiration.
