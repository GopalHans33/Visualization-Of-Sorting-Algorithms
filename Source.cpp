#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// Define constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BAR_WIDTH = 3;
const int BAR_SPACING = 1; // Additional spacing between bars

// Function to generate random array
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, WINDOW_HEIGHT);
    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Function to draw bars
void drawBars(sf::RenderWindow& window, const vector<int>& arr) {
    window.clear(sf::Color::White);
    for (size_t i = 0; i < arr.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH, arr[i]));
        bar.setPosition(i * (BAR_WIDTH + BAR_SPACING), WINDOW_HEIGHT - arr[i]);
        bar.setFillColor(sf::Color::Blue);
        window.draw(bar);
    }
    window.display();
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, sf::RenderWindow& window, float speed) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, window, speed);
        mergeSort(arr, mid + 1, right, window, speed);
        merge(arr, left, mid, right);
        drawBars(window, arr);
        sf::sleep(sf::seconds(speed));
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high, sf::RenderWindow& window, float speed) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            drawBars(window, arr);
            sf::sleep(sf::seconds(speed));
        }
    }
    swap(arr[i + 1], arr[high]);
    drawBars(window, arr);
    sf::sleep(sf::seconds(speed));
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high, sf::RenderWindow& window, float speed) {
    if (low < high) {
        int pi = partition(arr, low, high, window, speed);
        quickSort(arr, low, pi - 1, window, speed);
        quickSort(arr, pi + 1, high, window, speed);
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr, sf::RenderWindow& window, float speed) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                drawBars(window, arr);
                sf::sleep(sf::seconds(speed));
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr, sf::RenderWindow& window, float speed) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            drawBars(window, arr);
            sf::sleep(sf::seconds(speed));
        }
        arr[j + 1] = key;
        drawBars(window, arr);
        sf::sleep(sf::seconds(speed));
    }
}

// Selection Sort
void selectionSort(vector<int>& arr, sf::RenderWindow& window, float speed) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
        drawBars(window, arr);
        sf::sleep(sf::seconds(speed));
    }
}

int main() {
    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Visualization");

    // Prompt user for array size
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    // Generate random array
    vector<int> originalArray = generateRandomArray(size);

    // Sorting speed
    float speed;
    cout << "Enter sorting speed (seconds per step): ";
    cin >> speed;

    while (window.isOpen()) {
        // Create a copy of the original array to sort
        vector<int> arr = originalArray;

        // Display initial array
        drawBars(window, arr);

        // Select sorting algorithm
        int choice;
        cout << "Select Sorting Algorithm: " << endl;
        cout << "1. Merge Sort" << endl;
        cout << "2. Quick Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Selection Sort" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            window.close();
            break;
        }

        switch (choice) {
        case 1:
            mergeSort(arr, 0, arr.size() - 1, window, speed);
            break;
        case 2:
            quickSort(arr, 0, arr.size() - 1, window, speed);
            break;
        case 3:
            bubbleSort(arr, window, speed);
            break;
        case 4:
            insertionSort(arr, window, speed);
            break;
        case 5:
            selectionSort(arr, window, speed);
            break;
        default:
            cout << "Invalid choice." << endl;
            continue;
        }

        // Check for window events to keep it open
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}