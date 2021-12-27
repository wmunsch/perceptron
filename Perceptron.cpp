#include "Perceptron.h"
#include <vector>
#include <numeric>
#include <random>
#include <iostream>
using std::vector;

double integration_function(const vector<double>& input, const vector<double>& weights) {
	/*double sum = 0;
	for (int i = 0; i < input.size(); i++) {
		sum += input[i] * weights[i];
	}
	return sum;*/
	return inner_product(input.begin(), input.end(), weights.begin(), 0.0);
}

int activation_function(const double input) {
	if (input >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void randomize_weights(vector<double>& weights) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_real_distribution<double> distributionDouble(-.5, .5);
	for (int i = 0; i < weights.size(); i++) {
		weights[i] = distributionDouble(generator);
	}
}

void training_function(vector<vector<double>>& input, vector<double>& weights) {
	int incorrect = 0;
	for (int i = 0; i < MAX_EPOCHS; i++) {
		incorrect = 0;
		std::random_device seed;
		shuffle(input.begin(), input.end(), seed);

		for (int j = 0; j < input.size(); j++) {
			double dot = integration_function(input[j], weights);
			dot += BIAS_INPUT * weights.back();
			int calculatedOutput = activation_function(dot);
			double error = input[j].back() - calculatedOutput;

			if (error != 0) {
				incorrect++;
				//Perform training
				for (int k = 0; k < weights.size() - 1; k++) {
					weights[k] += input[j][k] * error;
				}
				weights.back() += BIAS_INPUT * error;
			}
		}

		std::cout << "Incorrect : " << incorrect << "\n";
		if (incorrect == 0) {
			break;
		}

	}
}
int classify(const vector<double>& input, const vector<double>& weights) {
	double dot = integration_function(input, weights);
	dot += BIAS_INPUT * weights.back();
	return activation_function(dot);
}