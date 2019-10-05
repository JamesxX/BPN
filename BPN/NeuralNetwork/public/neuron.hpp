#ifndef NEURALNETWORK_PUBLIC_NEURON_HPP
#define NEURALNETWORK_PUBLIC_NEURON_HPP

#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>

#include <vector>

namespace NeuralNetwork_ns
{

	class Neuron
	{
	public:

	private:
		_STD vector<NeuralNetwork_ns::numeric> m_Weights;
	};

}

#endif // NEURALNETWORK_PUBLIC_NEURON_HPP
