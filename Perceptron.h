#include <vector>
#pragma once
using std::vector;

const double BIAS_INPUT = 1;
const double MAX_EPOCHS = 100;

double integration_function(const vector<double>& input, const vector<double>& weights);
int activation_function(const double input);
void training_function(vector<vector<double>>& input, vector<double>& weights);
int classify(const vector<double>& input, const vector<double>& weights);
void randomize_weights(vector<double>& weights);