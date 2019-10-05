#ifndef NEURALNETWORK_PUBLIC_FORWARD_HPP
#define NEURALNETWORK_PUBLIC_FORWARD_HPP

#include <NeuralNetwork/public/library.hpp>
#include <vector>

#define NeuralNetwork_ns NeuralNetwork
namespace NeuralNetwork_ns
{

	typedef double numeric_t;
	typedef numeric_t numeric;
	typedef numeric_t weight_t;
	typedef numeric_t bias_t;
	typedef numeric_t output_t;
	typedef _STD vector< output_t> output_list_t;

	class Net;

	namespace Layer {
		class ILayer;

		typedef _STD vector<ILayer> layer_list_t;

		class InputLayer;
		class HiddenLayer;
		class OutputLayer;
	};

	class Neuron;

	typedef _STD vector<weight_t> synapse_list_t;

	typedef _STD size_t neuron_id_t;
	typedef _STD vector<Neuron> neuron_list_t;


	namespace ActivationFunction
	{
		class IActivationFunction;
		class Sigmoid;
		class Identity;
		class TanH;
	};

};

#endif // NEURALNETWORK_PUBLIC_FORWARD_HPP
