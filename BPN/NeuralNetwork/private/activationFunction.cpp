#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>
#include <NeuralNetwork/public/activationFunction.hpp>

#include <cmath>

namespace ActivationFunction = NeuralNetwork_ns::ActivationFunction;

// Sigmoid

NeuralNetwork_ns::output_t ActivationFunction::Sigmoid::operator()(NeuralNetwork_ns::output_t input)
{
	return 1/(1 + exp(-input));
}

NeuralNetwork_ns::output_t ActivationFunction::Sigmoid::derivative(NeuralNetwork_ns::output_t input)
{
	NeuralNetwork_ns::output_t sigmaX = (*this)(input);
	return sigmaX * (1 - sigmaX);
}

// Identity

NeuralNetwork_ns::output_t ActivationFunction::Identity::operator()(NeuralNetwork_ns::output_t input)
{
	return input;
}

NeuralNetwork_ns::output_t ActivationFunction::Identity::derivative(NeuralNetwork_ns::output_t input)
{
	return 1;
}

// TanH

NeuralNetwork_ns::output_t ActivationFunction::TanH::operator()(NeuralNetwork_ns::output_t input)
{
	return (exp(input) - exp(-input))/(exp(input) + exp(-input));
}

NeuralNetwork_ns::output_t ActivationFunction::TanH::derivative(NeuralNetwork_ns::output_t input)
{
	return 1 - pow((*this)(input), 2);
}