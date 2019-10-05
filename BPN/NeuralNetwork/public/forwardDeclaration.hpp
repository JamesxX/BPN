#ifndef NEURALNETWORK_PUBLIC_FORWARD_HPP
#define NEURALNETWORK_PUBLIC_FORWARD_HPP

#include <NeuralNetwork/public/library.hpp>

#define NeuralNetwork_ns NeuralNetwork
namespace NeuralNetwork_ns
{

	typedef double numeric;

	class Net;

	namespace Layer {
		class ILayer;
		class InputLayer;
		class HiddenLayer;
		class OutputLayer;
	}

	class Neuron;

	namespace ActivationFunction
	{
		class IActivationFunction;
		class Sigmoid;
		class Threshold;
	}
}

#endif // NEURALNETWORK_PUBLIC_FORWARD_HPP
