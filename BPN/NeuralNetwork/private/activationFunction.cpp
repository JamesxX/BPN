#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>
#include <NeuralNetwork/public/activationFunction.hpp>

#include <cmath>

namespace ActivationFunction = NeuralNetwork_ns::ActivationFunction;

#define ActivationFunctionPreprocessorSignature(name, method) \
NeuralNetwork_ns::matrix_component_t ActivationFunction::name::method(NeuralNetwork_ns::matrix_component_t input)

// IActivationFunction
ActivationFunctionPreprocessorSignature(IActivationFunction, operator())
{
	return input;
}

ActivationFunctionPreprocessorSignature(IActivationFunction, derivative)
{
	return 1;
}


// Sigmoid
ActivationFunctionPreprocessorSignature(Sigmoid, operator())
{
	return 1/(1 + exp(-input));
}

ActivationFunctionPreprocessorSignature(Sigmoid, derivative)
{
	NeuralNetwork_ns::matrix_component_t sigmaX = (*this)(input);
	return sigmaX * (1 - sigmaX);
}

// Identity
ActivationFunctionPreprocessorSignature(Identity, operator())
{
	return input;
}

ActivationFunctionPreprocessorSignature(Identity, derivative)
{
	return 1;
}

// TanH
ActivationFunctionPreprocessorSignature(TanH, operator())
{
	return (exp(input) - exp(-input))/(exp(input) + exp(-input));
}

ActivationFunctionPreprocessorSignature(Identity, derivative)
{
	return 1 - pow((*this)(input), 2);
}