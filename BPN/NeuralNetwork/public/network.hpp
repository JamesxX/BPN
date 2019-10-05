#ifndef NEURALNETWORK_PUBLIC_NETWORK_HPP
#define NEURALNETWORK_PUBLIC_NETWORK_HPP

#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>

#include <NeuralNetwork/public/layer.hpp>
#include <vector>

namespace NeuralNetwork_ns
{

	class Net
	{
	public:

	private:
		NeuralNetwork_ns::Layer::layer_list_t m_Layers;
	};

}

#endif // NEURALNETWORK_PUBLIC_NETWORK_HPP
