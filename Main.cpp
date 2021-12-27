#include "Perceptron.h"
#include <vector>
#include <iostream>
#include <random>
#include <string>
using std::vector;

int main() {
	//Code to build the finished application with.
	/*vector<double> weights{ -1.3119, -5.89517, 9.44548, 3.78922, -1.22725 };
	vector<double> input(4);

	while (true) {
		std::cout << "Enter the sepal length in cm : \n";
		std::string userInput;
		std::getline(std::cin, userInput);
		input[0] = stod(userInput);

		std::cout << "Enter the sepal width in cm : \n";
		std::getline(std::cin, userInput);
		input[1] = stod(userInput);

		std::cout << "Enter the petal length in cm : \n";
		std::getline(std::cin, userInput);
		input[2] = stod(userInput);

		std::cout << "Enter the petal width in cm : \n";
		std::getline(std::cin, userInput);
		input[3] = stod(userInput);

		if (classify(input, weights) == 0) {
			std::cout << "Iris Setosa \n\n";
		}
		else {
			std::cout << "Iris Versicolor \n\n";
		}
	}*/

	vector<vector<double>> irisData{
		{5.1, 3.5, 1.4, 0.2, 0}, {4.9, 3.0, 1.4, 0.2, 0}, {4.7, 3.2, 1.3, 0.2, 0}, {4.6, 3.1, 1.5, 0.2, 0},
		{5.0, 3.6, 1.4, 0.2, 0},{5.4, 3.9, 1.7, 0.4, 0},{4.6, 3.4, 1.4, 0.3, 0},{5.0, 3.4, 1.5, 0.2, 0},{4.4, 2.9, 1.4, 0.2, 0},{4.9, 3.1, 1.5, 0.1, 0},
		{5.4, 3.7, 1.5, 0.2, 0},{4.8, 3.4, 1.6, 0.2, 0},{4.8, 3.0, 1.4, 0.1, 0},{4.3, 3.0, 1.1, 0.1, 0},{5.8, 4.0, 1.2, 0.2, 0},{5.7, 4.4, 1.5, 0.4, 0},
		{5.4, 3.9, 1.3, 0.4, 0},{5.1, 3.5, 1.4, 0.3, 0},{5.7, 3.8, 1.7, 0.3, 0},{5.1, 3.8, 1.5, 0.3, 0},{5.4, 3.4, 1.7, 0.2, 0},{5.1, 3.7, 1.5, 0.4, 0},
		{4.6, 3.6, 1.0, 0.2, 0},{5.1, 3.3, 1.7, 0.5, 0},{4.8, 3.4, 1.9, 0.2, 0},{5.0, 3.0, 1.6, 0.2, 0},{5.0, 3.4, 1.6, 0.4, 0},{5.2, 3.5, 1.5, 0.2, 0},
		{5.2, 3.4, 1.4, 0.2, 0},{4.7, 3.2, 1.6, 0.2, 0},{4.8, 3.1, 1.6, 0.2, 0},{5.4, 3.4, 1.5, 0.4, 0},{5.2, 4.1, 1.5, 0.1, 0},{5.5, 4.2, 1.4, 0.2, 0},
		{4.9, 3.1, 1.5, 0.1, 0},{5.0, 3.2, 1.2, 0.2, 0},{5.5, 3.5, 1.3, 0.2, 0},{4.9, 3.1, 1.5, 0.1, 0},{4.4, 3.0, 1.3, 0.2, 0},{5.1, 3.4, 1.5, 0.2, 0},
		{5.0, 3.5, 1.3, 0.3, 0},{4.5, 2.3, 1.3, 0.3, 0},{4.4, 3.2, 1.3, 0.2, 0},{5.0, 3.5, 1.6, 0.6, 0},{5.1, 3.8, 1.9, 0.4, 0},{4.8, 3.0, 1.4, 0.3, 0},
		{5.1, 3.8, 1.6, 0.2, 0},{4.6, 3.2, 1.4, 0.2, 0},{5.3, 3.7, 1.5, 0.2, 0},{5.0, 3.3, 1.4, 0.2, 0},
		{7.0, 3.2, 4.7, 1.4, 1},{6.4, 3.2, 4.5, 1.5, 1},{6.9, 3.1, 4.9, 1.5, 1},{5.5, 2.3, 4.0, 1.3, 1},
		{6.5, 2.8, 4.6, 1.5, 1},{5.7, 2.8, 4.5, 1.3, 1},{6.3, 3.3, 4.7, 1.6, 1},{4.9, 2.4, 3.3, 1.0, 1},{6.6, 2.9, 4.6, 1.3, 1},{5.2, 2.7, 3.9, 1.4, 1},
		{5.0, 2.0, 3.5, 1.0, 1},{5.9, 3.0, 4.2, 1.5, 1},{6.0, 2.2, 4.0, 1.0, 1},{6.1, 2.9, 4.7, 1.4, 1},{5.6, 2.9, 3.6, 1.3, 1},{6.7, 3.1, 4.4, 1.4, 1},
		{5.6, 3.0, 4.5, 1.5, 1},{5.8, 2.7, 4.1, 1.0, 1},{6.2, 2.2, 4.5, 1.5, 1},{5.6, 2.5, 3.9, 1.1, 1},{5.9, 3.2, 4.8, 1.8, 1},{6.1, 2.8, 4.0, 1.3, 1},
		{6.3, 2.5, 4.9, 1.5, 1},{6.1, 2.8, 4.7, 1.2, 1},{6.4, 2.9, 4.3, 1.3, 1},{6.6, 3.0, 4.4, 1.4, 1},{6.8, 2.8, 4.8, 1.4, 1},{6.7, 3.0, 5.0, 1.7, 1},
		{6.0, 2.9, 4.5, 1.5, 1},{5.7, 2.6, 3.5, 1.0, 1},{5.5, 2.4, 3.8, 1.1, 1},{5.5, 2.4, 3.7, 1.0, 1},{5.8, 2.7, 3.9, 1.2, 1},{6.0, 2.7, 5.1, 1.6, 1},
		{5.4, 3.0, 4.5, 1.5, 1},{6.0, 3.4, 4.5, 1.6, 1},{6.7, 3.1, 4.7, 1.5, 1},{6.3, 2.3, 4.4, 1.3, 1},{5.6, 3.0, 4.1, 1.3, 1},{5.5, 2.5, 4.0, 1.3, 1},
		{5.5, 2.6, 4.4, 1.2, 1},{6.1, 3.0, 4.6, 1.4, 1},{5.8, 2.6, 4.0, 1.2, 1},{5.0, 2.3, 3.3, 1.0, 1},{5.6, 2.7, 4.2, 1.3, 1},{5.7, 3.0, 4.2, 1.2, 1},
		{5.7, 2.9, 4.2, 1.3, 1},{6.2, 2.9, 4.3, 1.3, 1},{5.1, 2.5, 3.0, 1.1, 1},{5.7, 2.8, 4.1, 1.3, 1}
	};

	
	vector<double> weights(5);

	randomize_weights(weights);

	std::random_device seed;
	shuffle(irisData.begin(), irisData.end(), seed);

	vector<vector<double>> testValues;
	for (int i = 0; i < 10; i++) {
		testValues.push_back(irisData.back());
		irisData.pop_back();
	}

	std::cout << "Initial Weight Values : \n";
	for (double i : weights) {
		std::cout << i << "\n";
	}

	training_function(irisData, weights);

	std::cout << "Final Weight Values : \n";
	for (double i : weights) {
		std::cout << i << "\n";
	}

	//Classify 10 iris data and test to see if correct
	for (int i = 0; i < testValues.size(); i++) {
		std::cout << "Expected : " << testValues[i].back() << "   found : ";
		std::cout << classify(testValues[i], weights) << "\n";
	}

	////Create fake iris data and test to see if the perceptron can classify
	vector<vector<double>> fakeIrisData{
		{5.3, 3.2, 1.2, 0.3, 0},{5.0, 3.6, 1.5, 0.1, 0},
		{5.4, 3.1, 4.4, 1.2, 1},{5.3, 3.1, 4.3, 1.3, 1}
	};

	for (int i = 0; i < fakeIrisData.size(); i++) {
		std::cout << "Expected : " << fakeIrisData[i].back() << "   found : ";
		std::cout << classify(fakeIrisData[i], weights) << "\n";
	}



}



